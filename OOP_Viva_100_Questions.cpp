/*
==============================================================================
   100 VIVA INTERVIEW QUESTIONS
   TOPIC: INHERITANCE & POLYMORPHISM IN C++ (OOP)
   Difficulty: Easy | Perfect for Viva Preparation
==============================================================================
   SECTION 1: INHERITANCE  (Q1  - Q50)
   SECTION 2: POLYMORPHISM (Q51 - Q100)
==============================================================================
*/

// ============================================================
//  SECTION 1: INHERITANCE (Q1 to Q50)
// ============================================================

/*
Q1. What is Inheritance in C++?
ANS: Inheritance is an OOP feature where a new class (called derived/child class)
     acquires the properties and behaviors of an existing class (base/parent class).
     It promotes code reusability and establishes an IS-A relationship.

     Example:
         class Animal { };              // Base class
         class Dog : public Animal { }; // Dog IS-A Animal
*/

/*
Q2. What is the syntax of Inheritance in C++?
ANS: Syntax:
         class DerivedClass : accessSpecifier BaseClass { };

     Example:
         class Student : public Person { };
         // Student inherits from Person using public access
*/

/*
Q3. What are the types of Inheritance in C++?
ANS: C++ supports 5 types:
     1. Single Inheritance      - one base, one derived class
     2. Multiple Inheritance    - multiple bases, one derived class
     3. Multilevel Inheritance  - chain: A -> B -> C
     4. Hierarchical Inheritance- one base, multiple derived classes
     5. Hybrid Inheritance      - combination of two or more types
*/

/*
Q4. What is Single Inheritance? Give an example.
ANS: One class inherits from exactly ONE base class.

     Example:
         class Vehicle {
         public:
             void start() { cout << "Vehicle started"; }
         };
         class Car : public Vehicle {
         public:
             void drive() { cout << "Car is driving"; }
         };
         int main() {
             Car c;
             c.start(); // inherited from Vehicle
             c.drive();
         }
*/

/*
Q5. What is Multiple Inheritance? Give an example.
ANS: A class inherits from MORE THAN ONE base class.

     Example:
         class Father { public: void property() { cout << "Land"; } };
         class Mother { public: void cook()     { cout << "Meals"; } };
         class Child : public Father, public Mother {
             // Gets both Father and Mother features
         };
*/

/*
Q6. What is Multilevel Inheritance?
ANS: Inheritance in a CHAIN - derived class becomes base for another class.

     Example:
         class A { };            // Grandparent
         class B : public A { }; // Parent (derived from A)
         class C : public B { }; // Child  (derived from B)

     C has access to members of both A and B.
*/

/*
Q7. What is Hierarchical Inheritance?
ANS: ONE base class is inherited by MULTIPLE derived classes.

     Example:
         class Shape { };
         class Circle    : public Shape { };
         class Rectangle : public Shape { };
         class Triangle  : public Shape { };

     All three inherit from Shape.
*/

/*
Q8. What is Hybrid Inheritance?
ANS: Combination of two or more types of inheritance.
     Can lead to the Diamond Problem.

     Diagram:
         A
        / \
       B   C
        \ /
         D   <-- D inherits from B and C, both inherit from A
*/

/*
Q9. What are the access specifiers used in inheritance?
ANS: Three access specifiers:
     1. public    - public members of base stay public in derived
     2. protected - public members of base become protected in derived
     3. private   - public members of base become private in derived

     Default (if not specified) is PRIVATE.
*/

/*
Q10. Difference between public and private inheritance?
ANS:
     Public Inheritance  (IS-A relationship):
     - public    -> public in derived
     - protected -> protected in derived

     Private Inheritance (HAS-A relationship):
     - public    -> private in derived
     - protected -> private in derived
*/

/*
Q11. Can a derived class access private members of the base class?
ANS: NO. Private members are NOT directly accessible in derived class.
     They can only be accessed via public or protected functions of the base class.

     Example:
         class Base {
         private:  int x = 10;
         public:   int getX() { return x; }
         };
         class Derived : public Base {
             void show() {
                 // cout << x;     // ERROR - private
                 cout << getX();  // OK - via public function
             }
         };
*/

/*
Q12. What are protected members and how do they behave in inheritance?
ANS: Protected members are:
     - Accessible WITHIN the class itself
     - Accessible in DERIVED classes
     - NOT accessible outside the class (like private)

     Example:
         class Base { protected: int age; };
         class Derived : public Base {
             void set(int a) { age = a; }  // OK - protected is accessible
         };
*/

/*
Q13. What is the order of constructor calls in inheritance?
ANS: Constructors: BASE first, then DERIVED (top to bottom).
     Destructors:  DERIVED first, then BASE (bottom to top - reverse).

     Example Output for class C inheriting B inheriting A:
     Constructors: A -> B -> C
     Destructors:  ~C -> ~B -> ~A
*/

