/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS SOURCE IS GOVERNED BY *
 * THE GNU LESSER/LIBRARY PUBLIC LICENSE, WHICH IS INCLUDED WITH    *
 * THIS SOURCE. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.        *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2001             *
 * by the XIPHOPHORUS Company http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: masking curve data for psychoacoustics
 last mod: $Id: masking.h,v 1.12 2001/02/17 10:13:48 xiphmont Exp $

 ********************************************************************/

#ifndef _V_MASKING_H_
#define _V_MASKING_H_

/* Not really an ATH, more a bottom curve to limit LSP dynamic range */
float ATH_Bark_dB[]={  
   15,   15,   15,    15,    11,    10,     8,    7,    7,    7,
    6,    2,    0,     0,    -3,    -5,    -6,   -6, -4.5f, 2.5f,
   10,   15,   15,    15,    15,    15,   15};

/* The below masking curves are straight from the R. Ehmer
   (J. Acoustical Society of America) papers ca 1958-59.  I modified
   them slightly as Ehmer does not correct for the Absolute Threshold
   of Hearing, and the low dB portions of the curves are thus highly
   suspect. */

/* Let's all do the Trek thing and just call them 'Ehmer curves' ;-)
   Note these are octaves, not Bark scale. */

#define EHMER_OFFSET 16
#define EHMER_MAX 56

float tone_125_40dB_SL[EHMER_MAX]={
  20,  20,  20,  20,  20,  20,  20,  20,   20, 20, 20, 20, 20, 20, 20, 20,  
  20,  18,  16,  14,  12,  11,   9,   7,    5,  3,  2,  0, -2, -4, -6, -8,
 -10, -12, -14, -16, -18, -20, -23, -25,  -28,-30,-34,-37,-40,-44,-48,-52,  
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_125_60dB_SL[EHMER_MAX]={
  40,  40,  40,  40,  40,  40,  40,  40,   40, 40, 40, 40, 40, 40, 40, 40,  
  40,  38,  36,  34,  32,  31,  29,  27,   25, 23, 22, 20, 18, 16, 14, 12,
  10,   8,   6,   4,   2,   0,  -3,  -5,   -8,-10,-14,-17,-20,-24,-28,-32,  
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_125_80dB_SL[EHMER_MAX]={
  60,  60,  60,  60,  60,  60,  60,  60,   60, 60, 60, 60, 60, 60, 60, 60,  
  60,  58,  56,  54,  52,  51,  49,  47,   45, 43, 42, 40, 38, 36, 34, 32,
  30,  28,  26,  24,  22,  20,  17,  15,   12, 10,  6,  3,  0, -4, -8,-12,  
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_125_100dB_SL[EHMER_MAX]={
  78,  78,  78,  78,  78,  78,  78,  78,   78, 78, 78, 78, 78, 78, 78, 78,  
  78,  77,  75,  74,  73,  72,  71,  70,   69, 68, 67, 65, 64, 63, 62, 60,
  58,  57,  55,  54,  52,  50,  48,  46,   44, 42, 40, 38, 36, 34, 31, 29,  
  27,  24,  22,  20,  18,  15,  13,  11};

float tone_250_40dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -19, -13,  -7,  -1,   4,   9,  15,  20,
  22,  23,  22,  19,  18,  18,  16,  13,     9,   7,   3,   1,  -1,  -3,  -6,  -8,
 -10, -13, -16, -19, -21, -24, -28, -32,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_250_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -10,   -5,  1,  7, 13, 19, 25, 30, 33,  
  36,  39,  38,  37,  38,  39,  39,  40,   38, 36, 35, 34, 33, 31, 29, 28,
  28,  28,  25,  20,  14,  10,   5,   0,   -5,-10,-15,-20,-25,-30,-35,-40,  
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_250_80dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -10,   10, 17, 24, 30, 37, 41, 48, 49,  
  50,  53,  54,  53,  53,  54,  55,  57,   57, 57, 58, 59, 60, 58, 57, 58,
  59,  58,  57,  54,  52,  50,  49,  47,   46, 47, 46, 44, 43, 42, 41, 40,  
  38,  32,  27,  22,  17,  11,   6,   0};
/* no data, just interpolated from 80 */
float tone_250_100dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -10,   15, 25, 34, 40, 50, 56, 60, 70,  
  70,  73,  74,  73,  73,  74,  75,  77,   77, 77, 78, 79, 80, 78, 77, 78,
  79,  78,  77,  74,  72,  70,  69,  67,   66, 67, 66, 64, 63, 62, 61, 60,  
  58,  52,  47,  42,  37,  31,  26,  20};

float tone_500_40dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -40,   -26, -20, -14,  -8,  -2,   4,  10,  17,
  23,  16,  12,   9,   6,   3,   0,  -3,    -7, -10, -13, -16, -20, -23, -26, -30,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_500_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -18, -12,  -6,   0,   6,  13,  20,  30,
  39,  34,  31,  29,  29,  27,  24,  21,    18,  16,  13,   8,   6,   3,   1,  -1,
  -5,  -2,  -5,  -8, -12, -15, -18, -22,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_500_80dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,  -22,-16,-10,  0, 10, 20, 32, 43,  
  53,  52,  52,  50,  49,  50,  52,  55,   55, 54, 51, 49, 46, 44, 44, 42,
  38,  34,  32,  29,  29,  28,  25,  23,   20, 16, 10,  7,  4,  2, -1, -4,  
  -7, -10, -15, -20, -25, -30, -35, -40};
