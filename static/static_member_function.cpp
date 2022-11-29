#include <stdio.h>

class Test
{
private:
	static int cCount;
public:
	Test()
	{
		++cCount;
	}
	~Test()
	{
		--cCount;
	}

	// 静态成员函数可以访问静态成员变量
	static int getCount()
	{
		return cCount;
	}
};

int Test::cCount = 0;

int main()
{
	// 静态成员函数可以通过类名直接调用
	printf("count = %d\n", Test::getCount());	// 0

	Test t1;
	Test t2;

	printf("count = %d\n", t1.getCount());		// 2
	printf("count = %d\n", t2.getCount());		// 2

	Test* pt = new Test();
	printf("count = %d\n", pt->getCount());		// 3
	delete pt;									// --3	

	printf("count = %d\n", Test::getCount());	// 2

	return 0;
}
