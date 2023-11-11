#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int predictor[12][15] =
{
	//0     1     2    3     4     5      6      7     8      9      10     11      12       13        14
	//f     i     m    ;     <     >      +      -     *      /       (      )      {         }         =   
	/*00 A*/ { 0,   -1,   -1,  -1,   -1,   -1,    -1,    -1,   -1,    -1,     -1,    -1,     -1,      -1,       -1},
	/*01 B*/ {-1,    1,   -1,   1,   -1,   -1,    -1,    -1,   -1,    -1,     -1,    -1,     -1,      -1,       -1},
	/*02 C*/ {-1,    5,   -1,   4,   -1,   -1,    -1,    -1,   -1,    -1,     -1,    -1,     -1,      -1,       -1},
	/*03 D*/ {-1,    6,   -1,  -1,   -1,   -1,    -1,    -1,   -1,    -1,     -1,    -1,     -1,      -1,       -1},
	/*04 E*/ {-1,   11,   -1,  -1,   -1,   -1,    -1,    -1,   -1,    -1,     11,    -1,     -1,      -1,       -1},
	/*05 F*/ {-1,   -1,   -1,  -1,    7,    8,    -1,    -1,   -1,    -1,     -1,    -1,     -1,      -1,       -1},
	/*06 G*/ {-1,   10,   -1,  -1,   -1,   -1,    -1,    -1,   -1,    -1,     -1,     9,     -1,      -1,       -1},
	/*07 L*/ {-1,   15,   -1,  -1,   -1,   -1,    -1,    -1,   -1,    -1,     15,    -1,     -1,      -1,       -1},
	/*08 M*/ {-1,   -1,   -1,  14,   -1,   -1,    12,    13,   -1,    -1,     -1,    14,     -1,      -1,       -1},
	/*09 N*/ {-1,   19,   -1,  -1,   -1,   -1,    -1,    -1,   -1,    -1,     20,    -1,     -1,      -1,       -1},
	/*10 P*/ {-1,   -1,   -1,  18,   -1,   -1,    18,    18,   16,    17,     -1,    18,     -1,      -1,       -1},
	/*11 Y*/ {-1,   -1,    3,  -1,   -1,   -1,    -1,    -1,   -1,    -1,     -1,    -1,     -1,       2,       -1}
};


string grammar[21] =    //文法
{
	/*00 A*/ "}Y{)B(f",  //A->f(B){Y}
	/*01 B*/ "GDC",      //B->CDG
	/*02 Y*/ "",        //Y->0
	/*03 Y*/ ";E=m",      //Y->m=E;
	/*04 C*/ ";",        //C->;
	/*05 C*/ ";E=i",      //C->i=E;
	/*06 D*/ ";Fi",       //D->iF;
	/*07 F*/ "E<",       //F-><E
	/*08 F*/ "E>",        //F->>E
	/*09 G*/ "",         //G->0
	/*10 G*/ "E=i",       //G->i=E
	/*11 E*/ "ML",       //E->LM
	/*12 M*/ "ML+",      //M->+LM
	/*13 M*/ "ML-",      //M->-LM
	/*14 M*/ "",        //M->0
	/*15 L*/ "PN",       //L->NP
	/*16 P*/ "PN*",      //P->*NP
	/*17 P*/ "PN/",      //P->/NP
	/*18 P*/ "",         //P->0
	/*19 N*/ "i",         //N->i
	/*20 N*/ ")E("       //N->(E)
};
int grammar_length[21] =
{
	// 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20
	   7, 3, 0, 4, 1, 4, 3, 2, 2, 0,  3,  2,  3,  3,  0,  2,  3,  3,  0,  1,  3
};

string temp[10] = { "t1","t2","t3","t4","t5","t6","t7","t8","t9","t10" };

string* expression = new string[10];

bool In_compute(char a);

bool In_limit(char a);

bool In_number(char a);

bool In_ID(char a);

bool In_keywords(string a);

double ChangeChar(string aaa, int i);  //把数字字符转换为数值

int Compile_the_line(string input_string, ofstream& outfile, int& position);




char GetTop(char* OPTR, int& OPTR_i);

int In(string c_get, char OP[]);

void PushND(string* OPND, string c_get, int& OPND_i);

void PushTR(char* OPTR, string c_get, int& OPTR_i);

string PopND(string* OPND, int& OPND_i);

char PopTR(char* OPTR, int& OPTR_i);

string Operate(string opnd1, char optr, string opnd2, int& temp_i);

