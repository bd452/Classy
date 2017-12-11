//
//  String.c
//  cArrayList
//
//  Created by Bryce Dougherty on 9/7/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#include "String.h"


String *string_make(charString str) {
    String *string = create(String);
    i$(string, set, str);
    return string;
}

classDef(String)
    mImp(String, get);
    mImp(String, set);
    mImp(String, hash);
    mImp(String, equals);
    self->cString = "";
    self->length = 0;
    
endDef


char func(String, get, int index) {
    if (self->length>index) {
        return self->cString[index];
    }
    perror("Index out of bounds");
    return (char)NULL;

}

void func(String, set, char* newString) {
    self->cString = newString;
    self->length = (int)strlen(newString);
}

long func(String, hash) {
    char *str = self->cString;
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (long)hash;
}

bool func(String, equals, String *str) {
    return strcmp(self->cString, str->cString) == 0;
}



