#pragma once

#include<string>
#include<unordered_map>
#include<functional>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

#include"Person.h"

/*代码已按照要求实现了题目中所有功能*/


class Date
{
protected:
	int __year;
	int __month;
	int __day;
public:
	friend ostream& operator<<(ostream& out, const Date& d)
	{
		out << d.__year << "/" << d.__month << "/" << d.__day << endl;
		return out;
	}
public:
	Date(int year = 0, int month = 0, int day = 0)
		:__year(year), __month(month), __day(day) {}
	Date(const Date& d) = default;
	~Date() = default;
};

class Activity
{
protected:
	Date __date;
	string __place;
	string __activity;
	set<shared_ptr<Person>>__members;
public:
	Activity(Date date, string place, string activity, set<shared_ptr<Person>> members)
		:__date(date), __place(place), __activity(activity), __members(members) {}
	Activity(const Activity&) = default;
	~Activity() = default;
public:
	friend ostream& operator<<(ostream& out, const Activity& a)
	{
		out << "------------------ Activity info -------------------" << endl;
		out << "Date: " << a.__date << endl;
		out << "place: " << a.__place << endl;
		out << "activity: " << a.__activity << endl;
		out << "-------------- Person info ---------------" << endl;
		for (const auto& e : a.__members)
		{
			DisplayPersonInfo(e);
		}
		out << endl;
		return out;
	}
};