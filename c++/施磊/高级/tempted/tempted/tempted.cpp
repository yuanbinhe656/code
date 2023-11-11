#include <iostream>
using namespace std;

template <typename T, typename U>
class MyClass {
    // ...
};

// ƫ�ػ�
template <typename T>
class MyClass< T, int> {
    // ����� U �ػ�Ϊ int
};
template <typename T, typename U, typename V>
class MyClass <T(U), V>
{
    // ...
public:
    MyClass() { cout << "call vecto"; }
};
template <typename T>
class MyClassFunc {
    // ...
};
template <typename T, typename A>
class MyClassFunc<T(A)> {
    // ...
public:
    MyClassFunc()
    {
        cout << "lal";
    }

};

template <typename T>
void MyFunction(T arg) {
    // ͨ�õĺ���ģ��汾
}
template <typename T, typename A, typename B>
void MyFunction(T(*a)(A,B)) {
    // ͨ�õĺ���ģ��汾
}

template <typename T, typename C, typename A, typename B>
void MyFunction(T(C::*a)(A, B)) {
    // ͨ�õĺ���ģ��汾
}

class Test {
public:
    int a(int i, int j)
    {
        return 0;
    }
};
int sum(int)
{
    return 0;
}
int main1()
{
    typedef int(*PFUNC1)(int);
    PFUNC1 punc1 = sum;
    typedef int PFUNC2(int);
    PFUNC2 *punc2 = sum;
    MyClassFunc<int(int)> s ;
    return 0;

}
