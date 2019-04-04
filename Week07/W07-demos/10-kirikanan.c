/*
 * Copyright (C) 2011-2018 Rahmat M. Samik-Ibrahim (2017-1)
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05 Wed Aug 29 18:42:16 WIB 2018
 * REV04 Tue Apr 17 09:25:59 WIB 2018
 * REV01 Wed May 17 17:02:37 WIB 2017
 * START Wed May  3 12:58:28 WIB 2017
 *
 * sem_init(), sem_wait(), sem_post(): semaphore
 * sleep(X): sleep X seconds
 * daftar_trit(T):  register thread T
 * jalankan_trit(): start all registered threads.
 * beberes_trit():  exit all threads above.  */

#define jmlKIRI     5
#define jmlKANAN    3
#define SLEEP       2000
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"

sem_t   syncModKiri, syncModKanan;
sem_t   syncKiriMod, syncKananMod;

#define aCetak 0
#define aKanan 1
#define aKiri  2

void cetak(char* posisi, int id) {
   printf("%2.2d %s(%2.2d)\n", getADDglobalID(aCetak), posisi, id);
}

void* Moderator (void* a) {
   int ii;
   while (TRUE) {
      for (ii=0; ii<jmlKIRI;  ii++)
         sem_wait (&syncKiriMod);
      for (ii=0; ii<jmlKANAN; ii++) {
         sem_post (&syncModKanan);
         rehat_acak(SLEEP);
      }
      for (ii=0; ii<jmlKANAN; ii++)
         sem_wait (&syncKananMod);
      for (ii=0; ii<jmlKIRI;  ii++) {
         sem_post (&syncModKiri);
         rehat_acak(SLEEP);
      }
   }
}

void* Kanan (void* a) {
   int id = getADDglobalID(aKanan);
   while (TRUE) {
      sem_wait (&syncModKanan);
      cetak("-+-+-+Kanan", id);
      sem_post (&syncKananMod);
   }
}

void* Kiri (void* a) {
   int id = getADDglobalID(aKiri);
   while (TRUE) {
      cetak("Kiri-+-+-+-", id);
      fflush(NULL);
      sem_post (&syncKiriMod);
      sem_wait (&syncModKiri);
   }
}

int main(int argc, char * argv[]) {
   int ii;

   init_globalID();
   sem_init (&syncModKiri,  0, 0);
   sem_init (&syncModKanan, 0, 0);
   sem_init (&syncKiriMod,  0, 0);
   sem_init (&syncKananMod, 0, 0);

   for (ii = 0 ; ii < jmlKANAN; ii++)
      daftar_trit(Kanan);
   for (ii = 0 ; ii < jmlKIRI; ii++)
      daftar_trit(Kiri);
   daftar_trit(Moderator);

   jalankan_trit();
   beberes_trit("Selese...");
}

/*
 * TAKE NOTE()
 */

