#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<string> 
#include<stack>
using namespace std;

class node{
	public:
		string name;
		node(string i):name(i){
			
		}
		
		node(){
			
		} 
};
class knod{
	public:
	double s;
	node name;
	knod(node as,double sa):s(sa),name(as){
	}
	knod(){
		string s=" ";
		name=node(s);
	}
	
};
class border{
	public:
		string name;
		node pname;
		node bname; 
		double time;
		double velocity;
		double distance;
		border():name(NULL),pname(NULL),bname(NULL),distance(0),velocity(0){
			
		}
		border (string iname,node ipname,node ibname,double ti,double v):name(iname),pname(ipname),bname(ibname),distance(ti),velocity(v){
			time=distance/velocity;
		
		} 
};
void maue(vector<border> &data);
void times(map<string,vector<border>>  &tdata);
void output(map<string,knod>& target,string end,string begin);
void distances ( map<string,vector<border> >  & tdata);
void stander(vector<border> &data,map<string,vector<border>> &tdata);
void toget(map<string,vector<border> >  &tdata, map < string,knod>& target);
void test();
map<string,knod> ::iterator mine(map<string,knod> &target);
int main()
{
	test();
	return 0;
}
void test()
{
	vector<border> data;
	maue(data);
	return ;
}
void maue(vector<border> &data)
{
	int se;
	double v,s;
	string iname,pname,bname;
	cout<<"��ӭ�����ͼѰ·"<<endl;
	cout<<"����е�ͼ�Ĵ���"<<endl;
	cout<<"��Ҫ�����밴 1 ����Ҫ�˳�ϵͳ�밴 0"<<endl;
	cin>>se;
	if(!se)
	{
		return ;
	}
	while(se!=0)
	{
		cout<<"�������·������"<<endl; 
	cin>>iname;
	cout<<"�������·���������"<<endl; 
	cin>>pname;
	cout<<"�������·���յ�����"<<endl; 
	cin>>bname;
	cout<<"�������·������·��"<<endl; 
	cin>>s;
	cout<<"�������·����ʻ�ٶ�"<<endl; 
	cin>>v;
	data.push_back(border(iname,node(pname),node(bname),s,v));
	cout<<"��Ҫֹͣ�����밴 0,�����밴 1"<<endl;
	cin.get();
	if(cin.get()=='0')
	{
		se=0;
	 } 
	}
	vector<border> ::iterator itr=data.begin();
	map<string,vector<border>> tdata;
	stander(data,tdata);
	cout<<"�����·������ѡ��"<<endl;
	cout<<"�����ʱ��·���� 1 ����������·�� 2����Ҫ�˳��밴0"<<endl;	
	cin>>se;
	while(se)
	{

		 
		if(se==1)
		{
			times(tdata);
		 }
		 else if(se==2)
		 {
		 	distances(tdata);
		  } 
		  else if(se==0)
		{
			return ;
		}
		else {
			cout<<"����������"<<endl; 
		}
		cout<<"�����ʱ��·���� 1 ����������·�� 2����Ҫ�˳��밴0"<<endl;
		cin>>se;
	}
	

}
void stander(vector<border> &data,map<string,vector<border>> &tdata)
{
	vector<border>::iterator  itr=data.begin();
	map<string,vector<border>>::iterator  its;
	while(itr!=data.end())
	{
		its=tdata.find(itr->pname.name);
		if(its==tdata.end())
		{
			vector<border> dis;
			dis.push_back(*itr);
			tdata.insert(make_pair(itr->pname.name,dis));
		
		}
		else{
			its->second.push_back(*itr);
		}
		its=tdata.find(itr->bname.name);
		if(its==tdata.end())
		{
			vector<border> dis;
			dis.push_back(*itr);
			tdata.insert(make_pair(itr->bname.name,dis));
		
		}
		
		itr++;
		 
	}
	return ;
}
void times(map<string,vector<border>> &tdata)
{
	map<string,knod> target,targod;
	toget(tdata,target);
	string be,end;
	map<string,knod> ::iterator itr,itc;
	vector<border> ::iterator itz;	
	cout<<"��������㣺"<<endl;
	cin>>be;
	itr=target.find(be);
	if(itr==target.end())
	{
		cout<<"����������"<<endl;
		return;
	}
	else
	{
		
		(itr->second).s=0;
	}
	cout<<"�������յ㣺"<<endl;
	cin>>end;
	itr=target.find(end);
	if(itr==target.end())
	{
		cout<<"�յ��������"<<endl;
		return;
	} 
	if(be==end)
	{
		cout<<"�����ķ�·��Ϊ 0"<<endl;
	}
	itr=mine(target);
	map<string,vector<border>>  ::iterator dwa;
	while(!target.empty()&&itr!=target.end())
	{
		
		dwa=tdata.find(itr->first);
		itz=(dwa->second).begin();
		while(itz!=(tdata.find(itr->first)->second).end())
		{
			itc=target.find(itz->bname.name);
			if(itc->second.s<0||itc->second.s>itr->second.s+itz->time)
			{
				itc->second.s=itr->second.s+itz->time;
				itc->second.name.name=itr->first;
			}
			itz++;
		}
		targod.insert(*itr);
		if(itr->first==end)
		{
			break;
		}
		target.erase(itr);
		itr=mine(target);
	}
	output(targod,end,be);
	
	
}
void output(map<string,knod>& target,string end,string begin)
{
	double sa=0;
	stack<string> que;
	string ddi;
	map<string,knod>::iterator iit=target.find(end);
	while(iit->first!=begin&& iit!=target.end())
	{
		que.push(iit->first);
		iit=target.find(iit->second.name.name); 
	}
	que.push(begin);
	if(iit==target.end())
	{
		cout<<"��վ�޷�����"<<endl;
	}
	else{
		cout<<"���辭����·��Ϊ��"<<endl;
		while(!que.empty())
		{
			ddi=que.top();
			cout<<ddi;
		
			que.pop();
			if(!que.empty())
			{
				cout<<"->";
			}
			else
			{
				cout<<endl;
			}
		}
		map<string,knod>::iterator iit=target.find(end);
		cout<<"����Ļ���Ϊ��"<<iit->second.s<<endl;
		 
		return ;
	}
}
void distances(map<string,vector<border> >  &tdata)
{
	map<string,knod> target,targod;
	toget(tdata,target);
	string be,end;
	map<string,knod> ::iterator itr,itc;
	vector<border> ::iterator itz;	
	cout<<"��������㣺"<<endl;
	cin>>be;
	itr=target.find(be);
	if(itr==target.end())
	{
		cout<<"����������"<<endl;
		return;
	}
	else
	{
		
		(itr->second).s=0;
	}
	cout<<"�������յ㣺"<<endl;
	cin>>end;
	itr=target.find(end);
	if(itr==target.end())
	{
		cout<<"�յ��������"<<endl;
		return;
	} 
	if(be==end)
	{
		cout<<"�����ķ�·��Ϊ 0"<<endl;
	}
	itr=mine(target);
	map<string,vector<border>>  ::iterator dwa;
	while(!target.empty()&&itr!=target.end())
	{
		
		dwa=tdata.find(itr->first);
		itz=(dwa->second).begin();
		while(itz!=(tdata.find(itr->first)->second).end())
		{
			itc=target.find(itz->bname.name);
			if(itc->second.s<0||itc->second.s>itr->second.s+itz->distance)
			{
				itc->second.s=itr->second.s+itz->distance;
				itc->second.name.name=itr->first;
			}
			itz++;
		}
		targod.insert(*itr);
		if(itr->first==end)
		{
			break;
		}
		target.erase(itr);
		itr=mine(target);
	}
	cout<<"·�����ţ�"<<endl; 
	output(targod,end,be);	
return ;	
}
map<string,knod> ::iterator mine(map<string,knod> &target)
{
	map<string,knod> ::iterator itr=target.begin();
	map<string,knod> ::iterator its=target.end();
	double min=-1;
	while(itr!=target.end())
	{
		if(itr->second.s>-1)
		{
			if(min <0)
			{
				min=itr->second.s;
				its=itr;
			}
			else if(itr->second.s<min)
			{
				min=itr->second.s;
				its=itr;
			}
		}
		itr++;
		}
		return its;	

}
void toget(map<string,vector<border> >  &tdata,map<string,knod>& target)
{
	map<string,vector<border>>::iterator  itt=tdata.begin();
	vector<border> ::iterator ire;
	string s=" ";
	while(itt!=tdata.end())
	{
		target.insert(make_pair(itt->first,knod(s,-1)));
		itt++;
	} 
	cout<<"�ɹ�ѡ���վ�����£�"<<endl;
	for(auto em:target)
	{
		cout<<em.first<<" ";
	}
	cout<<endl; 
	return ;
}

