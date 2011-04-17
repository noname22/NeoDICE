
# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

SRCS= final.c jump.c main.c module.c reloc.c subs.c sym.c
OBJS= final.o jump.o main.o module.o reloc.o subs.o sym.o

EXED= ../../ubin/dlink
EXE= dlink

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -Dunix
#CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DNO_ASM -DINTELBYTEORDER

PROTOS= protos.h

all: $(PROTOS) $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) -lamiga

$(PROTOS) : $(SRCS)
	rm -f $(PROTOS)
	fgrep -h Prototype $(SRCS) >$(PROTOS)

install:
	install -m 0755 $(EXE) $(EXED)
	strip $(EXED)

clean:
	rm -f $(PROTOS) $(OBJS) $(EXE)

