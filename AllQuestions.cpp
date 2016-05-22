An abstract class can be initantiate? 
	False cannot initantiate an abstract class since it is not complete defined.
In Java Can we instantiate abstract class?
    Yes we can via anonymous class
    abstract class My {
      public void myMethod() {
          System.out.print("Abstract");
      }
    }

    //class AbstractClass2 extends My{
    class AbstractClass2 {
        public static void main(String[] args) {
            My m = new My() {};
            m.myMethod();
        }
    };
Vtables create a static table per class /*????*/
Explain the use of Vtable.  
	Vtables are used for virtual functions. Its a shortform for Virtual 
	Function Table. It's a static table created by the compiler. Compiler 
	creates a static table per class and the data consists on pointers to 
	the virtual function definitions. They are automatically initialised by 
	the compiler's constructor code. 
	Since virtual function pointers are stored in each instance, the compiler is
	enabled to call the correct vrtual function at runtime. 
What is the difference between overloaded functions and overriden functions
	Overloading is static or compile time binding snd Overriding is dynamic or 
  run time binding
	Overloading means having methods with same name but different signature
	Overriding means rewriting the (virtual) method of the base class 
	rewriting the method in base class, relationship between parent/child
What is Overloading Polymorphism? 
	Overloading allows multiple functions to exist with same name but different parameters.
Explain Overriding Polymorphism	
	Overriding changes the behavior of a class to make it behave different 
	than its parent class. It is the process of redefining the inherited 
	method or attribute in a subclass. Overriding means changing behavior of 
	methods of base class in derive class by overriding the base class 
	methods. If class A is a base class with method 'calculate' and class B 
	inherits class A, thus derives method 'calculate' of class A. The 
	behavior of 'calculate' in class B can be changed by overriding it. 
Explain why and when do we use protected instead of private
	Private data members cannot be accessed outside the class. When a class 
	inherits a base class, all the data members except the private get 
	inherited into it. So if we want data members to be accessible to only 
	derived classes and not privately or publicly accessible, then we can 
	use protected. 
  Things that are private are only visible within the class itself.
  Things that are protected are visible in the class itself and in subclasses.
What is the default access level?
	The access privileges in C++ are private, public and protected. The 
	default access level assigned to members of a class is private. Private 
	members of a class are accessible only within the class and by friends 
	of the class. Protected members are accessible by the class itself and 
	its sub- classes. Public members of a class can be accessed by anyone. 
