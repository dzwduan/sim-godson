/*
 * main.c - main line routines
 *
 * This file is part of the godson2 simulator tool suite.
 *
 * Copyright (C) 1994, 1995, 1996, 1997, 1998 by Todd M. Austin
 *
 * Copyright (C) 1999 by Raj Desikan
 *
 * Copyright (C) 2004 by Fuxin Zhang, ICT.
 *
 * This source file is distributed "as is" in the hope that it will be
 * useful.  The tool set comes with no warranty, and no author or
 * distributor accepts any responsibility for the consequences of its
 * use. 
 *
 * Everyone is granted permission to copy, modify and redistribute
 * this tool set under the following conditions:
 *
 *    This source code is distributed for non-commercial use only. 
 *    Please contact the maintainer for restrictions applying to 
 *    commercial use.
 *
 *    Permission is granted to anyone to make or distribute copies
 *    of this source code, either as received or modified, in any
 *    medium, provided that all copyright notices, permission and
 *    nonwarranty notices are preserved, and that the distributor
 *    grants the recipient permission for further redistribution as
 *    permitted by this document.
 *
 *    Permission is granted to distribute this file in compiled
 *    or executable form under the same conditions that apply for
 *    source code, provided that either:
 *
 *    A. it is accompanied by the corresponding machine-readable
 *       source code,
 *    B. it is accompanied by a written offer, with no time limit,
 *       to give anyone a machine-readable copy of the corresponding
 *       source code in return for reimbursement of the cost of
 *       distribution.  This written offer must permit verbatim
 *       duplication by anyone, or
 *    C. it is distributed by someone who received only the
 *       executable form, and is accompanied by a copy of the
 *       written offer of source code that they received concurrently.
 *
 * In other words, you are welcome to use, share and improve this
 * source file.  You are forbidden to forbid anyone else to use, share
 * and improve what you give them.
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/types.h>
#ifndef _MSC_VER
#include <unistd.h>
#include <sys/time.h>
#endif
#ifdef BFD_LOADER
#include <bfd.h>
#endif /* BFD_LOADER */

#include "host.h"
#include "misc.h"
#include "mips.h"
#include "endian.h"
#include "version.h"
#include "options.h"
#include "stats.h"
#include "memory.h"
#include "loader.h"
#include "sim.h"
#include "cache.h"
#include "writeback.h"
#include "bpred.h"
//#include "fetch.h"
//#include "decode.h"
//#include "map.h"
//#include "issue.h"

#include "istat.h"


/* redirected program/simulator output file names */
static char *sim_simout = NULL;
static char *sim_progout = NULL;
FILE *sim_progfd = NULL;

/* EIO interfaces */
char *sim_eio_fname = NULL;
char *sim_chkpt_fname = NULL;
FILE *sim_eio_fd = NULL;

/* stats signal handler */
static void
signal_sim_stats(int sigtype)
{
  sim_dump_stats = TRUE;
}

/* exit signal handler */
static void
signal_exit_now(int sigtype)
{
  sim_exit_now = TRUE;
}

#if 0 /* not portable... :-( */
/* total simulator (data) memory usage */
unsigned int sim_mem_usage = 0;
#endif

/* execution start/end times */
time_t sim_start_time;
time_t sim_end_time;
int sim_elapsed_time;

/* byte/word swapping required to execute target executable on this host */
int sim_swap_bytes;
int sim_swap_words;

/* exit when this becomes non-zero */
int sim_exit_now = FALSE;

/* longjmp here when simulation is completed */
jmp_buf sim_exit_buf;

/* set to non-zero when simulator should dump statistics */
int sim_dump_stats = FALSE;

/* options database */
struct opt_odb_t *sim_odb;

/* stats database */
struct stat_sdb_t *sim_sdb;


/* track first argument orphan, this is the program to execute */
static int exec_index = -1;

/* dump help information */
static int help_me;

/* random number generator seed */
static int rand_seed;

/* initialize and quit immediately */
static int init_quit;

#ifndef _MSC_VER
/* simulator scheduling priority */
static int nice_priority;
#endif

/* default simulator scheduling priority */
#define NICE_DEFAULT_VALUE		0

static int
orphan_fn(int i, int argc, char **argv)
{
  exec_index = i;
  return /* done */FALSE;
}

static void
banner(FILE *fd, int argc, char **argv)
{

  fprintf(fd,
	  "sim-godson version %d.%d of %s.\n"
	  "Copyright (c) 2004 - 2005 by Fuxin Zhang.  All Rights Reserved.\n"
	  "\n", VER_MAJOR, VER_MINOR, VER_UPDATE);
}

