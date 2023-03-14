#include "testClass.h"

void testClass_Circle(void)
{
	//创建圆的对象c
	Circle c;
	//通过对象c调用函数
	c.setC_r(2);
	//输出结果，获取半径和面积
	cout << "以半径为："<< c.getC_r() <<" 的" << "圆的面积为：" << c.clcCircleS() << endl;
}

void testClass_StructFunc(void)
{
	//创建的对象只会调用无参构造
	Func f;
	Func("有参构造 ：",1);
	
	//拷贝构造
	Func f1 = Func("拷贝构造 ：",2);	//有参构造传值
	Func f2 = f1;	//拷贝构造

	Func f3 = f;//拷贝构造	//NULL : 0 / 如果声明属性时未给初始值将返回地址
}

//拷贝测试
void testClass_Copy(void)
{
	Func1 f1("拷贝测试: ",11);
	Func1 f2(f1);
	cout << f1.name << *f1.age << endl;
	cout << f2.name << *f2.age << endl;
}
//*****************************
//********	this指针的概念		*
//*****************************
void test_ClassThis(void)
{
	ClassThis c1(18);
	cout << "c1.age = " << c1.age << endl; //18

	ClassThis c2(24);
	//叠加
	c2.ClassThisFunction(c1).ClassThisFunction(c1);
	cout << "c2.age = " << c2.age << endl;//60
}

/*
*	空指针访问成员函数
*	注：如果用到this指针，需要加以判断，保证代码的健壮性
*
*/
void test_Null_Point(void)
{
	Null_Point* pNull = NULL;
	pNull->ShowComm();

	pNull->ShowAdvance();
}

/*
* const修饰成员函数:两个概念	常函数 常对象
* 使用const修饰
*/
void test_ConstObject(void)
{
	//const修饰的对象为 常对象
	const ConstObject constObject;
	//constObject.m_AA = 2; //常对象不能修改成员变量的值,但是可以访问
	cout << constObject.m_AA << endl;

	//mutable int m_BB; //mutable 修饰的可变
	constObject.m_BB = 2;
	cout << constObject.m_BB << endl;

	//常对象只能调用常函数
	//constObject.Show2();//错误
	constObject.Show();
	cout << constObject.m_BB << endl;

}

/*
*	友元
*/

static void Global_Firend(Friend_Object* fPtr)
{
	cout << "好朋友访问：" << fPtr->phone << endl;
	cout << "好朋友访问：" << fPtr->bank_card << endl;
}
void Global_Firend_Test(void)
{
	Friend_Object fPtr1;
	Global_Firend(&fPtr1);
}

/*
*	类-友元
*/
//类外写成员函数实现
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
	cout << "类-好朋友访问：" << inFriend->phone << endl;
	//如果要访问，必须声明该类为友元
	//cout << "类-好朋友访问：" << inFriend->bank_card << endl;
}
void OutFriend::find2()
{
	cout << "成员函数--好朋友访问：" << inFriend->phone << endl;
	//如果要访问，必须声明该成员函数为友元
	//cout << "成员函数--好朋友访问：" << inFriend->bank_card << endl;
}
void Class_Freind_Test(void)
{
	OutFriend of;
	of.find();
	of.find2();
}

/*
* 继承
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
*	子父类同名成员	函数/属性	的继承
*	如何访问？
*	子类访问本身可直接访问
*	子类访问父类的 函数/属性 需要 引入父类作用域
*/
void Inherit_test1(void)
{
	CPP cpp;
	//直接访问，访问的是子类中的成员 函数/属性
	cout << "CPP类中：	CPP Study" << cpp.m_name << endl;
	cpp.info();

	//访问父类的同名成员 函数/属性	需要加入父类作用域
	cout << "PublicArea类中：CPP Study" << cpp.PublicArea::m_name << endl;
	cpp.PublicArea::info();
}
