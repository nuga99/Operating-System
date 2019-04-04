/*
 * (C) 2018 Rahmat M. Samik-Ibrahim
 * You are free to SHARE and to ADAPT,
 * but WITHOUT ANY WARRANTY.
 * REV03 Mon Dec 10 18:53:06 WIB 2018
 * REV02 Wed Nov 21 20:48:39 WIB 2018
 * START Wed Nov 14 20:30:05 WIB 2018
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MYFLAGS     O_CREAT | O_RDWR
#define MYPROTECT PROT_READ | PROT_WRITE
#define MYVISIBILITY          MAP_SHARED
#define SFILE            "demo-file.bin"

typedef  struct {
   sem_t  sync[3];
   int    share;
   int    loop;
   pid_t  relative;
} myshare;

myshare* mymap;

void flushprintf(char* tag1, char* tag2){
   printf("%s[%s] loop%d relative(%d)\n", 
      tag1, tag2, mymap->loop, 
      getpid()  + mymap->relative);
   fflush(NULL);
}

#define MAIN "30:ADDSUB"
#define ADD1 "  31:ADD1"
#define SUB1 "  32:SUB1"

void main(void) {
   int fd   =open(SFILE,MYFLAGS,S_IRWXU);
   int ssize=sizeof(myshare);
   truncate(SFILE, ssize);
   mymap=mmap(NULL, ssize, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   mymap->share    = 0;
   mymap->loop     = 6;
   mymap->relative = 1000 - getpid();
   sem_init (&(mymap->sync[0]), 1, 0);
   sem_init (&(mymap->sync[1]), 1, 0);
   sem_init (&(mymap->sync[2]), 1, 0);
   flushprintf(MAIN, "EXEC");
   if (!fork())
      execlp("./31-add1", ADD1, NULL);
   if (!fork()) 
      execlp("./32-sub1", SUB1, NULL);
   do {
      sleep(1);
      flushprintf(MAIN, "LOOP");
   } while (--mymap->loop);
   flushprintf(MAIN, "WAIT");
   sem_wait (&(mymap->sync[0]));
   sem_wait (&(mymap->sync[0]));
   if      (mymap->share > 1500)
      flushprintf("SHARE +/-", "2000");
   else if (mymap->share > 500)
      flushprintf("SHARE +/-", "1000");
   else 
      flushprintf("SHARE +/-", "0");
   wait(NULL);
   wait(NULL);
   flushprintf(MAIN, "EXIT");
   close(fd);
}

//       1         2         3         4
// 4567890123456789012345678901234567890

