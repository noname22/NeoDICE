# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

EXES= bintohex fdtolib fdtopragma istrip lbmake libtos \
      makeproto romable hunks Join

ED= ../../ubin/

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER
LDFLAGS= -L../../ulib -lamiga

all: $(EXES)

bintohex: bintohex.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

fdtolib: fdtolib.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

fdtopragma: fdtopragma.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

istrip: istrip.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

lbmake: lbmake.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

libtos: libtos.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

makeproto: makeproto.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

romable: romable.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

hunks: hunks.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

Join: Join.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

install:
	install -m 0755 $(EXES) $(ED)

clean:
	rm -f $(EXES)