/*
Q14. How do you call base class constructor from derived class?
ANS: Use INITIALIZATION LIST in the derived constructor.

     Example:
         class Animal {
         public:
             Animal(string n) { cout << "Animal: " << n; }
         };
         class Dog : public Animal {
         public:
             Dog(string n) : Animal(n) {  // calls base constructor
                 cout << " -> Dog created";
             }
         };
*/

/*
Q15. What is function overriding in inheritance?
ANS: When derived class defines a function with the SAME NAME and SAME
     PARAMETERS as the base class - the derived version replaces the base version.

     Example:
         class Animal { public: void sound() { cout << "Some sound"; } };
         class Dog    { public: void sound() { cout << "Bark"; } }; // overrides
*/

/*
Q16. What is the IS-A relationship?
ANS: IS-A means the derived class IS A TYPE of the base class.
     It justifies public inheritance.

     Examples:
     - Dog IS-A Animal
     - Car IS-A Vehicle
     - Circle IS-A Shape
     - Manager IS-A Employee
*/

/*
Q17. What is the HAS-A relationship?
ANS: HAS-A means one class CONTAINS an object of another class (composition).
     It is NOT inheritance.

     Example:
         class Engine { };
         class Car {
             Engine e;  // Car HAS-A Engine (composition)
         };
*/

/*
Q18. What is the Diamond Problem in C++?
ANS: Occurs when a class inherits from two classes that both inherit from
     the same base class - causing the base class to be duplicated.

         A (duplicated!)
        / \
       B   C
        \ /
         D

     Solution: Virtual inheritance.
         class B : virtual public A { };
         class C : virtual public A { };
         class D : public B, public C { }; // Only ONE copy of A
*/

/*
Q19. What is virtual inheritance and why is it used?
ANS: Virtual inheritance ensures only ONE copy of the base class exists
     in the hierarchy, solving the Diamond Problem.

     Syntax:
         class B : virtual public A { };
         class C : virtual public A { };
         class D : public B, public C { };  // One copy of A only
*/

/*
Q20. Can we inherit constructors in C++?
ANS: Constructors are NOT automatically inherited.
     In C++11, we can use 'using' keyword to inherit them:

         class Base { public: Base(int x) { } };
         class Derived : public Base {
         public:
             using Base::Base;  // inherits Base(int x)
         };
*/

/*
Q21. Can we inherit destructors?
ANS: NO. Destructors are not inherited.
     But when a derived object is destroyed, the derived destructor runs first,
     then the base destructor runs AUTOMATICALLY. No explicit call needed.
*/

/*
Q22. What happens if no constructor is defined in the derived class?
ANS: Compiler provides a default constructor that automatically calls
     the BASE CLASS default constructor.
     If base class has no default constructor, you MUST explicitly call
     the appropriate base constructor via initialization list.
*/

/*
Q23. What is the C++ equivalent of 'super' keyword?
ANS: C++ has no 'super' keyword. Use the SCOPE RESOLUTION OPERATOR (::).

     Example:
         class Derived : public Base {
         public:
             void show() {
                 Base::show();  // call base class version explicitly
                 cout << "Derived";
             }
         };
*/

/*
Q24. What is the Object Slicing Problem?
ANS: When a derived object is ASSIGNED to a base class object, the derived-specific
     data members are "sliced off" and lost.

     Example:
         class Base  { int x; };
         class Derived : public Base { int y; };  // extra member y

         Derived d;
         Base b = d;  // y is SLICED OFF - b only has x
*/

/*
Q25. What is the use of 'using' keyword in a derived class?
ANS: Two uses:
     1. Inherit constructors (C++11):
         using Base::Base;

     2. Bring base class overloaded functions into scope:
         class Base { public: void show(int); void show(double); };
         class Derived : public Base {
         public:
             using Base::show;    // bring both show() into scope
             void show(string s); // add new overload
         };
*/

/*
Q26. What if two base classes have the same function name in multiple inheritance?
ANS: AMBIGUITY error. Solution: Use scope resolution operator.

     Example:
         class A { public: void greet() { cout << "A"; } };
         class B { public: void greet() { cout << "B"; } };
         class C : public A, public B { };

         C obj;
         obj.A::greet();  // specify which greet to call
         obj.B::greet();
*/

/*
Q27. What is an Abstract Class?
ANS: A class with at least ONE pure virtual function.
     - Cannot be instantiated directly
     - Acts as a blueprint for derived classes
     - Derived classes MUST implement all pure virtual functions

     Example:
         class Shape {
         public:
             virtual void draw() = 0;  // pure virtual makes it abstract
         };
*/

