//
//  main.c
//  cArrayList
//
//  Created by Bryce Dougherty on 9/7/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "classy.h"

typedef struct newStruct_ {
    int v1;
    int v2;
    int v3;
} ns;
obj printArgs(Dictionary *args);

int main(int argc, const char * argv[]) {
    // insert code here...
//    Class *newClass = Class_createEmpty(NULL, ß("newClass"), NULL);
    Class *newClass = c$(Class, createEmpty, NULL, ß("newClass"), NULL);
    
    i$(newClass, addInstanceMethod, ß("printArgs"), printArgs);
    
    return 0;
}

obj printArgs(Dictionary *args) {
    int *val1 = i$(args, get, ß("1"));
    int *val2 = i$(args, get, ß("2"));
    
    int *val3 = new(int);
    *val3 = *val1 + *val2;
    return val3;
}
