#ifndef ArrayList_h
#define ArrayList_h

#include "cObj.h"

classHead(ArrayList)
	obj* list;
	int count;
	int listSize;
    int m_func(ArrayList, addElement, void*);
	int m_func(ArrayList, removeElement, int);
    void m_func(ArrayList, resize, int);
	obj (*get)(struct ArrayList*, int);
endHead(ArrayList);

void func(ArrayList, resize, int newSize);
int func(ArrayList, addElement, obj element);
int func(ArrayList, removeElement, int index);
obj func(ArrayList, get, int index);

#endif
