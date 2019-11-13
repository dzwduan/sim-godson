/*
 * issue.h- issue stage interfaces
 *
 * This file is part of the godson2 simulator tool suite.
 *
 * Copyright (C) 2004 by Fuxin Zhang, ICT.
 *
 * This source file is distributed "as is" in the hope that it will be
 * useful.  It is distributed with no warranty, and no author or
 * distributor accepts any responsibility for the consequences of its
 * use. 
 *
 * Everyone is granted permission to copy, modify and redistribute
 * this source file under the following conditions:
 *
 *    This tool set is distributed for non-commercial use only. 
 *    Please contact the maintainer for restrictions applying to 
 *    commercial use of these tools.
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
 */
#ifndef ISSUE_H
#define ISSUE_H

#if 0

/* TODO: we need to find a way to efficiently performance issue queue
 * operations. 
 *   1. age increasment
 *   2. find issue queue slots for new instructions
 *   3. select instructions to issue
 */
struct issue_queue {
  int valid;
  int age;
  struct inst_descript *rs;
};

extern void issue_stage_init(void);
extern void issue_stage(void);
/*
extern void int_issue_enqueue(struct inst_descript *);
extern void fp_issue_enqueue(struct inst_descript *);
*/
extern void issue_enqueue(struct inst_descript *rs);

extern void readyq_enqueue(struct inst_descript *rs);		/* RS to enqueue */
extern void release_fu(void);

extern int issue_width;
extern int sim_has_bypass;

/* integer issue queue */
extern int int_issue_ifq_size;
extern int int_issue_num;
extern struct issue_queue *int_issue;

/* floating-point issue queue */
extern int fp_issue_ifq_size;
extern int fp_issue_num;
extern struct issue_queue *fp_issue;

extern counter_t sim_issue_insn;

#endif

#endif