/*
Q28. Difference between Inheritance and Composition?
ANS:
     Inheritance (IS-A):   class Dog : public Animal { };
     Composition  (HAS-A): class Car { Engine e; };

     Composition is often preferred for flexibility.
     Inheritance is used when a true IS-A relationship exists.
*/

/*
Q29. How to prevent a class from being inherited?
ANS: Use 'final' keyword (C++11):

         class MyClass final { };       // Cannot be base class
         class X : public MyClass { };  // ERROR

     Also works on virtual functions to prevent further overriding:
         virtual void show() final { }
*/

/*
Q30. What is the main benefit of inheritance?
ANS: CODE REUSABILITY - Write once in base class, reuse in multiple derived classes.
     Also enables: Extensibility, Hierarchical modeling, Polymorphism support,
     and Maintainability.
*/

/*
Q31. Difference between Base Class and Derived Class?
ANS:
     Base Class:
     - The class being inherited from (parent/superclass)
     - Exists independently
     - Example: class Animal { };

     Derived Class:
     - The class that inherits (child/subclass)
     - Depends on base class
     - Example: class Dog : public Animal { };
*/

/*
Q32. Can a derived class also act as a base class?
ANS: YES - this is Multilevel Inheritance.

     Example:
         class LivingBeing { };
         class Animal : public LivingBeing { }; // derived AND base
         class Dog    : public Animal { };      // derived from Animal
*/

/*
Q33. What members are NOT inherited from a base class?
ANS: The following are NOT inherited:
     1. Constructors
     2. Destructors
     3. Overloaded assignment operator (=)
     4. Friend functions
     (Note: private members exist but are NOT accessible)
*/

/*
Q34. What is the role of scope resolution (::) in inheritance?
ANS: Used to:
     1. Access a specific base class member when there is name ambiguity
     2. Explicitly call base class version of an overridden function

     Example:
         void show() {
             Base::show();  // explicitly call base version
         }
*/

/*
Q35. How does protected inheritance work?
ANS: In protected inheritance:
     - Public members of base     -> PROTECTED in derived
     - Protected members of base  -> PROTECTED in derived
     - Private members            -> not accessible

     Example:
         class Derived : protected Base {
             // Base's public members become protected here
         };
*/

/*
Q36. What is upcasting?
ANS: Converting a DERIVED class pointer/reference to a BASE class pointer/reference.
     It is SAFE and IMPLICIT (happens automatically).

     Example:
         Dog* d = new Dog();
         Animal* a = d;  // upcasting - safe, no cast needed
*/

/*
Q37. What is downcasting?
ANS: Converting a BASE class pointer/reference to a DERIVED class.
     It is UNSAFE and must be EXPLICIT using dynamic_cast or static_cast.

     Example:
         Animal* a = new Dog();
         Dog* d = dynamic_cast<Dog*>(a);  // downcasting - explicit and checked
*/

/*
Q38. Output of this code?
         class A { public: A() { cout << "A "; } };
         class B : public A { public: B() { cout << "B "; } };
         class C : public B { public: C() { cout << "C "; } };
         int main() { C obj; }

ANS: A B C
     Constructors called from base to derived (top to bottom).
*/

/*
Q39. What is the order of destructor calls?
ANS: Destructors are called in REVERSE order - derived to base.

     For class C : B : A, output is: ~C ~B ~A
*/

/*
Q40. What is method hiding in C++?
ANS: When derived class defines a function with the SAME NAME but DIFFERENT
     signature as base class - ALL base class overloads of that name get hidden.

     Fix: Use 'using Base::functionName;' in derived class.
*/

/*
Q41. Can we access base class private member via a public function?
ANS: YES - indirectly through public/protected member functions.

     Example:
         class Base { private: int x = 10; public: int getX() { return x; } };
         class Derived : public Base {
             void show() { cout << getX(); }  // OK - indirect access
         };
*/

/*
Q42. What does 'final' keyword do in inheritance?
ANS: Prevents further inheritance of a class or further overriding of a function.

     class Dog final { };       // No class can inherit from Dog
     virtual void bark() final; // Cannot be overridden in further derived classes
*/

/*
Q43. Can a class inherit from itself?
ANS: NO. It is invalid and causes a compiler error.
         class A : public A { };  // ERROR
*/

/*
Q44. Difference between overloading and overriding?
ANS:
     Overloading: Same name, different parameters, SAME class, compile-time
     Overriding:  Same name, same parameters, BASE & DERIVED class, runtime (with virtual)
*/

/*
Q45. What is an inherited interface?
ANS: A base class that defines common functions (often pure virtual) that
     all derived classes must implement - providing a common interface.

     Example:
         class Drawable { public: virtual void draw() = 0; }; // Interface
         class Circle : public Drawable { void draw() { cout << "Circle"; } };
*/

