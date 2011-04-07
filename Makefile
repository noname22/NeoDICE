PREFIX="/opt/neodice"

all:	 Banner Main Suplib
	@echo "done"

Banner:
	@echo ""
	@echo "==== NeoDICE 680x0 C Compiler ===="
	@echo ""

help:	Help

Help:	Banner
	@echo "Usage:"
	@echo "  make"
	@echo "  sudo make install"
	@echo ""
	@echo "Optionally an alternate install prefix (target) can be specified with:"
	@echo "  make PREFIX=\"/home/myhome/mysdk\""
	@echo "  sudo make install PREFIX=\"/home/myhome/mysdk\""
	@echo ""
	@echo "The default prefix is: $(PREFIX)"
	@echo ""
	@echo "!!! Note, does not work with x86_64 target yet (it segfaults) !!!"
	@echo ""
	@echo "If you're on a x86_64 system, please prepend CC=\"gcc -m32\" to make"
	@echo "and be sure to have a 32 bit dev libc installed (libc6-dev-i386)."
	@echo ""
	@echo "  CC=\"gcc -m32\" make"
	@echo "  sudo make install"
	@echo ""
	

Test:
	echo $(CFLAGS)

Configure:
	@echo "#ifndef SETTINGS_H" > settings.h
	@echo "#define NEODICE_PREFIX \"$(PREFIX)/\"" >> settings.h
	@echo "#endif" >> settings.h

Suplib:	Configure
	@echo "== Building support lib =="
	-mkdir -p ulib
	(cd suplib; make)
	(cd suplib; make install)

Main:	Suplib
	@echo "== Building compiler =="
	(cd src; make)
	-mkdir -p ubin
	(cd src; make install)

install:
	mkdir -p $(PREFIX)
	cp -r dlib $(PREFIX)
	cp -r ubin $(PREFIX)
	cp -r config $(PREFIX)
	cp -r include $(PREFIX)

	@echo "PATH=\$$PATH:$(PREFIX)/ubin" > $(PREFIX)/env.sh
	@echo "DCCOPTS=\"-2.0 -//\"" >> $(PREFIX)/env.sh
	@echo "DINCLUDE=\"$(PREFIX)/include/\"" >> $(PREFIX)/env.sh

	@echo ""
	@echo "done installing"
	@echo ""
	@echo "to set up the environment use: source $(PREFIX)/env.sh"

clean:
	(cd suplib; make clean; cd ..)
	(cd src;  make clean)
	-rm -rf ulib
	-rm -rf ubin
	
