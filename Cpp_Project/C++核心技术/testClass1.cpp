#include "testClass.h"

void testClass_Circle(void)
{
	//����Բ�Ķ���c
	Circle c;
	//ͨ������c���ú���
	c.setC_r(2);
	//����������ȡ�뾶�����
	cout << "�԰뾶Ϊ��"<< c.getC_r() <<" ��" << "Բ�����Ϊ��" << c.clcCircleS() << endl;
}

void testClass_StructFunc(void)
{
	//�����Ķ���ֻ������޲ι���
	Func f;
	Func("�вι��� ��",1);
	
	//��������
	Func f1 = Func("�������� ��",2);	//�вι��촫ֵ
	Func f2 = f1;	//��������

	Func f3 = f;//��������	//NULL : 0 / �����������ʱδ����ʼֵ�����ص�ַ
}

//��������
void testClass_Copy(void)
{
	Func1 f1("��������: ",11);
	Func1 f2(f1);
	cout << f1.name << *f1.age << endl;
	cout << f2.name << *f2.age << endl;
}
//*****************************
//********	thisָ��ĸ���		*
//*****************************
void test_ClassThis(void)
{
	ClassThis c1(18);
	cout << "c1.age = " << c1.age << endl; //18

	ClassThis c2(24);
	//����
	c2.ClassThisFunction(c1).ClassThisFunction(c1);
	cout << "c2.age = " << c2.age << endl;//60
}

/*
*	��ָ����ʳ�Ա����
*	ע������õ�thisָ�룬��Ҫ�����жϣ���֤����Ľ�׳��
*
*/
void test_Null_Point(void)
{
	Null_Point* pNull = NULL;
	pNull->ShowComm();

	pNull->ShowAdvance();
}

/*
* const���γ�Ա����:��������	������ ������
* ʹ��const����
*/
void test_ConstObject(void)
{
	//const���εĶ���Ϊ ������
	const ConstObject constObject;
	//constObject.m_AA = 2; //���������޸ĳ�Ա������ֵ,���ǿ��Է���
	cout << constObject.m_AA << endl;

	//mutable int m_BB; //mutable ���εĿɱ�
	constObject.m_BB = 2;
	cout << constObject.m_BB << endl;

	//������ֻ�ܵ��ó�����
	//constObject.Show2();//����
	constObject.Show();
	cout << constObject.m_BB << endl;

}

/*
*	��Ԫ
*/

static void Global_Firend(Friend_Object* fPtr)
{
	cout << "�����ѷ��ʣ�" << fPtr->phone << endl;
	cout << "�����ѷ��ʣ�" << fPtr->bank_card << endl;
}
void Global_Firend_Test(void)
{
	Friend_Object fPtr1;
	Global_Firend(&fPtr1);
}

/*
*	��-��Ԫ
*/
//����д��Ա����ʵ��
In_Friend::In_Friend()
{
	this->bank_card = "123456";
	this->phone = "iPhone14Pro";
}
OutFriend::OutFriend()
{
	inFriend = new In_Friend;
}

void OutFriend::find()
{
	cout << "��-�����ѷ��ʣ�" << inFriend->phone << endl;
	//���Ҫ���ʣ�������������Ϊ��Ԫ
	//cout << "��-�����ѷ��ʣ�" << inFriend->bank_card << endl;
}
void OutFriend::find2()
{
	cout << "��Ա����--�����ѷ��ʣ�" << inFriend->phone << endl;
	//���Ҫ���ʣ����������ó�Ա����Ϊ��Ԫ
	//cout << "��Ա����--�����ѷ��ʣ�" << inFriend->bank_card << endl;
}
void Class_Freind_Test(void)
{
	OutFriend of;
	of.find();
	of.find2();
}

/*
* �̳�
*/
void Inherit_test(void)
{
	CPP cpp;
	cpp.info();
	cpp.head();
	cpp.central();
	cpp.tail();
	
	C c;
	c.info();
	c.head();
	c.central();
	c.tail();
}
/*
*	�Ӹ���ͬ����Ա	����/����	�ļ̳�
*	��η��ʣ�
*	������ʱ����ֱ�ӷ���
*	������ʸ���� ����/���� ��Ҫ ���븸��������
*/
void Inherit_test1(void)
{
	CPP cpp;
	//ֱ�ӷ��ʣ����ʵ��������еĳ�Ա ����/����
	cout << "CPP���У�	CPP Study" << cpp.m_name << endl;
	cpp.info();

	//���ʸ����ͬ����Ա ����/����	��Ҫ���븸��������
	cout << "PublicArea���У�CPP Study" << cpp.PublicArea::m_name << endl;
	cpp.PublicArea::info();
}
