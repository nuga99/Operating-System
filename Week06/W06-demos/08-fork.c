/*
 * Copyright (C) 2005-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV02 Thu Oct 26 12:27:30 WIB 2017
 * REV01 Mon Oct 24 10:43:00 WIB 2016
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(void) {
   int ii=0;
   if (fork() == 0) ii++;
   wait(NULL);
   if (fork() == 0) ii++;
   wait(NULL);
   if (fork() == 0) ii++;
   wait(NULL);
   printf ("Result = %d \n",ii);
   exit(0);
}

/*
 * TAKE NOTE(MA)
 * Program ini akan membuat suatu proses parent 
 * menunggu terlebih dahulu sampai childnya selesai
 *
 * Oleh karena itu, 
 * maka proses child yang paling baru akan memiliki ii paling besar,
 * dan proses parent yang paling lama akan memilik ii paling kecil
 *
 * Nilai ii tiap proses akan lebih jelas 
 * ketika digambarkan setiap prosesnya
 */

