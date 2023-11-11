#include <iostream>
#include<bits/stdc++.h>//万能头文件
using namespace std;
pair<string, string> results[50]; // results保存词法分析结果，第一个sring存单词类型，第二个string存单词的值
int lexI = 0; // results的指针
void Lexical_Analysis()/*lexI为results的长度，即单词数*/
{
    string inputs;  // 输入字符串
    cin >> inputs;
    map<string, string> words;//应用map数据结构形成一个string->string的对应
    std::map<string, string>::iterator it;//用来遍历整个对应关系的迭代器
    //对应关系进行初始化，如下只包括了表达式的相关符号
    words["+"] = "plus";
    words["-"] = "minus";
    words["*"] = "times";
    words["/"] = "slash";
    words["="] = "eql";
    words["("] = "lparen";
    words[")"] = "rparen";
    int input_size = inputs.length(); //输入字符串的长度
    string word; // 字符识别
    for (int i = 0; i < input_size; i++)
    {
        while (inputs[i] == ' ' || inputs[i] == '\n')//若最开始为空格或换行符，则将指针的位置往后移
            i++;
        if (isalpha(inputs[i])) {//对标识符和基本字进行识别,调用库函数isalpha()
            word = inputs[i++];
            while (isalpha(inputs[i]) || isdigit(inputs[i]))
                word += inputs[i++];
            it = words.find(word); // 在map中找到相应的词性，并输出
            if (it != words.end())//判断是不是基本字，若为基本字则进行输出
                results[lexI++] = make_pair(words[word], word);//创建新的pair对象
            else
                results[lexI++] = make_pair("ident", word);
            i--;
        }
        else if (isdigit(inputs[i])) {//判断是不是常数，调用库函数isdigit()
            word = inputs[i++];
            while (isdigit(inputs[i]))
                word += inputs[i++];
            results[lexI++] = make_pair("number", word);
            i--;
        }
        // <和<=号
        else if (inputs[i] == '<') {
            word = inputs[i++];
            if (inputs[i] == '>') {
                word += inputs[i];
                results[lexI++] = make_pair(words[word], word);
            }
            else if (inputs[i] == '=') {
                word += inputs[i];
                results[lexI++] = make_pair(words[word], word);
            }
            else if (inputs[i] != ' ' || !isdigit(inputs[i]) || !isalpha(inputs[i])) {
                results[lexI++] = make_pair(words[word], word);
            }
            else
            {
                cout << "error!" << endl;
            }
            i--;
        }
        // >和>=
        else if (inputs[i] == '>') {
            word = inputs[i++];
            if (inputs[i] == '=') {
                word += inputs[i];
                results[lexI++] = make_pair(words[word], word);
            }
            else if (inputs[i] != ' ' || !isdigit(inputs[i]) || !isalpha(inputs[i])) {
                results[lexI++] = make_pair(words[word], word);
            }
            else {
                cout << "error!" << endl;
            }
            i--;
        }
        //:=
        else if (inputs[i] == ':') {
            word = inputs[i++];
            if (inputs[i] == '=') {
                word += inputs[i];
                results[lexI++] = make_pair(words[word], word);
            }
            else {
                cout << "error!" << endl;
            }
        }
        else {//其他的基本字
            word = inputs[i];
            it = words.find(word);
            if (it != words.end()) {
                results[lexI++] = make_pair(words[word], word);
            }
            else {
                cout << "error!" << endl;
            }
        }
    }
}
struct quad {/**四元式的结构体**/
    string result;
    string arg1;
    string arg2;
    string op;
};
struct quad quad[50]; // 四元式数组
int quaI = 0; // 指向四元式的指针
void emit(string op, string arg1, string arg2, string result)//生成一行四元式
{
    quad[quaI].op = op;
    quad[quaI].arg1 = arg1;
    quad[quaI].arg2 = arg2;
    quad[quaI].result = result;
    quaI++;
}
int i = 1; // 记录当前是t1/t2...t几了
string newT() //产生新变量名t1,t2等
{
    stringstream ss;
    ss << i;
    string ti = "t" + ss.str();
    i++;
    return ti;
}
/**非算数表达式的递归下降分析及四元式生成**/
int sym = 0; // 指示读入的符号
void advance()  //用来读入下一个符号
{
    ++sym;
    if (sym > lexI) {
        cout << "sym指针越界!";
        exit(0);
    }
}
string E1();
string F1()/*因子分析*/
{
    string arg;
    if (results[sym].first == "ident") {  //results的第一个string
        arg = results[sym].second;  //保存到results的第二个string里
        advance();
    }
    else if (results[sym].first == "number") {//如果是无符号整数，最终返回相应的整数
        arg = results[sym].second;
        advance();
    }
    //如果是左括号，则要进行右括号匹配，并判断中间是不是表达式，并得出表达式的值进行返回
    else if (results[sym].first == "lparen") {
        advance();
        arg = E1();
        if (results[sym].first == "rparen") {
            advance();
        }
        else {
            cout << "未能匹配右括号！\n";
            exit(0);
        }
    }
    return arg;
}
string T1()/*项分析*/
{
    string op, arg1, arg2, result;
    arg1 = F1();//通过因子分析得到第一个参数的值
    while (results[sym].first == "times" || results[sym].first == "slash")
    {
        op = results[sym].second;
        advance();
        arg2 = F1();//通过因子分析得到第二个参数的值
        result = newT();//产生中间变量名，相当于对结果进行存储
        emit(op, arg1, arg2, result);//产生四元式，相当于进行乘法或除法运算，得出结果
        arg1 = result;//保存得到的结果
    }
    return arg1;//返回项最终得到的值
}
string E1()/*表达式分析*/
{
    string op, arg1, arg2, result;
    if (results[sym].first == "plus" || results[sym].first == "minus") {
        advance();
    }
    arg1 = T1();//通过项分析得到第一个参数的值
    while (results[sym].first == "plus" || results[sym].first == "minus") {
        op = results[sym].second;
        advance();
        arg2 = T1();
        result = newT();
        emit(op, arg1, arg2, result);
        arg1 = result;
    }
    return arg1;
}
/**算数表达式的递归下降分析及四元式生成**/
int E2();
int F2()
{
    int arg = 0;
    if (results[sym].first == "ident") {
        cout << "算数表达式含字母，无法计算！\n";
        exit(0);
    }
    else if (results[sym].first == "number") {//如果 是数字，则返回相应的值
        arg = atoi(results[sym].second.c_str());
        advance();
    }
    //如果是左括号，则要进行右括号匹配，并判断中间是不是表达式，并得出表达式的值进行返回
    else if (results[sym].first == "lparen") {
        advance();
        arg = E2();
        if (results[sym].first == "rparen") {
            advance();
        }
        else {
            cout << "未能匹配右括号！\n";
            exit(0);
        }
    }
    return arg;
}
int T2()/*项分析*/
{
    string op;
    int arg1, arg2, result;
    arg1 = F2();
    while (results[sym].first == "times" || results[sym].first == "slash") {
        op = results[sym].second;
        advance();
        arg2 = F2();
        if (op == "*") {
            result = arg1 * arg2;
            arg1 = result;
        }
        else {
            if (arg2 != 0) {
                result = arg1 / arg2;
                arg1 = result;
            }
            else {
                cout << "除数不能为0！\n";
                exit(0);
            }
        }
    }
    return arg1;//返回该项所代表的值
}
int E2()/*表达式分析*/
{
    string op;
    int arg1, arg2, result;
    if (results[sym].first == "plus" || results[sym].first == "minus") {
        advance();
    }
    arg1 = T2();//通过项分析得到第一个参数的值
    while (results[sym].first == "plus" || results[sym].first == "minus") {
        op = results[sym].second;
        advance();
        arg2 = T2();//通过项分析得到第二个参数的值
        if (op == "+") {
            result = arg1 + arg2;
            arg1 = result;
        }
        else {
            result = arg1 - arg2;
            arg1 = result;
        }
    }
    return arg1;//返回该表达式所代表的值
}
int main()
{
    Lexical_Analysis(); //词法分析
    if (results[0].first == "number") { //算术表达式
        cout << E2();
    }
    else {
        E1();
        for (int i = 0; i < quaI; i++) {  //表达式       
            cout<<'('<<quad[i].op<<','<<quad[i].arg1<<','<<quad[i].arg2<<','<<quad[i].result<<')'<<endl;
        }
    }
    return 0;
}
