/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV02 Mon Oct 30 20:25:44 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void procStatus(int level) {
   printf("L%d: PID[%d] (PPID[%d])\n", level, getpid(), getppid());
   fflush(NULL);
}

int addLevelAndFork(int level) {
   if (fork() == 0) level++;
   wait(NULL);
   return level;
}

void main(void) {
   int level = 0;
   procStatus(level);
   level = addLevelAndFork(level);
   procStatus(level);
}
 
/*
 * TAKE NOTE(MA)
 * Program awalnya akan mengeprint level dari proses parent.
 *
 * Lalu, pada saat memasukkan value ke variabel level,
 * dilakukan fork dan level child akan menjadi 1,
 * serta terdapat wait(NULL) yang akan membuat 
 * proses parent berhenti sejenak tanpa menambahkan nilai levelnya
 *
 * Kemudian akan melakukan print untuk 
 * proses child dan dilanjutkan dengan proses parent
 */ 