/*
Q46. If same function exists in base and derived with public inheritance, which is called?
ANS: Derived class version takes priority for derived class objects.
     To call base version explicitly: obj.Base::show();
*/

/*
Q47. What happens with a private constructor in base class?
ANS: No other class can inherit from it because derived class constructor
     needs to call base constructor - which is private and inaccessible.
     Used to prevent inheritance (before 'final' keyword in C++11).
*/

/*
Q48. C++ 'extends' equivalent?
ANS: C++ uses colon (:) with access specifier:
         class Dog : public Animal { }

     Java uses: class Dog extends Animal { }
     Both achieve the same inheritance.
*/

/*
Q49. Should you inherit from standard library classes (vector, string)?
ANS: Generally DISCOURAGED. Standard library classes lack virtual destructors,
     which leads to undefined behavior when deleting through base pointer.
     Use COMPOSITION instead (HAS-A relationship).
*/

/*
Q50. Key benefits of Inheritance (summary)?
ANS: 1. Code Reusability    - Write once, use in multiple classes
     2. Extensibility       - Add new features without modifying base
     3. Hierarchical Modeling - Models real-world IS-A relationships
     4. Polymorphism Support - Foundation for runtime polymorphism
     5. Maintainability     - Changes in base reflect across all derived classes
*/


// ============================================================
//  SECTION 2: POLYMORPHISM (Q51 to Q100)
// ============================================================

/*
Q51. What is Polymorphism in C++?
ANS: Polymorphism means "many forms". It is the ability of a function or
     object to behave differently based on context.

     Real-world analogy: A person can be a Student, an Employee, and a Son
     at the same time - same person, different roles (many forms).

     In C++:
     - Same function name, different argument types (compile-time)
     - Same function name in base and derived class (runtime)
*/

/*
Q52. What are the two types of Polymorphism in C++?
ANS:
     1. Compile-Time Polymorphism (Static / Early Binding)
        - Resolved at COMPILE time
        - Achieved via: Function Overloading, Operator Overloading

     2. Run-Time Polymorphism (Dynamic / Late Binding)
        - Resolved at RUNTIME
        - Achieved via: Virtual Functions + Function Overriding
*/

/*
Q53. What is Compile-Time Polymorphism? Give example.
ANS: Function to be called is decided at COMPILE TIME by the compiler.

     Example (Function Overloading):
         class Calc {
         public:
             int    add(int a, int b)            { return a + b; }
             double add(double a, double b)      { return a + b; }
             int    add(int a, int b, int c)     { return a + b + c; }
         };
         // Compiler decides which add() based on argument types.
*/

/*
Q54. What is Runtime Polymorphism? Give example.
ANS: Function to be called is decided at RUNTIME using vtable mechanism.
     Requires: VIRTUAL functions + Base class POINTER or REFERENCE.

     Example:
         class Animal { public: virtual void sound() { cout << "..."; } };
         class Dog    { public: void sound() { cout << "Bark"; } };

         Animal* ptr = new Dog();
         ptr->sound();  // decides at RUNTIME -> calls Dog's sound()
*/

/*
Q55. What is Function Overloading?
ANS: Defining MULTIPLE functions with the SAME NAME but DIFFERENT parameters
     (type, number, or order of parameters).

     Rules:
     - Must differ in parameter list
     - Return type alone CANNOT differentiate

     Example:
         void print(int x)    { cout << "int: " << x; }
         void print(double x) { cout << "double: " << x; }
         void print(string s) { cout << "string: " << s; }
*/

/*
Q56. What is Operator Overloading?
ANS: Giving new meaning to existing C++ operators for user-defined types.

     Example (overloading + for Complex numbers):
         class Complex {
             int real, imag;
         public:
             Complex(int r, int i) : real(r), imag(i) {}
             Complex operator+(Complex& c) {
                 return Complex(real + c.real, imag + c.imag);
             }
         };
         Complex c1(1,2), c2(3,4);
         Complex c3 = c1 + c2;  // uses overloaded + operator
*/

/*
Q57. What is a Virtual Function?
ANS: A member function in the BASE class declared with 'virtual' keyword,
     which can be OVERRIDDEN in derived classes for runtime polymorphism.

     Key points:
     - Declared with 'virtual' in base class
     - Called via base class POINTER/REFERENCE for runtime behavior
     - Enables the correct derived class function to be called

     Example:
         class Shape {
         public:
             virtual void area() { cout << "Shape area"; }
         };
         class Circle : public Shape {
         public:
             void area() { cout << "pi*r^2"; }  // overrides
         };
*/

