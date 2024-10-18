# C and C++ notes

## Primitive data type:

All the data types in C and C++, we can categorize them into different groups: **fundamental (or primitive) data types**, **derived data types**, **user-defined data types**, and **additional types provided by C++**. Here's how you can explain them:

### 1. **Fundamental Data Types (Primitive Types)**
These are the basic types provided by the language:

- **C and C++**:
  - `char`: Represents a single character (typically 1 byte).
  - `int`: Represents an integer value (size varies based on system, e.g., 2 or 4 bytes).
  - `float`: Represents a floating-point number (typically 4 bytes).
  - `double`: Represents a double-precision floating-point number (typically 8 bytes).
  - `void`: Represents the absence of type (used for functions that don't return a value).
  - `bool` (C++ only): Represents a boolean value, `true` or `false` (added in C++).

- **Additional Variants**:
  - **Signed and Unsigned Types**:
    - `signed char`, `unsigned char`
    - `signed int`, `unsigned int`
    - `signed short`, `unsigned short`
    - `signed long`, `unsigned long`
    - `signed long long`, `unsigned long long` (C99 and C++11)

### 2. **Derived Data Types**
These are built from the fundamental types:

- **C and C++**:
  - **Pointers**: `int*`, `char*`, `float*`, etc.
  - **Arrays**: `int arr[10]`, `char name[20]`, etc.
  - **Functions**: Return types and parameter types are defined.
  - **References** (C++ only): `int&`, `char&`, etc.

### 3. **User-Defined Data Types**
These are created by the programmer:

- **C and C++**:
  - `struct`: Combines different types into a single entity.
  - `union`: Similar to `struct`, but all members share the same memory location.
  - `enum`: Enumeration types for defining named integer constants.

- **C++ Only**:
  - **Classes**: Similar to `struct`, but with the addition of member functions and more features (encapsulation, inheritance, polymorphism).
  - **`typedef` and `using`**: Used to define new names for existing types.
  - **`std::string`**: A class for handling sequences of characters more easily than C-style strings.

### 4. **Additional Data Types (C99 and C++ Standards)**
- **C99 Added Types**:
  - `long long int`: For larger integer types.
  - **Fixed-Width Integers**: `int8_t`, `int16_t`, `int32_t`, `int64_t`, and their unsigned versions from `<stdint.h>`.
  - `bool` (via `<stdbool.h>`)

- **C++ Adds Many More Types**:
  - **`std::string`**: A more powerful string handling class.
  - **Containers and Iterators** (STL): `std::vector`, `std::list`, `std::map`, etc.
  - **Smart Pointers**: `std::unique_ptr`, `std::shared_ptr`, etc.
  - **Wide Character Types**: `wchar_t`, `char16_t`, `char32_t`.
  - **Type Aliases**: `decltype`, `auto`, `std::nullptr_t`, etc. (C++11 onwards)

### Summary
1. **C**:
   - Fundamental types: `char`, `int`, `float`, `double`, `void`, etc.
   - Derived types: Pointers, arrays, functions.
   - User-defined types: `struct`, `union`, `enum`, `typedef`.
   - Additional (C99): `long long`, fixed-width integers.

2. **C++**:
   - All C types.
   - Extra fundamental type: `bool`.
   - More advanced user-defined types: Classes, `std::string`, smart pointers, etc.
   - Features from newer standards: `decltype`, `auto`, `nullptr`, smart pointers, wide characters, etc.

This breakdown should help you give a comprehensive answer if asked about the various data types in C and C++. You can also mention how the standards have evolved (e.g., C99, C++11, C++14, C++17, C++20) if the interviewer dives deeper.

---
**Additional learning**
I can print an integer in binary, octal and hex using printf command.
```cpp
int x =  11;
printf("0x%d", x); // for hex
printf("0o%d", x); // for octal
printf("%b", x); // for binary

// to specify the number I can always do this
x = 0x11; //for hex
x = 0o4; // for octal
x = 0b1100; // for binary
```

## Initializer List

### What Is an Initializer List?
An **initializer list** in C++ is a way to initialize the data members of a class before the constructor's body is executed. It is placed after the constructor signature and consists of a colon (`:`) followed by a list of member initializations, separated by commas. Each member is initialized with a value using the syntax: `member_name(value)`.

**Example**:
```cpp
class MyClass {
    int x;
    int y;
public:
    MyClass(int a, int b) : x(a), y(b) { // Initializer list
        // Constructor body
    }
};
```

### Why Do We Use Initializer Lists?
Using an initializer list has several benefits:
1. **Efficiency**: Data members are directly initialized, rather than being assigned values later. This can lead to performance improvements because the values are set in the memory when the object is created, instead of initializing them to default values first and then reassigning.
2. **Initialization of `const` Members**: You must use an initializer list to set `const` members, as they cannot be assigned after they are initialized.
3. **Initialization of References**: References must be initialized when they are created, so you need an initializer list for this.
4. **Initialization of Base Class**: If your class inherits from a base class, you need to use the initializer list to call the base class constructor.
5. **Calling Non-Default Constructors**: If a data member is an object of another class that does not have a default constructor, you have to use an initializer list.

### When to Use Initializer Lists vs. Constructor Body Initialization

1. **Use Initializer Lists When:**
   - **Initializing `const` Members**:
     ```cpp
     class MyClass {
         const int x;
     public:
         MyClass(int a) : x(a) {} // Must use initializer list for const members
     };
     ```
   - **Initializing References**:
     ```cpp
     class MyClass {
         int& ref;
     public:
         MyClass(int& r) : ref(r) {} // Must use initializer list for references
     };
     ```
   - **Calling Base Class Constructors**:
     ```cpp
     class Base {
     public:
         Base(int a) { /* ... */ }
     };

     class Derived : public Base {
     public:
         Derived(int a) : Base(a) {} // Must use initializer list to call base constructor
     };
     ```
   - **Initializing Members That Are Objects of Other Classes**:
     - If a class member is of a type that does not have a default constructor, or if you want to pass specific arguments to its constructor, you must use an initializer list.
     ```cpp
     class AnotherClass {
     public:
         AnotherClass(int a) { /* ... */ }
     };

     class MyClass {
         AnotherClass obj;
     public:
         MyClass(int a) : obj(a) {} // Must use initializer list to initialize `obj`
     };
     ```

2. **Initialize in the Constructor Body When:**
   - **The Member Variables Can Be Assigned After Initialization**:
     - For example, when you have basic types (like `int`, `char`, `float`), and there’s no significant difference between initializing and assigning.
     ```cpp
     class MyClass {
         int x;
     public:
         MyClass(int a) {
             x = a; // This is valid, but not always the best approach
         }
     };
     ```
   - **You Need to Perform Complex Initialization Logic**:
     - If the initialization involves more than just copying a value, and you need to run some conditional code, it might make sense to do it in the constructor body.
     ```cpp
     class MyClass {
         int x;
     public:
         MyClass(int a, int b) {
             if (a > b) {
                 x = a;
             } else {
                 x = b;
             }
         }
     };
     ```

### Cases Where You **Must** Use Initializer Lists
1. **`const` Data Members**: Once a `const` member is initialized, it cannot be changed. Therefore, you need to use an initializer list.
2. **Reference Members**: References need to be bound at initialization, so you must use an initializer list.
3. **Base Class Initialization**: If you want to pass specific values to a base class constructor, you have to use an initializer list.
4. **Member Objects Without Default Constructors**: If a class member does not have a default constructor, you must use the initializer list to call the appropriate constructor with parameters.

### Example Illustrating Good Use of Initializer List:
```cpp
class Complex {
    int real;
    int imaginary;
public:
    Complex(int r, int i) : real(r), imaginary(i) {} // Using initializer list is more efficient
};
```

### Summary
- **Initializer lists** are used for efficiency and to handle cases where direct initialization is necessary (e.g., `const` members, references, base classes, non-default-constructible objects).
- **Constructor body initialization** is more suitable when additional logic or conditional initialization is required.
- When preparing for interviews, make sure you can explain why and when each method should be used, and recognize situations that require initializer lists.


## Const

This basically makes the variable immutable 