float tone_500_100dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -10,   -7,  2, 10, 19, 27, 35, 55, 56,  
  62,  61,  60,  58,  57,  57,  59,  63,   65, 66, 62, 60, 57, 57, 58, 58,
  57,  56,  56,  56,  57,  57,  56,  57,   57, 54, 47, 41, 37, 28, 21, 16,  
  10,   3,  -3,  -8, -13, -18, -23, -28};

float tone_1000_40dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -55, -40, -30, -20, -10,  0,   9,  20,
  27,  20,  13,  14,  13,   5,  -1,  -6,   -11, -20, -30,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_1000_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -43,   -33,-23,-13, -3,  7,  17,  25,  37,  
  42,  33,  25,  25,  23,  18,  13,   9,     4, -1, -7,-13,-18, -23, -28, -33,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_1000_80dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -35,   -25,-14, -4,  6, 16, 27, 33, 50,  
  59,  57,  47,  41,  40,  43,  47,  48,    47, 42, 39, 37, 37, 36, 35, 32,
  30,  27,  21,  15,   5,  -2, -10, -18,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_1000_100dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900, -40, -30,   -20,-10,  0, 10, 23, 33, 45, 60,  
  70,  72,  55,  49,  43,  40,  44,  54,    59, 58, 49, 43, 52, 57, 57, 58,
  58,  54,  49,  47,  42,  39,  33,  28,    20, 15,  5,  0, -5,-15,-20,-25,  
-900,-900,-900,-900,-900,-900,-900,-900};

float tone_2000_40dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -40, -30, -21, -12, -3,   5,  12,  20,
  24,  21,  14,   5,  -5, -15, -25, -35,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_2000_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -40, -30, -21, -12,  -2,   8,  19,  31,
  38,  34,  24,  17,  14,  13,  11,   7,     3,  -2,  -6, -10, -14, -20, -26, -32,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_2000_80dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -40, -30, -21, -12,  -2,  13,  28,  40,
  51,  51,  43,  35,  28,  29,  35,  37,    37,  35,  31,  28,  25,  22,  19,  15,
  11,   8,   6,  2,   -6, -14, -22, -30,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_2000_100dB_SL[EHMER_MAX]={  
-900,-900,-900,-900,-900,-900,-900,-900,   -40, -30, -21, -10,   6,  25,  42,  60,
  66,  60,  53,  43,  35,  31,  34,  47,    58,  51,  43,  45,  54,  59,  59,  56,
  54,  51,  40,  29,  20,  11,   2,  -8,   -17, -26, -35,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float tone_4000_40dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -40, -30, -21, -12,   0,   3,  10,  18,
  24,  21,  14,   5,  -5, -15, -25, -35,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float tone_4000_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -40, -30, -21, -12,  -2,   8,  19,  31,
  38,  33,  28,  23,  19,  14,  11,   8,     3,  -2,  -7, -12, -17, -22, -27, -37,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float tone_4000_80dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -60, -50, -40, -29, -12,   5,  19,  37,
  51,  49,  40,  35,  36,  36,  36,  33,    32,  24,  18,   8,  -3, -12, -20, -29,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float tone_4000_100dB_SL[EHMER_MAX]={
 -20, -12,  -8,  -4,   0,   4,   8,  11,    15,  22,  26,  28,  32,  36,  43,  52,
  62,  59,  50,  48,  50,  50,  45,  36,    45,  30,  20,  10,  0,  -10, -19, -28,
 -37,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};


float tone_8000_40dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900,-900,   -40, -30, -21, -12,   0,   3,  10,  18,
  24,  21,  14,   5,   0,  0,   5,   10,    15,  25,  30,  45,  50,  55,  60,  65,
  70,  75,  80,  85,  90, 95, 100,  100,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};