/*
Q58. What is a Pure Virtual Function?
ANS: A virtual function with NO IMPLEMENTATION in the base class.
     Declared with = 0.

     Syntax:   virtual void functionName() = 0;

     Effects:
     - Makes the class ABSTRACT (cannot instantiate)
     - Derived classes MUST provide implementation

     Example:
         class Shape {
         public:
             virtual void draw() = 0;  // pure virtual
         };
*/

/*
Q59. Difference between Virtual and Pure Virtual Function?
ANS:
     Virtual Function:
     - HAS a body in base class
     - Derived class MAY override (optional)
     - Base class CAN be instantiated

     Pure Virtual Function:
     - NO body in base class (= 0)
     - Derived class MUST override (mandatory)
     - Base class CANNOT be instantiated (abstract)
*/

/*
Q60. What is a vtable (Virtual Table)?
ANS: A table of function pointers maintained per class (with virtual functions).
     - Each object has a hidden vptr pointing to its class's vtable
     - At runtime, vtable is used to find the correct function to call

     Dog's vtable:
     +------------------+
     | &Dog::sound      |  <- points to Dog's sound()
     | &Dog::move       |  <- points to Dog's move()
     +------------------+
*/

/*
Q61. What is vptr (Virtual Pointer)?
ANS: A hidden pointer inside every object of a class with virtual functions.
     - vptr points to the class's vtable
     - Set automatically by the constructor
     - Used at runtime to dispatch the correct virtual function

     This mechanism is how C++ implements runtime polymorphism.
*/

/*
Q62. What is Early Binding (Static Binding)?
ANS: The function call is resolved at COMPILE TIME.
     - Happens with non-virtual functions
     - Happens with function overloading and operator overloading
     - Faster, but no runtime flexibility

     Example:
         A obj;
         obj.show();  // compiler already knows to call A::show()
*/

/*
Q63. What is Late Binding (Dynamic Binding)?
ANS: The function call is resolved at RUNTIME.
     - Happens with VIRTUAL functions
     - Requires base class POINTER or REFERENCE
     - Slightly slower but flexible

     Example:
         Animal* ptr = new Dog();
         ptr->sound();  // runtime decides: calls Dog::sound()
*/

/*
Q64. Why use a pointer/reference for runtime polymorphism?
ANS: With a direct object, type is fixed at compile time (no polymorphism).
     With a BASE CLASS POINTER, the actual type is resolved at runtime via vtable.

         Animal a = Dog();   // No polymorphism - slicing occurs
         Animal* p = new Dog(); // RUNTIME polymorphism - calls Dog version
         Animal& r = Dog();     // RUNTIME polymorphism - calls Dog version
*/

/*
Q65. What is an Abstract Class?
ANS: A class with at least ONE pure virtual function.
     - Cannot create objects of abstract class
     - Used as a base (blueprint) only
     - Derived class must implement all pure virtual functions to be concrete

     Example:
         class Vehicle {
         public:
             virtual void start() = 0;
             virtual void stop() = 0;
             void info() { cout << "I am a Vehicle"; }  // normal function allowed
         };
*/

/*
Q66. Can we create an object of an abstract class?
ANS: NO. Compiler gives an error.

         class Shape { public: virtual void draw() = 0; };
         Shape s;  // ERROR - cannot instantiate abstract class

         But POINTER to abstract class is fine:
         Shape* ptr;         // OK
         ptr = new Circle(); // OK - Circle is concrete
*/

/*
Q67. What is a Concrete Class?
ANS: A class that implements ALL pure virtual functions from its abstract base.
     Objects CAN be created from it.

     Example:
         class Shape { virtual void draw() = 0; };  // Abstract
         class Circle : public Shape {
         public:
             void draw() { cout << "Circle"; }  // implemented -> Concrete
         };
         Circle c;  // OK
*/

/*
Q68. What is Function Overriding?
ANS: When a derived class provides its own implementation of a function
     already defined in the base class WITH THE SAME SIGNATURE.

     Rules:
     - Same function name
     - Same parameter list
     - Same return type (or covariant)
     - Base function should be virtual for runtime polymorphism

     Example:
         class Animal { public: virtual void speak() { cout << "..."; } };
         class Cat    { public: void speak() { cout << "Meow"; } }; // overrides
*/

/*
Q69. What is the 'override' keyword in C++11?
ANS: Tells the compiler explicitly that a function is meant to override a virtual function.
     If no matching virtual function in base class, COMPILER GIVES ERROR (catches bugs).

     Example:
         class Base { public: virtual void show(int x) { } };
         class Derived : public Base {
         public:
             void show(int x) override { }     // OK
             void show(double) override { }    // ERROR - no matching virtual
             void shwo(int x) override { }     // ERROR - typo caught!
         };
*/

