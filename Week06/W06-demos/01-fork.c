/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV01 Wed May  3 20:49:54 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   char *iAM="PARENT";
  
   printf("PID[%d] PPID[%d] (START:%s)\n", getpid(), getppid(), iAM);
   if (fork() > 0) {
      sleep(1);     /* LOOK THIS ************** */
      printf("PID[%d] PPID[%d] (IFF0:%s)\n", getpid(), getppid(), iAM);
   } else {
      iAM="CHILD";
      printf("PID[%d] PPID[%d] (ELSE:%s)\n", getpid(), getppid(), iAM);
   }
   printf("PID[%d] PPID[%d] (STOP:%s)\n", getpid(), getppid(), iAM);
}

/*
 * TAKE NOTE(MA)
 *
 * Program ini akan membuat sebuah proses terbagi atas 2,
 * yaitu proses saat ini (parent) dan proses duplikat parentnya (child),
 * setelah dilakukan fork()
 *
 * Pada dasarnya, fork() akan bernilai 0 
 * jika proses tersebut adalah proses child,
 * jadi, karena fork() hanya membagi menjadi proses child 
 * dan parent saja dan kedua proses berjalan bersamaan,
 * maka proses parent akan masuk ke statement if 
 * yang mana proses itu akan diberhentikan selama satu detik
 * dan proses child akan masuk ke statement else,
 * kemudian menyelesaikan print sampai program selesai.
 *
 * Kemudian, setelah proses parent disleep selama satu detik,
 * barulah proses parent bisa berjalan kembali
 * dan menyelesaikan print hingga program selesai.
 */

