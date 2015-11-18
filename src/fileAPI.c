#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "include/fileAPI.h"


void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

int fileIO_init(void *self)
{
	fileIO *fileio = self;
	fileio->_(input)(fileio);
	printf("file streamed opened!\n");
	return 1;
}

void fileIO_destroy(void *self)
{
	fileIO *fileio = self;
	fclose(fileio->in);
	fclose(fileio->out);
	if(fileio->buffer) free(fileio->buffer);
	
	Object *obj = self;

    if(obj) {
        if(obj->description) free(obj->description);
        free(obj);
    }
	
}

void *fileIO_input(void *self)
{
	fileIO *fileio = self;
	char buffer[100];
	printf("specify input file:");
	scanf("%s", buffer);
	fileio->in = fopen(buffer,"r");
	if(!fileio->in) die("Failed to open input file");
	
	printf("specify output file:");
	scanf("%s", buffer);
	fileio->out = fopen(buffer, "w");
	if(!fileio->out) die("Failed to open output file");
	
	printf("specify buffer size:");
	scanf("%d", &fileio->sz);
	fileio->buffer = malloc(sizeof(char) * fileio->sz);
	if(fileio->buffer==NULL){
		free(fileio->buffer);
		die("failed to allocate memory");
		return NULL;
	}
	printf("here");
	return fileio;
}



