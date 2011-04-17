
CFLAGS= -O2 -Wall -I.. -DINTELBYTEORDER -Dunix
OBJS= addhead.o addtail.o newlist.o remhead.o \
	gethead.o strdup.o getsucc.o gettail.o \
	getpred.o remove.o strnicmp.o getcwd.o \
	findname.o stricmp.o enqueue.o strins.o \
	insert.o order.o

LIB= libamiga.a

all: $(LIB)

$(LIB) : $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)
	ranlib $@

clean:
	rm -f $(OBJS) $(LIB)

install:
	cp $(LIB) ../ulib/$(LIB)

