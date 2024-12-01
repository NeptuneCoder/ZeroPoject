#pragma once
#include <string>
class Person
{
public:
    Person();
    Person(int age, const std::string &name);
    ~Person();
    void sayHello();

private:
    int _age;
    const std::string _name;
};