char Precede(char top_optr, string c_get);



int main()
{


	ofstream outfile;
	outfile.open("total.txt", ios::ate);
	outfile << setw(20) << "位置" << setw(20) << "单词" << setw(20) << "类型" << endl;

	int position = 0;


	ifstream infile("a.txt", ios::in);//
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	int flag = 0;
	char  input_char[200];
	string input_string;
	do
	{
		infile.getline(input_char, 200);
		input_string = input_char;
		flag = Compile_the_line(input_string, outfile, position);
		if (flag == 0)return 0;
	} while (!infile.eof());

	outfile.close();
	return 0;
}

bool In_compute(char a)
{
	char compute[11] = { '+','-','*','/','=','%','<','>','!','|','&' };
	for (int i = 0; i < 11; i++)
	{
		if (a == compute[i])return true;
	}
	return false;
}
bool In_limit(char a)
{
	char limit[11] = { ';','{','(',')',',','?',':','}','#','[',']' };
	for (int i = 0; i < 11; i++)
	{
		if (a == limit[i])return true;
	}
	return false;
}
bool In_number(char a)
{
	char number[] = { '0','1','2','3','4','5','6','7','8','9','e','.' };
	if (a >= '0' && a <= '9')return true;
	else if (a == 'e' || a == '.')return true;
	else return false;
}
bool In_ID(char a)
{
	if (a >= '0' && a <= '9')return true;
	if (a >= 'a' && a <= 'z')return true;
	if (a >= 'A' && a <= 'Z')return true;
	if (a == '_')return true;
	return false;
}

bool In_keywords(string a)
{
	string keywords[65] =
	{

	   "asm",      "auto",         "bad_cast",     "bad_typeid",
	   "bool",     "break",        "case",         "catch",
	   "char",     "class",        "const",        "const_cast",
	   "continue", "default",      "delete",       "do",
	   "char",   "dynamic_cast", "else",         "enum",
	   "except",   "explicit",     "extern",       "false",
		"finally",  "float",        "for",          "friend",
	   "goto",     "if",           "inline",       "int",
	   "long",     "mutable",      "namespace",    "new",
	   "operator", "private",      "protected",    "public",
	   "register", "reinterpret_cast",     "return",   "short",
	   "signed",   "sizeof",       "static",       "static_cast",
	   "struct",   "switch",       "template",     "this",
	   "throw",    "true",         "try",          "typedef",
	   "typeid",   "typename",     "union",        "unsigned",
	   "using",    "virtual",      "void",         "volatile",
	   "while"
	};
	for (int i = 0; i < 65; i++)
		if (a == keywords[i])return true;
	return false;
}


double ChangeChar(string aaa, int i)  //把数字字符转换为数值
{
	int j, k, l, p;
	double n = 0.0, m = 0.0;
	for (j = 0; j < i; j++)                    //对小数点进行定位，无小数点返回-1
	{
		if (aaa[j] == '.') { k = j; break; }
		else k = -1;
	}
	for (j = 0; j < i; j++)               //对e定位,无e返回-1
	{
		if (aaa[j] == 'e') { l = j; break; }
		else l = -1;
	}
	if (k == -1 && l == -1)                       //整数情况转数值    
	{
		for (p = 0; p < i; p++)
		{
			m = (aaa[p] - '0') * pow(10, i - 1 - p);
			n = n + m;
		}
	}
	else if (k != -1 && l == -1)                            //小数情况转数值，不含e
	{
		for (p = 0; p < k; p++)            //小数的整数部分
		{
			m = (aaa[p] - '0') * pow(10, k - 1 - p);
			n = n + m;
		}
		for (p = k + 1; p < i; p++)         //小数的小数部分
		{
			m = (aaa[p] - '0') * pow(10, k - p);
			n = n + m;
		}
	}
	else
	{
		for (p = 0; p < k; p++)            //小数的整数部分
		{
			m = (aaa[p] - '0') * pow(10, k - 1 - p);
			n = n + m;
		}
		for (p = k + 1; p < l; p++)         //小数的小数部分
		{
			m = (aaa[p] - '0') * pow(10, k - p);
			n = n + m;
		}
		m = 0;
		for (p = l + 1; p < i; p++)
		{
			m = m + (aaa[p] - '0') * pow(10, i - 1 - p);
		}
		n = n * pow(10, m);
	}
	return n;
}


