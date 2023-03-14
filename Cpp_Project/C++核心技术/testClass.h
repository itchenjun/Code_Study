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

//*****************************
//********	thisָ��ĸ���		*
//*****************************
/*
*	1.���βκͳ�Ա����ͬ��ʱ������thisָ��������
*	2.���ض�����
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
*	��ָ����ʳ�Ա����
*	�����ܷ��ʳ�Ա����
*	ע������õ�thisָ�룬��Ҫ�����жϣ���֤����Ľ�׳��
* 
*/

class Null_Point {

public:
	void ShowComm() {
		cout << "��ͨ����" << endl;
	}
	//���»�ֱ�ӱ���
	/*void ShowAdvance() {
		cout << "���ó�Ա��"<< this->m_Method << endl;
	}*/
	//�Ľ���
	void ShowAdvance() {
		if (this == NULL) {
			cout << "�޷����ó�Ա~~~" << endl;
			return;
		}
		cout << "���ó�Ա��" << this->m_Method << endl;
	}
	int m_Method;
};
void test_Null_Point(void);

/*
* const���γ�Ա����:��������
* 
* **��������**
* ��Ա�������const�����ǳ�Ϊ�������Ϊ**������**
* �������ڲ������޸ĳ�Ա����
* ��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�
*  
* **������**
* ��������ǰ��const�Ƹö���Ϊ������
* ������ֻ�ܵ��ó�����
*/
class ConstObject {

public:
	
	ConstObject() {
		m_AA = 0;
		m_BB = 0;
	}
	//thisָ��ı�����һ��ָ�볣����ָ���ָ�򲻿��޸�
	//�������ָ��ָ���ֵҲ�������޸ģ���Ҫ����������
	////const Type* const pointer;
	//this = NULL; //�����޸�ָ���ָ�� Person* const this;
	//this->mA = 100; //����thisָ��ָ��Ķ���������ǿ����޸ĵ�
	void Show() const {
		//����const�󲻿��޸�
		//this->m_AA = 100;//�����޸ĵ���ֵ
		this->m_BB = 101;
	}
	void Show2() {
		m_AA = 5;
	}
	int m_AA;
	mutable int m_BB; //mutable �ɱ��
};
void test_ConstObject(void);


/*
*	��Ԫ
* ȫ�ֺ�������Ԫ
* ������Ԫ
* ��Ա��������Ԫ
* 
*/
/*	
*	ȫ�ֺ���-��Ԫ
*/


class Friend_Object {

	//����ȫ�ֺ��� Ϊ ������(��Ԫ)
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
	//��Ҫ���ʸó�Ա������������Ԫ friend
	string bank_card;
};

static void Global_Firend(Friend_Object* fPtr);
void Global_Firend_Test(void);

/*
* �� -��Ԫ
* �ⲿ����ʵ��-��ʼ���ȵ�
*/

class In_Friend;
class OutFriend {
public:
	//������������ʵ����cpp�ļ���
	OutFriend();
	void find();
	void find2();
	In_Friend* inFriend;
};

class In_Friend {
	//������Ϊ��Ԫ
	friend OutFriend;

	//������Ա����Ϊ��Ԫ
	friend void OutFriend::find2();
	
public:
	In_Friend();
public:
	string phone;
private:
	//��Ҫ���ʸó�Ա������������Ԫ friend
	string bank_card;
};
void Class_Freind_Test(void);


/*
* �̳�
*	ʹ�ü̳еļ����������ظ�����
*/

class PublicArea {
public:
	PublicArea() {
		this->m_name = "����";
	}
	void head() {
		cout << "��ҳ	ͼƬ	��Ƶ	ѧ��" << endl;
	}
	void central() {
		cout << "��һ��������" << endl;
	}
	void tail() {
		cout << "�ٶ��������" << endl;
	}
	void info() {
		cout << "�����У�CPP Study" << endl;
	}

public:
	string m_name;
};

//�̳�1
class CPP : public PublicArea
{
public:
	CPP() {
		this->m_name = "����";
	}
	void info() {
		cout << "�����У�CPP Study" << endl;
	}
public:
	string m_name;
};
//�̳�2
class C : public PublicArea
{
public:
	void info() {
		cout << "C Study" << endl;
	}
};
void Inherit_test(void);

/*
* �̳� ͬ����Աʱ��������Ҫ��::
*/
void Inherit_test1(void);