/*
Q70. What does 'final' do on a virtual function?
ANS: Prevents further derived classes from overriding that specific function.

     Example:
         class A { public: virtual void show() { } };
         class B : public A { public: void show() final { } }; // locked
         class C : public B { public: void show() { } };  // ERROR - final!
*/

/*
Q71. What is Covariant Return Type in overriding?
ANS: An exception to the "same return type" rule.
     Overriding function can return DERIVED TYPE pointer/reference
     when base returns BASE TYPE pointer/reference.

     Example:
         class Base    { public: virtual Base*    create() { return new Base(); } };
         class Derived : public Base { public: Derived* create() { return new Derived(); } };
         // Derived* is covariant to Base* - allowed!
*/

/*
Q72. Can static functions be virtual?
ANS: NO. Static functions belong to the CLASS, not an object.
     Virtual functions require a vptr (per object). Static functions have no 'this' pointer.

     virtual static void show() { }  // ERROR - not allowed
*/

/*
Q73. Can constructors be virtual?
ANS: NO. When a constructor runs, the object is not yet fully created.
     The vtable (vptr) has not been set up yet, so virtual dispatch cannot work.

     class A { virtual A() { } };  // ERROR - virtual constructor not allowed
*/

/*
Q74. Should destructors be virtual? Why?
ANS: YES, when a class is used as a base class with polymorphism.

     Without virtual destructor:
     - delete via Base* calls ONLY Base destructor
     - Derived destructor NEVER runs -> Memory Leak / Undefined Behavior

     With virtual destructor:
     - delete via Base* calls Derived destructor THEN Base destructor -> Correct!

     Rule: If a class has any virtual function, make destructor virtual too.
*/

/*
Q75. What happens if destructor is NOT virtual and you delete via base pointer?
ANS: UNDEFINED BEHAVIOR and potential memory leak!

     Example:
         class Base { public: ~Base() { } };       // NOT virtual
         class Derived : public Base {
             int* arr;
             Derived()  { arr = new int[100]; }
             ~Derived() { delete[] arr; }           // NEVER CALLED via Base*
         };
         Base* ptr = new Derived();
         delete ptr;  // Only ~Base() runs. arr is leaked!

     FIX: Make ~Base() virtual.
*/

/*
Q76. Difference between Method Overloading and Method Overriding?
ANS:
     Overloading:
     - Same name, different parameters
     - Same class
     - Compile-time (static binding)
     - No virtual needed

     Overriding:
     - Same name, same parameters
     - Base and derived class
     - Runtime (dynamic binding)
     - Needs virtual keyword in base
*/

/*
Q77. Write a complete runtime polymorphism example.
ANS:
         #include <iostream>
         using namespace std;

         class Shape {
         public:
             virtual void area() { cout << "Unknown area" << endl; }
         };
         class Circle : public Shape {
         public:
             void area() override { cout << "Area = pi*r*r" << endl; }
         };
         class Rectangle : public Shape {
         public:
             void area() override { cout << "Area = L * B" << endl; }
         };
         int main() {
             Shape* s;
             s = new Circle();    s->area(); // pi*r*r
             s = new Rectangle(); s->area(); // L * B
             return 0;
         }

     Same pointer 's', two different behaviors = Polymorphism!
*/

/*
Q78. What does the 'virtual' keyword tell the compiler?
ANS: "Do NOT resolve this function call at compile time.
      Wait until RUNTIME. Check what type of object is actually pointed to,
      then call the correct version."

     Without virtual: Always calls base class version (static binding)
     With virtual:    Calls actual object's version (dynamic binding)

     Example:
         A* p = new B();
         p->show();  // With virtual: B's show | Without virtual: A's show
*/

/*
Q79. Can we override a non-virtual function?
ANS: We can REDEFINE it in derived class, but it is METHOD HIDING, not true overriding.
     - No runtime polymorphism
     - Base class pointer always calls base version regardless of actual object

     Example:
         class A { public: void show() { cout << "A"; } };  // non-virtual
         class B : public A { public: void show() { cout << "B"; } }; // hiding

         A* ptr = new B();
         ptr->show();  // prints "A" (NOT B) - no virtual = no polymorphism
*/

/*
Q80. What is duck typing? Is it related to C++ polymorphism?
ANS: Duck typing: "If it walks like a duck and quacks like a duck, it is a duck."
     Type determined by BEHAVIOR, not declaration.

     C++ achieves similar effect via TEMPLATES (compile-time duck typing).
     Runtime polymorphism in C++ requires explicit virtual functions.
     Python/JS use duck typing directly without needing inheritance.
*/

