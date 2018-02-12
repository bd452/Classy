//
//  ClassyClass.c
//  cArrayList
//
//  Created by Bryce Dougherty on 12/12/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#include "ClassyClass.h"
#include <stdarg.h>

classDef(Class)
    mImp(Class, addInstanceMethod);
    mImp(Class, addClassMethod);
    mImp(Class, addProperty);
    mImp(Class, classExec);
    mImp(Class, instExec);
    mImp(Class, create);

    self->classMethods = create(Dictionary);
    self->instanceMethods = create(Dictionary);
    self->properties = create(Dictionary);
endDef


struct Class* func(Class, create, String* className, Class* superClass, Dictionary* classMethods, Dictionary* instanceMethods, Dictionary* properties) {
    Class *c = create(Class);
    c->className = className;
    c->superClass = superClass;
    c->classMethods = eqn(classMethods, create(Dictionary));
    c->instanceMethods = eqn(instanceMethods, create(Dictionary));
    c->properties = eqn(properties, create(Dictionary));
    return c;
}

struct Class* func(Class, createEmpty, String* name, struct Class* superclass) {
    return Class_create(self, name, superclass, NULL, NULL, NULL);
}

obj ci$(Class *reciever, String *methodName, ...) {
    
    Method *method = i$(reciever->instanceMethods, get, methodName);
    Dictionary *argsList = create(Dictionary);
    int numArgs = method->numArgs;
    va_list args;
    va_start(args, methodName);
    for (int i = 0; i < numArgs; i++) {
        String * argName = i$(method->argNames, get, i);
        obj arg = va_arg(args, obj);
        i$(argsList, put, argName, arg);
    }
    return i$(reciever, instExec, methodName, argsList);
}
obj cc$(Class *reciever, String *methodName, ...) {
    Method *method = i$(reciever->classMethods, get, methodName);
    Dictionary *argsList = create(Dictionary);
    int numArgs = method->numArgs;
    va_list args;
    va_start(args, methodName);
    for (int i = 0; i < numArgs; i++) {
        String * argName = i$(method->argNames, get, i);
        obj arg = va_arg(args, obj);
        i$(argsList, put, argName, arg);
    }
    return i$(reciever, instExec, methodName, argsList);
}

obj func(Class, classExec, String* methodName, Dictionary* args) {
    Method *m = i$(self->classMethods, get, methodName);
    IMP implementation = m->implementation;
    ifn(implementation) {
         return implementation(args);
    }
    else {
        return NULL;
    }
}
obj func(Class, instExec, String *methodName, Dictionary *args) {
    Method *m = i$(self->instanceMethods, get, methodName);
    IMP implementation = m->implementation;
    ifn(implementation) {
        return implementation(args);
    }
    else {
        return NULL;
    }
}
int func(Class, addInstanceMethod, String *name, IMP implementation) {
    Method *m = new(Method);
    m->name = name;
    m->implementation = implementation;
    i$(self->instanceMethods, put, name, m);
    return m != NULL && i$(self->instanceMethods, has, name);
}
int func(Class, addClassMethod, String* name, IMP implementation) {
    Method *m = new(Method);
    m->name = name;
    m->implementation = implementation;
    i$(self->classMethods, put, name, m);
    return m != NULL && i$(self->classMethods, has, name);
}
int func(Class, addProperty, String* key, obj value) {
    return i$(self->properties, put, key, value) != NULL;
}

obj func(Class, getProperty, String* name) {
    return i$(self->properties, get, name);
}
