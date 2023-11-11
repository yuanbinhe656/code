#include<stdio.h>
#include<map>
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
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

using namespace std;
	bool cm(pair<char ,int>a,pair<char,int>b);
	bool cmt(treenote a,treenote b);
	void mid(pnote s,string si,map<string,char>& code,map<char,string> &decode);
	void decodes(string s,map<string,char>& code);
int main()
{
	string Data="jinnntian";
	cout<<Data<<endl;

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

	vector<pair<char,int >> nums(Datew.begin(),Datew.end());

	sort(nums.begin(),nums.end(),cm);
	vector<pair<char,int >> ::iterator itr=nums.begin();
	vector<treenote> tree;
	for(;itr!=nums.end();itr++)
	{
		cout<<"num:"<<itr->second<<endl;
		treenote ar(itr->first,itr->second,NULL,NULL);
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
		map<string,char> code;
		map<char,string> decode;
		mid(tr,str,code,decode);
			string taget="";
		map<char,string>::iterator ita;
		for(auto em:decode)
		{
			cout<<"cahr:"<<em.first<<"  strign£»"<<em.second<<endl; 
		}
		for(auto em:Data)
		{
			ita=decode.find(em);
			if(ita!=decode.end())
			{
				taget+=ita->second; 
			}
		}
		cout<<taget<<endl;
		 decodes(taget,code);
		
	return 0;
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
	cout<<sta;
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
	

