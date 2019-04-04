/*
 * Copyright (C) 2005-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV07 Tue Jan 22 21:02:11 WIB 2019
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV05 Wed Nov  1 13:34:33 WIB 2017
 * REV00 Mon Oct 24 10:43:00 WIB 2016
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*************************************************** main ** */
void main(void) {
   pid_t val1, val2, val3;
   val3 = val2 = val1 = 1000;
   printf("PID==[%5.5d] ==== ======= ==== =======\n", getpid());
   fflush(NULL);
   // TWO FORK()s //
   val1 = fork();
   wait(NULL);
   val2 = fork();
   printf("VAL1=[%5.5d] VAL2=[%5.5d] VAL3=[%5.5d]\n", val1, val2, val3);
}

/*
 * TAKE NOTE(MA)
 * Program ini hanya akan menunjukkan pid dari proses
 * dan variabel val1, val2, val3 akan memiliki value yang sama, yaitu 1000
 */

