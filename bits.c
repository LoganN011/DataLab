/* 
 * CS:APP Data Lab 
 * 
 * < Logan Nunno / lnunno1 >
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 *   Explanation: By using the Hamming weight method we are able to count 
 * the number of bits in pairs and commapact the oginal number down to 
 * get the solution. First we mask the value with 5 so every other bit is 
 * saved. We then do the same the with the remaining bits and add them to
 * together. We then do the same process over again just with the new value 
 * and using 3 so the bits are counted in pairs. We then sum the pairs. We keep
 * doing this for 5 total times until we get the final number and that is 
 * number of 1's in the. Had to update the code to not use constants higher 
 * than 0xFF so now there are only 3 masks and we just the last two totals 
 * to get the total number of bits. 
 */
int bitCount(int x)
{
  int mask1 = 0x55+(0x55<<8)+(0x55<<16)+(0x55<<24);
  int mask2 = 0x33+(0x33<<8)+(0x33<<16)+(0x33<<24); 
  int mask3 = 0x0F+(0x0F<<8)+(0x0F<<16)+(0x0F<<24);
    
  x = (x & mask1) + ((x >> 1) & mask1); 
  x = (x & mask2) + ((x >> 2) & mask2); 
  x = (x & mask3) + ((x >> 4) & mask3); 
  x +=x >> 8;
  x +=x >> 16;

  return x&0x3f;
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 *   Explanation: Using demorgans law we know we can rewrite nor using & and ~
 * This is done by distributing the not into the equation so it can be 
 * rewritten as (~x&~y) and that is logically the same as nor   
 */
int bitNor(int x, int y) {
  return ~x&~y;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 *  Explanation: Saved both the nth and mth byte by removing all other bytes 
 * with a mask of FF. Shifting the x over by n*8(or <<3) we can save both 
 * m and n. Then we remove the m and nth byte from the x so it has a hole of 
 * 0x00 at those spots so both can be placed in there. we the finally place 
 * m in the nth byte and n in the mth byte by shifting them over to be in 
 * line with where they should be in x.
 */
int byteSwap(int x, int n, int m) {
  int nB = (x >> (n<<3))& 0xFF; 
  int mB = (x >> (m<<3))& 0xFF;
  x = (x & ~(0xFF<<(n<<3))) & (x & ~(0xFF<<(m<<3)));
  x = x | (mB<<(n<<3));
  x = x | (nB<<(m<<3));
  return x ;
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 *   Explanation: To multiply by 3/4 we first multiply by 3 by adding x + 2x 
 * to get a number that is 3x as big. Then we calculate a bias of that number
 * to know if the number will need to be rounded. We added the bias to the 
 * number and then divided by 4 so that number produces the correct output.   
 */
int ezThreeFourths(int x) {
  
  int bias=0;
  int mult3= x+( x<<1);
  bias = (mult3>>31) & 3;
  return (mult3+bias)>>2;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 *   Explanation: First we find the both the exp and the mantissa of the value 
 * we then use them to see if the number is NaN. To be not a number the exp is 
 * all 1's and the mantissa is non zero. If the number passed in is anthing 
 * but not a number we compute the abs of the number by masking the number with
 * all 1's but the sing bit a 0 so it will be removed and the number will
 * always be positive.
*/
unsigned float_abs(unsigned uf) {
  unsigned exp =0;
  unsigned m=0;
  exp = uf & 0x7F800000;
  m = uf & 0x007FFFFF;
  if(exp == 0x7F800000 && m !=0)
  {
    return uf;
  }

  return uf&0x7FFFFFFF;
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 *   Explanation: First we find the both the exp and the mantissa of the value 
 * we then use them to see if the number is NaN. To be not a number the exp is 
 * all 1's and the mantissa is non zero. If the number passed in is anthing 
 * but not a number we compute the negative value of f by xor the sign bit so
 * if it is on it will not be off and if it is off it will now be on. 
 */
unsigned float_neg(unsigned uf) {
  unsigned exp =0;
  unsigned m=0;
  exp = uf & 0x7F800000;
  m = uf & 0x007FFFFF;
    
  if(exp == 0x7F800000 && m !=0)
  {
    return uf;
  }

  return uf^0x80000000;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 *   Explanation: To check to see if the provided number is a Ascii Digit
 * we have to check if the provided number is with 0x30 to 0x39. we do this by
 * check to see if the number is greater than or equal to 0x30 by subtracting
 * 0x30 from x and checking if it is postitive. We then check if x is less 
 * than or equal to 0x39 by subtracting it x from that number and seeing if 
 * it is positive. To subtract we convert the number into twos compliment that 
 * is be sutracted and add it to the other number.
 */
int isAsciiDigit(int x) {
  return !((x+(~0x30+1)) >>31) & !((0x39+(~x+1))>>31);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 *   Explanation: To check if a number is positive when check the sign bit and 
 * if that number is not 1 when then it is postive. We also check to see if x
 * is zero becuase if x is 0 then it should return 0
 */
int isPositive(int x) {
  return !(x>>31) & !!x;
}
