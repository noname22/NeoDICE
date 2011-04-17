
# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

SRCS= asm1.c asm2.c asmaddr.c asmflt.c asubs.c block.c cexp.c exp.c gen.c \
 genarith.c genass.c genbool.c genlogic.c genmisc.c lex.c main.c reg.c \
 rules.c sem.c stmt.c subs.c sym.c toplevel.c types.c error.c pragma.c

OBJS= asm1.o asm2.o asmaddr.o asmflt.o asubs.o block.o cexp.o exp.o gen.o \
 genarith.o genass.o genbool.o genlogic.o genmisc.o lex.o main.o reg.o \
 rules.o sem.o stmt.o subs.o sym.o toplevel.o types.o error.o pragma.o

EXED= ../../ubin/dc1
EXE= dc1

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -DDEBUG -Dunix
#CFLAGS= -Wall -Wstrict-prototypes -g -I../.. -L../../ulib -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -DDEBUG
#CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -L../../ulib -DNO_ASM -DINTELBYTEORDER -DDEBUG

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

