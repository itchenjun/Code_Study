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

void testClass_Copy(void)
{
	Func1 f1("��������: ",11);
	Func1 f2(f1);
	cout << f1.name << *f1.age << endl;
	cout << f2.name << *f2.age << endl;
}
