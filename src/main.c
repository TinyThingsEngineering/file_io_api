#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "include/fileAPI.h"
#include "include/object.h"

int process_input(fileIO *stream);

Object fileIOProto = {
    .init = fileIO_init,
	.input = fileIO_input,
    .destroy = fileIO_destroy
};

int main(int argc, char *argv[])
{
    // simple way to setup the randomness
    fileIO *filestream = NEW(fileIO,"hello");
	while(process_input(filestream)){
		
	}
	filestream->_(destroy)(filestream);
   return 0;
}


int process_input(fileIO *stream)
{
	size_t read = 0; 
    read = fread(stream->buffer, sizeof(unsigned char), stream->sz, stream->in);
	if(read == stream->sz){
		fwrite(stream->buffer, sizeof(unsigned char), stream->sz, stream->out);
	}else{
		printf("not enough bytes, copying up to end\n");
		fwrite(stream->buffer, sizeof(unsigned char), read, stream->out);
		return 0;
	}
    
    return 1;
}
