

/*代码已按照要求实现了题目中所有功能*/


#include"Club.h"


/* --------------------------------------- SportClub接口定义 --------------------------------------- */
void SportClub::displayClubInfo() const
{
	cout << "------------------------- SportClub info begin -------------------------" << endl;
	string interest = __interest == Running ? "Running" : "Swimming";
	cout << "interest: " << interest << endl;
	cout << "coach: " << __coach << endl;
	this->displayMembers();
	this->displayActivities();
	cout << "------------------------- SportClub info end -------------------------" << endl;
}
void SportClub::displayMembers() const
{
	for (const auto& e : this->__members)
	{
		//type(e) --> shared_ptr<Person>
		//cout << *e << endl;
		//换一种方式打印 -- 直接传指针给函数
		DisplayPersonInfo(e);
	}
}
void SportClub::displayActivities() const
{
	for (const auto& e : this->__acivities)
	{
		//type(e) --> shared_ptr<Activity>
		cout << *e << endl;
	}
}
void SportClub::addMember(const Person& p)
{
	shared_ptr<Person>ptr(new Person(p));//拷贝构造一个，去掉const属性
	this->__members.insert(ptr);
}
void SportClub::addActivity(const Activity& a)
{
	shared_ptr<Activity>ptr(new Activity(a));
	this->__acivities.insert(ptr);
}



/* --------------------------------------- MusicClub接口定义 --------------------------------------- */
void MusicClub::displayClubInfo() const
{
	cout << "------------------------- MusicClub info begin -------------------------" << endl;
	string instrument = __instrument == Piano ? "Piano" : "Violine";
	cout << "instrument: " << instrument << endl;
	this->displayMembers();
	this->displayActivities();
	cout << "------------------------- MusicClub info end -------------------------" << endl;
}
void MusicClub::displayMembers() const 
{
	for (const auto& e : this->__members)
	{
		//type(e) --> shared_ptr<Person>
		DisplayPersonInfo(e);//换一种方式打印
	}
}
void MusicClub::displayActivities() const 
{
	for (const auto& e : this->__acivities)
	{
		//type(e) --> shared_ptr<Activity>
		cout << *e << endl;
	}
}
void MusicClub::addMember(const Person& p) 
{
	shared_ptr<Person>ptr(new Person(p));//拷贝构造一个，去掉const属性
	this->__members.insert(ptr);
}
void MusicClub::addActivity(const Activity& a) 
{
	shared_ptr<Activity>ptr(new Activity(a));
	this->__acivities.insert(ptr);
}




/* --------------------------------------- ClubCenter接口定义 --------------------------------------- */
void ClubCenter::addClub(shared_ptr<Club>& cb)
{
	this->__clubs.push_back(cb);
}
void ClubCenter::traverse()
{
	for (const auto& e : __clubs)
	{
		//先判断是什么类型的club
		//e的类型是shared_ptr<Club>
		shared_ptr<SportClub>ptrSport = dynamic_pointer_cast<SportClub>(e);
		shared_ptr<MusicClub>ptrMusic = dynamic_pointer_cast<MusicClub>(e);
		assert(!(ptrSport == nullptr && ptrMusic == nullptr));
		if (ptrSport != nullptr)
		{
			//是一个SportClub
			//打印SportClub信息
			ptrSport->displayClubInfo();
		}
		else if (ptrMusic != nullptr)
		{
			//是一个MusicClub
			//打印MusicClub信息
			ptrMusic->displayClubInfo();
		}
	}
}

/* --------------------------------------- 其它功能接口定义 --------------------------------------- */
void DisplayPersonInfo(const shared_ptr<Person>& ptr)
{
	shared_ptr<const Student>ptr_to_student = dynamic_pointer_cast<const Student>(ptr);
	if (ptr_to_student == nullptr)
	{
		cout << "----------- Person ----------" << endl;
		//说明是Person
		cout << "id: " << ptr->__id << endl;
		cout << "name: " << ptr->__name << endl;
	}
	else
	{
		cout << "----------- Student ----------" << endl;
		cout << "id: " << ptr_to_student->__id << endl;
		cout << "name: " << ptr_to_student->__name << endl;
		cout << "schoolName: " << ptr_to_student->__schoolName << endl;
		cout << "discountRate: " << ptr_to_student->__discountRate << endl;
	}
}