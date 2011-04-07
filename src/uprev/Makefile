
# Makefile for linux/FreeBSD/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

SRCS=  UpRev.c
OBJS=  UpRev.o

EXED= ../../ubin/uprev
EXE= uprev

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER

all: $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) -lamiga
	strip $(EXE)

install:
	install -m 0755 $(EXE) $(EXED)

clean:
	rm -f $(OBJS) $(EXE)

