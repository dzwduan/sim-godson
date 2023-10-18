#ifndef _RISCV_SYSCALLS_
#define _RISCV_SYSCALLS_

// cat /usr/include/asm/unistd_64.h 

#define SS_SYS_read 0
#define SS_SYS_write 1
#define SS_SYS_open 2
#define SS_SYS_close 3
#define SS_SYS_stat 4
#define SS_SYS_fstat 5
#define SS_SYS_lstat 6
#define SS_SYS_poll 7
#define SS_SYS_lseek 8
#define SS_SYS_mmap 9
#define SS_SYS_mprotect 10
#define SS_SYS_munmap 11
#define SS_SYS_brk 12
#define SS_SYS_rt_sigaction 13
#define SS_SYS_rt_sigprocmask 14
#define SS_SYS_rt_sigreturn 15
#define SS_SYS_ioctl 16
#define SS_SYS_pread64 17
#define SS_SYS_pwrite64 18
#define SS_SYS_readv 19
#define SS_SYS_writev 20
#define SS_SYS_access 21
#define SS_SYS_pipe 22
#define SS_SYS_select 23
#define SS_SYS_sched_yield 24
#define SS_SYS_mremap 25
#define SS_SYS_msync 26
#define SS_SYS_mincore 27
#define SS_SYS_madvise 28
#define SS_SYS_shmget 29
#define SS_SYS_shmat 30
#define SS_SYS_shmctl 31
#define SS_SYS_dup 32
#define SS_SYS_dup2 33
#define SS_SYS_pause 34
#define SS_SYS_nanosleep 35
#define SS_SYS_getitimer 36
#define SS_SYS_alarm 37
#define SS_SYS_setitimer 38
#define SS_SYS_getpid 39
#define SS_SYS_sendfile 40
#define SS_SYS_socket 41
#define SS_SYS_connect 42
#define SS_SYS_accept 43
#define SS_SYS_sendto 44
#define SS_SYS_recvfrom 45
#define SS_SYS_sendmsg 46
#define SS_SYS_recvmsg 47
#define SS_SYS_shutdown 48
#define SS_SYS_bind 49
#define SS_SYS_listen 50
#define SS_SYS_getsockname 51
#define SS_SYS_getpeername 52
#define SS_SYS_socketpair 53
#define SS_SYS_setsockopt 54
#define SS_SYS_getsockopt 55
#define SS_SYS_clone 56
#define SS_SYS_fork 57
#define SS_SYS_vfork 58
#define SS_SYS_execve 59
#define SS_SYS_exit 60
#define SS_SYS_wait4 61
#define SS_SYS_kill 62
#define SS_SYS_uname 63
#define SS_SYS_semget 64
#define SS_SYS_semop 65
#define SS_SYS_semctl 66
#define SS_SYS_shmdt 67
#define SS_SYS_msgget 68
#define SS_SYS_msgsnd 69
#define SS_SYS_msgrcv 70
#define SS_SYS_msgctl 71
#define SS_SYS_fcntl 72
#define SS_SYS_flock 73
#define SS_SYS_fsync 74
#define SS_SYS_fdatasync 75
#define SS_SYS_truncate 76
#define SS_SYS_ftruncate 77
#define SS_SYS_getdents 78
#define SS_SYS_getcwd 79
#define SS_SYS_chdir 80
#define SS_SYS_fchdir 81
#define SS_SYS_rename 82
#define SS_SYS_mkdir 83
#define SS_SYS_rmdir 84
#define SS_SYS_creat 85
#define SS_SYS_link 86
#define SS_SYS_unlink 87
#define SS_SYS_symlink 88
#define SS_SYS_readlink 89
#define SS_SYS_chmod 90
#define SS_SYS_fchmod 91
#define SS_SYS_chown 92
#define SS_SYS_fchown 93
#define SS_SYS_lchown 94
#define SS_SYS_umask 95
#define SS_SYS_gettimeofday 96
#define SS_SYS_getrlimit 97
#define SS_SYS_getrusage 98
#define SS_SYS_sysinfo 99
#define SS_SYS_times 100
#define SS_SYS_ptrace 101
#define SS_SYS_getuid 102
#define SS_SYS_syslog 103
#define SS_SYS_getgid 104
#define SS_SYS_setuid 105
#define SS_SYS_setgid 106
#define SS_SYS_geteuid 107
#define SS_SYS_getegid 108
#define SS_SYS_setpgid 109
#define SS_SYS_getppid 110
#define SS_SYS_getpgrp 111
#define SS_SYS_setsid 112
#define SS_SYS_setreuid 113
#define SS_SYS_setregid 114
#define SS_SYS_getgroups 115
#define SS_SYS_setgroups 116
#define SS_SYS_setresuid 117
#define SS_SYS_getresuid 118
#define SS_SYS_setresgid 119
#define SS_SYS_getresgid 120
#define SS_SYS_getpgid 121
#define SS_SYS_setfsuid 122
#define SS_SYS_setfsgid 123
#define SS_SYS_getsid 124
#define SS_SYS_capget 125
#define SS_SYS_capset 126
#define SS_SYS_rt_sigpending 127
#define SS_SYS_rt_sigtimedwait 128
#define SS_SYS_rt_sigqueueinfo 129
#define SS_SYS_rt_sigsuspend 130
#define SS_SYS_sigaltstack 131
#define SS_SYS_utime 132
#define SS_SYS_mknod 133
#define SS_SYS_uselib 134
#define SS_SYS_personality 135
#define SS_SYS_ustat 136
#define SS_SYS_statfs 137
#define SS_SYS_fstatfs 138
#define SS_SYS_sysfs 139
#define SS_SYS_getpriority 140
#define SS_SYS_setpriority 141
#define SS_SYS_sched_setparam 142
#define SS_SYS_sched_getparam 143
#define SS_SYS_sched_setscheduler 144
#define SS_SYS_sched_getscheduler 145
#define SS_SYS_sched_get_priority_max 146
#define SS_SYS_sched_get_priority_min 147
#define SS_SYS_sched_rr_get_interval 148
#define SS_SYS_mlock 149
#define SS_SYS_munlock 150
#define SS_SYS_mlockall 151
#define SS_SYS_munlockall 152
#define SS_SYS_vhangup 153
#define SS_SYS_modify_ldt 154
#define SS_SYS_pivot_root 155
#define SS_SYS__sysctl 156
#define SS_SYS_prctl 157
#define SS_SYS_arch_prctl 158
#define SS_SYS_adjtimex 159
#define SS_SYS_setrlimit 160
#define SS_SYS_chroot 161
#define SS_SYS_sync 162
#define SS_SYS_acct 163
#define SS_SYS_settimeofday 164
#define SS_SYS_mount 165
#define SS_SYS_umount2 166
#define SS_SYS_swapon 167
#define SS_SYS_swapoff 168
#define SS_SYS_reboot 169
#define SS_SYS_sethostname 170
#define SS_SYS_setdomainname 171
#define SS_SYS_iopl 172
#define SS_SYS_ioperm 173
#define SS_SYS_create_module 174
#define SS_SYS_init_module 175
#define SS_SYS_delete_module 176
#define SS_SYS_get_kernel_syms 177
#define SS_SYS_query_module 178
#define SS_SYS_quotactl 179
#define SS_SYS_nfsservctl 180
#define SS_SYS_getpmsg 181
#define SS_SYS_putpmsg 182
#define SS_SYS_afs_syscall 183
#define SS_SYS_tuxcall 184
#define SS_SYS_security 185
#define SS_SYS_gettid 186
#define SS_SYS_readahead 187
#define SS_SYS_setxattr 188
#define SS_SYS_lsetxattr 189
#define SS_SYS_fsetxattr 190
#define SS_SYS_getxattr 191
#define SS_SYS_lgetxattr 192
#define SS_SYS_fgetxattr 193
#define SS_SYS_listxattr 194
#define SS_SYS_llistxattr 195
#define SS_SYS_flistxattr 196
#define SS_SYS_removexattr 197
#define SS_SYS_lremovexattr 198
#define SS_SYS_fremovexattr 199
#define SS_SYS_tkill 200
#define SS_SYS_time 201
#define SS_SYS_futex 202
#define SS_SYS_sched_setaffinity 203
#define SS_SYS_sched_getaffinity 204
#define SS_SYS_set_thread_area 205
#define SS_SYS_io_setup 206
#define SS_SYS_io_destroy 207
#define SS_SYS_io_getevents 208
#define SS_SYS_io_submit 209
#define SS_SYS_io_cancel 210
#define SS_SYS_get_thread_area 211
#define SS_SYS_lookup_dcookie 212
#define SS_SYS_epoll_create 213
#define SS_SYS_epoll_ctl_old 214
#define SS_SYS_epoll_wait_old 215
#define SS_SYS_remap_file_pages 216
#define SS_SYS_getdents64 217
#define SS_SYS_set_tid_address 218
#define SS_SYS_restart_syscall 219
#define SS_SYS_semtimedop 220
#define SS_SYS_fadvise64 221
#define SS_SYS_timer_create 222
#define SS_SYS_timer_settime 223
#define SS_SYS_timer_gettime 224
#define SS_SYS_timer_getoverrun 225
#define SS_SYS_timer_delete 226
#define SS_SYS_clock_settime 227
#define SS_SYS_clock_gettime 228
#define SS_SYS_clock_getres 229
#define SS_SYS_clock_nanosleep 230
#define SS_SYS_exit_group 231
#define SS_SYS_epoll_wait 232
#define SS_SYS_epoll_ctl 233
#define SS_SYS_tgkill 234
#define SS_SYS_utimes 235
#define SS_SYS_vserver 236
#define SS_SYS_mbind 237
#define SS_SYS_set_mempolicy 238
#define SS_SYS_get_mempolicy 239
#define SS_SYS_mq_open 240
#define SS_SYS_mq_unlink 241
#define SS_SYS_mq_timedsend 242
#define SS_SYS_mq_timedreceive 243
#define SS_SYS_mq_notify 244
#define SS_SYS_mq_getsetattr 245
#define SS_SYS_kexec_load 246
#define SS_SYS_waitid 247
#define SS_SYS_add_key 248
#define SS_SYS_request_key 249
#define SS_SYS_keyctl 250
#define SS_SYS_ioprio_set 251
#define SS_SYS_ioprio_get 252
#define SS_SYS_inotify_init 253
#define SS_SYS_inotify_add_watch 254
#define SS_SYS_inotify_rm_watch 255
#define SS_SYS_migrate_pages 256
#define SS_SYS_openat 257
#define SS_SYS_mkdirat 258
#define SS_SYS_mknodat 259
#define SS_SYS_fchownat 260
#define SS_SYS_futimesat 261
#define SS_SYS_newfstatat 262
#define SS_SYS_unlinkat 263
#define SS_SYS_renameat 264
#define SS_SYS_linkat 265
#define SS_SYS_symlinkat 266
#define SS_SYS_readlinkat 267
#define SS_SYS_fchmodat 268
#define SS_SYS_faccessat 269
#define SS_SYS_pselect6 270
#define SS_SYS_ppoll 271
#define SS_SYS_unshare 272
#define SS_SYS_set_robust_list 273
#define SS_SYS_get_robust_list 274
#define SS_SYS_splice 275
#define SS_SYS_tee 276
#define SS_SYS_sync_file_range 277
#define SS_SYS_vmsplice 278
#define SS_SYS_move_pages 279
#define SS_SYS_utimensat 280
#define SS_SYS_epoll_pwait 281
#define SS_SYS_signalfd 282
#define SS_SYS_timerfd_create 283
#define SS_SYS_eventfd 284
#define SS_SYS_fallocate 285
#define SS_SYS_timerfd_settime 286
#define SS_SYS_timerfd_gettime 287
#define SS_SYS_accept4 288
#define SS_SYS_signalfd4 289
#define SS_SYS_eventfd2 290
#define SS_SYS_epoll_create1 291
#define SS_SYS_dup3 292
#define SS_SYS_pipe2 293
#define SS_SYS_inotify_init1 294
#define SS_SYS_preadv 295
#define SS_SYS_pwritev 296
#define SS_SYS_rt_tgsigqueueinfo 297
#define SS_SYS_perf_event_open 298
#define SS_SYS_recvmmsg 299
#define SS_SYS_fanotify_init 300
#define SS_SYS_fanotify_mark 301
#define SS_SYS_prlimit64 302
#define SS_SYS_name_to_handle_at 303
#define SS_SYS_open_by_handle_at 304
#define SS_SYS_clock_adjtime 305
#define SS_SYS_syncfs 306
#define SS_SYS_sendmmsg 307
#define SS_SYS_setns 308
#define SS_SYS_getcpu 309
#define SS_SYS_process_vm_readv 310
#define SS_SYS_process_vm_writev 311
#define SS_SYS_kcmp 312
#define SS_SYS_finit_module 313
#define SS_SYS_sched_setattr 314
#define SS_SYS_sched_getattr 315
#define SS_SYS_renameat2 316
#define SS_SYS_seccomp 317
#define SS_SYS_getrandom 318
#define SS_SYS_memfd_create 319
#define SS_SYS_kexec_file_load 320
#define SS_SYS_bpf 321
#define SS_SYS_execveat 322
#define SS_SYS_userfaultfd 323
#define SS_SYS_membarrier 324
#define SS_SYS_mlock2 325
#define SS_SYS_copy_file_range 326
#define SS_SYS_preadv2 327
#define SS_SYS_pwritev2 328
#define SS_SYS_pkey_mprotect 329
#define SS_SYS_pkey_alloc 330
#define SS_SYS_pkey_free 331
#define SS_SYS_statx 332
#define SS_SYS_io_pgetevents 333
#define SS_SYS_rseq 334
#define SS_SYS_pidfd_send_signal 424
#define SS_SYS_io_uring_setup 425
#define SS_SYS_io_uring_enter 426
#define SS_SYS_io_uring_register 427
#define SS_SYS_open_tree 428
#define SS_SYS_move_mount 429
#define SS_SYS_fsopen 430
#define SS_SYS_fsconfig 431
#define SS_SYS_fsmount 432
#define SS_SYS_fspick 433
#define SS_SYS_pidfd_open 434
#define SS_SYS_clone3 435
#define SS_SYS_close_range 436
#define SS_SYS_openat2 437
#define SS_SYS_pidfd_getfd 438
#define SS_SYS_faccessat2 439
#define SS_SYS_process_madvise 440
#define SS_SYS_epoll_pwait2 441
#define SS_SYS_mount_setattr 442
#define SS_SYS_quotactl_fd 443
#define SS_SYS_landlock_create_ruleset 444
#define SS_SYS_landlock_add_rule 445
#define SS_SYS_landlock_restrict_self 446
#define SS_SYS_memfd_secret 447
#define SS_SYS_process_mrelease 448


