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
    //specify object descirption, input file, output file for one object multiple
	//can be created (multiple file streams at once)
	//if you want user defined input instead toggle "USERIO" in fileAPI.c
	char *desc_ifile_ofile_sz[] = {"hello", "hello.txt", "hello_out.txt", "4"};
	
	//open fileIO object name it hello
    fileIO *filestream = NEW(fileIO,desc_ifile_ofile_sz);
	while(stream_file(filestream)){
		
	}
	filestream->_(destroy)(filestream);
	getchar();
	
   return 0;
}



