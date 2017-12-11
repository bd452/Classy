//
//  Dictionary.c
//  cArrayList
//
//  Created by Bryce Dougherty on 12/11/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#include "Dictionary.h"


classDef(Dictionary)
    mImp(Dictionary, get);
    mImp(Dictionary, put);
    mImp(Dictionary, destroy);
    mImp(Dictionary, has);
    mImp(Dictionary, keys);
    self->table = calloc(INITIAL_CAPACITY, sizeof(Entry*));
    self->size = 0;
    self->capacity = INITIAL_CAPACITY;
    self->hash = String_hash;
    self->equals = String_equals;
    self->collisions = 0;
    self->rehashes = 0;
endDef


obj func(Dictionary, get, String *key) {
    size_t index = self->hash(key)%self->capacity;
    if (index > self->capacity) return NULL;
    while (self->table[index] != NULL && !self->equals((self->table[index])->key, key)) {
        index = (index + 1) % self->capacity;
    }
    if (self->table[index] == NULL) {
        assert("Key not found");
    }
    return self->table[index]->value;
}

obj func(Dictionary, put, String* key, obj value) {
    size_t index = self->hash(key)%self->capacity;
    if (index > self->capacity) return NULL;
    while (self->table[index] != NULL && !self->equals((self->table[index])->key, key)) {
        self->collisions++;
        index = (index + 1) % self->capacity;
    }
    if (self->table[index] == NULL) {
        Entry *e = malloc(sizeof(Entry));
        if (e == NULL) {
            fprintf(stderr, "table::put() failed to allocate space");
            assert(NULL);
            return NULL;
        }
        e->key = key;
        e->value = value;
        self->table[index] = e;
        self->size++;
        if (self->size > self->capacity / RESIZE_FACTOR) {
            self->rehash(self);
        }
        return NULL;
    } else {
        void *val = self->table[index]->value;
        self->table[index]->value = value;
        return val;
    }
}

void func(Dictionary, destroy) {
    for (size_t i = 0; i < self->capacity; ++i)
    {
        if (self->table[i] != NULL)
        {
            free(self->table[i]);
        }
    }
    free(self->table);
    free(self);
}

bool func(Dictionary, has, String* key) {
    size_t index = self->hash(key) % self->capacity;
    if (index > self->capacity) return false;
    while (self->table[index] != NULL && !self->equals((self->table[index])->key, key)) {
        index = (index + 1) % self->capacity;
    }
    return self->table[index] != NULL;
}

void func(Dictionary, rehash) {
    size_t oldCapacity = self->capacity;
    size_t newCapacity = oldCapacity * RESIZE_FACTOR;
    Entry **oldT = self->table;
    Entry **newT = calloc(newCapacity, sizeof(Entry*));
    if (newT == NULL) {
        fprintf(stderr, "table::rehash() failed to allocate space");
        assert(NULL);
    }
    self->capacity = newCapacity;
    self->table = newT;
    self->size = 0;
    for (unsigned int i = 0; i < oldCapacity; ++i) {
        Entry *e = oldT[i];
        if (e != NULL) {
            self->put(self, e->key, e->value);
            free(e);
        }
    }
    self->rehashes++;
    free(oldT);
}
ArrayList* func(Dictionary, keys) {
    ArrayList *kk = create(ArrayList);
    if (kk == NULL) {
        fprintf(stderr, "table::keys() failed to allocate space");
        assert(NULL);
        return NULL;
    }
    int index = 0;
    for (unsigned int i = 0; i < self->capacity; ++i) {
        Entry *e = self->table[i];
        if (e != NULL) {
            String *key = e->key;
            i$(kk, addElement, key);
            index++;
        }
    }
    return kk;
}