static void
usage(FILE *fd, int argc, char **argv)
{
  fprintf(fd, "Usage: %s {-options} executable {arguments}\n", argv[0]);
  opt_print_help(sim_odb, fd);
}

static int running = FALSE;

/* print all simulator stats */
void
sim_print_stats(FILE *fd)		/* output stream */
{
#if 0 /* not portable... :-( */
  extern char etext, *sbrk(int);
#endif

  if (!running)
    return;

  /* Calculate standard deviation */
  //doStatistics();

  /* get stats time */
  sim_end_time = time((time_t *)NULL);
  sim_elapsed_time = MAX(sim_end_time - sim_start_time, 1);

  compute_formula();
  
#if 0 /* not portable... :-( */
  /* compute simulator memory usage */
  sim_mem_usage = (sbrk(0) - &etext) / 1024;
#endif
  int i;
  /* print simulation stats */
  fprintf(fd, "\nsim: ** simulation statistics **\n");
  //stat_print_stats(sim_sdb, fd);
  for (i=0;i<total_cpus;i++) {
    fprintf(fd, "\n** cpu%d simulation statistics **\n\n",i);
	stat_print_stats(cpus[i].sdb, fd);
    fprintf(fd, "\n********************************************************************\n");
  }
  sim_aux_stats(fd);
  fprintf(fd, "\n");
}

char sim_istat_filename[80];

/* print stats, uninitialize simulator components, and exit w/ exitcode */
void
exit_now(int exit_code)
{
  /* print simulation stats */
  sim_print_stats(stderr);

#ifdef ISTAT
  save_istat(sim_istat_filename);
#endif

  /* un-initialize the simulator */
  sim_uninit();

  /* all done! */
  exit(exit_code);
}

