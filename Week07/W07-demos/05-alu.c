/*
 * Copyright (C) 2013-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV04 Wed Aug 29 18:37:38 WIB 2018
 * REV03 Tue Apr 17 09:33:25 WIB 2018
 * REV01 Wed Nov  2 13:50:33 WIB 2016
 * START Xxx Xxx XX XX:XX:XX UTC 2013
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

#define      NThreads 4

sem_t        switch1, switch2;
int          addvar1, addvar2, addresult;
int          subvar1, subvar2, subresult;
int          mulvar1, mulvar2, mulresult;
int          divvar1, divvar2, divresult;

void* manager (void* a) {
   printf("Manager starts \n");

   for (int ii=0; ii< NThreads;ii++)
       sem_wait (&switch1);
   sem_wait  (&mutex);
   addvar1 = 5;
   addvar2 = 2;
   subvar1 = 7;
   subvar2 = 2;
   mulvar1 = 2;
   mulvar2 = 3;
   divvar1 = 4;
   divvar2 = 2;
   sem_post  (&mutex); 
   for (int ii=0; ii< NThreads;ii++)
       sem_post (&switch2);
   for (int ii=0; ii< NThreads;ii++)
       sem_wait (&switch1);
   printf("Result: %d + %d = %d\n", addvar1, addvar2, addresult);
   printf("Result: %d - %d = %d\n", subvar1, subvar2, subresult);
   printf("Result: %d * %d = %d\n", mulvar1, mulvar2, mulresult);
   printf("Result: %d / %d = %d\n", divvar1, divvar2, divresult);
}

void* add (void* a) {
   sem_post  (&switch1);
   sem_wait  (&switch2);

   sem_wait  (&mutex);
   printf("Add starts \n");
   addresult = addvar1 + addvar2;
   sem_post  (&mutex);
   sem_post  (&switch1);
}

void* subtract (void* a) {
   sem_post  (&switch1);
   sem_wait  (&switch2);

   sem_wait  (&mutex);
   printf("Subtract starts \n");
   subresult = subvar1 - subvar2;
   sem_post  (&mutex);
   sem_post  (&switch1);
}

void* multiply (void* a) {
   sem_post  (&switch1);
   sem_wait  (&switch2);
   sem_wait  (&mutex);
   printf("Multiply starts \n");
   mulresult = mulvar1 * mulvar2;
   sem_post  (&mutex);
   sem_post  (&switch1);
}

void* divide (void* a) {
   printf("Divide starts \n");
   sem_post  (&switch1);
   sem_wait  (&switch2);
   sem_wait  (&mutex);
   divresult = divvar1 / divvar2;
   sem_post  (&mutex);
   sem_post  (&switch1);
}

void main(void) {
   sem_init      (&mutex,   0, 1);
   sem_init      (&switch1, 0, 0);
   sem_init      (&switch2, 0, 0);
   daftar_trit   (manager);
   daftar_trit   (add);
   daftar_trit   (subtract);
   daftar_trit   (multiply);
   daftar_trit   (divide);
   jalankan_trit ();
   beberes_trit  ("Done...");
}

/*
 * TAKE NOTE (ZA)
 * line 49-58: fungsi add pada program ini
 * line 60-69: fungsi substarct pada program ini
 * line 71-79: fungsi multiply pada program ini
 * line 81-89: fungsi devide pada program ini
 * line 91-101: fungsi main untuk menjalankan program ini
 * *sem_wait, to wait on a semaphore
 * If the value of the semaphore is negative, the calling process blocks;
 * one of the blocked processes wakes up when 
 * another process calls sem_post.
 * sem_post, to increment the value of a semaphore. It increments the 
 * value of the semaphore and wakes up a blocked process waiting on the semaphore, if any.
 */


