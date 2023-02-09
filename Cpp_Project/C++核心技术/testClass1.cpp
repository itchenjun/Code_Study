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

void testClass_Copy(void)
{
	Func1 f1("拷贝测试: ",11);
	Func1 f2(f1);
	cout << f1.name << *f1.age << endl;
	cout << f2.name << *f2.age << endl;
}