// refer include\uapi\asm-generic\ioctls.h
/*
 * These are the most common definitions for tty ioctl numbers.
 * Most of them do not use the recommended _IOC(), but there is
 * probably some source code out there hardcoding the number,
 * so we might as well use them for all new platforms.
 *
 * The architectures that use different values here typically
 * try to be compatible with some Unix variants for the same
 * architecture.
 */

/* 0x54 is just a magic number to make these relatively unique ('T') */

#define SS_IOCTL_TCGETS		0x5401
#define SS_IOCTL_TCSETS		0x5402
#define SS_IOCTL_TCSETSW		0x5403
#define SS_IOCTL_TCSETSF		0x5404
#define SS_IOCTL_TCGETA		0x5405
#define SS_IOCTL_TCSETA		0x5406
#define SS_IOCTL_TCSETAW		0x5407
#define SS_IOCTL_TCSETAF		0x5408
#define SS_IOCTL_TCSBRK		0x5409
#define SS_IOCTL_TCXONC		0x540A
#define SS_IOCTL_TCFLSH		0x540B
#define SS_IOCTL_TIOCEXCL	0x540C
#define SS_IOCTL_TIOCNXCL	0x540D
#define SS_IOCTL_TIOCSCTTY	0x540E
#define SS_IOCTL_TIOCGPGRP	0x540F
#define SS_IOCTL_TIOCSPGRP	0x5410
#define SS_IOCTL_TIOCOUTQ	0x5411
#define SS_IOCTL_TIOCSTI		0x5412
#define SS_IOCTL_TIOCGWINSZ	0x5413
#define SS_IOCTL_TIOCSWINSZ	0x5414
#define SS_IOCTL_TIOCMGET	0x5415
#define SS_IOCTL_TIOCMBIS	0x5416
#define SS_IOCTL_TIOCMBIC	0x5417
#define SS_IOCTL_TIOCMSET	0x5418
#define SS_IOCTL_TIOCGSOFTCAR	0x5419
#define SS_IOCTL_TIOCSSOFTCAR	0x541A
#define SS_IOCTL_FIONREAD	0x541B
#define SS_IOCTL_TIOCINQ		FIONREAD
#define SS_IOCTL_TIOCLINUX	0x541C
#define SS_IOCTL_TIOCCONS	0x541D
#define SS_IOCTL_TIOCGSERIAL	0x541E
#define SS_IOCTL_TIOCSSERIAL	0x541F
#define SS_IOCTL_TIOCPKT		0x5420
#define SS_IOCTL_FIONBIO		0x5421
#define SS_IOCTL_TIOCNOTTY	0x5422
#define SS_IOCTL_TIOCSETD	0x5423
#define SS_IOCTL_TIOCGETD	0x5424
#define SS_IOCTL_TCSBRKP		0x5425	/* Needed for POSIX tcsendbreak() */
#define SS_IOCTL_TIOCSBRK	0x5427  /* BSD compatibility */
#define SS_IOCTL_TIOCCBRK	0x5428  /* BSD compatibility */
#define SS_IOCTL_TIOCGSID	0x5429  /* Return the session ID of FD */
#define SS_IOCTL_TCGETS2		_IOR('T', 0x2A, struct termios2)
#define SS_IOCTL_TCSETS2		_IOW('T', 0x2B, struct termios2)
#define SS_IOCTL_TCSETSW2	_IOW('T', 0x2C, struct termios2)
#define SS_IOCTL_TCSETSF2	_IOW('T', 0x2D, struct termios2)
#define SS_IOCTL_TIOCGRS485	0x542E
#ifndef SS_IOCTL_TIOCSRS485
#define SS_IOCTL_TIOCSRS485	0x542F

