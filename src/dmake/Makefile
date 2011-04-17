# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

SRCS= buffer.c cmdlist.c convert.c depend.c main.c parse.c run.c subs.c var.c
OBJS= buffer.o cmdlist.o convert.o depend.o main.o parse.o run.o subs.o var.o

EXED= ../../ubin/dmake
EXE= dmake

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -Dunix

PROTOS= dmake-protos.h

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