float tone_8000_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -10,   -21, -18, -14, -10,   0,  3,   15,  30,
  43,  40,  36,  35,  36,  38,  41,  43,    45,  47,  50,  55,  60,  65,  70,  75,
  80,  85,  90,  95, 100, 100, 100, 100,  -900,-900,-900,-900,-900,-900,-900,-900,
  -900,-900,-900,-900,-900,-900,-900,-900};
float tone_8000_80dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900,-900,-900, -10,    -1,   2,   6,  10,  13,  19,  25,  35,
  63,  55,  50,  48,  46,  45,  45,  50,    55,  65,  75,  80,  85,  90,  95,  100,
 100, 100, 100, 100,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
 -900,-900,-900,-900,-900,-900,-900,-900};
float tone_8000_100dB_SL[EHMER_MAX]={
 -18, -12,  -7,  -3,   0,   2,   6,   9,    12,  19,  22,  21,  19,  21,  40,  40,
  80,  60,  35,  25,  15,   5,   5,   5,    25,  30,  35,  43,  50,  55,  60,  65,
  70,  75,  80,  85,  90,  95, 100, 100,  -900,-900,-900,-900,-900,-900,-900,-900,
  -900,-900,-900,-900,-900,-900,-900,-900};

#if 0 /* not used for the time being */
float noise_500_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900,-900, -20, -11,  -2,     7,  16,  25,  34,  43,  52,  61,  66,
  69,  68,  58,  50,  44,  38,  32,  28,    25,  24,  20,  18,  17,  12,  10,   8,
   5,   0,  -5,  -8, -12, -15, -18, -22,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float noise_500_80dB_SL[EHMER_MAX]={
-900,-900,-900, -20, -10,  -1,   8,  17,    26,  35,  44,  53,  62,  70,  79,  83,
  85,  85,  81,  77,  74,  71,  68,  63,    61,  59,  56,  55,  54,  52,  48,  47,
  45,  46,  45,  43,  40,  37,  33,  32,    35,  32,  30,  29,  20,  10,   0, -10,
 -20, -30,-900,-900,-900,-900,-900,-900};

float noise_1000_60dB_SL[EHMER_MAX]={
-900,-900,-900,-900, -24, -15,  -6,   3,    12,  21,  28,  34,  40,  48,  57,  60,
  61,  56,  54,  45,  36,  27,  21,  19,    17,  13,  10,   0, -10, -20, -20,-900,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float noise_1000_80dB_SL[EHMER_MAX]={
-900, -26, -17,  -8,   1,  10,  19,  28,    37,  41,  46,  51,  58,  68,  74,  81,
  80,  81,  70,  66,  58,  61,  59,  55,    54,  53,  52,  49,  48,  42,  38,  38,
  39,  34,  30,  27,  20,  10,   0, -10,   -20, -30,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float noise_2000_60dB_SL[EHMER_MAX]={
-900,-900,-900, -34, -25, -16,  -7,   2,    11,  18,  23,  30,  35,  42,  51,  58,
  58,  57,  50,  40,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float noise_2000_80dB_SL[EHMER_MAX]={
-900, -26, -17,  -8,   1,  10,  19,  28,    33,  38,  43,  48,  53,  62,  70,  77,
  77,  75,  70,  67,  68,  66,  62,  61,    60,  59,  52,  47,  39,  35,  34,  35,
  35,  33,  30,  27,  20,  10,   0, -10,   -20, -30,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float noise_4000_60dB_SL[EHMER_MAX]={
-900,-900,-900, -34, -25, -16,  -7,   2,    11,  20,  25,  31,  37,  45,  56,  62,
  64,  61,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

float noise_4000_80dB_SL[EHMER_MAX]={
-900, -26, -17,  -8,   1,  10,  19,  26,    33,  39,  45,  50,  55,  65,  75,  82,
  84,  81,  78,  72,  70,  69,  66,  61,    50,  48,  46,  40,  35,  30,  25,  20,
  15,  10,   5,   0, -10, -20, -30,-900,  -900,-900,-900,-900,-900,-900,-900,-900,
-900,-900,-900,-900,-900,-900,-900,-900};

#endif
#endif


