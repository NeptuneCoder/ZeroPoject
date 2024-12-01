#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
Person::Person() : _name("unknown"), _age(0)
{
}

// Person(int age, char *name);
Person::Person(int age, const std::string &name) : _age(age), _name(name)
{
}

void Person::sayHello()
{
    cout << "Hello, my name is " << _name << " and I am " << _age << " years old." << endl;
}
Person::~Person()
{

    // TODO Auto-generated destructor stub
    cout << "Person destructor called." << endl;
}
