//
//  Dictionary.h
//  cArrayList
//
//  Created by Bryce Dougherty on 12/11/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#ifndef Dictionary_h
#define Dictionary_h

#include <stdio.h>
#include "cObj.h"
#include "String.h"
#include "ArrayList.h"

#define INITIAL_CAPACITY 16

/// The load at which the table will rehash
#define LOAD_THRESHOLD 0.75

/// The table size will double upon each rehash
#define RESIZE_FACTOR 2

/// The "buckets" in the table
typedef struct Entry_t {
    String* key;     ///< key must be "hashable"
    obj value;   ///< value can be any type
} Entry;

classHead(Dictionary)
    Entry** table;    ///< table of Entry pointers
    size_t size;      ///< number of entries in table
    size_t capacity;  ///< total capacity of table
    long (*hash)(String* key);  ///< hash function for key
    bool (*equals)(String *key1, String* key2); ///< equals function for key comparison
    void (*print)(void *key, void* value);  ///< print function for table dump debug
    size_t collisions;      ///< number of collisions throughout life of hash table
    size_t rehashes;

    obj m_func(Dictionary, get, String*);
    obj m_func(Dictionary, put, String*, obj);
    void m_func(Dictionary, destroy);
    bool m_func(Dictionary, has, String*);
    void m_func(Dictionary, rehash);
    ArrayList* m_func(Dictionary, keys);

endHead(Dictionary)


obj func(Dictionary, get, String *key);
obj func(Dictionary, put, String* key, obj value);
void func(Dictionary, destroy);
bool func(Dictionary, has, String* key);
void func(Dictionary, rehash);
ArrayList* func(Dictionary, keys);

#endif /* Dictionary_h */
