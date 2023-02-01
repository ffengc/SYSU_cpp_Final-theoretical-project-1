#pragma once

#include<string>
#include<unordered_map>
#include<functional>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



/*代码已按照要求实现了题目中所有功能*/


class Person
{
protected:
	string __id;
	string __name;
public:
	friend void DisplayPersonInfo(const shared_ptr<Person>& ptr);
	virtual void f() { ; }
public:
	Person(string id = "", string name = "")
		:__id(id), __name(name) {}
	Person(const Person&) = default;
	~Person() = default;
};

class Student :public Person
{
protected:
	string __schoolName;
	double __discountRate;
public:
	friend void DisplayPersonInfo(const shared_ptr<Person>& ptr);
public:
	Student(string id = "", string name = "", string schoolName = "", double discountRate = 0)
		:Person(id, name), __schoolName(schoolName), __discountRate(discountRate) {}
	Student(const Student&) = default;
	~Student() = default;
};

