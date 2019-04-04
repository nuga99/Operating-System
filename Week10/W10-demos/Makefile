# REV14 Mon Dec 10 15:17:15 WIB 2018
# REV03 Thu Mar  9 21:18:27 WIB 2017
# START Tue Sep 13 11:44:18 WIB 2016

CC            = gcc
CPP           = cpp
CFLAGS        = -std=gnu99
LDFLAGS       = 
CPPFLAGS      =
DEPFLAGS      = -MM -MT $(@:.d=.o) 
OUTPUT_OPTION = -o $@
COMPILE       = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
SRCS          = $(wildcard *.c)
OBJ           = $(SRCS:.c=.o)
DEP           = $(OBJ:.o=.d)
PROGS         = $(SRCS:.c=  )

P10=10-server
P11=11-client
P12=12-clisvr
P50=50-get-put
P51=51-get-put-loop
P52=52-open-close
P53=53-file-pointer
P54=54-write
P55=55-write
P56=56-copy
P57=57-dup
P58=58-dup2
P59=59-io
P60=60-readwrite
P61=61-open-dup
P62=62-os172
P63=63-os171-dup
P64=64-os161


EXECS= \
        $(P10) \
        $(P11) \
        $(P12) \
        $(P50) \
        $(P51) \
        $(P52) \
        $(P53) \
        $(P54) \
        $(P55) \
        $(P56) \
        $(P57) \
        $(P58) \
        $(P59) \
        $(P60) \
        $(P61) \
        $(P62) \
        $(P63) \
        $(P64) \


DEMOFILES=\
	demo-file1.txt \
	demo-file2.txt \
	demo-file3.txt \
	demo-file4.txt \
	demo-file5.txt \
	demo-file6.txt \
	demo-file7.txt \
	demo-file8.txt \
	demo-file9.txt \
	demo-fileA.txt \
	demo-copy.txt  \
        $(P61)-demo.txt \
        $(P62)-demo.txt \
        $(P63)-demo.txt \
        $(P64)-demo.txt \
        

MODE644=\
	demo-file4.txt \

all:  $(EXECS) demo-file4.txt

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

.phony: clean demo
clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo: demo-file4.txt
demo-file4.txt:
	@echo "Line 1: Blah Blah Blah 1" >  demo-file4.txt
	@echo "Line 2: Blah Blah Blah 2" >> demo-file4.txt
	@echo "Line 3: Blah Blah Blah 3" >> demo-file4.txt
	@chmod 644 $(MODE644)


## CC            = gcc
## CPP           = cpp
## LDFLAGS       = 
## CFLAGS        =
## CPPFLAGS      =
## DEPFLAGS      = -MM -MT $(@:.d=.o) 
## OUTPUT_OPTION = -o $@
## COMPILE       = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
## SRCS          = $(wildcard *.c)
## OBJ           = $(SRCS:.c=.o)
## DEP           = $(OBJ:.o=.d)
## PROGS         = $(SRCS:.c=  )

## 
## all: main1 main2 main3 main4
## 
## main1: main1.o sub1.o sub2.o sub3.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
##    
## main2: main2.o sub1.o sub2.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
##    
## main3: main3.o sub1.o sub3.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
##    
## main4: main4.o sub2.o sub3.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
## 
## -include $(DEP)
## 
## %.d: %.c
## 	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@
## 
## .phony: clean cleandep all
## 
## clean:
## 	rm -rf $(OBJ) $(PROGS) $(DEP) 
## 