#define SS_IOCTL_TIOCGPTN	_IOR('T', 0x30, unsigned int) /* Get Pty Number (of pty-mux device) */
#define SS_IOCTL_TIOCSPTLCK	_IOW('T', 0x31, int)  /* Lock/unlock Pty */
#define SS_IOCTL_TIOCGDEV	_IOR('T', 0x32, unsigned int) /* Get primary device node of /dev/console */
#define SS_IOCTL_TCGETX		0x5432 /* SYS5 TCGETX compatibility */
#define SS_IOCTL_TCSETX		0x5433
#define SS_IOCTL_TCSETXF		0x5434
#define SS_IOCTL_TCSETXW		0x5435
#define SS_IOCTL_TIOCSIG		_IOW('T', 0x36, int)  /* pty: generate signal */
#define SS_IOCTL_TIOCVHANGUP	0x5437
#define SS_IOCTL_TIOCGPKT	_IOR('T', 0x38, int) /* Get packet mode state */
#define SS_IOCTL_TIOCGPTLCK	_IOR('T', 0x39, int) /* Get Pty lock state */
#define SS_IOCTL_TIOCGEXCL	_IOR('T', 0x40, int) /* Get exclusive mode state */
#define SS_IOCTL_TIOCGPTPEER	_IO('T', 0x41) /* Safely open the slave */
#define SS_IOCTL_TIOCGISO7816	_IOR('T', 0x42, struct serial_iso7816)
#define SS_IOCTL_TIOCSISO7816	_IOWR('T', 0x43, struct serial_iso7816)

