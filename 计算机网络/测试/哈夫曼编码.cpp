#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include <algorithm>
#include <fstream>
using namespace std;
typedef class treenote * pnote;
	class treenote{
		public: 
	char da;
	int num;
	pnote left;
	pnote right;
	treenote(char a,int b,pnote c,pnote r):da(a),num(b),left(c),right(r){
	}
	treenote()
	{
		da=0;
		num=0;
		left=NULL;
		right=NULL;
	}
};
void input(string &Data,string &path);
void test1();
string Huffman(string &Data,map<string,char>& code,map<char,string> decode);
void decodes(string s,map<string,char>& code);
void mid(pnote s,string si,map<string,char>& code,map<char,string> &decode);
bool cm(pair<char ,int>a,pair<char,int>b);
bool cmt(treenote a,treenote b);
void compare(string s,string c);
int main()
{
	test1();
	return 0;
}
void test1()
{
	vector<int> anum;
	string Data,path;
	map<string,char> code;
	map<char,string> decode;
	string taget;
	input(Data,path);
	taget=Huffman(Data,code, decode);
	 decodes(taget,code);
	 compare(Data,taget);
}
void input(string &Data,string &path)
{
	cout<<"数据编码"<<endl; 
	cout<<"请输入文件路径："<<endl; 
	cin>>path;
	ifstream file(path,ios::in);
	if(!file.is_open())
	{
		cout<<"open file error"<<endl;
		return ;
	}
	string len;
	while(getline(file,len))
	{
		Data+=len;
		len="\n";
	}
	cout<<"文件中的内容是："<<endl;
	cout<<Data<<endl; 
	file.close();
	return;
	
}
string Huffman(string &Data,map<string,char>& code,map<char,string> decode)
{
	map<char,int> Datew;
	for(auto em:Data)
	{
		map<char,int> ::iterator itr=Datew.find(em);
		if(itr==Datew.end())
		{
			Datew.insert(pair<char,int>(em,1));		
		}
		else 
		{
		itr->second+=1;
		}
		}
		map<char,int> ::iterator itr=Datew.begin();
			vector<pair<char,int >> nums(Datew.begin(),Datew.end());
	sort(nums.begin(),nums.end(),cm);
	vector<pair<char,int >> ::iterator itrs=nums.begin();
	vector<treenote> tree;
	for(;itrs!=nums.end();itrs++)
	{
		treenote ar(itrs->first,itrs->second,NULL,NULL);
		tree.push_back(ar);
	}

	while(1)
	{
			vector<treenote>::iterator itt1=tree.end()-1;
			if(itt1==tree.begin())
			{
				break;
			}
			vector<treenote>::iterator itt2=itt1-1;
			pnote p1=new treenote(itt1->da,itt1->num,itt1->left,itt1->right);
			pnote p2=new treenote(itt2->da,itt2->num,itt2->left,itt2->right);
			tree.erase(itt2,tree.end());
			
			treenote tr('0',p1->num+p2->num,p1,p2);
			tree.push_back(tr);
			sort(tree.begin(),tree.end(),cmt);	
		}
		treenote sno=tree[0];
		pnote tr=&tree[0];
		string str="";

		mid(tr,str,code,decode);
		cout<<"编码表"<<endl;
		for(auto em:decode)
		{
			cout<<"原始："<<em.first<<"  编码："<<em.second<<endl;
		}
		string taget="";
		map<char,string> ::iterator ita;
		for(auto em:Data)
		{
			ita=decode.find(em);
			if(ita!=decode.end())
			{
				taget+=ita->second; 
			}
		}
		cout<<endl;
		cout<<"数据加密"<<endl;
		cout<<"加密后数据为："<<endl; 
		cout<<taget<<endl;
		    ofstream os;   

		    cout<<"加密路径为：" <<"E:\\my\\out.txt"<<endl;
    os.open("E:\\my\\out.txt", ios::trunc);
    	if (os.is_open()) {	
		os << taget << endl;  
		os.close();}
cout<<endl;
    return taget;
		
		
			
}
void mid(pnote s,string si,map<string,char>& code,map<char,string> &decode)
{

	pnote sa=s->left;
			if(sa==NULL)
	{
		code.insert(pair<string,char>(si,s->da));
		decode.insert(pair<char,string>(s->da,si));

		return;
	}
	si=si+"0";
	mid(sa,si,code,decode);
	si.erase(si.end()-1);
	 sa=s->right;

	si=si+"1";
	mid(sa,si,code,decode);
	
}
void decodes(string s,map<string,char>& code)
{
	string str="";
	string sta="";
	map<string,char>::iterator its;
	for(auto em:s)
	{
		str+=em;
		its=code.find(str);
		if(its!=code.end())
		{
			
			sta+=its->second;
			str="";
		}
	}
	cout<<"数据解码"<<endl;
	cout<<"文件解码后为："<<endl;
	cout<<sta<<endl;
			    ofstream os;  
				cout<<"解码路径为：" <<"E:\\my\\deout.txt"<<endl;
				cout<<endl;
    os.open("E:\\my\\deout.txt", ios::trunc);

    	if (os.is_open()) {	
		os << sta << endl;  
		os.close();}
	return ;
}
	bool cm(pair<char ,int>a,pair<char,int>b)
	{
		return a.second>b.second;
	}
		bool cmt(treenote a,treenote b)
	{
		return a.num>b.num;
	}
void compare(string s,string c)
{
	cout<<"原始数据与编码后数据对比："<<endl;
	cout<<"原始数据："<<endl;
	cout<<s<<endl;
	cout<<"编码后数据："<<endl;
	cout<<c<<endl;
	return ;
}
