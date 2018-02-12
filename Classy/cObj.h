//
//  cObj.h
//  cArrayList
//
//  Created by Bryce Dougherty on 9/7/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#ifndef cObj_h
#define cObj_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef void* obj;
typedef char* charString;

//#define ß(string) string->cString


#define assert(val, ...) printf(val, ##__VA_ARGS__);

#define ifn(test) if(test != NULL)
#define eqn(test, else) test != NULL ? test : else

#define fori(dictionary, varName) ArrayList *keys = Dictionary_keys(dictionary); for (int i = 0; i < dictionary->size; i++)



#define var(type, name) type *name = malloc(sizeof(type)); *name
#define $(type) *(type *)
#define i$(object, methodName, ...) object->methodName(object, ##__VA_ARGS__)
#define c$(object, methodName, ...) object##_##methodName(__VA_ARGS__)

#define create(object) object##_new();

#define classDef(type) type* type##_##new() { type *self = malloc(sizeof(type));
#define endDef return self; }
#define classHead(name) typedef struct name {
#define endHead(name) } name; name *name##_##new(void);
#define mImp(type, name) self->name = &type##_##name
#define vImp(name) self->name
#define new(x) malloc(sizeof(x));

#define m_func(object, name, ...) (*name)(struct object*, ##__VA_ARGS__)
#define func(object, name, ...) object##_##name(object *self, ##__VA_ARGS__)
#define println(format, ...) printf(format"\n", ##__VA_ARGS__)
#endif /* cObj_h */