#define SS_IOCTL_FIONCLEX	0x5450
#define SS_IOCTL_FIOCLEX		0x5451
#define SS_IOCTL_FIOASYNC	0x5452
#define SS_IOCTL_TIOCSERCONFIG	0x5453
#define SS_IOCTL_TIOCSERGWILD	0x5454
#define SS_IOCTL_TIOCSERSWILD	0x5455
#define SS_IOCTL_TIOCGLCKTRMIOS	0x5456
#define SS_IOCTL_TIOCSLCKTRMIOS	0x5457
#define SS_IOCTL_TIOCSERGSTRUCT	0x5458 /* For debugging only */
#define SS_IOCTL_TIOCSERGETLSR   0x5459 /* Get line status register */
#define SS_IOCTL_TIOCSERGETMULTI 0x545A /* Get multiport config  */
#define SS_IOCTL_TIOCSERSETMULTI 0x545B /* Set multiport config */

#define SS_IOCTL_TIOCMIWAIT	0x545C	/* wait for a change on serial input line(s) */
#define SS_IOCTL_TIOCGICOUNT	0x545D	/* read serial port inline interrupt counts */

/*
 * Some arches already define FIOQSIZE due to a historical
 * conflict with a Hayes modem-specific ioctl value.
 */
#ifndef FIOQSIZE
# define FIOQSIZE	0x5460
#endif

