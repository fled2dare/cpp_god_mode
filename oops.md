# OOPs

class -> it is used to hold the data and functions/methods that should come in with an object. 
object -> when a class is defined no space is allocated, when it is instantiated (i.e. object is created) that is when memory is allocated

## Pillars of OOPs

### Encapsulation

Binding all the data and the functions together that manipulates them

### Abstraction 

This basically mean show only the essential information and hide the other details.
    - Abstraction using classes
    - Abstraction using header files (math.h -> `pow()`)

### Polymorphism

### How to Explain Polymorphism to an Interviewer

1. **Definition**:
   - **Polymorphism** is a fundamental concept in OOP that allows objects to be treated as instances of their superclass rather than their actual class.
   - It allows one interface to be used for different data types or classes, enabling different behaviors while using the same function or operator name.

2. **Types of Polymorphism**:
   - **Compile-time (Static) Polymorphism**:
     - Achieved through function overloading and operator overloading.
     - The decision about which function to call is made at compile-time.
     - Example:
       ```cpp
       int add(int a, int b) { return a + b; }
       double add(double a, double b) { return a + b; }
       ```
     - Here, the `add` function is overloaded, and the compiler decides which one to call based on the argument types.
   
   - **Run-time (Dynamic) Polymorphism**:
     - Achieved through the use of **virtual functions** in inheritance.
     - The decision about which function to call is made at runtime based on the object type.
     - Example:
       ```cpp
       class Animal {
       public:
           virtual void makeSound() { cout << "Animal sound"; }
       };

       class Dog : public Animal {
       public:
           void makeSound() override { cout << "Bark"; }
       };

       class Cat : public Animal {
       public:
           void makeSound() override { cout << "Meow"; }
       };

       void playSound(Animal* animal) {
           animal->makeSound();
       }

       int main() {
           Dog dog;
           Cat cat;
           playSound(&dog); // Outputs: Bark
           playSound(&cat); // Outputs: Meow
       }
       ```
     - In the example, `makeSound` is a **virtual function** in the `Animal` class. When we call `playSound`, it uses the type of the object (either `Dog` or `Cat`) at runtime to decide which version of `makeSound` to execute.
     - This is **dynamic polymorphism**, which allows different behaviors to be defined in subclasses but invoked via a common interface.

3. **Why Mention Virtual Functions**:
   - Virtual functions are a key concept in polymorphism that enables run-time behavior change. By marking a method as `virtual` in the superclass, you tell C++ that this method can be **overridden** by subclasses, and the program should **dynamically determine** which version to use at runtime.
   - Without virtual functions, even if a subclass overrides a method, the superclass version would still be called due to **static binding**.

### Summary:
- **Inheritance**: Superclass (base/parent) provides reusable properties/methods; Subclass (derived/child) inherits them, adding new features or modifying existing ones.
- **Reusability**: Ability to leverage existing code (e.g., a base class) to create new code (e.g., derived classes) without rewriting.
- **Polymorphism**:
  - **Compile-time**: Function/operator overloading.
  - **Run-time**: Achieved via virtual functions and inheritance, allowing objects to behave differently even when accessed through a base class pointer/reference.

By explaining these concepts clearly, including examples, you demonstrate not only your understanding of fundamental OOP principles but also your knowledge of more advanced features like dynamic binding and virtual functions.

### Inheritance

The capability of a class to derive properties and characteristics from another class is called inheritance.

1. **Subclass and Superclass**:
   - **Superclass** (also known as **Base Class** or **Parent Class**):
     - This is the class that provides properties and methods (member variables and functions) that can be inherited by other classes.
     - The superclass defines common behavior or data that can be shared across multiple subclasses.
     - Example:
       ```cpp
       class Animal {
       public:
           void eat() { cout << "Eating..."; }
       };
       ```
       Here, `Animal` is a superclass.
   
   - **Subclass** (also known as **Derived Class** or **Child Class**):
     - This is a class that inherits properties and methods from the superclass.
     - The subclass can also have its own additional properties or methods, which are not present in the superclass.
     - The subclass can override the behavior of the superclass as needed.
     - Example:
       ```cpp
       class Dog : public Animal {
       public:
           void bark() { cout << "Barking..."; }
       };
       ```
       Here, `Dog` is a subclass that inherits from `Animal`.

2. **Reusability**:
   - **Reusability** refers to the concept of using existing code (like classes, functions) to create new code without rewriting it.
   - In the context of inheritance, reusability means that you can create a new subclass from an existing superclass and reuse its code, reducing redundancy.
   - Example:
     - If you have a base class `Vehicle` with common properties like `speed` and `fuel`, you can create specific subclasses like `Car` or `Bike` without rewriting the `speed` and `fuel` functionalities. This promotes code reuse and maintainability.


---

### 1. **Dangling Pointers**
   - A **dangling pointer** is a pointer that points to a memory location that has already been freed or deleted. Accessing a dangling pointer can lead to undefined behavior, crashes, or security vulnerabilities.
   - **Example**:
     ```cpp
     int* ptr = new int(5);
     delete ptr;  // ptr is now a dangling pointer
     *ptr = 10;   // Undefined behavior, since ptr points to a deleted memory location
     ```

   - **Common Causes**:
     - Deleting a pointer and continuing to use it.
     - Returning pointers to local variables from a function.

