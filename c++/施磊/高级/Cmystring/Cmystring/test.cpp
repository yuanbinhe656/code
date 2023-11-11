#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class CMyString {
public:
    CMyString(const char* str = nullptr) {
        cout << "CMyString(const char* str = nullptr)" << endl;
        if (str) {
            data_ = new char[strlen(str) + 1];
            strcpy(data_, str);
        }
        else {
            data_ = nullptr;
        }
    }

    // �ƶ����캯��
    CMyString(CMyString&& other) noexcept {
        cout << " CMyString(CMyString&& other) noexcept {" << endl;
        data_ = other.data_;
        other.data_ = nullptr;
    }

    // �ƶ���ֵ�����
    CMyString& operator=(CMyString&& other) noexcept {
        cout << " CMyString& operator=(CMyString&& other)" << endl;
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            other.data_ = nullptr;
        }
        return *this;
    }

    ~CMyString() {
        delete[] data_;
    }

private:
    char* data_;
};
CMyString GetString()
{
    char strs[3] = "aa";
    CMyString str(strs);
    return str;
}

int main() {
    
    CMyString str2 = GetString();  // ʹ�� std::move �� str1 �ƶ��� str2
    int* ptr = new int[10];
    int* pre = ptr + 2;
    delete[] pre;
    cout << *ptr;
    // ��� str2 Ӧ�ð��� "Hello"
    ///cout << "str2: " << str2 << std::endl;

    // str1 ����Ӧ��Ϊ��
    //cout << "str1: " << str1 << std::endl;

    return 0;
}