/* Used for packet mode */
#define TIOCPKT_DATA		 0
#define TIOCPKT_FLUSHREAD	 1
#define TIOCPKT_FLUSHWRITE	 2
#define TIOCPKT_STOP		 4
#define TIOCPKT_START		 8
#define TIOCPKT_NOSTOP		16
#define TIOCPKT_DOSTOP		32
#define TIOCPKT_IOCTL		64

#define TIOCSER_TEMT	0x01	/* Transmitter physically empty */



/* internal system call buffer size, used primarily for file name arguments,
   argument larger than this will be truncated */
#define MAXBUFSIZE 		1024

/* total bytes to copy from a valid pointer argument for ioctl() calls,
   syscall.c does not decode ioctl() calls to determine the size of the
   arguments that reside in memory, instead, the ioctl() proxy simply copies
   NUM_IOCTL_BYTES bytes from the pointer argument to host memory */
#define NUM_IOCTL_BYTES		128


#ifndef __x86_64__
/* copy from /usr/include/bits/stat.h, it is not defined if _USE_LARGEFILE64
 * is not defined */
struct stat64 {
	unsigned long long st_dev;	/* Device.  */
	unsigned long long st_ino;	/* File serial number.  */
	unsigned int	st_mode;	/* File mode.  */
	unsigned int	st_nlink;	/* Link count.  */
	unsigned int	st_uid;		/* User ID of the file's owner.  */
	unsigned int	st_gid;		/* Group ID of the file's group. */
	unsigned long long st_rdev;	/* Device number, if device.  */
	unsigned long long __pad1;
	long long	st_size;	/* Size of file, in bytes.  */
	int		st_blksize;	/* Optimal block size for I/O.  */
	int		__pad2;
	long long	st_blocks;	/* Number 512-byte blocks allocated. */
	int		st_atime;	/* Time of last access.  */
	unsigned int	st_atime_nsec;
	int		st_mtime;	/* Time of last modification.  */
	unsigned int	st_mtime_nsec;
	int		st_ctime;	/* Time of last status change.  */
	unsigned int	st_ctime_nsec;
	unsigned int	__unused4;
	unsigned int	__unused5;
};
#endif


