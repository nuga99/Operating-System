# REV04 Wed Nov 14 20:38:35 WIB 2018
# REV03 Tue May  1 20:35:45 DST 2018
# START Wed Apr 18 20:55:24 WIB 2018

CC=gcc
CFLAGS=-std=gnu99 -pthread

P10=10-create-file
P11=11-create-mmap
P20=20-parent
P21=21-child
P22=22-hello-goodbye
P23=23-kirim-ambil
P24=24-producer-consumer
P30=30-add1sub1
P31=31-add1
P32=32-sub1


EXECS= \
        $(P10) \
        $(P11) \
        $(P20) \
        $(P21) \
        $(P22) \
        $(P23) \
        $(P24) \
        $(P30) \
        $(P31) \
        $(P32) \


DEMOFILES=\
	demo-file.txt \
	demo-file.bin \
        

all:  $(EXECS)

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo:
	bash .shsh