Explain passing objects by reference, passing objects by value and passing 
  objects by pointer 
	Pass by value:
	=============
	The callee function receives a set of values that are to be received by 
	the parameters. All these copies of values have local scope, i.e., they 
	can be accessed only by the callee function. The simplicity and 
	guarantee of unchanging of values passed are the advantages of pass by 
	value. 
	Ref. http://www.learncpp.com/cpp-tutorial/72-passing-arguments-by-value/
	void foo(int y)
	{
		using namespace std;
		cout << "y = " << y << endl;
	}
	int main()
	{
		foo(5); // first call
		int x = 6;
		foo(x); // second call
		foo(x+1); // third call
		return 0;
	}
	Pass by reference:
	=================
	The callee function receives a set of references which are aliases to 
	variables. If a change is made to the reference variable, the original 
	value (passed by the caller function) will also be changed. All the 
	references are handled by the pointers. Multiple values modification can 
	be done by passing multiple variables.
	// E:\Ctest\Pass_By_Reference.cpp
	// 2:23 PM 6/18/2014
	#include <iostream>
	using namespace std;
	void foo(int &y) // y is now a reference
	{
		using namespace std;
		cout << "y = " << y << endl;
		y = 6;
		cout << "y = " << y << endl;
	} // y is destroyed here
	 
	int main()
	{
		int x = 5;
		cout << "x = " << x << endl;
		foo(x);
		cout << "x = " << x << endl;
		return 0;
	}
	// Output:
	// x = 5
	// y = 5
	// y = 6
	// x = 6
	// E:\Ctest\Pass_By_Reference1.cpp
	// 3:35 PM 6/18/2014
	// passing parameters by reference in Cplusplus.doc
	#include <iostream>
	using namespace std;
	void duplicate (int& a, int& b, int& c)
	{
		a *= 2;
		b *= 2;
		c *= 2;
	}
	int main ()
	{
		int x=1, y=3, z=7;
		duplicate (x, y, z);
		cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
		return 0;
	}
	// Output: x=2, y=6, z=14
	// E:\Ctest\Pass_By_Reference2.cpp
	#include <stdio.h>
	void Square(int &Val);
	main()
	{
		int Number=10;
		printf("Number is %d\n", Number);
		Square(Number);
		printf("Number is %d\n", Number);
	}
	void Square(int &Val)
	{
		Val *= Val;
		printf("Number is %d\n", Val);
	}
	// Output:
	// Number is 10
	// Number is 100
	// Number is 100
	Pass by pointer:
	================
	The callee function receives a pointer to the variable. The value of the 
	pointer in the caller function can then be modified. The advantages of 
	this process are that the changes are passed back to the caller function 
	and multiple variables can be changed. 
	#include <stdio.h>
	void add(int*); 			/* Function declaration 	*/
	int main()
	{
		int i=4;				/* variable declaration 	*/
		int* ptr;				/* int pointer			*/
		ptr = &i;				/* 'ptr' now contains the
								address of 'i'		*/
		printf("i starts out life as %d.\n", i);
		printf("             *ptr is %d.\n", *ptr);
		add(ptr); 				/* Function call       		*/
		printf("            i is now %d.\n", i);
		return 0;
	}
	void add(int *ptr)	 		/* Function definition 		*/
	{
		++*ptr;				    /* Add 1 to the value
								 * pointed too by 'ptr'		*/
		return;
	}
	// Output:
	// i starts out life as 4.
				 // *ptr is 4.
				// i is now 5.
	Pass by Address:
	===============
	// E:\Ctest\Pass_By_Address1.cpp
	#include <stdio.h>
	void Square(int *pVal);
	main()
	{
		int Number=10;
		printf("Number is %d\n", Number);
		Square(&Number);
		printf("Number is %d\n", Number);
	}
	void Square(int *pVal)
	{
		*pVal *= *pVal;            
		printf("Number is %d\n", *pVal);
	}
	// Output:
	// Number is 10
	// Number is 100
	// Number is 100
	// E:\Ctest\Pass_By_Address.cpp
	// 2:24 PM 6/18/2014
	#include <iostream>
	using namespace std;
	void foo(int *pValue)
	{
		*pValue = 6;
	}
	 
	int main()
	{
		int nValue = 5;
	 
		cout << "nValue = " << nValue << endl;
		foo(&nValue);
		cout << "nValue = " << nValue << endl;
		return 0;
	}
	// Output: 
	// nValue = 5
	// nValue = 6
	// E:\Ctest\Pass_By_Address1.cpp
	#include <stdio.h>
	void Square(int *pVal);
	main()
	{
		int Number=10;
		printf("Number is %d\n", Number);
		Square(&Number);
		printf("Number is %d\n", Number);
	}
	void Square(int *pVal)
	{
		*pVal *= *pVal;            
		printf("Number is %d\n", *pVal);
	}
	// Output:
	// Number is 10
	// Number is 100
	// Number is 100
	//home/tovantran/Ctest/qualcomm3.c --> 2014-06-18 by ./.tv  owner: tovantran
	#include <stdio.h>
	#include <stdlib.h>
	/*
	 * What gets printed when you run example?
	 */
	int main(int argc, char *argv[]) {
		unsigned int x = 0x12345678;
		unsigned int *p = &x;
		printf("0x%x\n",*(unsigned char *)&x);
		printf("0x%x\n",*(unsigned int *)&x);
		printf("%p\n", (void *)(unsigned long)*&x);
	/*	printf("0x%d\n",*p);*/
	/*	printf("0x%x\n", *&x);*/
		return 0;
	}
	// Output:
	// 0x78
	// 0x12345678
	// 0x12345678
Void Pointers?
	//home/tovantran/Ctest/pointer2.cpp --> 2014-06-18 by ./.tv  owner: tovantran
	// cplusplus.doc
	#include <iostream>
	using namespace std;

	void increase (void* data, int
			type)
	{
		switch (type)
		{
			case sizeof(char) :
				//(*((char*)data))++; break;
				(*((char*)data))++; break;
			case sizeof(short):
				(*((short*)data))++; break;
			case sizeof(long) :
				(*((long*)data))++; break;
		}
	}
	int main ()
	{
		char a = 5;
		short b = 9;
		long c = 12;
		increase (&a,sizeof(a));
		increase (&b,sizeof(b));
		increase (&c,sizeof(c));
		cout << (int) a << ", " << b << ", " << c << endl;
		return 0;
	}
	//Output: 6, 10, 13 
