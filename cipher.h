/**********************************************************************
 *  cipher.h
 *
 *  Created on: Feb 24, 2013
 *  CS240 lab6, Spring  2013
 *
 *  header file for cipher.h. Declare required functions. 
 **********************************************************************/
#ifndef _CIPHER_H
#define _CIPHER_H


/* Max Buffer size of input/output */
#define MAX_BUFF_SIZE		1025	

/* number of implementations we have for encryption */
#define ENC_IMPLS			3	

/* 
 * The ”input” pointer points to the unsigned char as input. The ”oﬀset” is an integer
 * used as the oﬀset in the cipher function. The converted unsigned char is stored in the
 * place pointed by output.
 */
void cesar(unsigned char* input, char offset, unsigned char* output);

/*
 * The xor function takes as input the ”input” pointer and a key. The unsigned char pointed
 * by the input pointer is converted using the XOR cipher by performing the XOR between the 
 * input unsigned byte and the key before storing the result (unsigned) to output.
 */
 void xor(unsigned char* input, char offset, unsigned char* output);

/*
 * The rotate function takes as ”input” as a pointer to a single unsigned char. 
 * The integer parameter, oﬀset, indicates both the direction and the number of positions to 
 * rotate the given char. A negative oﬀset means rotating to the left in a circle. E.g. an 
 * oﬀset -n means rotate the unsigned byte to the left (in a circle) by n bit positions. 
 * Similarly, a positive oﬀset means rotating to the right in a circle. A zero oﬀset will 
 * have no eﬀect. For the purpose of this assignment, you can assume the oﬀset to be between
 * -7 and 7. (Note: in general, one can deﬁne any oﬀset value, but use modulo 8 to determine
 * the eﬀective oﬀset.) The result must be stored in the output. 
 */
void rotate(unsigned char* input, char offset, unsigned char* output);

/* function pointer to be used to express the encryption functions */
typedef void (*encryptFunc)(unsigned char*, char, unsigned char*);

/*
 * array of function names
 */
extern char* encryptNames[ENC_IMPLS];

/*
 * array of functtion pointers
 */
extern encryptFunc encrypts[ENC_IMPLS];

/* cipher function will be the main interface to do the encryption */
void cipher (encryptFunc func, unsigned char* input, char offset, unsigned char* output);

#endif//_CIPHER_H

