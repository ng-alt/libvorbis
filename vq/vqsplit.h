/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE Ogg Vorbis SOFTWARE CODEC SOURCE CODE.  *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS SOURCE IS GOVERNED BY *
 * THE GNU PUBLIC LICENSE 2, WHICH IS INCLUDED WITH THIS SOURCE.    *
 * PLEASE READ THESE TERMS DISTRIBUTING.                            *
 *                                                                  *
 * THE OggSQUISH SOURCE CODE IS (C) COPYRIGHT 1994-2000             *
 * by Monty <monty@xiph.org> and The XIPHOPHORUS Company            *
 * http://www.xiph.org/                                             *
 *                                                                  *
 ********************************************************************

 function: build a VQ codebook decision tree 
 last mod: $Id: vqsplit.h,v 1.3 2000/10/12 03:13:02 xiphmont Exp $

 ********************************************************************/

#ifndef _VQSPL_H_
#define _VQSPL_H_

#include "vorbis/codebook.h"

extern void vqsp_book(vqgen *v,codebook *b,long *quantlist);
extern int vqenc_entry(codebook *b,float *val);
extern int lp_split(float *pointlist,long totalpoints,
		    codebook *b,
		    long *entryindex,long entries, 
		    long *pointindex,long points,
		    long *membership,long *reventry,
		    long depth, long *pointsofar);

#endif