Aliases in C++ ?
	typedef struct SomeStruct {
	int a;
	int b;
	} MyStruct;
	MyStruct var1;
	MyStruct *var2;
	Basically an alias is any time when you can give something a new name. 
	There are quite a few ways to do this in C/C++ -- for example you can 
	use the preprocessor to alias all kinds of things. 
How do we define a destructor?
	~B(){}
Can constructors be overloaded?
	Yes
Every class has at least one constructor even when none is declared?
    True
Static vs. dynamic binding?
	Binding means connecting the function call to a function implementation. 
	Connecting the function call to the function implementation before 
	execution is static binding whereas connection them at the run-time is 
	dynamic binding 
	C++ provide the facility to sepecify that the compiler should match 
	function calls with correct definition at the run time. This process is 
	called as Dynamic binding
What is shallow copy?
	Just copies the values of the data type they are
Which classes allow primative types to be accessed as objects
	Wrapper
Which of the following library function below by default aborts the program
	terminate()
	end()
	abort()
	exit()  <---------
What is the different between struct and class
	By default the struct members are public while default class members are 
  private
Which of the following below can perform conversations between pointers 
to related classes?
   static_cast
	 dynamic_cast 
	Both static_cast and dynamic_cast can perform conversions between 
	pointers to related classes. Only the difference between them is that 
	the static_cast performs the conversion between pointers of the 
	non-polymorphic related classes and dynamic_cast performs the conversion 
	of the polymorphic related classes. 
What happens when a pointer is deleted twice?
	It can abort the program
	It can cause a failure
	It can cause an error
	It can cause a trap <-----
The default access level assigned to members of a class is
	Private

shadows a parameter

inline vs. macro
	macro code replaces and inline in run time see breakpoint

Function chaining?
a = b = c = d func1().func2() when return function is int & ref.

typedef vs. #define
	#define is a preprocessor token: the compiler will never see it
	typefef is a compiler token: 
	#define MY_TYPE int
	typefef int My_Type 
Why must the copy assignment operator return a reference/const reference?
	Base& operator=(const Base &source)

g++ “Calling” function without parenthesis ( not f() but f; ). Why always returns 1?
cout << boolalpha << test1 << endl; //return true

C Program to Check Whether a Number is Prime or Not
Divide by 1 and itself is known as prime number (ie. number 1) and 15 is not prime it divisible 1, 3, 5, 15

Inline functions are invoked at the time of 
	Run time compile does type checking 

Which of the following operators below allow to define the member functions of the a 
class outside the class
    :: scope
There is nothing like virtual constructor of a class
     True
What is the deep copy
	A deep copy created a copy of the dynamically allocated objects too
What defines a general set of operations that will be applied to various types 
of data?
    Template class
  	Function template <-----
  	Class template
Which of the following below is/are a valid iterator type?
   input iterator
	 backward iterator
	 foward iterator
	 both a and c above <-------
Explain how to call C from C++
	 extern "C" void showme()
What is the pointer? explain and example?
	A pointer is a variable that holds a memory address. This address is the 
	location of another object in memory. If one variable contains the 
	address of another variable, the first variable is said to point to the 
	second... 
What is NULL pointer and void pointer and what is the use?
	A NULL pointer has fixed reserved value that is not zero or space which 
	indicated that no object is referred. NULL pointers are used in C/C++ as 
	compile time constant NULL pointer represents certain conditions like 
	last element in linked list 
  (cplusplus.doc)
  void pointers can point to any data type, from an integer value or a float to a string of characters. 
  Its sole limitation is that the pointed data cannot be referenced directly (we can not use reference    
  asterisk * operator on them), since its length is always undetermined, and for that reason we will always   
  have to resort to type casting or assignations to turn our void pointer to a pointer of a concrete data type  
  that we can refer. 
How to declare a class as a friend of another class
	Friend class can be declared as below
	class A{
		int i;
		public:
		friend class B;
	};
		class CSquare {
		private:
			int side;
		public:
			void set_side (int a)
			{side=a;}
			friend class CRectangle;
		};

What are the characteristics of friend functions?
	A friend function is not in the scope of the class n which it has been declared as friend.
	It cannot be called using the object of that class..................
	// friend functions
	#include <iostream.h>

	class CRectangle {
		int width, height;
	  public:
		void set_values (int, int);
		int area (void) {return (width * height);}
		friend CRectangle duplicate (CRectangle);
	};
