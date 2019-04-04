/*
 * Copyright (C) 2017-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Wed Aug 29 18:33:51 WIB 2018
 * START Mon Nov 27 10:19:59 WIB 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"
#define  NTHREAD      8
#define  RECDEEP      8
#define  LOOP1  100000
#define  LOOP2  100000
#define  LOOP3  100000

volatile int share;
void  multiloop(int recursive) {
   int dummy;
   if (recursive-- < 0) return;
   sleep(1);
   for (int ii; ii<LOOP1; ii++) {
      for (int jj; jj<LOOP2; jj++) {
         for (int kk; kk<LOOP3; kk++) {
            dummy+=ii*jj*kk;
         }
      }
   }
   share=dummy;
   multiloop(recursive);
}

void* thread (void* a) {
   printf("Start Thread...\n");
   multiloop(RECDEEP);
   printf("Stop  Thread...\n");
}

void main(void) {
   printf("This is MAIN\n");
   for (int ii=0;ii<NTHREAD;ii++)
      daftar_trit  (thread);
   jalankan_trit ();
   beberes_trit  ("TREXIT!");
}

/*
 * TAKE NOTE()
 */

