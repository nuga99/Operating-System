/*
 * Copyright (C) 2015-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05 Wed Aug 29 18:34:21 WIB 2018
 * REV04 Tue Apr 17 09:30:43 WIB 2018
 * REV01 Wed Nov  2 11:49:39 WIB 2016
 * START Xxx Sep 30 XX:XX:XX UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

sem_t	generik;
sem_t	generik2;

void* thread1 (void* a) {
   sem_wait   (&generik);
   printf("THREAD1: I am second!\n");
   sem_post   (&generik2);
}

void* thread2 (void* a) {
   printf("THREAD2: I am first!\n");
   sem_post   (&generik);
}

void* thread3 (void* a) {
   sem_wait   (&generik2);
   printf("THREAD3: I am last!\n");
}

void main(void) {
   sem_init      (&generik,  0, 0);
   sem_init      (&generik2, 0, 0);
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   jalankan_trit ();
   beberes_trit  ("Bye Bye Main...");
}

/*
 * TAKE NOTE(MGW)
 * Thread berjalan concurrently (berdampingan) dan mengakses memori yang sama 
 * secara bersamaan. Hal tersebut menyebabkan "Race condition" dimana tidak 
 * ada keteraturan dan kejelasan ketika beberapa thread mengakses 1 variable
 * yang sama. Maka dari itu, datang peran semaphore yang menunggu suatu instruksi 
 * selesai untuk melanjutkan.
 *
 * Pada main, pertama menginit semaphore generik dan generik2 dengan sem_init() dengan 0.
 * Lalu menjalankan thread setelah didaftarkan. Ke-3 thread, thread1 thread2 dan thread3
 * jalan bersamaan. Tetapi thread1 semaphore menunggu generik dan thread3 semaphore 
 * menunggu generik2. Maka thread2 jalan terlebih dengan print string 
 * "THREAD2: I am first!", kemudian sem_post() mengubah generik menjadi 1, yang 
 * mengijinkan thread1 untuk jalan, setelah sem_wait(), generik kembali berubah menjadi 0 
 * dan print string "THREAD1: I am second!" dan sem_post() generik2 yang mengijinkan 
 * thread3 untuk jalan dan print string "THREAD3: I am last!". Setelah semua thread
 * selesai, beberes_trit() dijalankan dengan print string "Bye Bye Main...".
 *
 * Dengan adanya semaphore, bisa dipastikan flow jalannya sebuah program dengan runtutan
 * yang pasti dan jelas serta menghapuskan kemungkinan terjadinya "Race condition"
 */

