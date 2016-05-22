//Lvalue Rvalue you tube Bo Qian also May20Test.cpp SmartPointer
#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
	int i;
public:
	Base(int i): i(i) { cout << "CTOR" << endl;}
	Base(const Base &b) { cout << "copy CTOR" << endl; } //if copy not create compile create one
	~Base(){ cout << "DTOR " << endl;}
	int getInt() { return i; }
};

                
void obValue (Base o) /*Base o copy by value COPY is made and call DTOR */
{
	cout << "ob Value " << endl;
}
void ob (Base &o)
{
	cout << "ob lvalue ref "  << /*typeid(o).name()*/ o.getInt() << endl;
}
void ob (Base *o)
{
	cout << "ob pointer * "  << /*typeid(o).name()*/ o->getInt() << endl;
}
void ob (Base &&o) 
{ 
	cout << "on rvalue ref && " << o.getInt() << endl;
}
void ob (Base const &o) //rvalue ref const. Base o create a new obj copy CTOR if pass by value. 
						
{
	cout << "ob rvalue ref const " << endl;
}
//overload function based on parameter types lvalue or rvalue but not by value 
void printValue(int i) { cout << "printValue: "<< i << endl; }
void print(int &i) { cout <<"print & lvalue ref:" << i << endl; } //error: invalid initialization of non-const reference of type ‘int&’
void print(int *i) { cout << "print pointer *i: " << *i << endl; }
// 2 statements are the same && or const &
void print(int &&i) { cout <<"print && rvalue ref: " << i << endl; }  //rvalue ref &&
void print(int const &i) { cout <<"print & const rvalue ref: " << i << endl; } //rvalue ref const
//void printValue(int &i){} //call of overloaded ‘printValue(int&)’ is ambiguous printValue(int i)
int main()
{
	int a = 1; //lvalue
	int &b = a; //lvalue reference before reference
	int &&c = 1; //rvalue reference

	printValue(a); //value
	printValue(1); //value
	print(a); //lvalue ref &
	print(&a); //pointer *
	print(1); //rvalue ref &&
	// print(&a); //rvalue ref &&
	{
		 Base *b = new Base(11);
		 Base b1(12);
		      obValue(*b);  //COPY CTOR by value b is address *b is pointer is integer
		 		 	ob(*b);  //ob2(*b)  ob2(b1) / lvalue ref
		 				 ob(b);  //b is address, *b is value  ob1(b) ob1(&b1) / pointer *
		           			ob(12); //Ref
		       obValue(b1);
		       ob(b1);  //lvalue ref
		       ob(&b1); //pointer
		       ob(11); //rvalue ref && /rvalue ref const
		cout << "from main" << endl;
		  delete b;
	} //end of scope DTOR is called if COPY CTOR is called when pass by value
	int i = 1;
	// int &r = i; //OK lvalue assignment 
	//&r = 5; //lvalue required as left operand of assignment
	// int &r = 5; //non-const reference of type int& from an rvalue
	const int &r = 5; //OK const here can initialize using rvalue
	
	int d = 5;  //lvalue is created with 5
	int &temp = d;
	d = temp; //ref e is initilize with temporarily lvalue

	cout << r  << " " << d << endl;

	
}
