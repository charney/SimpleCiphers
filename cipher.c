/**********************************************************************
 *  cipher.c
 *
 *  Created on: Feb 24, 2013
 *  Updated: August 17, 2013
 *  CS240 lab6: Spring,  2013
 *
 *  Author: Chad Harney
 **********************************************************************/

#include <stdio.h>
#include <string.h>
#include "cipher.h"

/* the number of bytes read from the stdin */
extern int bytesRead;

char* encryptNames[ENC_IMPLS] = {"cesar","xor","rotate"};

encryptFunc encrypts[ENC_IMPLS] = {&cesar,&xor,&rotate};


/* cesar function
 * -----------------
 *
 * cesar function is given the input and the offset. The function returns the result in the
 * output string.
 */
void cesar(unsigned char* input, char offset, unsigned char* output) {
	int i = 0;
	for(i = 0; i < bytesRead; i++){
		output[i]=(input[i] + offset) % 256;
	}
	bytesRead = 0;
}


/* xor function
 * --------------
 * The xor function takes as input the input pointer and a key. The unsigned char pointed
 * by the input pointer is converted using the XOR cipher by performing the XOR between the 
 * input unsigned byte and the key before storing the result (unsigned) to output.
 */
void xor(unsigned char* input, char offset, unsigned char* output) {
	unsigned char key = (unsigned char)offset;
	int i = 0;
	// input = "HELLO GOODBYE GOPHERS";
	for(i = 0; i < bytesRead; i++){
		output[i]=input[i] ^ key;
	}
	bytesRead = 0;
}

/* rotate function
 * ---------------
 * The rotate function takes as input as a pointer to a single unsigned char.
 * The integer parameter, offset, indicates both the direction and the number of positions to
 * rotate the given char. A negative offset means rotating to the left in a circle. E.g. an
 * offset -n means rotate the unsigned byte to the left (in a circle) by n bit positions.
 * Similarly, a positive offset means rotating to the right in a circle. A zero offset will
 * have no effect. For the purpose of this assignment, you can assume the offset to be between
 * -7 and 7. (Note: in general, one can dene any offset value, but use modulo 8 to determine
 * the effective offset.) The result must be stored in the output.
 */
void rotate(unsigned char* input, char offset, unsigned char* output) {
	int i = 0;
	unsigned char a,b;
	if(offset > 0){
		char offset2 = 8 - offset;

	for(i = 0; i < bytesRead; i++){
			a = input[i] >> offset;
			b = input[i] << offset2;
			output[i] = a | b;
		}
	}

	if(offset < 0){
		offset = offset * -1;
		char offset2 = 8 - offset;

		for(i = 0; i < bytesRead; i++){
			a = input[i] << offset;
			b = input[i] >> offset2;
			output[i] = a | b;
		}
	}

	if(offset == 0){
		char offset2 = 8 - offset;

		for(i = 0; i < bytesRead; i++){
			output[i] = input[i];
		}
	}

	bytesRead = 0;
}


/* cipher function will be the main interface to do the encryption */
void cipher (encryptFunc func, unsigned char* input, char offset, unsigned char* output){
	(*func)(input,offset,output);
}
