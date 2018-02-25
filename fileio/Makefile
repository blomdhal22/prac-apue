ROOT=..
include $(ROOT)/Make.defines.linux

PROGS = fileflags hole mycat seek

all: $(PROGS) setfl.o

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o file.hole

include $(ROOT)/Make.libapue.inc