Class vs. Structure
	Class has private as default access specifier. default inheritance type is private
	Struct has public as default access specifier. default inheritance type is public
How to call a base member function from derived class member function?  
	#include <iostream>
	using namespace std;
	class A{
	public:
	int i;
	// A(){ cout << "A default ctor " << endl; };  // need default ctors
	// A(int j = 0): i(j){}  //or initialize
	A(int j): i(j){}
	int geti() { return i;};
	};
	class B : public A{
	public:
		// static const int j = 0;
		// int ii;
		// B(int i) { A::i = i;}
		B(int i): A(i) { cout << "Call A::geti() "<< A::geti() << endl;}
		int getii() {return i;}
	};
	int main(){
		A a(2);
		// cout << a.geti() << endl;
		B b(5);				//set i in base class and call geti() from base class
		cout << b.getii() << endl;
		// cout << a.geti() << endl;
		return 0;
	}
How to call default ctors;
	#include <iostream>
	using namespace std;
	class A { 
	public: 
		int i;
		A() { cout << "A()" << endl;}; 
		A(int x) { i=x; cout << "A( int x)" << endl;}; 
	}; 
	int main() { 
		A a(1); //ctors with parameter
		// A b();   //fail compile thinks run function 
		A b;	//ctors
		// cout << "b.i =" << b.i << endl;
	}
	//Output:
	// A( int x)
	// A()
What is static member?
	Static data members of a class are also known as "class variables", 
	because their content does not depend on any object. There is only one 
	unique value for all the objects of that same class. In fact, static 
	members have the same properties as global variables but enjoying class 
	scope (Cplusplus)( only one copy of static data member is shared amongst objects) 
	Borland C++ When you declare a static data member 
	within a class, you are not defining it. (That is, you are not 
	allocating storage for it.) Instead, you must provide a global 
	definition for it elsewhere, outside the class
	http://careerride.com/C++-static-dynamic-binding-of-functions.aspx
	Static member functions are used to maintain a single copy of a class 
	member function across various objects of the class. Static member 
	functions can be called either by itself, independent of any object, by 
	using class name and :: 
	A static function can have an access to only other static members 
	(functions or variables) declared in the same class.
	Restrictions on static member functions are:
	1. They can directly refer to other static members of the class.
	2. Static member functions do not have this pointer.
	3. Static member function can not be virtual.
	What is static member?
	A static member is created and initialize once and shared among all 
	class objects.
	Static member functions.
	The static member functions are created to access static variables of a class. 
	http://careerride.com/C++-what-are-static-member-functions.aspx
	#include <iostream>
	using namespace std;
	class A { 
	public: 
		static int i;
		// int i;
		A() { cout << "A()" << endl;}; 
		A(int x) { i=x; cout << "A( int x)" << endl;}; 
	}; 
	int A::i;  		//define a outside class 
	int main() { 
		A a; 		//ctors with parameter
		// A b();   //fail run function without A b; is ctors
		A b (4);	//ctors
		A c (5);
		cout << "b.i =" << b.i << endl;
		cout << "a.i =" << a.i << endl;
	}
	//Output
	// A()
	// A( int x)
	// A( int x)
	// b.i =5
	// a.i =5
Uses of static class data  
	1. To provide access control mechanism to some shared resource used by 
	   all the objects of a class 
	2. To keep track of no of objects in existence of a particular class 
What are static and dynamic type checking?
	- Static type checking performs the type checking operation 
	before the execution of the program. To perform this operation, the 
	arguments, expressions, variables must be given a data type. 
	- Dynamic type checking performs the type checking operation at the time of the 
	program execution. To perform this operation, the arguments, 
	expressions, variables must be given a data type 
