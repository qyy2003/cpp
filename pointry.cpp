#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void fun1(int *x, int *y) // 交换两个参数指针，但是不影响函数外面的值
{
    int *k;
    k = x;
    x = y;
    y = k;
}

void fun2(int *x, int *y) // 相当于引用，交换两个参数指针所指的值
{
    int k;
    k = *x;
    *x = *y;
    *y = k;
}

void fun3(int &x, int &y) // 引用，x和y是int类型而不是*int
{
    int k;
    k = x;
    x = y;
    y = k;
}

void fun4(int *x, int *y) // 等于fun2()
{
    int *k;
    k = new int;
    *k = *x;
    *x = *y;
    *y = *k;
}

int &fun5() // fun5()的返回值引用了xa，所以修改fun5()就修改了xa，并且静态变量xa会保持之前修改过的值
{
    static int xa = 10;
    return xa;
}

int main()
{
    int a = 233, b = 666;
    int *x1 = &a, *y1 = &b;
    int &x3 = a, &x4 = b; // 引用

    fun1(x1, y1);
    cout << a << " " << b << endl;
    cout << *x1 << " " << *y1 << endl;
    cout << "----------------------------" << endl;

    fun2(x1, y1);
    cout << a << " " << b << endl;
    cout << *x1 << " " << *y1 << endl;
    cout << "----------------------------" << endl;

    fun3(a, b);
    cout << a << " " << b << endl;
    cout << *x1 << " " << *y1 << endl;
    cout << "----------------------------" << endl;

    fun4(x1, y1);
    cout << a << " " << b << endl;
    cout << *x1 << " " << *y1 << endl;
    cout << "----------------------------" << endl;

    cout << fun5() << endl;
    fun5() = 30;
    cout << fun5() << endl;
    return 0;
}
//he from xyy
