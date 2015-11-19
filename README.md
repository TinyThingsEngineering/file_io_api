# file_io_api

Simple file stream api that copys an input file to an output file n bytes at a time. Input file, outputfile, and n bytes specified by user. Creating a fileIO object will prompt the user for details.By toggling off #define USERIO in fileAPI.c the object description, input file, output file, and bytes to transfer can be set in software. Example of how to use the api in src/main.c

to run: 

-clone

-in linux run 'make clean' then 'make' (if in windows under msys change makefile line to - TARGET: bin/fileO.exe,run 'make clean', then 'make')

-run with 'bin/./fileO (in windows under msys bin/fileO.exe) 