Anonymouse class in Java?
	 Create a class anonymous from interface or abstract one time. See caveprogram
	 abstract class A{
     static String str;
	}
	abstract class B extends A{  //can not create object with abastract class 
		public B(){
			str = "123";
		}
	}

	abstract class C extends A{
		public C(){
			str = "abc";
		}
	}

	public class Main2{

		public static void main(String[] args){
	//        B bb = new B(); //B is abstract; cannot be instantiated
			B b = new B() {};  //working because it is anonymous class one time
			C c = new C() {};  // anonymous class 
			b.str = "123";
			System.out.println("b.str = " + b.str);  //static so B C has the same object(memory)
			System.out.println("c.str = " + c.str);
			c.str = "abc";
			System.out.println("b.str = " + b.str);
			System.out.println("c.str = " + c.str);
		}
	}
	// Output:
	// b.str = 123
	// c.str = 123
	// b.str = abc
	// c.str = abc
	//home/tovantran/Ctest/Main1.java ----------> 2014-06-17 by ./.tv  owner: tovantran
	abstract class A{
		static String str;
	}

	class B extends A{
		public B(){
			str = "123";
		}
	}

	class C extends A{
		public C(){
			str = "abc";
		}
	}

	public class Main1{

		public static void main(String[] args){
			A b = new B();
			A c = new C();
			System.out.println("b.str = " + b.str);
			System.out.println("c.str = " + c.str);
		}
	}
	// Output:
	// b.str = abc
	// c.str = abc
How many ways to create an object or initantiate in Java?
	1. Using new keyword
	This is the most common way to create an object in java. I read 
	somewhere that almost 99% of objects are created in this way. 
	MyObject object = new MyObject();
	2. Using Class.forName()
	If we know the name of the class & if it has a public default 
	constructor we can create an object in this way. MyObject object = 
	(MyObject) Class.forName("subin.rnd.MyObject").newInstance(); 
	3. Using clone()
	The clone() can be used to create a copy of an existing object.
	MyObject anotherObject = new MyObject(); 
	MyObject object = anotherObject.clone();
	4. Using object deserialization
	Object deserialization is nothing but creating an object from its 
	serialized form. ObjectInputStream inStream = new 
	ObjectInputStream(anInputStream ); MyObject object = (MyObject) 
	inStream.readObject(); 
	5. Anonymous class ?
	6. Copy or assign?
		A a = b;
How many ways to create an object or initantiate in C++?
	A *a = new A;	//create on heap
	A b;			//create on stack
	// E:\Ctest\TestCode4.cpp
	// 12:49 PM 6/17/2014

	#include <iostream>
	using namespace std;
	class A { 
	public: 
		static int i;
		// int i;
		A() { cout << "A()" << endl;}; 
		A(int x) { i=x; cout << "A( int x)" << endl;}; 
	}; 
	int A::i;  		//static define a outside class ***
	int main() { 
		A *aa = new A(1); 		//ctors with parameter
		cout << "a.i =" << (*aa).i << endl;  //need bracket since () is higher *
		cout << "a.i =" <<  aa->i << endl;
		// A b();   //fail run function without A b; is ctors
		A a;
		A b (4);	//ctors
		A c (5);
		cout << "b.i =" << b.i << endl;
		cout << "a.i =" << a.i << endl;
	}
Is it possible to overload a constructor?
	Yes. When an object is created or defined, a constructor method is 
	created. It is used to initializations of the different declared member 
	variables of its object. Overloading a constructor means make it behave 
	differently. 
	Example:
	The function below has the same name but overloaded to return double and integer values.
	double func( double a );
	int func( int a, int b );
How should a constructor handle a failure?
	Constructors don't have a return type, so it's not possible to use return codes. 
	The best way to signal constructor failure is therefore to throw an exception. 
Why is Base class virtual
	When derived class from 2 base classes can have 2 objects by put virtual on base class
	we now have only one object
What is virtual destructors? 
		The explicit destroying of object with the use of delete operator to a 
	base class pointer to the object is performed by the destructor of the 
	base-class is invoked on that object. The above process can be 
	simplified by declaring a virtual base class destructor. All the derived 
	class destructors are made virtual in spite of having the same name as 
	the base class destructor. In case the object in the hierarchy is 
	destroyed explicitly by using delete operator to the base class pointer 
	to a derived object, the appropriate destructor will be invoked Virtual 
	constructor: No virtual ctors. A constructor of a class can not be 
	virtual and if causes a syntax error. No object is created 
Explain default constructor. What is a default constructor?
	Default constructor is the constructor with no arguments or all the arguments 
	has default values. A constructor that has no argument is a default constructor. 
What is copy constructor?
	A copy constructor is a special type of constructor that is used to create an 
	object as a copy of an existing object. It takes an argument which is a 
	reference to the object to be copied. 
	Line( const Line &obj); // copy constructor 
