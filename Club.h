#pragma once

/*代码已按照要求实现了题目中所有功能*/


/*全部采用了智能指针 -- 因此析构函数不用自己定义*/
/*拷贝构造会调用自己的拷贝构造 -- 因此拷贝构造可以用默认的*/

#include<initializer_list>
#include<assert.h>
#include"Date.h"

enum SportType
{
	Running, Swimming
};
enum InstrumentType
{
	Piano, Violine
};

class Club
{
protected:
	string __name;
	set<shared_ptr<Person>>__members;
	set<shared_ptr<Activity>>__acivities;
public:
	virtual void displayMembers()const = 0;
	virtual void displayActivities()const = 0;
	virtual void addMember(const Person& p) = 0;
	virtual void addActivity(const Activity& a) = 0;
	virtual void displayClubInfo() const = 0;//打印Club信息
public:
	Club(string name, set<shared_ptr<Person>>members, set<shared_ptr<Activity>>acivities)
		:__name(name), __members(members), __acivities(acivities) {}
	Club(const Club&) = default;
	~Club() = default;
};

class SportClub :public Club
{
protected:
	SportType __interest;
	string __coach;
public:
	SportClub(string name, set<shared_ptr<Person>>members, set<shared_ptr<Activity>>acivities,
		SportType interest, string coach)
		:Club(name, members, acivities), __interest(interest), __coach(coach) {}
	SportClub(const SportClub&) = default;
	~SportClub() = default;
public:
	virtual void displayClubInfo() const;//打印Club信息
	virtual void displayMembers() const override;
	virtual void displayActivities() const override;
	virtual void addMember(const Person& p) override;
	virtual void addActivity(const Activity& a) override;
};



class MusicClub :public Club
{
protected:
	InstrumentType __instrument;
public:
	MusicClub(string name, set<shared_ptr<Person>>members, set<shared_ptr<Activity>>acivities,
		InstrumentType instrument)
		:Club(name, members, acivities), __instrument(instrument) {}
	MusicClub(const MusicClub&) = default;
	~MusicClub() = default;
public:
	virtual void displayClubInfo() const;//打印Club信息
	virtual void displayMembers() const override;
	virtual void displayActivities() const override;
	virtual void addMember(const Person& p) override;
	virtual void addActivity(const Activity& a) override;
};


class ClubCenter
{
protected:
	vector<shared_ptr<Club>>__clubs;
public:
	//支持初始化列表构造
	ClubCenter(const initializer_list<shared_ptr<Club>>& list)
	{
		for (const auto& e : list)
		{
			__clubs.push_back(e);
		}
	}
	ClubCenter(const vector<shared_ptr<Club>>clubs)
		:__clubs(clubs) {}
	ClubCenter(const ClubCenter&) = default;
	~ClubCenter() = default;
public:
	void addClub(shared_ptr<Club>& cb);
	void traverse();
};