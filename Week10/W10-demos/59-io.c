/*
 * Copyright (C) 2015-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05 Wed Aug 29 20:55:23 WIB 2018
 * REV02 Thu Mar  9 21:23:03 WIB 2017
 * REV01 Sun Oct 16 20:52:42 WIB 2016
 * START Xxx Apr 25 XX:XX:XX WIB 2015
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE1 "demo-file9.txt"

void main(void) {
   int fd1, fd2;
   char strvar[100];
   printf ("***** Please check file %s ***** *****\n", FILE1);

/* BLOCK ***************
   close(STDERR_FILENO);
   close(STDOUT_FILENO);
   BLOCK *************** */

   fd1 = open (FILE1, O_RDWR | O_CREAT | O_TRUNC, 0644);
   fd2 = dup(fd1);
   printf(         "AAAAA print to standard output!!\n"); 
   fprintf(stdout, "BBBBB print to standard output!!\n"); 
   fprintf(stderr, "CCCCC print to standard error!!!\n");
   sprintf(strvar, "DDDDD print to fd1=%d!!!\n", fd1);
   dprintf(fd1,    "%s", strvar);
   dprintf(fd2,    "EEEEE print to fd2=%d!!!\n", fd2);
   close(fd1);
   close(fd2);
}


/*
 * TAKE NOTE (AII)

 * printf function is used to print character stream 
 * of data on stdout console.
 * fprintf places output on the named output stream.
 * sprintf writes formatted text to an array of char, 
 * as opposed to a stream.
 * dprintf places output on the file associated with the 
 * file descriptor fildes rather than on a stream.
 * open file demo-file9.txt to see the difference

 */

