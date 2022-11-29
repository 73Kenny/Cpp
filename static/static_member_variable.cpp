#include <stdio.h>

class Test
{
private:
	// 静态成员变量，与全局变量、静态变量放在静态区/全局区
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
	int getCount()
	{
		return cCount;
	}
};

// 链接时需要告诉编译器静态变量 cCount 隶属于 Test 类中
int Test::cCount = 0;

Test gTest;

int main()
{
	Test t1;
	Test t2;

	printf("count = %d\n", t1.getCount());		// 3
	printf("count = %d\n", t2.getCount());		// 3
	printf("count = %d\n", gTest.getCount());	// 3

	Test* pt = new Test();
	printf("count = %d\n", pt->getCount());		// 4
	delete pt;									// --4	
	printf("count = %d\n", pt->getCount());		// 3

	return 0;
}
