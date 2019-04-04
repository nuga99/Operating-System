/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 20:55:23 WIB 2018
 * REV05 Mon Oct  2 16:24:19 WIB 2017
 * REV04 Thu Mar  9 21:22:10 WIB 2017
 * REV02 Sun Oct 16 20:51:34 WIB 2016
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
#define FILE1 "demo-file7.txt"

static char* str1 = "AAAXBBB\n";
static char* str2 = "CCC\n";

void main(void) {
   int fd1, fd2;
   fd1 = open (FILE1, O_RDWR | O_CREAT, 0644);
   fd2 = dup(fd1);
   printf("File Descriptors --- fd1 = %d, fd2 = %d\n", fd1, fd2);
   write(fd1, str1, strlen(str1));
   write(fd2, str2, strlen(str2));
   close(fd1);
   close(fd2);
   printf("**** Please check file %s *****\n", FILE1);
   printf("**** Compare with 54-write\n");
}

/*
 * TAKE NOTE(TA)
 * O_RDWR open for reading and writing
 * O_CREAT indicates that the call to open() has a mode argument,
 * if the file being opened already exist O_CREAT has no effect
 * if the file being opened does not exist it is created
 * if O_CREAT is specified and the file did not previously exist a sucessful open
 * () sets the access time, change time, and modification time for the file
 *
 * if succesful, dup() returns a new file descriptor
 * if unsucessful, dup() returs -1 and sets errno to EBADF or EMFILE
 * 
 */

