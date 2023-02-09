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