Define private, protected and public access control.
	Private
	A member (either data member or member function) declared in a private 
	section of a class can only be accessed by member functions and friends of 
	that class. 
	Protected
	A member (either data member or member function) declared in a protected 
	section of a class can only be accessed by member functions and friends 
	of that class, and by member functions and friends of derived classes 
	Public 
	A member (either data member or member function) declared in a public 
	section of a class can be accessed by anyone 
What is private, public and protected Inheritance? 
	private inheritance: 
	all the public and protected members in base become private. 
	protected inheritance: 
	all the public and protected members in base class become protected. 
	public inheritance: 
	in case of public inheritance, public remains public and protected remains 
	protected.. 
What are the advantages of inheritance?
    Allows the code to be reused as many times as needed. The base class 
	once defined and once it is compiled, it need not be reworked. Saves 
	time and effort as the main code need not be written again. 
What are the different types of Inheritance?
    Single Inheritance
    A (parent class) -> B (child class)
    Multiple Inheritance
    A -> C, B -> C
    Hierarchical inheritance
    A -> B, A -> C, A -> D
    Multilevel inheritance
    A -> B, B -> C
    Hybrid inheritance
    A -> B, A -> C, B -> D, C -> D.
What is a concrete derived class?  
	The derived class that implements the missing functionality of an abstract 
	class is the concrete derived class. This is to say, it provides all 
	missing functionalities of the abstract class.
Explain the problem with overriding functions
	Overriding of functions occurs in Inheritance. A derived class may 
	override a base class member function. In overriding, the function names 
	and parameter list are same in both the functions. Depending upon the 
	caller object, proper function is invoked. 
	Consider following sample code:
	//home/tovantran/Ctest/Function_Override.cpp --> 2014-06-18 by ./.tv  owner: tovantran
	#include <iostream>
	using std::cout;
	using std::endl;

	class A { 
		int a; 
		public: 
		A() { a = 10; } 
		int show() { cout << "A::a " << a << endl; return 0;} 
		int show1() { cout << "A::a " << a << endl; return 0;}
	}; 
	class B: public A { 
		int b; 
		public: 
		B() { b = 20; } 
		int show() 
		{ cout <<"B::b "<< b << endl; return 1;} 
	}; 

	int main() { 
		A ob1; 
		B ob2; 
		ob2.show(); // calls derived class show() function. o/p is 20 
		ob1.show();
	// B *pA = (B *)&ob1;     //cast from A into B
	
	 B *pA = &ob2; 		  // will call derived class because B *pa
	// B *pA = (B *)&ob1;     // will call derived class because B *pa
	//  A *pA = &ob2;          // will call base class because A *pa
	//	A *pA = &ob1;          // will call base class because A *pa
		cout << pA->show() << endl;  //cannot access base member function
		cout << pA->show1() << endl;
		return 0; 
	}  
	As seen above, the derived class functions override base class 
	functions. The problem with this is, the derived class objects can not 
	access base class member functions which are overridden in derived 
	class. (Should not have virtual function when call function override base class)
	Base class pointer can point to derived class objects; but it has access 
	only to base members of that derived class. 
	Therefore, pA = &ob2; is allowed. But pa->show() will call Base class 
	show() function and o/p would be 10. 
What is Polymorphism? from IBM
	Polymorphic functions are functions that you can apply to objects of more than one type. 
	C++ implements polymorphic functions in two ways: 
	Overloaded functions are STATICALLY bound at compile time, as discussed in 
	Overloading Functions. 
	C++ provides virtual functions. A virtual function is a function that 
	you can call for a number of different user-defined types that are 
	related through derivation. Virtual functions are bound DYNAMICALLY at 
	run time. 
What is Private virtual method in C++ ?
	Yes, private virtual functions can be overridden in the derived classes.
	Methods of derived classes can't call virtual functions from the base class, 
	but they can provide their own implementation for them
What are static and dynamic type checking?
	Static type checking performs the type checking operation before the 
	execution of the program. To perform this operation, the arguments, 
	expressions, variables must be given a data type. 

	Dynamic type checking performs the type checking operation at the time 
	of the program execution. To perform this operation, the arguments, 
	expressions, variables must be given a data type 
