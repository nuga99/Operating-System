/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Wed Aug 29 16:11:46 WIB 2018
 * REV05 Wed Nov  1 13:30:44 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(void) {
   printf("  [[[ This is 00-show-pid: PID[%d] PPID[%d] ]]]\n", getpid(), getppid());
}

/*
 * TAKE NOTE (AII, MA)
 * In Linux, an executable stored on disk is called a program,
 * and a program loaded into memory and running is 
 * called a process. 
 * When a process is started, it is given a unique 
 * number called process ID (PID)
 * that identifies that process to the system
 * 
 * Each process is assigned a parent process ID (PPID) 
 * that tells which process started it. 
 * The PPID is the PID of the process’s parent.
 *
 * To see PID and PPID in current process you can use 
 * getpid() and getppid()
 *
 * Program ini menunjukkan id dari proses saat ini dan 
 * PARENT id dari proses saat ini
 * dengan menggunakan fungsi getpid() dan getppid()
 */