/*
Q81. Compile-time vs Runtime polymorphism - speed comparison?
ANS:
     Compile-Time: FASTER
     - Resolved at compile time
     - Direct function call (no vtable lookup)
     - No extra memory for vptr

     Runtime: SLIGHTLY SLOWER
     - vtable lookup at runtime
     - Extra memory per object for vptr (8 bytes on 64-bit)
     - More flexible
*/

/*
Q82. Can we achieve polymorphism without virtual functions?
ANS: YES - using TEMPLATES (Compile-time polymorphism).

     Example:
         template <typename T>
         void print(T val) { cout << val; }

         print(5);         // int
         print(3.14);      // double
         print("hello");   // string

     One function name, different types = polymorphism at compile time!
*/

/*
Q83. Output of this code?
         class A { public: virtual void display() { cout << "A\n"; } };
         class B : public A  { public: void display() { cout << "B\n"; } };
         int main() {
             A* ptr = new B();
             ptr->display();
         }

ANS: B
     display() is virtual -> runtime dispatch via vtable.
     ptr points to B object -> B's display() is called.
*/

/*
Q84. Output if 'virtual' is removed from Q83?
ANS: A
     Without virtual -> static binding at compile time.
     ptr is type A* -> compiler always calls A::display().
     Actual object type is ignored.
*/

/*
Q85. What happens when derived class does NOT override a virtual function?
ANS: The BASE CLASS version is called.

     Example:
         class Animal { public: virtual void sound() { cout << "Generic"; } };
         class Fish : public Animal { };  // no override

         Animal* ptr = new Fish();
         ptr->sound();  // calls Animal::sound() - "Generic"
*/

/*
Q86. Can a pure virtual function have a default implementation?
ANS: YES! A pure virtual function CAN have a body, but the class is still abstract.
     Derived classes must still override. They can call base version using Base::func().

     Example:
         class Base {
         public:
             virtual void show() = 0;  // still pure virtual
         };
         void Base::show() { cout << "Default base show"; }  // body outside class

         class Derived : public Base {
         public:
             void show() {
                 Base::show();   // call base default
                 cout << "Derived";
             }
         };
*/

/*
Q87. What is an Interface in C++?
ANS: C++ has no 'interface' keyword. An Interface is simulated using a class
     with ONLY pure virtual functions (no data, no implementation).

     Example:
         class Printable {       // Interface
         public:
             virtual void print() = 0;
             virtual void save()  = 0;
             virtual ~Printable() { }
         };
         class Document : public Printable {
             void print() { cout << "Printing"; }
             void save()  { cout << "Saving"; }
         };
*/

/*
Q88. How many virtual functions can a class have?
ANS: Unlimited. There is no set maximum.
     Each virtual function adds one entry to the class's vtable.

     Example:
         class MyClass {
             virtual void f1() { }
             virtual void f2() { }
             virtual void f3() { }
             // ... as many as needed
         };
*/

/*
Q89. How does virtual function affect object size?
ANS: Each object of a class with virtual functions contains a hidden VPTR (8 bytes on 64-bit).

     class A { int x; };               // sizeof = 4 bytes
     class B { int x; virtual void f(); }; // sizeof = 16 bytes (4 + 4 padding + 8 vptr)

     This is the only size overhead of virtual functions.
*/

/*
Q90. How to use array of pointers for polymorphic behavior?
ANS: Store different derived class objects in BASE POINTER ARRAY.
     Call virtual functions - each object responds differently.

     Example:
         Shape* shapes[3];
         shapes[0] = new Circle();
         shapes[1] = new Rectangle();
         shapes[2] = new Triangle();

         for (int i = 0; i < 3; i++)
             shapes[i]->draw();  // Each draws differently - Polymorphism!
*/

/*
Q91. Difference between Overriding and Hiding?
ANS:
     Overriding:
     - Same name AND same signature
     - Base function is VIRTUAL
     - Runtime dispatch via vtable
     - Correct function called based on actual object type

     Hiding:
     - Same name, different signature OR non-virtual base function
     - NO runtime dispatch
     - Base class pointer always calls base version
*/

/*
Q92. When should you use virtual functions?
ANS: USE when:
     1. Different derived classes need different behaviors for same function
     2. You use base class pointers to manage derived objects
     3. You need runtime polymorphism (e.g., plugin systems, game objects)
     4. Designing frameworks where others extend your base class

     AVOID when:
     - Class is not meant to be a base class (no inheritance)
     - Performance is extremely critical
     - You know all function calls at compile time
*/

/*
Q93. Can we call a virtual function from a constructor? What happens?
ANS: Technically yes, but DANGEROUS and DISCOURAGED.

     In a constructor, the vptr points to the CURRENT class's vtable,
     NOT the derived class vtable (which isn't set up yet).
     So the base class version is ALWAYS called, even if derived overrides it.

     Example:
         class Base {
         public:
             Base() { show(); }          // called in constructor
             virtual void show() { cout << "Base"; }
         };
         class Derived : public Base {
         public:
             void show() { cout << "Derived"; }
         };
         Derived d;  // prints "Base" NOT "Derived" - surprising!
*/

