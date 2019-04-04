/*
 * Copyright (C) 2005-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08 Mon Feb 11 15:33:59 WIB 2019
 * REV07 Wed Aug 29 16:11:46 WIB 2018
 * REV06 Wed Nov  1 13:35:19 WIB 2017
 * REV02 Mon Oct 24 10:43:00 WIB 2016
 * REV01 Sun Feb 27 08:31:46 WIB 2011
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DISPLAY1 "START * PARENT **** ** PID (%5d) ** ***********\n"
#define DISPLAY2 "RANDOM: val1(%5d) -- val2(%5d) -- val3(%5d)\n"
/*************************************************** main ** */
void main(void) {
   pid_t val1, val2, val3;
   printf(DISPLAY1, getpid());
   val1 = fork();
   val2 = fork();
   val3 = fork();
   printf(DISPLAY2, val1, val2, val3);
   wait(NULL);
}

/*
 * TAKE NOTE(MA)
 * Pada program ini, hasil fork akan dimasukkan
 * ke dalam variabel val1, val2, dan val3
 *
 * Yang mana,
 * nilai dari fork hanya akan masuk ke parentnya, bukan childnya
 * karena proses child tidak memasukkan nilainya
 * ke variabel dari fork tersebut
 *
 * Lalu, karena tidak ada sleep atau wait,
 * maka setiap proses akan terus berjalan bersamaan
 * Yang nanti pada akhirnya akan terbentuk 8 proses,
 * dan hasil printnya akan random,
 * urutannya akan berbeda-beda setiap program ini berjalan
 */