/* Note stat64 has the same shape as stat for x86-64.  */
struct stat64 {
	unsigned long long st_dev;	/* Device.  */
	unsigned long long st_ino;	/* File serial number.  */
	unsigned int	st_mode;	/* File mode.  */
	unsigned int	st_nlink;	/* Link count.  */
	unsigned int	st_uid;		/* User ID of the file's owner.  */
	unsigned int	st_gid;		/* Group ID of the file's group. */
	unsigned long long st_rdev;	/* Device number, if device.  */
	unsigned long long __pad1;
	long long	st_size;	/* Size of file, in bytes.  */
	int		st_blksize;	/* Optimal block size for I/O.  */
	int		__pad2;
	long long	st_blocks;	/* Number 512-byte blocks allocated. */
	int		st_atime;	/* Time of last access.  */
	unsigned int	st_atime_nsec;
	int		st_mtime;	/* Time of last modification.  */
	unsigned int	st_mtime_nsec;
	int		st_ctime;	/* Time of last status change.  */
	unsigned int	st_ctime_nsec;
	unsigned int	__unused4;
	unsigned int	__unused5;
};


/* used in SS_SYS_sched_setparam */
struct sched_param {
	int sched_priority;
};


/* open(2) flags for SimpleScalar target, syscall.c automagically maps *
 * between these codes to/from host open(2) flags                 *
 *                                                            *
 * these flags are defined on riscv platform                       */
 /* fcntl / open */
