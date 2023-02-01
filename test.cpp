
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include"Club.h"

/*代码已按照要求实现了题目中所有功能*/


#if 0
class A
{
public:
	virtual void f()
	{
		cout << "A::f()" << endl;
	}
	int _a;
};
class B :public A
{
public:
	virtual void f()
	{
		cout << "B::f()" << endl;
	}
	int _b;
};
int main()
{
	shared_ptr<A>ptr1(new A);
	shared_ptr<A>ptr2(new B);
	shared_ptr<B>ptrB = dynamic_pointer_cast<B>(ptr2);
	if (ptrB == nullptr)
	{
		cout << "转换失败" << endl;
	}
	else
	{
		cout << typeid(*ptrB).name() << endl;
		cout << "转换成功" << endl;
	}
	cout << endl;
	return 0;
}
#endif

void test_deep_copy()
{
	cout << " ---------------------- 测试深拷贝 ---------------------- " << endl;
	string SportClubName1 = "Running";
	set<shared_ptr<Person>> SportClubmembers1 =
	{
		shared_ptr<Person>(new Person("123","Jack"))
		,shared_ptr<Person>(new Student("122","Sam","SYSU",0.8))
		,shared_ptr<Person>(new Student("121","Yes","SYSU",0.2))
	};
	set<shared_ptr<Person>>ActivityMembers1 = { shared_ptr<Person>(new Person("124","Jacy")) };
	set<shared_ptr<Activity>>SportClubAcivities1 = {
		shared_ptr<Activity>(new Activity(Date(2022,1,1),"Guangzhou","play running games", ActivityMembers1))
	};
	SportType interest1 = Running;
	string coach1 = "Coach Li";
	shared_ptr<SportClub>ptr1(new SportClub(SportClubName1, SportClubmembers1, SportClubAcivities1, interest1, coach1));


	shared_ptr<Club>ptr_copy(new SportClub(*ptr1));
	ptr_copy->displayClubInfo();
	cout << endl << endl << endl;
}
int main()
{
	/*
	SportClub(string name, set<shared_ptr<Person>>members, set<shared_ptr<Activity>>acivities,
		SportType interest, string coach)
	*/
	test_deep_copy();

	// -------------------------------------------- 定义第一个SportClub对象 ----------------------------------------------
	string SportClubName1 = "Running";
	set<shared_ptr<Person>> SportClubmembers1 =
	{
		shared_ptr<Person>(new Person("123","Jack"))
		,shared_ptr<Person>(new Student("122","Sam","SYSU",0.8))
		,shared_ptr<Person>(new Student("121","Yes","SYSU",0.2))
	};
	set<shared_ptr<Person>>ActivityMembers1 = { shared_ptr<Person>(new Person("124","Jacy")) };
	set<shared_ptr<Activity>>SportClubAcivities1 = {
		shared_ptr<Activity>(new Activity(Date(2022,1,1),"Guangzhou","play running games", ActivityMembers1))
	};
	SportType interest1 = Running;
	string coach1 = "Coach Li";
	shared_ptr<Club>ptr1(new SportClub(SportClubName1, SportClubmembers1, SportClubAcivities1, interest1, coach1));


	// -------------------------------------------- 定义第二个SportClub对象 ----------------------------------------------
	string SportClubName2 = "Swimming";
	set<shared_ptr<Person>> SportClubmembers2 =
	{
		shared_ptr<Person>(new Person("123","Jack"))
		,shared_ptr<Person>(new Student("129","Lucy","SYSU",0.77))
		,shared_ptr<Person>(new Student("120","Mendy","SYSU",0.2))
	};
	set<shared_ptr<Person>>ActivityMembers2 = { shared_ptr<Person>(new Person("134","Cat")) };
	set<shared_ptr<Activity>>SportClubAcivities2 = {
		shared_ptr<Activity>(new Activity(Date(2022,1,1),"BeiJing","play swimming games", ActivityMembers2))
	};
	SportType interest2 = Swimming;
	string coach2 = "Coach Wang";
	shared_ptr<Club>ptr2(new SportClub(SportClubName2, SportClubmembers2, SportClubAcivities2, interest2, coach2));

	// -------------------------------------------- 定义第1个MusicClub对象 ----------------------------------------------
	string MusicClubName1 = "Piano";
	set<shared_ptr<Person>> MusicClubmembers1 =
	{
		shared_ptr<Person>(new Person("131","Judy"))
		,shared_ptr<Person>(new Student("139","Cindy","SYSU",0.69))
		,shared_ptr<Person>(new Student("140","Zoo","SYSU",0.88))
	};
	set<shared_ptr<Person>>ActivityMembers3 = { shared_ptr<Person>(new Person("131","Judy")) };
	set<shared_ptr<Activity>>MusicClubAcivities1 = {
		shared_ptr<Activity>(new Activity(Date(2022,1,1),"BeiJing","play Piano", ActivityMembers3))
	};
	InstrumentType interest3 = Piano;
	shared_ptr<Club>ptr3(new MusicClub(MusicClubName1, MusicClubmembers1, MusicClubAcivities1, interest3));

	// -------------------------------------------- 定义第2个MusicClub对象 ----------------------------------------------
	string MusicClubName2 = "Violine";
	set<shared_ptr<Person>> MusicClubmembers2 =
	{
		shared_ptr<Person>(new Person("151","Oran"))
		,shared_ptr<Person>(new Student("156","Kindy","SYSU",0.66))
		,shared_ptr<Person>(new Student("154","Zoody","SYSU",0.58))
	};
	set<shared_ptr<Person>>ActivityMembers4 = { shared_ptr<Person>(new Person("151","Oran")) };
	set<shared_ptr<Activity>>MusicClubAcivities2 = {
		shared_ptr<Activity>(new Activity(Date(2022,1,1),"Shanghai","play Violine", ActivityMembers4))
	};
	InstrumentType interest4 = Violine;
	shared_ptr<Club>ptr4(new MusicClub(MusicClubName2, MusicClubmembers2, MusicClubAcivities2, interest4));

	vector<shared_ptr<Club>> arr = { ptr1,ptr2,ptr3 };
	cout << " ============================= 添加三个Club对象进去 ============================= " << endl;
	ClubCenter ccenter(arr);
	cout << " ============================= 调用traverse() ============================= " << endl;
	ccenter.traverse();
	cout << " =============================== 新增一个Club对象 =============================== " << endl;
	ccenter.addClub(ptr4);
	cout << " ============================= 调用traverse() ============================= " << endl;
	ccenter.traverse();
	return 0;
}