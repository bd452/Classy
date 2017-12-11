#include "ArrayList.h"
#include <stdio.h>



//ArrayList *new_arrayList() {
//	ArrayList* al = malloc(sizeof(ArrayList));
classDef(ArrayList)

	self->count = 0;
    self->listSize = 20;
	self->list = malloc(20 * sizeof(void*));
	self->list[10] = NULL;

    mImp(ArrayList, addElement);
    mImp(ArrayList, removeElement);
    mImp(ArrayList, resize);
    mImp(ArrayList, get);

endDef



obj func(ArrayList, get, int index) {
    void *element = self->list[index];
    return element;
}

void func(ArrayList, resize, int newSize) {
    size_t newSize_t = newSize*sizeof(void*);
    self->list = realloc(self->list, newSize_t);
    self->listSize = newSize;
}

int func(ArrayList, addElement, void* element) {
    int count = self->count;
    if (count + 1 >= self->listSize) {
        ArrayList_resize(self, self->listSize * 1.25);
        
        c$(ArrayList, resize, self, self->listSize * 1.25);
    }
//    int *intelement = (int*)element;
    self->list[count] = element;
//    intelement = (int*)self->list[count];
    self->count++;
    return self->list[count] == element && self->count == count+1;
}

int func(ArrayList, removeElement, int index) {
    int count = self->count;
    self->list[count-1] = NULL;
    if (count < self->listSize * 0.75) {
        i$(self, resize, self->listSize * 0.75);
        ArrayList_resize(self, self->listSize * 0.75);
    }
    self->count--;
    return self->list[count-1] == NULL;

}

