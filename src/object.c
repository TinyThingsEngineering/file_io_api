#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "include/object.h"

void Object_destroy(void *self)
{
	Object *obj = self;
	if(obj){
		if(obj->description) free(obj->description);
		free(obj);
	}
}

void Object_describe(void *self)
{
	Object *obj = self;
	
	printf("%s.\n", obj->description[0]);
}

void *Object_input(void *self)
{
	printf("Expected user input.\n");
	return NULL;
}

int Object_init(void *self)
{
	return 1;
}

void *Object_new(size_t size, Object proto, char *description[4])
{
	int i = 0;
	if(!proto.init) proto.init = Object_init;
	if(!proto.describe) proto.describe = Object_describe;
	if(!proto.destroy) proto.destroy = Object_destroy;
	
	Object *el = calloc(1, size);
	*el = proto;
	
	for( i = 0;i<4;i++){
		el->description[i] = strdup(description[i]);
	}
	//el->description = (description);
	
	if(!el->init(el)){
		el->destroy(el);
		return NULL;
		
	}else{
		return el;
	}
}