/*
Q94. What is Dynamic Dispatch?
ANS: The process of selecting which function to call at RUNTIME based on
     the ACTUAL type of the object (not the declared type of the pointer).

     Implemented via vtable and vptr.

     Example:
         Animal* ptr = new Dog();
         ptr->sound();
         // Dynamic dispatch: ptr->vptr -> Dog's vtable -> Dog::sound()
*/

/*
Q95. What is Liskov Substitution Principle (LSP)?
ANS: "Objects of derived class should be substitutable for objects of base class
      without breaking correctness of the program."

     In C++ terms: Any function working with Base* should work correctly
     with Derived* too.

     Example:
         void makeSound(Animal* a) { a->sound(); }

         makeSound(new Dog());    // Dog IS-A Animal - works correctly
         makeSound(new Cat());    // Cat IS-A Animal - works correctly
         makeSound(new Car());    // ERROR - Car is NOT an Animal - violates LSP
*/

/*
Q96. What is the Open/Closed Principle and how does polymorphism support it?
ANS: "Classes should be OPEN for extension, CLOSED for modification."

     With polymorphism:
     - Add new derived classes without changing existing code
     - New behaviors added by creating new classes, not editing old ones

     Example:
         class Shape { public: virtual void draw() = 0; }; // closed for modification
         class Triangle : public Shape { void draw() {...} }; // open for extension
         class Pentagon : public Shape { void draw() {...} }; // another extension

     No change to Shape class needed to add new shapes!
*/

/*
Q97. What is RTTI (Runtime Type Information)?
ANS: A C++ mechanism providing information about an object's TYPE at runtime.

     Two main features:
     1. dynamic_cast  - safely converts base pointer to derived pointer
     2. typeid        - returns type information of an object

     Example:
         Animal* ptr = new Dog();
         Dog* d = dynamic_cast<Dog*>(ptr);    // safe downcast
         if (d) cout << "It is a Dog!";
         cout << typeid(*ptr).name();          // prints type name at runtime
*/

/*
Q98. What is dynamic_cast and when to use it?
ANS: Safely DOWNCASTS a base class pointer to derived class pointer.
     - Returns nullptr if cast fails (for pointers)
     - Requires at least one virtual function in base class (RTTI)

     Example:
         class Animal { public: virtual ~Animal() { } };
         class Dog : public Animal { public: void fetch() { cout << "Fetching!"; } };

         Animal* ptr = new Dog();
         Dog* d = dynamic_cast<Dog*>(ptr);
         if (d != nullptr) {
             d->fetch();   // safe to call Dog-specific function
         }
*/

/*
Q99. static_cast vs dynamic_cast in inheritance?
ANS:
     static_cast:
     - Compile-time resolution
     - NO runtime type checking
     - Faster, but UNSAFE for downcasting
     - If wrong type: undefined behavior
     - Dog* d = static_cast<Dog*>(animalPtr);

     dynamic_cast:
     - Runtime resolution
     - HAS runtime type checking
     - Safe for downcasting (returns nullptr on failure)
     - Requires virtual function in base class
     - Dog* d = dynamic_cast<Dog*>(animalPtr);

     Use static_cast when type is guaranteed.
     Use dynamic_cast when type is uncertain.
*/

/*
Q100. How do Inheritance and Polymorphism work together? (Summary)
ANS: They are the two most powerful OOP pillars working in tandem:

     INHERITANCE provides:
     - Base class defines common structure/interface
     - Derived classes inherit and EXTEND the base class
     - Establishes IS-A relationship

     POLYMORPHISM provides:
     - Same function call, different behavior based on object type
     - One interface, many implementations
     - Base class pointer manages any derived object

     Together they enable:
     - Write generic code with base class pointers
     - Automatically get correct derived behavior at runtime

     Classic Example:
         class Shape { public: virtual void draw() = 0; }; // Inheritance + interface
         class Circle : public Shape { void draw() { cout << "O"; } };
         class Square : public Shape { void draw() { cout << "[]"; } };

         void render(Shape* s) { s->draw(); }  // One function works for ALL shapes!

         render(new Circle()); // prints O
         render(new Square()); // prints []

     This is the POWER of Inheritance + Polymorphism!
*/

// ===========================================================
//  END OF FILE
//  Total Questions: 100
//  Section 1 - Inheritance  : Q1  to Q50  (50 questions)
//  Section 2 - Polymorphism : Q51 to Q100 (50 questions)
// ===========================================================
