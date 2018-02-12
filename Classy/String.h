//
//  String.h
//  cArrayList
//
//  Created by Bryce Dougherty on 9/7/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#ifndef String_h
#define String_h

#include <stdio.h>
#include "cObj.h"

#define ß(str) string_make(str)

classHead(String)
    char *cString;
    int length;
    char m_func(String, get, int);
    void m_func(String, set, char*);
    long m_func(String, hash);
    bool m_func(String, equals, struct String*);
endHead(String)

String *string_make(charString str);

char func(String, get, int index);
void func(String, set, char* string);
long func(String, hash);
bool func(String, equals, String *str);

#endif /* String_h */
