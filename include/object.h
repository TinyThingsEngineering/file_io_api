#ifndef _object_h
#define _object_h

typedef struct{
	char *description;
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*input)(void *self);
	
}Object;

int   Object_init(void *self);
void *Object_input(void *self);
void  Object_destroy(void *self);
void  Object_describe(void *self);
void *Object_new(size_t size, Object proto, char *description);

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif