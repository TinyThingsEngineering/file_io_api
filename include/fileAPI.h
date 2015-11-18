#ifndef _fileAPI_h
#define _fileAPI_h

#include "object.h"

struct fileIO{
	Object proto;
	FILE *in;
	FILE *out;
	int sz; 
	char *buffer;
};

typedef struct fileIO fileIO;


int fileIO_init(void *self);
void fileIO_destroy(void *self);
void *fileIO_input(void *self);


#endif