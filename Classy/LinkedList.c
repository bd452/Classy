//
//  LinkedList.c
//  cArrayList
//
//  Created by Bryce Dougherty on 9/7/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#include "LinkedList.h"

classDef(LinkedList)
    self->first = new(LinkedListNode);
    mImp(LinkedList, add);
    mImp(LinkedList, last);
    mImp(LinkedList, pop);

endDef


void func(LinkedList, add, obj data) {
    LinkedListNode *newNode = new(LinkedListNode);
    
    LinkedListNode *lastNode = i$(self, last);
    newNode->next = lastNode;
    lastNode->prev = lastNode;
}

LinkedListNode* func(LinkedList, last) {
    LinkedListNode *node = self->first;
    while (node->next) {
        node = node->next;
    }
    return node;
}

obj func(LinkedList, pop, int index) {
    LinkedListNode *node = self->first;
    int i = 0;
    while (i != index && node->next != NULL) {
        node = node->next;
    }
    if (i == index) {
        return node->data;
    }
    else {
        return NULL;
    }
}
