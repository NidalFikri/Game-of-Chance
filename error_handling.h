/*
 * error_handling.h
 *
 *  Created on: Nov 24, 2019
 *      Author: nidal
 */

#ifndef ERROR_HANDLING_H_
#define ERROR_HANDLING_H_

#include<stdio.h>
#include<stdlib.h>

void die(char * msg)
{
	char error_message[100];
	strcpy(error_message,"[!!] Fatal Error ");
	strcat(error_message,msg,83);
	perror(error_message);
	exit(1); //EXIT_FAILURE
}

//Eror check memory allocation.
void *ec_malloc(unsigned int size)
{
	void *ptr;
	ptr = malloc(size);
	if (ptr == NULL) die("memory allocation.");	//Die in peace.
	return ptr;
}

#endif /* ERROR_HANDLING_H_ */
