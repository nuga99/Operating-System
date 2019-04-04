/*
 * Copyright (C) 2005-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV03 Mon Oct 30 15:10:10 WIB 2017
 * REV00 Wed May  3 17:07:09 WIB 2017
 * START 2005
 *
 * fflush(NULL): flushes all open output streams
 * fork():       creates  a new process by cloning
 * getpid():     get PID (Process ID)
 * wait(NULL):   wait until the child is terminated
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(void) {
   int firstPID = (int) getpid();
   int   RelPID;

   fork();
   wait(NULL);
   fork();
   wait(NULL);
   fork();
   wait(NULL);

   RelPID=(int)getpid()-firstPID+1000;
   printf("RelPID: %d\n", RelPID);
   fflush(NULL);
}


/*
 * TAKE NOTE(MA)
 * Pada program ini, dapat dilihat bahwa terdapat 
 * 3 kali fork yang diselingi dengan  wait(NULL).
 *
 * Print pertama akan dilakukan pada proses child paling baru,
 * dan setelah selesai akan ke parentnya lagi.
 *
 * Detail lebih jelas akan terlihat ketika menggambarkan prosesnya.
 */

