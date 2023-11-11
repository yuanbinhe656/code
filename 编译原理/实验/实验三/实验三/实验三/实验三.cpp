#include <iostream>
#include <string>
#include<bits/stdc++.h>
#define N 8
using namespace std;

string words[N];//每个元素都是“lparen”/“ident”这样的标志符
int sym = 0;//words的指针

// 函数声明
void E();
void T();
void F();
// 填充words数组
void getwords()
{
    string line;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> line;
        int pos = line.find(',', 0);
        words[i] = line.substr(1, pos - 1);
        // cout << words[i];
    }
}

// 指针前进
void advance()
{
    ++sym;
    if (sym > N - 1) {
        cout << "ERROR!words指针越界";
        exit(0);
    }
}
// 因子分析
void F()
{
    //cout << "F正在分析" << words[sym] << endl;

    if (words[sym] == "ident") {
        advance();
    }
    else if (words[sym] == "number") {
        advance();
    }
    else if (words[sym] == "lparen") {
        advance();
        E();
        //cout << "E返回，F正在分析" << words[sym] << endl;
        if (words[sym] == "rparen") {
            advance();
        }
        else {
            //cout << "ERROR!未能匹配右括号！语法错误" << endl;
            exit(0);
        }
    }
    return;
}

// 项分析
void T()
{
    //cout << "T正在分析" << words[sym] << endl;

    F();
    //cout << "1F返回，T正在分析" << words[sym] << endl;
    while (words[sym] == "times" || words[sym] == "slash") {
        advance();
        F();
        //cout << "2F返回，T正在分析" << words[sym] << endl;
    }
    return;
}

// 表达式分析
void E()
{
    //cout << "E正在分析" << words[sym] << endl;

    if (words[sym] == "plus" || words[sym] == "minus") {
        advance();
    }

    T();
    //cout << "1T返回，E正在分析" << words[sym] << endl;

    while (words[sym] == "plus" || words[sym] == "minus") {
        advance();
        T();
        //cout << "2T返回，E正在分析" << words[sym] << endl;
    }
    return;
}
int main()
{
    getwords();
    E();
    if (sym == N - 1) {
        cout << "Yes,it is correct." << endl;
    }
    else {
        cout << "No,it is wrong.";
    }

    return 0;
}
