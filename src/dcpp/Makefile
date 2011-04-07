
# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

SRCS= cexp.c cpp.c define.c direct.c include.c main.c precomp.c subs.c sym.c
OBJS= cexp.o cpp.o define.o direct.o include.o main.o precomp.o subs.o sym.o

EXED= ../../ubin/dcpp
EXE= dcpp

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -DDEBUG

PROTOS= protos.h

all: $(PROTOS) $(EXE)

$(EXE) : $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(EXE) -lamiga
	strip $(EXE)

$(PROTOS) : $(SRCS)
	rm -f $(PROTOS)
	fgrep -h Prototype $(SRCS) >$(PROTOS)

install:
	install -m 0755 $(EXE) $(EXED)

clean:
	rm -f $(PROTOS) $(OBJS) $(EXE)

