/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV02 Mon Oct 30 10:24:44 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>

void main(void) {
   int ii;
   printf("Sleeping 3s with fflush(): ");
   fflush(NULL);
   for (ii=0; ii < 3; ii++) {
      sleep(1);
      printf("x ");
      fflush(NULL);
   }
   printf("\nSleeping with no fflush(): ");
   for (ii=0; ii < 3; ii++) {
      sleep(1);
      printf("x ");
   }
   printf("\n");
}

/*
 * TAKE NOTE(MA, MIM)
 * Fungsi fflush(NULL) berfungsi untuk membuat 
 * print langsung dikeluarkan tanpa harus menunggu baris baru
 *
 * Oleh karena itu, maka ketika program dijalankan akan terlihat bahwa 
 * output akan keluar perlahan lahan 
 * pada satu baris ketika menggunakan fflush,
 * bukan 1 baris langsung keluar semua outputnya

 * Fflush() tidak mempercepat I/O tetapi user process menunggu hingga 
 * I/O selesai. Hal ini dikarenakan user process dan I/O menggunakan 
 * scheduling yang berbeda.
 */

