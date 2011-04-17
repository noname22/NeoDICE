# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

SRCS= main.c subs.c reloc.c symbol.c data.c code.c
OBJS= main.o subs.o reloc.o symbol.o data.o code.o

EXED= ../../ubin/dobj
EXE= dobj

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -Dunix

PROTOS= protos.h

all: $(PROTOS) $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) -lamiga
	strip $(EXE)

$(PROTOS) : $(SRCS)
	rm -f $(PROTOS)
	fgrep -h Prototype $(SRCS) >$(PROTOS)

install:
	install -m 0755 $(EXE) $(EXED)

clean:
	rm -f $(PROTOS) $(OBJS) $(EXE)