int Compile_the_line(string input_string, ofstream& outfile, int& position)
{
	int i;
	i = input_string.size();

	///////////////////////////////除去空符

	int* type = new int[i];//定义运算符整型数组
	for (int j = 0; j < i; j++)
	{

		if (In_compute(input_string[j])) type[j] = 4;//运算符定为类型4
		else if (In_limit(input_string[j]))  type[j] = 5;//界符定为类型5 
		else if ('0' <= input_string[j] && input_string[j] <= '9' || input_string[j] == '+' || input_string[j] == '-')//若该符是无符号数,定为类型3
		{
			type[j] = 3;
			j++;
			while (In_number(input_string[j]))
			{
				type[j] = 3;
				j++;
			}
			j--;
		}
		else if (In_ID(input_string[j]) && input_string[j] > '9')//标识符和关键字先都作为标识符处理，定为2和1,下划线或字母开头   
		{
			type[j] = 2;
			j++;
			while (In_ID(input_string[j]))
			{
				type[j] = 2;
				j++;
			}
			j--;
		}

		else if (input_string[j] == 39)// 单引号  常量类型6           
		{
			type[j] = 6;
			j++;
			type[j] = 6;
			j++;
			type[j] = 6;
		}
		else if (input_string[j] == '"')//双引号  常量类型7
		{
			type[j] = 7;
			int k = j;
			j++;
			while (input_string[j] != '"')
			{
				j++;
			}
			for (; k <= j; k++)
			{
				type[k] = 7;
			}
		}
		else if (input_string[j] == ' ' || input_string[j] == '\n')//注意' '(一个空字符)不同于'\0'(一个结束标志）
		{
			type[j] = 0;
		}
		else cout << "ERROR" << j + 1;/////////////////////////////////////////?????????????
	}
	/////将标识符中的关键字部分提取出来
	string* a = new string[i];
	int k = 0;//记录截取的单词个数
	int* StringType = new int[i];
	for (int j = 0; j < i; j++)
	{
		switch (type[j])
		{


		case 4:         //运算符定为类型4
			while (type[j] == 4)
			{
				a[k] = a[k] + input_string[j];
				j++;
			}
			StringType[k] = 4;
			break;
		case 2:        //标识符类型2
			while (type[j] == 2)
			{
				a[k] = a[k] + input_string[j];
				j++;
			}
			if (In_keywords(a[k]))
				StringType[k] = 1;     //关键字类型1
			else StringType[k] = 2;
			break;
		case 3:         //常数
			while (type[j] == 3)
			{
				a[k] = a[k] + input_string[j];
				j++;
			}
			StringType[k] = 3;
			break;

		case 6:         //字符常量
			j++;//越过首‘
			a[k] = a[k] + input_string[j];
			j++;//越过尾’
			j++; //下一个

			StringType[k] = 6;
			break;

		case 7:         //字符串常量
			j++;//越过首“
			while (type[j] == 7 && input_string[j] != '"')
			{
				a[k] = a[k] + input_string[j];
				j++;
			}
			j++;//下一个
			StringType[k] = 7;
			break;


		case 5:   //界符定为类型5
			a[k] = a[k] + input_string[j];
			StringType[k] = 5;
			j++;
			break;
		default:  while (type[j] == 0)//遇上空格时
		{
			j++;
		}
			   k--;
		}
		j--;
		k++;

	}

	double* num_value = new double[k];
	for (int l = 0; l < k; l++)
	{
		if (StringType[l] == 3)
		{
			int m = a[l].size();
			num_value[l] = ChangeChar(a[l], m);
		}
	}


	cout << setw(20) << "位置" << setw(20) << "单词" << setw(20) << "类型" << endl;

	for (int l = 0; StringType[k] != 0 && l < k; l++)
	{
		switch (StringType[l])
		{
		case 1:cout << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 2:cout << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 3:cout << setw(20) << position + l + 1 << setw(20) << num_value[l] << setw(20) << StringType[l] << endl; break; //常数
		case 4:cout << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 5:cout << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 6:cout << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 7:cout << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		}
	}



	for (int l = 0; StringType[k] != 0 && l < k; l++)
	{
		switch (StringType[l])
		{
		case 1:outfile << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 2:outfile << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 3:outfile << setw(20) << position + l + 1 << setw(20) << num_value[l] << setw(20) << StringType[l] << endl; break; //常数
		case 4:outfile << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 5:outfile << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 6:outfile << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		case 7:outfile << setw(20) << position + l + 1 << setw(20) << a[l] << setw(20) << StringType[l] << endl; break;
		}
	}
	position = position + k;



	char* b = new char[k];

	if (a[0] == "for")b[0] = 'f';  //表示for
	else cout << "没有for关键字" << endl;
	int l;
	for (l = 0; l < k; l++)        //b[]作为剩余输入串
	{
		b[l] = a[l][0];
	}

	for (l = 0; l < k; l++)        //b[]作为剩余输入串
	{
		if (StringType[l] == 2 || StringType[l] == 3) b[l] = 'i';//i除了作为步进的标识，还作为for中表达式中的变量或常数
	}

	for (l = 0; l < k; l++)        //b[]作为剩余输入串
	{

		if (a[l] == "{" && a[l + 1] != "}") b[l + 1] = 'm'; //m作为赋值语句中赋值变量的标识	 
	}

	if (b[k - 1] != '#') { cout << "缺少结束符 ；" << endl; return 0; }
	//将每行；换做#作为结束标志


//sign[]作为分析栈

	char* sign = new char[100];
	sign[0] = '#';
	sign[1] = 'A';
	//分析栈初始为#
	int sign_i = 1;//指示当前的分析栈栈顶

	/*  string *reverse_polish=new string[k];//逆波兰式
	  for(l=0;l<k;l++)
		  reverse_polish[l]="-1";
	  int polish_i=1;
	  reverse_polish[0]=a[0]+" ";

	 string  *Quaternion=new string[k];//四元式
	 for(l=0;l<k;l++)
		 Quaternion[l]="-1";
	 int Quaternion_i=1;
	 Quaternion[0]=a[0]+" ";
   */


	cout << endl;
	cout << "分析栈" << "                          " << "剩余串" << endl;
	cout << endl;
	for (l = 0; l <= sign_i; l++)
		cout << sign[l] << " ";

	cout << endl;
	cout << "                               ";
	for (l = 0; l < k; l++)
	{
		cout << a[l] << " ";
	}
	cout << endl;
	int n;


	for (l = 0; l < k;)
	{
		switch (b[l])
		{
		/*00*/case 'f':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'A')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[0][0]]; n++)
						  {
							  sign[n] = grammar[predictor[0][0]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[0][0]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }




		/*01*/case 'i':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}

					  if (sign[sign_i] == 'B')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[1][1]]; n++)
						  {
							  sign[n] = grammar[predictor[1][1]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[1][1]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

					  if (sign[sign_i] == 'C')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[2][1]]; n++)
						  {
							  sign[n] = grammar[predictor[2][1]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[2][1]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

					  if (sign[sign_i] == 'D')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[3][1]]; n++)
						  {
							  sign[n] = grammar[predictor[3][1]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[3][1]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'E')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[4][1]]; n++)
						  {
							  sign[n] = grammar[predictor[4][1]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[4][1]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'G')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[6][1]]; n++)
						  {
							  sign[n] = grammar[predictor[6][1]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[6][1]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'L')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[7][1]]; n++)
						  {
							  sign[n] = grammar[predictor[7][1]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[7][1]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'N')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[9][1]]; n++)
						  {
							  sign[n] = grammar[predictor[9][1]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[9][1]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }




		/*02*/case 'm':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'Y')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[11][2]]; n++)
						  {
							  sign[n] = grammar[predictor[11][2]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[11][2]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*03*/case ';':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;

			break;
		}
					  if (sign[sign_i] == 'B')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[1][3]]; n++)
						  {
							  sign[n] = grammar[predictor[1][3]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[1][3]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'C')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[2][3]]; n++)
						  {
							  sign[n] = grammar[predictor[2][3]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[2][3]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'M')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[8][3]]; n++)
						  {
							  sign[n] = grammar[predictor[8][3]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[8][3]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'P')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[10][3]]; n++)
						  {
							  sign[n] = grammar[predictor[10][3]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[10][3]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;;
					  }


		/*04*/case '<':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'F')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[5][4]]; n++)
						  {
							  sign[n] = grammar[predictor[5][4]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[5][4]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*05*/case '>':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'F')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[5][5]]; n++)
						  {
							  sign[n] = grammar[predictor[5][5]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[5][5]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
		/*06*/case '+':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'M')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[8][6]]; n++)
						  {
							  sign[n] = grammar[predictor[8][6]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[8][6]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'P')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[10][6]]; n++)
						  {
							  sign[n] = grammar[predictor[10][6]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[10][6]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*07*/case '-':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'M')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[8][7]]; n++)
						  {
							  sign[n] = grammar[predictor[8][7]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[8][7]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'P')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[10][7]]; n++)
						  {
							  sign[n] = grammar[predictor[10][7]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[10][7]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*08*/case '*':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'P')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[10][8]]; n++)
						  {
							  sign[n] = grammar[predictor[10][8]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[10][8]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*09*/case '/':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'P')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[10][9]]; n++)
						  {
							  sign[n] = grammar[predictor[10][9]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[10][9]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*10*/case '(':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}
					  if (sign[sign_i] == 'E')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[4][10]]; n++)
						  {
							  sign[n] = grammar[predictor[4][10]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[4][10]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'L')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[7][10]]; n++)
						  {
							  sign[n] = grammar[predictor[7][10]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[7][10]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'N')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[9][10]]; n++)
						  {
							  sign[n] = grammar[predictor[9][10]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[9][10]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*11*/case ')':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}

					  if (sign[sign_i] == 'G')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[6][11]]; n++)
						  {
							  sign[n] = grammar[predictor[6][11]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[6][11]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'M')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[8][11]]; n++)
						  {
							  sign[n] = grammar[predictor[8][11]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[8][11]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }
					  if (sign[sign_i] == 'P')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[10][11]]; n++)
						  {
							  sign[n] = grammar[predictor[10][11]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[10][11]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }



		/*12*/case '{':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}

		/*13*/case '}':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}

					  if (sign[sign_i] == 'Y')//栈顶为非终结符时
					  {
						  //sign[sign_i]='\0';//退栈 
						  sign_i--;//栈顶前移
						  int q = 0;
						  for (n = sign_i + 1; n <= sign_i + grammar_length[predictor[11][13]]; n++)
						  {
							  sign[n] = grammar[predictor[11][13]][q];
							  q++;
						  }
						  sign_i += grammar_length[predictor[11][13]];
						  for (n = 0; n <= sign_i; n++)
							  cout << sign[n];
						  cout << endl;

						  cout << "                               ";
						  for (n = l; n < k; n++)
							  cout << a[n] << " ";
						  cout << endl;
						  break;
					  }

		/*14*/case '=':if (sign[sign_i] == b[l])//终结符匹配
		{
			l = l + 1; //剩余输入串下标自加
			sign_i--;//栈顶前移
			for (n = 0; n <= sign_i; n++)
				cout << sign[n];
			cout << endl;
			cout << "                               ";
			for (n = l; n < k; n++)
				cout << a[n] << " ";
			cout << endl;
			break;
		}

		case '#':if (sign[sign_i] == '#')//#匹配
		{
			cout << "匹配成功！" << endl; l++; break;
		}
		default: return 0;
		}
	}




	string* Quaternion = new string[8];//四元式
	for (l = 2; a[l] != ";"; l++)
	{
		Quaternion[1] += a[l];
	}
	for (l = l + 1; a[l] != ";"; l++)
	{
		Quaternion[2] += a[l];
	}
	for (l = l + 1; a[l] != ")"; l++)
	{
		Quaternion[3] += a[l];
	}
	l = l + 2;
	if (a[l][0] == 'm')
	{
		Quaternion[4] += a[l];
		Quaternion[4] += a[l + 1];
		Quaternion[4] += "t1";
		l += 2;
		Quaternion[5] += "t1=";
		for (; a[l] != ";"; l++)
		{
			Quaternion[5] += a[l];
		}


	}
	else
	{
		Quaternion[4] = "";
		Quaternion[5] = "";
	}

	if (Quaternion[4] == "")
	{
		cout << "1.  " << Quaternion[1] << endl;
		cout << "2.  " << "if " << Quaternion[2] << " goto 4" << endl;
		cout << "3.  " << "goto 6" << endl;
		cout << "4.  " << Quaternion[3] << endl;
		cout << "5.  " << "goto 2" << endl;
		cout << "6.  " << endl;
		return 1;
	}




	char* OPTR = new char[50];
	int OPTR_i = 1;
	OPTR[0] = ';';
	string* OPND = new string[100];
	int OPND_i = 0;
	string c_get;



	char OP[7] = { '+','-','*','/','(',')',';' };
	string x;
	char optr;
	string opnd1;
	string opnd2;
	int temp_i = 0;
	for (l = 0; a[l] != "{"; l++) {};
	l = l + 3;
	c_get = a[l];
	while (c_get != ";" || GetTop(OPTR, OPTR_i) != ';')
	{
		if (!In(c_get, OP))
		{
			PushND(OPND, c_get, OPND_i); l++; c_get = a[l];
		}
		else
			switch (Precede(GetTop(OPTR, OPTR_i), c_get))           //运算优先级的比较
			{
			case '<':
				PushTR(OPTR, c_get, OPTR_i);
				l++;
				c_get = a[l];
				break;
			case '=':
				x = PopTR(OPTR, OPTR_i);
				l++;
				c_get = a[l];
				break;
			case '>':
				optr = PopTR(OPTR, OPTR_i);
				opnd2 = PopND(OPND, OPND_i);
				opnd1 = PopND(OPND, OPND_i);
				PushND(OPND, Operate(opnd1, optr, opnd2, temp_i), OPND_i);
				break;
			}
	}
	ofstream infile("b.txt", ios::out);
	cout << 1 << ".  " << Quaternion[1] << endl;
	infile << "1.  " << Quaternion[1] << endl;
	cout << 2 << ".  " << "if " << Quaternion[2] << " goto 4" << endl;
	infile << "2.  " << "if " << Quaternion[2] << " goto 4" << endl;
	cout << 3 << ".  " << "goto " << 3 + 4 + temp_i << endl;
	infile << "3.  " << "goto " << 3 + 4 + temp_i << endl;
	for (l = 1; l <= temp_i; l++)
	{
		cout << 3 + l << ".  " << expression[l - 1] << endl;
		infile << 3 + l << ".  " << expression[l - 1] << endl;
	}
	cout << 4 + temp_i << ".  " << "m=t" << temp_i << endl;
	infile << 4 + temp_i << ".  " << "m=t" << temp_i << endl;
	cout << 5 + temp_i << ".  " << Quaternion[3] << endl;
	infile << 5 + temp_i << ".  " << Quaternion[3] << endl;
	cout << 6 + temp_i << ".  " << "goto 2" << endl;
	infile << 6 + temp_i << ".  " << "goto 2" << endl;
	cout << 7 + temp_i << endl;
	infile << 7 + temp_i << endl;






	delete[]OPTR;
	delete[]OPND;


	delete[]sign;
	delete[]b;
	delete[]Quaternion;

	delete[]type;
	delete[]a;
	delete[]num_value;
	delete[]StringType;
	return 1;
}




