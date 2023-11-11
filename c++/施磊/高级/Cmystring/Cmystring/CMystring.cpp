#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

class CMyString {
public:

	CMyString(char* s = nullptr)
	{
		cout << "CMyString(char* s = nullptr)";
		// 深拷贝
		if (strlen(s) != 0)
		{
			// strlen 到/0字符结束的长度
			m_ptr = new char[strlen(s) + 1];
			strcpy(m_ptr, s);
		}
		else
		{
			m_ptr = new char[1];
			*m_ptr = '\0';
		}
	}
	CMyString(const CMyString& str)
	{
		m_ptr = new char[strlen(str.m_ptr) + 1];
		strcpy(m_ptr, str.m_ptr);
	}

	/// <summary>
	///  将赋值运算符传出参数设为引用，减少了链式赋值的多次拷贝
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	CMyString& operator=(const CMyString& str)
	{
		if (this == &str)
		{
			return *this;
		}
		delete[]m_ptr;
		m_ptr = new char[strlen(str.m_ptr) + 1];
		strcpy(m_ptr, str.m_ptr);
		return *this;
	}
	// 右值赋值构造
	CMyString& operator=( CMyString& str)
	{
		m_ptr = str.m_ptr;
		str.m_ptr = nullptr;
		return *this;
	}
	// 右值引用拷贝构造
	CMyString (CMyString&& str)
	{
		cout << "CMyString (CMyString&& str)" << endl;
		m_ptr = str.m_ptr;
		str.m_ptr = nullptr;

	}
	const char* c_str()const { return m_ptr; }
	~CMyString()
	{
		cout << "~CMyString()" << endl;
		delete[]m_ptr;
	}
	friend CMyString operator+(const CMyString& lhs, const CMyString& rlh);
private:
	char* m_ptr;

};
// CMyString加法
CMyString operator+(const CMyString& lhs, const CMyString& rhs)
{
	CMyString temp;
	delete temp.m_ptr;
	temp.m_ptr = new char[strlen(lhs.m_ptr) + strlen(rhs.m_ptr) + 1];
	strcpy(temp.m_ptr, lhs.m_ptr);
	strcat(temp.m_ptr, rhs.m_ptr);
	return temp;
}
CMyString sGetString()
{
	char strs[3] = "aa";
	CMyString str(strs);
	return str;
}
int amain()
{
	CMyString res = sGetString();
	/*
	char str[3] = "aa";
	CMyString Mys1 = str;
	vector<CMyString> vec;
	vec.push_back(Mys1);
	vec.push_back(CMyString(str));
	*/
	return 0;
}