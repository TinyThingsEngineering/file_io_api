#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "include/fileAPI.h"
#include "include/object.h"

int stream_file(fileIO *stream);

Object fileIOProto = {
    .init = fileIO_init,
	.input = fileIO_input,
    .destroy = fileIO_destroy
};

int main(int argc, char *argv[])
{
    // simple way to setup the randomness
    fileIO *filestream = NEW(fileIO,"hello");
	while(stream_file(filestream)){
		
	}
	filestream->_(destroy)(filestream);
	getchar();
	getchar();
   return 0;
}


int stream_file(fileIO *stream)
{
	size_t read = 0; 
    read = fread(stream->buffer, sizeof(unsigned char), stream->sz, stream->in);
	if(read == (int)stream->sz){
		fwrite(stream->buffer, sizeof(unsigned char), stream->sz, stream->out);
	}else{
		if(read > 1 || read == 0){
			printf("not enough bytes, copying only %d byte(s)\n",read-1);
		}
		fwrite(stream->buffer, sizeof(unsigned char), read, stream->out);
		return 0;
	}
    
    return 1;
}
