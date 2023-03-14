#pragma once
#include "main.h"

//class类
const double PI = 3.14;
class Circle {

public:
	//私有成员属性可以通过get和set函数（方法）进行读写操作
	void setC_r(double c_r)
	{
		//通过this关键字获取属性
		this->c_r = c_r;
	}
	double getC_r()
	{
		return this->c_r;
	}
	//方法
	//计算圆的面积
	double clcCircleS() 
	{
		return PI * c_r * c_r;
	}
private:
	//属性
	double c_r;
};

void testClass_Circle(void);


//构造函数 析构函数
class Func {
public:
	//无参构造
	Func(){
		cout << "无参构造" << endl;
	}
	//有参构造
	Func(string name,int age){
		this->name = name;
		this->age = age;
		cout << this->name << this->age << endl;
	}
	//拷贝构造
	Func(const Func& f){
		cout << "浅拷贝构造" << endl;
		this->name = f.name;
		this->age = f.age;
		cout << this->name << this->age << endl;
	}
	~Func()
	{
		cout << "析构函数" << endl;
	}
private:
	/*string name = "NULL : ";
	int age = 0;*/
	string name;
	int age;
};
void testClass_StructFunc(void);

//浅拷贝 深拷贝
/*
*	浅拷贝：简单赋值操作
*	深拷贝：在堆区重新申请空间，进行拷贝操作：可以解决浅拷贝重复释放堆区的问题
* 
*/
class Func1
{
public:
	//无参构造
	Func1() {
		cout << "无参构造" << endl;
	}
	//有参构造
	Func1(string name, int age) {
		this->name = name;
		this->age = new int(age);
		cout << "有参构造" << endl;
	}
	//拷贝构造
	Func1(const Func1 & f) {
		this->name = f.name;
		cout << "深拷贝构造" << endl;
		this->age = new int(*f.age);
	}
	~Func1()
	{
		cout << "析构函数" << endl;
		if (age != NULL) {
			delete age;
		}
	}
public:
	string name;
	int *age;
};
void testClass_Copy(void);

//*****************************
//********	this指针的概念		*
//*****************************
/*
*	1.当形参和成员变量同名时，可用this指针来区分
*	2.返回对象本身
*/
class ClassThis {
public:
	ClassThis(int age) {
		//1
		this->age = age;
	}
	ClassThis& ClassThisFunction(ClassThis ct) {
		this->age += ct.age;
		//2
		return *this;
	}
	int age;
};
void test_ClassThis(void);


/*
*	空指针访问成员函数
*	但不能访问成员属性
*	注：如果用到this指针，需要加以判断，保证代码的健壮性
* 
*/

class Null_Point {

public:
	void ShowComm() {
		cout << "普通方法" << endl;
	}
	//以下会直接报错
	/*void ShowAdvance() {
		cout << "调用成员："<< this->m_Method << endl;
	}*/
	//改进：
	void ShowAdvance() {
		if (this == NULL) {
			cout << "无法调用成员~~~" << endl;
			return;
		}
		cout << "调用成员：" << this->m_Method << endl;
	}
	int m_Method;
};
void test_Null_Point(void);

/*
* const修饰成员函数:两个概念
* 
* **常函数：**
* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改
*  
* **常对象：**
* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数
*/
class ConstObject {

public:
	
	ConstObject() {
		m_AA = 0;
		m_BB = 0;
	}
	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	////const Type* const pointer;
	//this = NULL; //不能修改指针的指向 Person* const this;
	//this->mA = 100; //但是this指针指向的对象的数据是可以修改的
	void Show() const {
		//加上const后不可修改
		//this->m_AA = 100;//不可修改的左值
		this->m_BB = 101;
	}
	void Show2() {
		m_AA = 5;
	}
	int m_AA;
	mutable int m_BB; //mutable 可变的
};
void test_ConstObject(void);


/*
*	友元
* 全局函数做友元
* 类做友元
* 成员函数做友元
* 
*/
/*	
*	全局函数-友元
*/


class Friend_Object {

	//声明全局函数 为 好朋友(友元)
	friend void Global_Firend(Friend_Object* fPtr);
public:
	Friend_Object()
	{
		this->bank_card = "123456";
		this->phone = "iPhone14Pro";
	}

public:
	string phone;
private:
	//想要访问该成员，必须声明友元 friend
	string bank_card;
};

static void Global_Firend(Friend_Object* fPtr);
void Global_Firend_Test(void);

/*
* 类 -友元
* 外部类做实现-初始化等等
*/

class In_Friend;
class OutFriend {
public:
	//类中做声明，实现在cpp文件中
	OutFriend();
	void find();
	void find2();
	In_Friend* inFriend;
};

class In_Friend {
	//声明类为友元
	friend OutFriend;

	//声明成员函数为友元
	friend void OutFriend::find2();
	
public:
	In_Friend();
public:
	string phone;
private:
	//想要访问该成员，必须声明友元 friend
	string bank_card;
};
void Class_Freind_Test(void);


/*
* 继承
*	使用继承的技术，减少重复代码
*/

class PublicArea {
public:
	PublicArea() {
		this->m_name = "父类";
	}
	void head() {
		cout << "网页	图片	视频	学术" << endl;
	}
	void central() {
		cout << "不一样的内容" << endl;
	}
	void tail() {
		cout << "百度相关搜索" << endl;
	}
	void info() {
		cout << "父类中：CPP Study" << endl;
	}

public:
	string m_name;
};

//继承1
class CPP : public PublicArea
{
public:
	CPP() {
		this->m_name = "子类";
	}
	void info() {
		cout << "子类中：CPP Study" << endl;
	}
public:
	string m_name;
};
//继承2
class C : public PublicArea
{
public:
	void info() {
		cout << "C Study" << endl;
	}
};
void Inherit_test(void);

/*
* 继承 同名成员时，访问需要加::
*/
void Inherit_test1(void);