#define SS_O_RDONLY            0
#define SS_O_WRONLY            1
#define SS_O_RDWR              2
#define SS_O_CREAT          0x40
#define SS_O_EXCL           0x80
#define SS_O_NOCTTY        0x100
#define SS_O_TRUNC         0x200
#define SS_O_APPEND        0x400
#define SS_O_NONBLOCK      0x800
#define SS_O_DIRECTORY   0x10000

// refer tools\include\uapi\asm-generic\fcntl.h
#define SS_O_ACCMODE	00000003
#define SS_O_RDONLY	00000000
#define SS_O_WRONLY	00000001
#define SS_O_RDWR		00000002
#ifndef SS_O_CREAT
#define SS_O_CREAT		00000100	/* not fcntl */
#endif
#ifndef SS_O_EXCL
#define SS_O_EXCL		00000200	/* not fcntl */
#endif
#ifndef SS_O_NOCTTY
#define SS_O_NOCTTY	00000400	/* not fcntl */
#endif
#ifndef SS_O_TRUNC
#define SS_O_TRUNC		00001000	/* not fcntl */
#endif
#ifndef SS_O_APPEND
#define SS_O_APPEND	00002000
#endif
#ifndef SS_O_NONBLOCK
#define SS_O_NONBLOCK	00004000
#endif
#ifndef SS_O_DSYNC
#define SS_O_DSYNC		00010000	/* used to be O_SYNC, see below */
#endif
#ifndef SS_FASYNC
#define SS_FASYNC		00020000	/* fcntl, for BSD compatibility */
#endif
#ifndef SS_O_DIRECT
#define SS_O_DIRECT	00040000	/* direct disk access hint */
#endif
#ifndef SS_O_LARGEFILE
#define SS_O_LARGEFILE	00100000
#endif
#ifndef SS_O_DIRECTORY
#define SS_O_DIRECTORY	00200000	/* must be a directory */
#endif
#ifndef SS_O_NOFOLLOW
#define SS_O_NOFOLLOW	00400000	/* don't follow links */
#endif
#ifndef SS_O_NOATIME
#define SS_O_NOATIME	01000000
#endif
#ifndef SS_O_CLOEXEC
#define SS_O_CLOEXEC	02000000	/* set close_on_exec */
#endif


/* open(2) flags translation table for SimpleScalar target */
struct {
  int ss_flag;
  int local_flag;
} ss_flag_table[] = {
  /* target flag */	/* host flag */
  { SS_O_RDONLY,	O_RDONLY },
  { SS_O_WRONLY,	O_WRONLY },
  { SS_O_RDWR,		O_RDWR },
  { SS_O_ACCMODE, O_ACCMODE}, 
  { SS_O_APPEND,	O_APPEND },
#ifdef O_SYNC
  { SS_O_SYNC,		O_SYNC },
#endif
  { SS_O_NONBLOCK,	O_NONBLOCK },
  { SS_O_CREAT,		O_CREAT },
  { SS_O_TRUNC,		O_TRUNC },
  { SS_O_EXCL,		O_EXCL },
  { SS_O_NOCTTY,	O_NOCTTY },
#ifdef FASYNC
  { SS_FASYNC,      FASYNC },
#endif
#ifdef O_LARGEFILE
  { SS_O_LARGEFILE, O_LARGEFILE },
#endif
#ifdef O_DIRECT
  { SS_O_DIRECT,   O_DIRECT },
#endif
#ifdef O_DIRECTORY
  { SS_O_DIRECTORY, O_DIRECTORY },
#endif
#ifdef O_NOFOLLOW
  { SS_O_NOFOLLOW, O_NOFOLLOW },
#endif
};
#define SS_NFLAGS	(sizeof(ss_flag_table)/sizeof(ss_flag_table[0]))

#endif