char GetTop(char* OPTR, int& OPTR_i)
{
	char top_optr;
	top_optr = OPTR[OPTR_i - 1];
	return top_optr;
}

int In(string c_get, char OP[])
{
	for (int i = 0; i < 7; i++)
	{
		if (c_get[0] == OP[i])
			return 1;
	}
	return 0;
}
void PushND(string* OPND, string c_get, int& OPND_i)
{
	OPND[OPND_i] = c_get;
	OPND_i++;
}

void PushTR(char* OPTR, string c_get, int& OPTR_i)
{
	OPTR[OPTR_i] = c_get[0];
	OPTR_i++;
}

string PopND(string* OPND, int& OPND_i)
{
	string top_opnd = OPND[OPND_i - 1];
	OPND_i--;
	return top_opnd;
}


char PopTR(char* OPTR, int& OPTR_i)
{
	char top_optr = OPTR[OPTR_i - 1];
	OPTR_i--;
	return top_optr;
}

string Operate(string opnd1, char optr, string opnd2, int& temp_i)
{

	//	cout<<temp[temp_i]<<"="<<opnd1<<optr<<opnd2<<endl;
	expression[temp_i] = temp[temp_i] + "=" + opnd1 + optr + opnd2;
	temp_i++;
	return temp[temp_i - 1];
}



char Precede(char top_optr, string c_get)
{

	char f;
	int i, j;

	switch (top_optr)                         //前一个算符
	{
	case '+': i = 20;  break;            //用数字代替其优先权+-×/();
	case '-': i = 20;  break;
	case '*': i = 40;  break;
	case '/': i = 40;  break;
	case '(': i = 0;   break;
	case ')': i = 50;  break;
	case ';': i = -10; break;
	}
	switch (c_get[0])                        //当前算符
	{
	case '+': j = 10;  break;            //用数字代替其优先权+-×/()#
	case '-': j = 10;  break;
	case '*': j = 30;  break;
	case '/': j = 30;  break;
	case '(': j = 50;   break;
	case ')': j = 0;  break;
	case ';': j = -10; break;
	}
	if (i > j) f = '>';
	if (i == j) f = '=';
	if (i < j) f = '<';

	return f;
}

