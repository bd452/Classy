//
//  ClassyClass.h
//  cArrayList
//
//  Created by Bryce Dougherty on 12/12/17.
//  Copyright © 2017 bd452. All rights reserved.
//

#ifndef ClassyClass_h
#define ClassyClass_h

#include <stdio.h>
#import "classy.h"

typedef obj (*IMP)(Dictionary* args);

typedef struct method_ {
    String *name;
    int numArgs;
    ArrayList *argNames;
    IMP implementation;
} Method;

classHead(Class)
    String *className;
    struct Class *superClass;
    Dictionary *classMethods;
    Dictionary *instanceMethods;
    Dictionary *properties;
    int m_func(Class, addInstanceMethod, String *, IMP);
    int m_func(Class, addClassMethod, String*, IMP);
    int m_func(Class, addProperty, String*, obj);
    obj m_func(Class, instExec, String*, Dictionary*);
    obj m_func(Class, classExec, String*, Dictionary*);
    obj m_func(Class, getProperty, String*);
    struct Class* m_func(Class, create, String*, struct Class*, Dictionary*, Dictionary*, Dictionary*);
    struct Class* m_func(Class, createEmpty, String*, struct Class*);
endHead(Class)

struct Class* func(Class, create, String* className, Class* superClass, Dictionary* classMethods, Dictionary* instanceMethods, Dictionary* properties);
struct Class* func(Class, createEmpty, String*, struct Class*);

obj func(Class, instExec, String* methodName, Dictionary* args);
obj func(Class, classExec, String* methodName, Dictionary* args);
int func(Class, addInstanceMethod, String *, IMP implementation);
int func(Class, addClassMethod, String*, IMP implementation);
int func(Class, addProperty, String*, obj);
obj func(Class, getProperty, String*);

#endif /* ClassyClass_h */
