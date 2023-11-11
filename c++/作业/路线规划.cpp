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
	cout<<"欢迎进入地图寻路"<<endl;
	cout<<"请进行地图的创建"<<endl;
	cout<<"若要输入请按 1 ，若要退出系统请按 0"<<endl;
	cin>>se;
	if(!se)
	{
		return ;
	}
	while(se!=0)
	{
		cout<<"请输入该路线姓名"<<endl; 
	cin>>iname;
	cout<<"请输入该路线起点姓名"<<endl; 
	cin>>pname;
	cout<<"请输入该路线终点姓名"<<endl; 
	cin>>bname;
	cout<<"请输入该路线所需路程"<<endl; 
	cin>>s;
	cout<<"请输入该路线行驶速度"<<endl; 
	cin>>v;
	data.push_back(border(iname,node(pname),node(bname),s,v));
	cout<<"若要停止输入请按 0,否则请按 1"<<endl;
	cin.get();
	if(cin.get()=='0')
	{
		se=0;
	 } 
	}
	vector<border> ::iterator itr=data.begin();
	map<string,vector<border>> tdata;
	stander(data,tdata);
	cout<<"请进行路径优先选择"<<endl;
	cout<<"若最短时间路径按 1 ，若最短里程路径 2，若要退出请按0"<<endl;	
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
			cout<<"请重新输入"<<endl; 
		}
		cout<<"若最短时间路径按 1 ，若最短里程路径 2，若要退出请按0"<<endl;
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
	cout<<"请输入起点："<<endl;
	cin>>be;
	itr=target.find(be);
	if(itr==target.end())
	{
		cout<<"起点输入错误"<<endl;
		return;
	}
	else
	{
		
		(itr->second).s=0;
	}
	cout<<"请输入终点："<<endl;
	cin>>end;
	itr=target.find(end);
	if(itr==target.end())
	{
		cout<<"终点输入错误"<<endl;
		return;
	} 
	if(be==end)
	{
		cout<<"其所耗费路程为 0"<<endl;
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
		cout<<"两站无法到达"<<endl;
	}
	else{
		cout<<"所需经过的路径为："<<endl;
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
		cout<<"所需的花费为："<<iit->second.s<<endl;
		 
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
	cout<<"请输入起点："<<endl;
	cin>>be;
	itr=target.find(be);
	if(itr==target.end())
	{
		cout<<"起点输入错误"<<endl;
		return;
	}
	else
	{
		
		(itr->second).s=0;
	}
	cout<<"请输入终点："<<endl;
	cin>>end;
	itr=target.find(end);
	if(itr==target.end())
	{
		cout<<"终点输入错误"<<endl;
		return;
	} 
	if(be==end)
	{
		cout<<"其所耗费路程为 0"<<endl;
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
	cout<<"路程最优："<<endl; 
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
	cout<<"可供选择的站点如下："<<endl;
	for(auto em:target)
	{
		cout<<em.first<<" ";
	}
	cout<<endl; 
	return ;
}