Is there any reason for private virtual functions?
    http://www.gotw.ca/publications/mill18.htm
	I am asking what the reasons it seems logical to have the point of virtual
	function is to be overriden in the derived class but the derived class cannot 
	touch anything that is private in the base class.
	You use private virtual function when you don't want anyone(including
	derived classes) to call the function directly (which should be most of the time
	in a good flexible design). You might use them when implementing the
	"Template Method" pattern. To ensure that the virtual function is always
	called through the wrapper class and not directly you make it private.
	Some people recommand that virtual functions should be private by default and
	only protected and public if you have a good reason.
	// To override a virtual function, it is not necessary to have access to it.
	#include <iostream>
	using namespace std;
	class Base
	{
	public:
		void Print()				//wrapper wrap private virtual into public
		{
			PrintImplementation();
		}
	private:
		virtual void PrintImplementation()  //private virtual function
		{
			cout << "Base\n";
		}
	};

	class Derived : public Base
	{
	private:
		virtual void PrintImplementation()  //private virtual function
		{
			cout << "Derived\n";
		}
	};
	int main()
	{
		Base b;
		Derived d;
		Base * ptr0 = &b;
		Base * ptr1 = &d;
		ptr0->Print();
		ptr1->Print();
		return 0;
	}
	http://bytes.com/topic/c/answers/507241-there-any-reason-private-virtual-functions
	You can also have the public non-virtual function call multiple virtual
	functions and derived classes can be selective in what they override.
What is This?
	This refers to address of current object is pointing to.
	// /E:\Ctest\This.cpp 10:27 AM 6/20/2014
	// javavids JAVA OOPS Constructors
	#include <iostream>
	using namespace std;
	class A{
		int i;
		public:
		void seti(int i) { this->i = i;} //this prefer to A obj in Java this.i = i;
		int geti() { return i;}			 // Java has no pointer 
	};

	int main() {
		A obj;
		obj.seti(10);
		cout << obj.geti() << endl;
		return 0;
	}
	// https://www.youtube.com/watch?v=WFqqX0MMn-w
	// C++ Tutorial 26: The this keyword. 
	// In C++ make more sense if it is a pointer as below to use ->
	// #include <iostream>
	// using namespace std;
	// class A{
		// int i;
		// public:
		// void seti(int i) { this->i = i;} //this prefer to A obj in java this.i = i;
		// int geti() { return i;}
	// };

	// int main() {
		// A ob;
		// A *p = &ob;
		// p->seti(10);
		// cout << p->geti() << endl;
		// return 0;
	// }
	// Output: 10
Member initialize class? this->reference = i only when it has value no value reference(1)
	// /E:\Ctest\MemberInitilize.cpp 10:54 AM 6/20/2014
	// http://www-h.eng.cam.ac.uk/help/tpl/languages/C++/constructors.html
	#include <iostream>
	using namespace std;
	class A {
	public: 
		int i; 
		int& reference; 
		// A(){ reference=i; }; //error: uninitialized reference member 'A::reference'
								// do this way if pass value int reference
		A( ) : reference(i){ }; // do this way if pass reference int &reference
	};
	int main() {
		A a; 
	}
	// But it won't compile, because you can't create a reference without it 
	// having a value. This is a situation where you need to use a "Member 
	// initializer list". the body of the constructor code does nothing, but 
	// the :reference(i) part ensures that the correct constructor for 
	// reference is used, one provided by the compiler that takes an argument 
	// used to initialise the reference.
What is the difference malloc and new ?
    Malloc taking the size as parameter while new calculate automatically.
    Malloc returning void pointer while new already typecast it as specified type.
    Malloc don’t called constructor while new called constructor on the raw memory.
    Malloc can return NULL but new never, it throw exception bad_malloc.
// allocate memory for an array
	char *ch = (char*)malloc( sizeof(char) * 10 );
	char *ch1= new char[10];
What is the difference between free and delete?
    Free de- allocates the memory.
    Delete first check with NULL, then called destructor at end de-allocates the memory.
    Call free with NULL pointer will crash the application while delete don’t.
    Delete is checking NULL condition then de-allocates the memory.
Data structure  - Explain quick sort and merge sort algorithms. 
    Quick sort – Divides the array elements in two halves or partitions. On dividing, 
    the quick sort procedure is recursively called to sort the two halves. 
    A “pivot” is used as the center point and elements less than the pivot 
    are moved to the left or before the pivot and elements greater than pivot 
    are moved to the right.

    Merge sort- Merge sort is based on divide and conquer mechanism. 
    The array elements are divided into partitions (n/2). 
    Each partition is sorted recursively and then merged.