### 2. **Call by Value vs Call by Reference**
   - **Call by Value**:
     - A copy of the actual argument is passed to the function. Modifications inside the function do not affect the original variable.
     - **Example**:
       ```cpp
       void foo(int x) {
           x = 10;  // Changes only the copy of the argument
       }

       int main() {
           int a = 5;
           foo(a);
           // a is still 5
       }
       ```

   - **Call by Reference**:
     - The actual argument is passed, allowing the function to modify the original variable.
     - **Example**:
       ```cpp
       void foo(int& x) {
           x = 10;  // Modifies the original argument
       }

       int main() {
           int a = 5;
           foo(a);
           // a is now 10
       }
       ```

### 3. **Prefix vs Postfix Increment/Decrement**
   - **Prefix (`++i` / `--i`)**:
     - The value is incremented/decremented **before** it is used in the expression.
     - **Example**:
       ```cpp
       int i = 5;
       int j = ++i;  // i becomes 6, then j is set to 6
       ```

   - **Postfix (`i++` / `i--`)**:
     - The value is incremented/decremented **after** it is used in the expression.
     - **Example**:
       ```cpp
       int i = 5;
       int j = i++;  // j is set to 5, then i becomes 6
       ```

### 4. **Copy Constructor vs Copy Assignment Operator**
   - **Copy Constructor**:
     - Initializes a new object as a copy of an existing object.
     - Called when a new object is created from an existing object (e.g., `MyClass obj2 = obj1;`).
     - **Syntax**:
       ```cpp
       MyClass(const MyClass& other);
       ```

   - **Copy Assignment Operator**:
     - Assigns the values from one existing object to another existing object.
     - Called when two already-existing objects are involved (e.g., `obj1 = obj2;`).
     - **Syntax**:
       ```cpp
       MyClass& operator=(const MyClass& other);
       ```

### 5. **Move Constructor vs Move Assignment Operator**
   - **Move Constructor**:
     - Transfers resources from one object to another **without copying**.
     - Primarily used to **optimize performance** by avoiding unnecessary copying.
     - **Syntax**:
       ```cpp
       MyClass(MyClass&& other);  // '&&' denotes an r-value reference
       ```

   - **Move Assignment Operator**:
     - Similar to the move constructor, but used when two existing objects are involved.
     - Transfers resources from one object to another, leaving the original in a valid but unspecified state.
     - **Syntax**:
       ```cpp
       MyClass& operator=(MyClass&& other);
       ```

### 6. **Pointers vs References**
   - **Pointers**:
     - Stores the **memory address** of a variable.
     - Can be reassigned to point to different variables.
     - Can be `nullptr` (pointing to nothing).
     - **Example**:
       ```cpp
       int a = 5;
       int* ptr = &a;  // ptr stores the address of a
       ```

   - **References**:
     - An **alias** for an existing variable.
     - Must be initialized at the time of declaration and cannot be changed to refer to a different variable.
     - Cannot be `nullptr`.
     - **Example**:
       ```cpp
       int a = 5;
       int& ref = a;  // ref is an alias for a
       ```

    Explaining what it means for a **reference** to be an "alias" to a variable.

    ### **What is an Alias to a Variable?**
    - When we say a **reference** is an "alias" to a variable, it means the reference is just another name for the same variable. 
    - Any operation performed using the reference actually affects the original variable, because both the reference and the original variable point to the **same memory location**.
    - **Example**: If you have `int x = 10;` and create `int& ref = x;`, both `x` and `ref` refer to the same integer `10`. Changing `ref` will also change `x`, and vice versa.

    ### **Code Example: Pointers vs References**

    Here's a complete code example you can run on your PC:

    ```cpp
    #include <iostream>

    void demonstratePointers() {
        int x = 10;
        int *ptr = &x; // ptr stores the address of x

        std::cout << "Value of x: " << x << std::endl;
        std::cout << "Pointer ptr points to value: " << *ptr << std::endl;

        // Changing the value using the pointer
        *ptr = 20;
        std::cout << "After changing *ptr, x is: " << x << std::endl;

        // Changing the value of x directly
        x = 30;
        std::cout << "After changing x, *ptr is: " << *ptr << std::endl;
    }

    void demonstrateReferences() {
        int y = 15;
        int &ref = y; // ref is a reference (alias) to y

        std::cout << "Value of y: " << y << std::endl;
        std::cout << "Reference ref refers to value: " << ref << std::endl;

        // Changing the value using the reference
        ref = 25;
        std::cout << "After changing ref, y is: " << y << std::endl;

        // Changing the value of y directly
        y = 35;
        std::cout << "After changing y, ref is: " << ref << std::endl;
    }

    int main() {
        std::cout << "Demonstrating Pointers:" << std::endl;
        demonstratePointers();

        std::cout << "\nDemonstrating References:" << std::endl;
        demonstrateReferences();

        return 0;
    }
    ```

    ### **Explanation**
    1. **Pointers**:
      - `ptr` is a pointer that stores the **address** of `x`. 
      - We can use `*ptr` (dereferencing) to access the value stored at that address.
      - Changing `*ptr` changes the value of `x` because `ptr` points to `x`.

    2. **References**:
      - `ref` is a **reference** to `y`, meaning it is just another name for `y`. 
      - Any change made to `ref` will directly change `y` and vice versa because they refer to the same memory location.

    ### **Expected Output**
    ```
    Demonstrating Pointers:
    Value of x: 10
    Pointer ptr points to value: 10
    After changing *ptr, x is: 20
    After changing x, *ptr is: 30

    Demonstrating References:
    Value of y: 15
    Reference ref refers to value: 15
    After changing ref, y is: 25
    After changing y, ref is: 35
    ```