int
main(int argc, char **argv, char **envp)
{
  char *s;
  int i, exit_code;

#ifndef _MSC_VER
  /* catch SIGUSR1 and dump intermediate stats */
  signal(SIGUSR1, signal_sim_stats);

  /* catch SIGUSR2 and dump final stats and exit */
  signal(SIGUSR2, signal_exit_now);
#endif /* _MSC_VER */

  /* register an error handler */
  fatal_hook(sim_print_stats);

  /* set up a non-local exit point */
  if ((exit_code = setjmp(sim_exit_buf)) != 0)
    {
      /* special handling as longjmp cannot pass 0 */
      exit_now(exit_code-1);
    }

  /* register global options */
  sim_odb = opt_new(orphan_fn);
  opt_reg_flag(sim_odb, "-h", "print help message",
	       &help_me, /* default */FALSE, /* !print */FALSE, NULL);
  opt_reg_flag(sim_odb, "-v", "verbose operation",
	       &verbose, /* default */FALSE, /* !print */FALSE, NULL);
#ifdef DEBUG
  opt_reg_flag(sim_odb, "-d", "enable debug message",
	       &debugging, /* default */FALSE, /* !print */FALSE, NULL);
#endif /* DEBUG */
  //opt_reg_flag(sim_odb, "-i", "start in Dlite debugger",
	       //&dlite_active, /* default */FALSE, /* !print */FALSE, NULL);
  opt_reg_int(sim_odb, "-seed",
	      "random number generator seed (0 for timer seed)",
	      &rand_seed, /* default */1, /* print */TRUE, NULL);
  opt_reg_flag(sim_odb, "-q", "initialize and terminate immediately",
	       &init_quit, /* default */FALSE, /* !print */FALSE, NULL);
  opt_reg_string(sim_odb, "-chkpt", "restore EIO trace execution from <fname>",
		 &sim_chkpt_fname, /* default */NULL, /* !print */FALSE, NULL);

  /* stdio redirection options */
  opt_reg_string(sim_odb, "-redir:sim",
		 "redirect simulator output to file (non-interactive only)",
		 &sim_simout,
		 /* default */NULL, /* !print */FALSE, NULL);
  opt_reg_string(sim_odb, "-redir:prog",
		 "redirect simulated program output to file",
		 &sim_progout, /* default */NULL, /* !print */FALSE, NULL);

#ifndef _MSC_VER
  /* scheduling priority option */
  opt_reg_int(sim_odb, "-nice",
	      "simulator scheduling priority", &nice_priority,
	      /* default */NICE_DEFAULT_VALUE, /* print */TRUE, NULL);
#endif

  /* FIXME: add stats intervals and max insts... */

  /* register all simulator-specific options */
  sim_reg_options(sim_odb);

  /* parse simulator options */
  exec_index = -1;
  opt_process_options(sim_odb, argc, argv);

  /* redirect I/O? */
  if (sim_simout != NULL)
    {
      /* send simulator non-interactive output (STDERR) to file SIM_SIMOUT */
      fflush(stderr);
      if (!freopen(sim_simout, "w", stderr))
	fatal("unable to redirect simulator output to file `%s'", sim_simout);
    }

  if (sim_progout != NULL)
    {
      /* redirect simulated program output to file SIM_PROGOUT */
      sim_progfd = fopen(sim_progout, "w");
      if (!sim_progfd)
	fatal("unable to redirect program output to file `%s'", sim_progout);
    }

  /* need at least two argv values to run */
  if (argc < 2)
    {
      banner(stderr, argc, argv);
      usage(stderr, argc, argv);
      exit(1);
    }

  /* opening banner */
  banner(stderr, argc, argv);

  if (help_me)
    {
      /* print help message and exit */
      usage(stderr, argc, argv);
      exit(1);
    }

  /* seed the random number generator */
  if (rand_seed == 0)
    {
      /* seed with the timer value, true random */
      mysrand(time((time_t *)NULL));
    }
  else
    {
      /* seed with default or user-specified random number generator seed */
      mysrand(rand_seed);
    }

  /* exec_index is set in orphan_fn() */
  if (exec_index == -1)
    {
      /* executable was not found */
      fprintf(stderr, "error: no executable specified\n");
      usage(stderr, argc, argv);
      exit(1);
    }
  /* else, exec_index points to simulated program arguments */

  /* check simulator-specific options */
  sim_check_options(sim_odb, argc, argv);

#if 0
#ifndef _MSC_VER
  /* set simulator scheduling priority */
  if (nice(0) != nice_priority)
    {
      if (nice(nice_priority - nice(0)) < 0)
	fatal("could not renice simulator process");
    }
#endif
#endif

  /* default architected value... */
  //sim_pop_insn = 0;

#ifdef BFD_LOADER
  /* initialize the bfd library */
  bfd_init();
#endif /* BFD_LOADER */

  /* initialize the instruction decoder */
  md_init_decoder();

  /* initialize all simulation modules */
  sim_init();

  /* initialize architected state */
  if(argv[exec_index][0] != ':')
    sim_load_prog(argv[exec_index], argc-exec_index, argv+exec_index, envp);
  else if(!strcmp(argv[exec_index],":s") || !strcmp(argv[exec_index],":S"))
    sim_load_splash_prog(argv[exec_index+1], argc-exec_index-1, argv+exec_index+1, envp);
  else
  {
    check_multiprog_args(argv[exec_index],argc-exec_index-1, argv+exec_index+1, envp);
	sim_load_multiprog();
  }

#ifdef ISTAT
  {
    char *p;
    p = strrchr(argv[exec_index],'/');
    if (p) {
      /* contain path */
      p++;
      sprintf(sim_istat_filename,"%s.istat",p);
    }else {
      sprintf(sim_istat_filename,"%s.istat",argv[exec_index]);
    }
    myfprintf(stderr,"To use istat file name %s\n",sim_istat_filename);
  }
#endif


  /* register all simulator stats */
  sim_sdb = stat_new();
  sim_reg_stats(sim_sdb);
#if 0 /* not portable... :-( */
  stat_reg_uint(sim_sdb, "sim_mem_usage",
		"total simulator (data) memory usage",
		&sim_mem_usage, sim_mem_usage, "%11dk");
#endif

  /* record start of execution time, used in rate stats */
  sim_start_time = time((time_t *)NULL);

  /* emit the command line for later reuse */
  fprintf(stderr, "sim: command line: ");
  for (i=0; i < argc; i++)
    fprintf(stderr, "%s ", argv[i]);
  fprintf(stderr, "\n");

  /* output simulation conditions */
  s = ctime(&sim_start_time);
  if (s[strlen(s)-1] == '\n')
    s[strlen(s)-1] = '\0';
  fprintf(stderr, "\nsim: simulation started @ %s, options follow:\n", s);
  opt_print_options(sim_odb, stderr, /* short */TRUE, /* notes */TRUE);
  sim_aux_config(stderr);
  fprintf(stderr, "\n");

  /* omit option dump time from rate stats */
  sim_start_time = time((time_t *)NULL);

  if (init_quit)
    exit_now(0);

  running = TRUE;
  sim_main();

  /* simulation finished early */
  exit_now(0);

  return 0;
}