What is a Wrapper class?  
  Wrapper classes wrap primitive values in a class and offers utility to 
  access them through objects. Some of the primitive wrapper data types are:
  Byte, short, int, long, float, double, char, Boolean.
What is Functor?
  A functor is pretty much just a class which defines the operator().
  class Functor{
	int x;
	public:
	int operator() (int x) { return ++x; };
	};
	int function(int x) { return ++x;};
	
	int main(){
	Functor obj;
	 cout << obj(2) << endl; //object
	 //obj.operator()(2) == obj(2)
	 cout << obj.operator()(2) << endl;
	 cout << function(5) << endl; //function
	 }
What is the different between copy ctor vs. assign operator = ?
	Copy constructor is called when a new object is created from an existing object, as a copy 
	of the existing object (see this G-Fact). And assignment operator is called when an already
	initialized object is assigned a new value from another existing object.
	 t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
	 Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);" 
	 // http://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/
	#include <iostream>
	#include <stdio.h>
	using namespace std;

	class Test
	{
	public:
		Test(){}
		Test(const Test &t)
		{
		    cout << "Copy Ctor" << endl;
		}
		Test& operator = (const Test &t)
		{
		    cout << "Assign opertor" << endl;
		}
	};

	int main()
	{
		  Test t1, t2;
		  t2 = t1;        //assign
		  Test t3 = t1;   //copy
		  return 0;
	}
What is interface in C++
	An interface class is a class that has no members variables, and where all of the functions are pure virtual! In other words, the class is purely a definition, and has no actual 
	implementation. Interfaces are useful when you want to define the functionality that derived 	
	classes must implement, but leave the details of how the derived class implements that 
	functionality entirely up to the derived class.

What is pure virtual destructor
	Class has pure virtual destructor is also called Abstract class
	virtual ~Base()=0; // Pure virtual destructor

class IErrorLog
{
    virtual bool OpenLog(const char *strFilename) = 0;
    virtual bool CloseLog() = 0;
    virtual bool WriteError(const char *strErrorMessage) = 0;
};
Explicit vs. implicit
	int nValue = 5; // explicit assignment
	double dValue(4.7); // implicit assignment
	explicit Foo(int n) { m_n = n; } //not allow
	Foo bar1(10);
	Foo bar2 = 20;  //error if explicit in ctor
	
what is concept of copy elision?
http://qa.geeksforgeeks.org/1816/what-is-concept-of-copy-elision

what is object slicing?

Virtual Dtor vs. Pure Virtual Dtor ? p.723 Thinking in C++
	they would prevent the instantiation of the base class if there
	are not pure virtual function it is not important

 virtual destructor ? 
 virtual ~B()

pointer vs. reference
	pointer can change, reference cannot change after assignment
	pointer can null, reference cannot be null

c++ noexcept
	ability to throw an exception

call virtual function inside constructor?

Shadow parameter Shadow memory Shadow RAM
	If you dont ask yourself then interviews will ask you

C++ memcpy() vs std::copy() vs. strcpy()
	char s[5] = {'a', 'b', '\0', 'c', 'd'};
	char membuf[5];
	char strbuf[5];
	strcpy(strbuf, s);
	memcpy(membuf, s , 5);
	char membuf = "abcd";
	char strbuf = "ab";
	
Big vs. Little Endian

Race condition

Interleave - pre-empted

Does C++ pass objects by value or reference?

C++: Reasons for passing objects by value. Reference and value.

How to clone a thread in Linux

The difference between fork(), vfork(), exec() and clone()
//http://stackoverflow.com/questions/4856255/the-difference-between-fork-vfork-exec-and-clone
clone (csbu book) and code July12CloneThread.
	In the kernel, fork is actually implemented by a clone system call. This clone interfaces effectively
	provides a level of abstraction in how the Linux kernel can create processes.
	clone allows you to explicitly specify which parts of the new process are copied into the new process,
	and which parts are shared between the two processes. This may seem a bit strange at first, but allows us
	to easily implement threads with one very simple interface. Clone child has the same PID different TID.
	clone returns 21826
	parent: 21825 21825 (TID, PID)
	thread: 21826 21825
Calling fork (Linux Adv Programming)
	When a program calls fork, a duplicate process, called the child process, is created.The
	parent process continues executing the program from the point that fork was called.
	The child process, too, executes the same program from the same place.
	To spawn a new process, you first use fork to make a copy of the current process.
	Then you use exec to transform one of these processes into an instance of the program you want to spawn.
