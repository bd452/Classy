# Classy
A simple framework for object-oriented programming in C

----

Just a small project I've been working on to use object-oriented programming principles in C. The syntax and internal workings are roughly modeled after Objective-C, but obviously more lightweight.

I hated how the only way for me to use classes was either to:
 - Use structs and function pointers, and call with a class->function(args) format
 - Use C++ (!?)

I basically am just using various macros to achieve the first option, but without all the boilerplate.

This actually doesn't follow many of the basic programming principles of OO programming, but I think it's still a cool project.

----

## Creating a Class:

2 files are used for class creation, a header (.h) and a class (.c) file

  ### The Header File:

  In the header file, the class's instance variables and methods are encased between two keywords
  ```c
      classHead(className) 
      
      ***IVARS AND FUNCTIONS GO HERE***
      
      endHead(className)
  ```
  Within this interface, instance variables are declared using traditional C syntax, and methods are created as so: 
  ```c    
      varType varName
      m_func(className, functionName, args)
  ```    
  Then, outside the interface, methods must again be declared with and then with the syntax
  ```c
      func(className, functionName, args)
  ```

_**Example myClass.h**_
  ```c
  classHead(myClass)
    int myIvar;
    void m_func(myClass, myFunction, int arg1, String *arg2, boolean arg3);
  endHead(myClass)
  
  void func(myClass, myFunction, int arg1, String *arg2, boolean arg3);
  ```
  
### The Class File
  
  In the class file, the class's instance variables and methods must be instantiated with a similar syntax to the interface:
  ```c
      classDef(className)
      
      ***METHOD AND IVAR INSTANTIATION HERE***
      
      endDef
  ```
  Inside these keywords, the functions are instantiated with the macro
  ```c
      mImp(className, functionName)
  ```    
  The instance variables are instantiated either with 
  ```c
      vImp(varName) = INITIAL_VALUE 
  ```    
  OR 
  ```c      
      self->varName = initialValue.
  ```    
  Finally, outside the definition, the functions are defined with the same syntax as in the header: 
  
      func(className, functionName, args) { IMPLEMENTATION }
  
  
_**Example myClass.m**_
  ```c
  classHead(myClass)
    vImp(myIvar) = 0; // or self->myIvar = 0
    mImp(myClass, myFunction);
  endHead(myClass)
  
  void func(myClass, myFunction, int arg1, String *arg2, boolean arg3) {
    printf("%d, %s, %d", arg1, arg2->cString, arg3);
  }
  ```
  
  When in a function definition, the keyword "self" can be used to reference the current instance of the class, similarly to Java's "this" or Objective-C's "self". Ex:
      
  ```c
  void func(myClass, myFunction, int arg1, String *arg2, boolean arg3) {
    printf("%d", self->myIvar);
  }
  ```
  
  ### Using a Class
  
  #### Create a new instance
  
  To create a new instance of a class, use the function
  ```c
  create(classType)
  ```
  When calling an instance method of a particular class, use the syntax 
  ```
  i$(className, functionName, args)
  ```
  
  ### Provided Classes
  
  A few basic classes are provided as examples of sorts. These include:
   - a linked list: *LinkedList*
   - a dynamically resizing Array: *ArrayList*
   - a hashmap: *Dictionary*
   - a String: *String*

  
  
  
