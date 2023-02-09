#pragma once
#include "main.h"

//class��
const double PI = 3.14;
class Circle {

public:
	//˽�г�Ա���Կ���ͨ��get��set���������������ж�д����
	void setC_r(double c_r)
	{
		//ͨ��this�ؼ��ֻ�ȡ����
		this->c_r = c_r;
	}
	double getC_r()
	{
		return this->c_r;
	}
	//����
	//����Բ�����
	double clcCircleS() 
	{
		return PI * c_r * c_r;
	}
private:
	//����
	double c_r;
};

void testClass_Circle(void);


//���캯�� ��������
class Func {
public:
	//�޲ι���
	Func(){
		cout << "�޲ι���" << endl;
	}
	//�вι���
	Func(string name,int age){
		this->name = name;
		this->age = age;
		cout << this->name << this->age << endl;
	}
	//��������
	Func(const Func& f){
		cout << "ǳ��������" << endl;
		this->name = f.name;
		this->age = f.age;
		cout << this->name << this->age << endl;
	}
	~Func()
	{
		cout << "��������" << endl;
	}
private:
	/*string name = "NULL : ";
	int age = 0;*/
	string name;
	int age;
};
void testClass_StructFunc(void);

//ǳ���� ���
/*
*	ǳ�������򵥸�ֵ����
*	������ڶ�����������ռ䣬���п������������Խ��ǳ�����ظ��ͷŶ���������
* 
*/
class Func1
{
public:
	//�޲ι���
	Func1() {
		cout << "�޲ι���" << endl;
	}
	//�вι���
	Func1(string name, int age) {
		this->name = name;
		this->age = new int(age);
		cout << "�вι���" << endl;
	}
	//��������
	Func1(const Func1 & f) {
		this->name = f.name;
		cout << "�������" << endl;
		this->age = new int(*f.age);
	}
	~Func1()
	{
		cout << "��������" << endl;
		if (age != NULL) {
			delete age;
		}
	}
public:
	string name;
	int *age;
};
void testClass_Copy(void);
