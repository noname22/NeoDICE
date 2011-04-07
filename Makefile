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
	@echo "  make install PREFIX=\"/home/myhome/mysdk\""
	@echo ""
	@echo "The default prefix is: $(PREFIX)"
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
	(cd suplib; pwd)
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

	@echo ""
	@echo "done installing"
	@echo ""
	@echo "to set up the environment use: source $(PREFIX)/env.sh"

clean:
	(cd suplib; make clean; cd ..)
	(cd src;  make clean)
	-rm -rf ulib
	-rm -rf ubin
	
