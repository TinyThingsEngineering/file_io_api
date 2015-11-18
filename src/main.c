#include <stdio.h>
#include "include/fileAPI.h"
#include "include/object.h"


Object fileIOProto = {
    .init = fileIO_init,
	.input = fileIO_input,
    .destroy = fileIO_destroy
};

int main(int argc, char *argv[])
{
    //open fileIO object name it hello
    fileIO *filestream = NEW(fileIO,"hello");
	while(stream_file(filestream)){
		
	}
	filestream->_(destroy)(filestream);
	getchar();
	getchar();
   return 0;
}



