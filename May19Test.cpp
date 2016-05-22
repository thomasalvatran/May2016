#include <iostream>
using namespace std;


class Person
{
	const char *m_name;
	int m_age;
public:
	Person(const Person &p) : m_name(p.m_name), m_age(p.m_age) //exactly compile create shallow copy
	{ //when pass by value copy ctor is called
		cout << "Copy CTOR" << endl; 
	} //DTOR is called object is detroyed
	Person() : m_name(0), m_age(0){ cout << "Empty Person CTOR" << endl; } 
	Person(const char *name, int age) : m_name(name), m_age(age){ cout << "PERSON CTOR" << endl;}
	~Person(){ cout << "Person DTOR" << endl; }
	void display() { printf("Person %s %d\n", m_name, m_age );}
	void display(Person p) { cout << "Person obj: " << p.m_name << " " << p.m_age << endl; }

	template<typename T> friend class SP;
};

template <typename T>
class SP : public Person
{
	T *pData; //pointer
	T m_obj; //obj
public:
	SP(T *pValue) : pData(pValue){ cout << "SP CTOR" << endl; }
	SP(const T &obj) : m_obj(obj){} 
	~SP(){ delete pData; cout << "SP DTOR" << endl; }
	T& operator *() { return *pData;}
	T* operator->() { return pData; }
	T /*&*/ getObject() { return m_obj; }
	   /*T&*/ 
	void displaySP() { cout <<"SP() obj: " << m_obj.m_name << " " << m_obj.m_age << endl; }  //m_name is private need friend class
	// void displaySP(T m_obj) { cout << "SP pointer: "<< pData->m_name << " "<< pData->m_age << endl; }
	void displaySPP(/*T &pData*/) { cout << "SPP() pointer: "<< pData->m_name << " "<< pData->m_age << endl; }

	//overload overide
	/*T&*/       /*&*/
	void display(T m_obj)  { cout << "SP display obj: " << m_obj.m_name << " " << m_obj.m_age << endl; }  
	void display(SP<T> &pData) { cout << "SP display pointer: "<< pData->m_name << " "<< pData->m_age << endl;}
	T* get() const { return pData;}
	// void display() { cout << "SP pointer: "<< pData->m_name << " "<< pData->m_age << endl;}
};

int main()
{
	SP<Person> *sp = new SP<Person>(new Person("tom", 12));  //sp pointer of SP<Person> 
	sp->displaySPP();
	sp->display(*sp);
	sp->get()->display();

	SP<Person> p = SP<Person>(new Person("Scott", 25));      //p pointer
	SP<Person> p1(new Person("Thomas", 35));			     // pointer
	p->display();
	p1->display();     //Base
	// p1.displaySPP();	   //override 
	// p1.display(*p1);
	p1.display(*p1);  //*p is value or object
	p1.display(p1);   //pointer

	// p1.displaySPP(p1);
	p1.displaySPP();
	//p1.displaySP(); //FAIL it is a pointer

	SP<Person> obj(Person("Tom", 33));					//object
	obj.display(obj.getObject());
	obj.getObject().display(obj.getObject());
	// obj.display(obj); 
	obj.displaySP(); // OK is is object
	obj.display(obj.getObject());
}


// class Person
// {
// 	const char *p_name;
// 	int m_age;
// public:
// 	Person(): p_name(0), m_age(0) {}
// 	Person(const char *name, int age) : p_name(name), m_age(age) {}
// 	~Person() {} 
// 	void display() { cout << p_name << " " << m_age << endl; }
// };


// class SP 
// {
// 	Person* pData;
// public:
// 	SP(Person *pValue) : pData(pValue){}
// 	~SP() { delete pData; }
// 	Person& operator *() { return *pData; }
// 	Person* operator->() { return  pData; }
// };




// int main()
// {
// 	// Person *p = new Person("Scott", 25);
// 	SP p(new Person("Scott", 25));
// 	p->display();
// }














// class Person
// {
// 	int age;
// 	const char* pName;

// public:
// 	// Person(): pName(0),age(0)
// 	// {
// 	// }
// 	Person(const char* pName, int age): pName(pName), age(age)
// 	{
// 	}
// 	~Person()
// 	{
// 	}

// 	void Display()
// 	{
// 		printf("Name = %s Age = %d \n", pName, age);
// 	}
// 	void Shout()
// 	{
// 		printf("Ooooooooooooooooo\n");
// 	} 
// };

// template < typename T > class SP
// {
// private:
//     T*    pData; // Generic pointer to be stored
// public:
// 	SP(T* pValue) : pData(pValue)
// 	{
// 	}
// 	~SP()
// 	{
// 		delete pData;
// 	}

// 	T& operator* ()
// 	{
// 		return *pData;
// 	}

// 	T* operator-> ()
// 	{
// 		return pData;
// 	}
// };

// int main()
// {
// 	SP<Person> p(new Person("Scott", 25));
// 	p->Display();
//     // Dont need to delete Person pointer..
// }