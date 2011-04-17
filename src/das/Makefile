
# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

SRCS= direct.c exp.c lab.c main.c ops.c passa.c passb.c passc.c passg.c sect.c subs.c
OBJS= direct.o exp.o lab.o main.o ops.o passa.o passb.o passc.o passg.o sect.o subs.o

EXED= ../../ubin/das
EXE= das

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -DDEBUG -Dunix

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

