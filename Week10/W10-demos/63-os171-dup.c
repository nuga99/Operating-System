/*
 * (c) 2017 Rahmat M. Samik-Ibrahim -- This is free software
 * REV01 Fri May 18 13:43:59 WIB 2018
 * START Thu Mar 30 16:56:54 WIB 2017
 *
 * fd2=dup(fd1)  duplicates fd1 to fd2
 * O_RDWR	Open the file so that it can be read from and written to.
 * O_TRUNC	Initially clear all data from the file.
 * O_CREAT	If the file does not exist, create it. 
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE "63-os171-dup-demo.txt"

static char* str1 = "AABB\n";
static char* str2 = "CCDD\n";
static char* str3 = "EEFF\n";

void main(void) {
   int fd1, fd2, fd3;
   /* STDIN=0, STDOUT=1, STDERR=2, therefore 
      fd1, fd2, fd3  will be 3, 4, and 5 */
   fd1 = open (FILE, O_TRUNC | O_RDWR | O_CREAT, 0644);
   fd2 = open (FILE, O_TRUNC | O_RDWR | O_CREAT, 0644);
   fd3 = dup(fd2);
   printf("fd1 = %d, fd2 = %d, fd3 = %d\n", fd1, fd2, fd3);
   write(fd1, str1, strlen(str1));
   write(fd2, str2, strlen(str2));
   write(fd3, str3, strlen(str3));
   close(fd1);
   close(fd2);
   close(fd3);
}

