//
//  LinkedList.h
//  cArrayList
//
//  Created by Bryce Dougherty on 9/7/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include "cObj.h"
#include <stdio.h>

typedef struct LinkedListNode {
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
    obj data;
} LinkedListNode;

classHead(LinkedList)
    LinkedListNode *first;
    obj m_func(LinkedList, pop, int);
    void m_func(LinkedList, push, LinkedListNode);
    LinkedListNode* m_func(LinkedList, last);
    void m_func(LinkedList, add, obj data);
endHead(LinkedList)

void func(LinkedList, add, obj data);
void func(LinkedList, push, LinkedListNode);
LinkedListNode* func(LinkedList, last);
obj func(LinkedList, pop, int);

#endif /* LinkedList_h */
