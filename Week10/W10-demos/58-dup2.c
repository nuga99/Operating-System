/*
 * Copyright (C) 2015-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 20:55:23 WIB 2018
 * REV04 Thu Mar  9 21:22:36 WIB 2017
 * REV02 Sun Oct 16 20:52:15 WIB 2016
 * START Xxx Apr 25 XX:XX:XX WIB 2015
 *
 * dup(fd) duplicates fd
 * fd2=dup(fd1)  <---> dup2(fd1, fd2)
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FILE1 "demo-file8.txt"

static char* str1 = "AAAXBBB\n";
static char* str2 = "CCC\n";

void main(void) {
   int fd1, fd2;
   fd1 = open (FILE1, O_RDWR | O_CREAT, 0644);
   dup2(fd1, fd2);
   printf("File Descriptors --- fd1 = %d, fd2 = %d\n", fd1, fd2);
   write(fd1, str1, strlen(str1));
   write(fd2, str2, strlen(str2));
   close(fd1);
   close(fd2);
   printf("**** Please check file %s *****\n", FILE1);
   printf("**** Compare with 54-write\n");
}

/*
 * TAKE NOTE (AII)
 *
 * dup(fd1, fd2) akan membuat copy dari fd1 kemudian 
 * disimpan di fd1
 * Dengan dup() maka mereka akan memiliki locks, file 
 * position pointers dan flags yang sama
 * Oleh karena itu setelah diwrite di fd1 "AAAXBBB\n", 
 * write untuk fd2 akan dimulai dari pointer yang sama 
 * setelah write di fd1. 
 * Isi akhir dari file demo-file8.txt setelah dilakukan 
 * write akan menjadi
 * AAAXBBB
 * CCC
 */


