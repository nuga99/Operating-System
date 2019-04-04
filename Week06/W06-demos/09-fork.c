/*
 * Copyright (C) 2005-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV03 Mon Oct 30 11:04:10 WIB 2017
 * REV00 Mon Oct 24 10:43:00 WIB 2016
 * START 2015
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void) {
   int value;

   value=fork();
   wait(NULL);
   printf("I am PID[%4d] -- The fork() return value is: %4d)\n", getpid(), value);

   value=fork();
   wait(NULL);
   printf("I am PID[%4d] -- The fork() return value is: %4d)\n", getpid(), value);
}

/*
 * TAKE NOTE (ZA)
 * program akan membagi 2 proses yaitu parent (proses saat ini) 
 * dan child (penambahan +1 dari parentnya)
 * fork() akan bernilai 0 jika proses tersebut adalah proses child,
 * fork() pada program ini membagi proses child dan parent, 
 * maka kedua proses tersebut berjalan bersamaan
 * di program ini ada proses yang menunggu ketika fungsi fork() 
 * sampai selesai dijalankan
 * value yang direturn adalah parent sebelumnya
 */

