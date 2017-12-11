//
//  main.c
//  cArrayList
//
//  Created by Bryce Dougherty on 9/7/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "String.h"
#include "cObj.h"
#include "Dictionary.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    ArrayList *myList = c$(ArrayList, new);

    for (int k = 0; k < 1000; k++) {
        var(int, i) = k;
        if (k%2) {
            
            i$(myList, addElement, i);
//            myList->addElement(myList, i);
        } else {
            i$(myList, addElement, i);
//            myList->addElement(myList, i);
        }
        int *val = i$(myList, get, k);
        printf("%d: %d \n", k, *val);
    }
    for (int k = 999; k > 0; k--) {
        i$(myList, removeElement, 0);
        int *val = i$(myList, get, 0);
//        printf("%d: %d \n", k, *val);
    }
    
    Dictionary* dict = create(Dictionary);
    
    String *v = ß("val");
    i$(dict, put, ß("key1"), ß("value1"));
    i$(dict, put, ß("key2"), ß("value2"));
    String *val1 = i$(dict, get, ß("key1"));
    String *val2 = i$(dict, get, ß("key2"));
//    ArrayList *list = ArrayList_new();//c$(ArrayList, new);
//    var(int, i) = 5;
//    i$(list, addElement, i);
    i$(dict, destroy);
    
    
    /* code */
    
    return 0;
}
