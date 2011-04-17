# Makefile for linux/UNIX
#
# (c)Copyright 1992 Obvious Implementations Corp, All Rights Reserved
# CONFIDENTIAL, This is unpublished proprietary source code owned by
# Obvious Implementations Corp.  This material contains trade secrets of
# Obvious Implementations Corp.

EXES= bintohex fdtolib fdtopragma istrip lbmake libtos \
      makeproto romable hunks Join

ED= ../../ubin/

CFLAGS= -Wall -Wstrict-prototypes -O2 -I../.. -DREGISTERED -DCOMMERCIAL -DNO_ASM -DINTELBYTEORDER -Dunix
LDFLAGS= -L../../ulib -lamiga

all: $(EXES)

bintohex: bintohex.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

fdtolib: fdtolib.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

fdtopragma: fdtopragma.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

istrip: istrip.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

lbmake: lbmake.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

libtos: libtos.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

makeproto: makeproto.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

romable: romable.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

hunks: hunks.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

Join: Join.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

install:
	install -m 0755 $(EXES) $(ED)

clean:
	rm -f $(EXES)

