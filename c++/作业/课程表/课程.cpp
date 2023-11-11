#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <sstream>
#include<map>
using namespace std;


class course{
	private:
		string cno; 
		string name;
		double credit;
		
		vector<course> pre;
		int nums;
	public :
		vector<string> pno;
	course(){
		
	}	
	course(const course& s)
	{
		cno=s.cno ;
		name=s.name;
		credit=s.credit;
		pno=s.pno;
		pre.assign(s.pre.begin(),s.pre.end());
		nums=s.nums;
	}
	course(string cn,string na,double cre,vector<string> pn):cno(cn),name(na),credit(cre),pno(pn){
		
	}
	void setp(vector<course> Pre){
		pre.assign(Pre.begin(),Pre.end());
	}
	void setn(int n)
	{
		nums=n;
		return;
	}
	int Nums()
	{
		return nums;
	}
	void show()
	{
		cout<<" "<<cno<<" "<<name<<" "<<credit<<" "<<nums<<" ";
		for(auto em:pno) 
		cout<<em<<" ";
		
		cout<<endl;
	return;
		}	
	string Cno()
	{
		return cno;
	}
	string Name()
	{
		return name;
	}
	double Cridit()
	{
		return credit;
	}
	vector<string> Pno()
	{
		return pno;
	}
	vector<course> Pre()
	{
		return pre;
	}

	void setnum(vector<map<string,course>> &kdata)
{
	if(pno.size()==0)
	{
		nums=0;
		return;		
	}

		int max=0;
	
	map<string,course>::iterator itr;
	int a;
	for(auto em:pno)
	{
		for(auto am:kdata)
		{
			itr=am.find(em);
			if(itr!=am.end())
			{
				 a=itr->second.Nums();
				if(a>max)
				{
					max=itr->second.Nums();
				}
				break;
			}
		}
	}
	nums=max+1;		
	}


		
};
void ave(	vector<vector<map<string,course>>> &enddata,int n,double cridit);
void show(map<string,course>& cdata);
void cinput(map<string,course> &cdata);
void output(int &n,double &cridit,map<string,course> cdata);
void sinput(int &n,double &cridit); 
void modify(map<string,course>& cdata); 
void anpai(	vector<map<string,course>> kdata,int n,double cridit);
void pai(	vector<vector<map<string,course>>> &enddata,int n,double cridit);
void test();
void menu();
int main()
{
	test();
	return 0;
}
void menu()
{
	printf("��ӭʹ�ÿγ̹���ϵͳ\n");
	printf("��������ʹ�ù������\n");
	printf("1.�γ�����\n");
	printf("2.�γ��޸�\n");
	printf("3.ѧ������\n");
	printf("4.�����ʾ\n");
	printf("5.�˳�ϵͳ\n");
}
void test()
{
	int num,n;
	double cridit;
	
	map<string,course> cdata;
	while(true)
	{
	menu();
	cin>>num;
	switch(num)
	{
		case 1:
			cinput(cdata);
			break;
		case 2:
			modify(cdata);
			break;
		case 3:
			sinput(n,cridit);
			break;
		case 4:
			output(n,cridit,cdata);
			break;
		case 5:
			return ;
			break;
		default:
			cout<<"�����������������"<<endl;
			break;

	}
	}
	
 } 
void cinput(map<string,course>& cdata)
{
	string cno,cna,cnn;
	vector<string>pn;
	int flag=1;
	double cre;
	cout<<"��������룺"<<endl;
	while(flag)
	{
	cout<<"�γ̺�  �γ���  ѧ��"<<endl; 
	cin>>cno>>cna>>cre;
	cout<<"���Ƿ������޿Σ���������1����������0"<<endl;
	cin>>flag; 
	while(flag)
	{
		cout<<"�����������޿Σ�"<<endl; 
		cin>>cnn;
		cout<< "�������������޿��밴1�������밴0"<<endl;
		cin>>flag;
		pn.push_back(cnn);
	}
	cdata.insert(make_pair(cno,course(cno,cna,cre,pn)));
	pn.clear();	
	cout<< "���������밴1�������밴0"<<endl;
	cin>>flag;
	}	
	return ;
}
void show(map<string,course>& cdata)
{
	cout<<"�γ̺�  �γ���  ѧ��  ���޿�"<<endl; 
	for(auto em:cdata)
	{
		em.second.show();
	}
}
void modify(map<string,course>& cdata)
{
	string cno,cna,cnn;
	vector<string> pn;
	int flag=1;
	double cre;
	cout<<endl;
	cout<<"�ɹ�ѡ���޸ĵĿγ����£�"<<endl;
	show(cdata) ;
	cout<<"������Ҫ�޸ĵĿγ̺ţ�"<<endl;
	map<string,course>::iterator itr;
	while(flag)
	{
	cin>>cno;
	
	itr=cdata.find(cno); 
	if(itr!=cdata.end())
	{
	cout<<"�γ���  ѧ��" <<endl; 
	cin>>cna>>cre;
	cout<<"���Ƿ������޿Σ���������1����������0"<<endl;
	cin>>flag; 
	while(flag)
	{
		cout<<"�����������޿Σ�"<<endl; 
		cin>>cnn;
		cout<< "�������������޿��밴1�������밴0"<<endl;
		cin>>flag;
		pn.push_back(cnn);
	}
	cdata.erase(itr);
	cdata.insert(make_pair(cno,course(cno,cna,cre,pn)));	
	cout<< "���������밴1�������밴0"<<endl;
	cin>>flag;
	}
	else 
	{
		cout<<"�ÿγ�δ¼�룬����������"<<endl; 
	 } 

	
	}	
	return ;

}
void sinput(int &n,double &cridit)
{
	cout<<"������ѧ����"<<endl;
	cin>>n;
	cout<<"������ÿѧ������޶���ѧ��"<<endl;
	cin>>cridit;
	return ;
}

void output(int &n,double &cridit,map<string,course> cdata)
{
	vector<map<string,course>> kdata;
	map<string,course> data;
	map<string,course>::iterator itr;
	int flag=1;
	while(!cdata.empty())
	{
		for(auto em:cdata)
		{
			for(auto am:em.second.Pno())
			{
				itr=cdata.find(am);
				if(itr!=cdata.end())
				{
					flag=0;
					}	
					
			}
			if(flag==1)
			{
				em.second.setnum(kdata);
				if(kdata.size()>em.second.Nums())
				{
				kdata[em.second.Nums()].insert(em);					
				}
				else
				{
				data.insert(em);
				kdata.push_back(data);
				data.clear();	
				}

				
				cdata.erase(em.first);
				break;
			}

		}
	}
	if(n<kdata.size())
	{
		cout<<"ѧ����̫�٣��޷�ѧ��ȫ���γ�"<<endl;
		return; 
	}
	else
	{
		anpai(kdata,n,cridit);
	}
	return ;
}

void anpai(	vector<map<string,course>> kdata,int n,double cridit)
{
	vector<map<string,course>> ::reverse_iterator j = kdata.rbegin(); 
	vector<vector<map<string,course>>> enddata(kdata.size(),vector<map<string,course>>(kdata.size()));
	vector<string> ::iterator itrc;
	map<string,course>::iterator itrm1,itrm2,itrm3;
	course last,tail;
	map<string,course> ::iterator itr;
	//shuchu
	for(auto am:kdata)
	{
		for (auto em:am)
		{
			
				em.second.show();
			
		}
	}
	int cs=0;
	for(int i=0;j != kdata.rend();j++,i++)//ÿһ����б��� 
	{
	
		int num;
		for(itrm1=j->begin();itrm1!=j->end();)//ÿһ���е�Ԫ�� 
		{
				num=kdata.size()-1;
				enddata[i][num].insert(*itrm1);
			
				kdata[num-cs].erase(itrm1++);
		}
		while(num!=i-1)
		{
				for(itrm2=enddata[i][num].begin();itrm2!=enddata[i][num].end();itrm2++)//��׼�����������Ԫ�ر��� 
		{
			
					 
					itrc=itrm2->second.pno.begin();
				for(itrc=itrm2->second.pno.begin();itrc!=itrm2->second.pno.end();itrc++	)//ÿһ����Ԫ�ص�ǰ�����б��� 
		{
			for(auto &em:kdata)
			{
				itrm3=em.find(*itrc);
				if(itrm3!=em.end())
				{
					int anm=itrm3->second.Nums();

					enddata[i][anm+i].insert(*itrm3);

					em.erase(itrm3);

					break;
				}
				
			}	

		}
}
		num--;

	//	itrm2=enddata[i][num].begin();
	//	cout<<"itr"<<itrm2->second.Cno()<<endl;

				
		}
	

	
				cs++;

		}
		int i=0;
		int jk=0;
			for(i=0;i<enddata.size();i++)
	{
		cout<<"------"<<"i"<<i<<"---------"<<endl;
		for(jk=0;jk<enddata[i].size();jk++)
		{
		cout<<"------"<<"j"<<jk<<"---------"<<endl;
			for(auto bm:enddata[i][jk])
			{
				bm.second.show();
			}
			
		}

	}
	double sum=0;
	double avesum=0;
	int size=enddata.size();
	vector<map<string,course>> mulu;
	for(auto em:enddata)
	{
		for(auto am:em)
		{
			for(auto bm:am)
			{
				sum+=bm.second.Cridit();
			}
		}
	}
	double ave=sum/n;
	if(ave>cridit)
	{
		cout<<"�γ����ù��࣬�޷��ɹ�����"<<endl; 
		return ;
	 } 
	 if((cridit-ave)/2>4)
	 {
	 	ave+=4;
	 }
	 else
	 {
	 ave+=(cridit-ave)/2;	 	
	 }
	 
		pai(enddata,n,cridit);		
}
void pai(	vector<vector<map<string,course>>> &enddata,int n,double cridit)
{
	double sum=0;
	double avesum=0;
	vector<vector<int>> rank(enddata.size(),vector<int>(enddata.size()));
	int size=enddata.size();
	vector<map<string,course>> mulu;
	map<string,course> ke;
	int x1,x2,y1,y2,a;
	x2=1,y2=1,x1=0,y1=0;
	map<string,course>::iterator itrm1=enddata[x1][y1].begin(),itrm2=enddata[x2][y2].begin(),itrm3;
	cout<<"itr1"<<itrm2->second.Cno()<<endl;
	int sem=0;
	int flag1=1,flag2=1,flag3=1;
	if(sem>=n)
	{
		flag1=0;
	}
	for(sem=0;sem<n&&flag1;sem++)
	{
		ke.clear();
		avesum=0;
		flag2=1;
		for(;itrm1!=enddata[x1][y1].end();)
		{
			if(itrm1==enddata[x1][y2].begin()&&x1==x2&&y1==y2&&flag3)
			{
				cout<<"buyai"<<endl;
				flag2=0;
				itrm1=itrm2;
				if(y2!=size-1)
					{
						x2++;
						y2++;
						itrm2=enddata[x2][y2].begin();
					}
				else
					{
						if(y1<size-1)
						{
								int a=y2-x2;
						y2=y1+1;
						x2=y2-a-1;


						}
						else
						{
							flag3=0;
						}
					
					}

					
				
			}

			avesum+=itrm1->second.Cridit();
			if(avesum>cridit)
			{
				mulu.push_back(ke); 
				break;
			}
			else
			{
				cout<<"sem"<<sem<<endl; 
				cout<<"charux1="<<x1<<"  y1="<<y1<<endl;
				cout<<"x2="<<x2<<"  y2="<<y2<<endl;
				cout<<"yuansu::"<<itrm1->second.Cno();
				cout<<"cridit"<<cridit<<"avesem"<<avesum<<endl;
				cout<<endl;

				ke.insert(*itrm1);
				itrm1++;
			}
		
		if(itrm1==enddata[x1][y1].end())
		{
			rank[x1][y1]=sem;
						if(flag3==0)
			{
				flag1=0;
			mulu.push_back(ke); 
				break;
			}
			if(flag2==0)
			{
				x1=0;
				y1++;
				itrm1=enddata[x1][y1].begin();
				break;
			}

			if(x1==y1)
			{
				if(y1==size-1)
				{
					//flag1=1;
					mulu.push_back(ke); 
					break;
				}
				else
				{
					y1++;
					x1=0;
					cout<<"diyi"<<avesum<<endl;

					itrm1=enddata[x1][y1].begin();
					
					break;
				}
			}
			else if(y2-x2<y1){
				x1++;
				itrm1=enddata[x1][y1].begin();}
			else if(y1==y2&&x1==x2)
			{
					x1=x2;
					y1=y2;
					itrm1=itrm2;
					if(y2!=size-1)
					{
						x2++;
						y2++;
						itrm2=enddata[x2][y2].begin();
					}
					else
					{
						if(y1<size-1)
						{
						int a=y2-x2;
						y2=y1+1;
						x2=y2-a-1;
						itrm2=enddata[x2][y2].begin();							
						}
						else{
							flag3=0;
						}

					}
				}	
		
			
			}
		}
			
		if(avesum<cridit&&y1>=sem)
		{
		for(;itrm2!=enddata[x2][y2].end()&&flag3;)
			{

				if(x2!=y2&&rank[x2][y2-1]>=sem)
				{
					mulu.push_back(ke);
					break;
				}
				avesum+=itrm2->second.Cridit(); 
				if(avesum>cridit)
				{


					mulu.push_back(ke);
					
					break;
				}
				else
				{
				cout<<"x1="<<x1<<"  y1="<<y1<<endl;
				cout<<"chax2="<<x2<<"  y2="<<y2<<endl;
				
				cout<<"yuansu::"<<itrm2->second.Cno();

					ke.insert(*itrm2);
					itrm2++;
					
				}
				if(itrm2==enddata[x2][y2].end())
				{
					if(y2<size-1)
					{
						y2++;
						x2++;
						itrm2=enddata[x2][y2].begin();
					}
					else {
									
								if(y1<size-1)
						{
								int a=y2-x2;
						y2=y1+1;
						x2=y2-a-1;
						cout<<"dashen"<<endl;
						cout<<"dashen"<<endl;
						cout<<"dashen"<<endl;
						cout<<"dashen"<<endl;
						cout<<endl;
						
						}
						else
						{
							flag3=0;
						}
					
					}
				}
			}
	}}
				int i=0;
		int jk=0;
			for(auto em:mulu)
	{
		cout<<"------"<<"i"<<i<<"---------"<<endl;
		
	

			for(auto bm:em)
			{
				bm.second.show();
			
			
		}
		i++;
	}
	}
	

void pao(	vector<vector<map<string,course>>> &enddata,int n,double cridit)
{
	double sum=0;
	double avesum=0;
	vector<vector<int>> rank(enddata.size(),vector<int>(enddata.size()));
	int size=enddata.size();
	vector<map<string,course>> mulu(n,map<string,course>());
	int x1,x2,y1,y2,a;
	x2=1,y2=1,x1=0,y1=0;
	map<string,course>::iterator itrm1,itrm2=enddata[x2][y2].begin(),itrm3;
	int sem=0;
	for(;sem<n;sem++)
	{
		cout<<"diyic1"<<endl;
		avesum=0;
		if(y1<=sem)//����ÿһ������ 
		{
			int flag=1;
			for(;y1<=sem&&x1<=y1&&avesum<cridit&&flag;)
			{
				cout<<"diyic2"<<endl;
				if(x1==x2&&y1==y2&&y1<size-1)
				{
					itrm1=itrm2;
				//	cout<<"dadaalax1:"<<x1<<"y1:"<<y1<<endl;
					//cout<<"itr1:"<<itrm1->second.Cno()<<endl;
					if(y2<size-1)
					{
					y2++;
					x2++;
					itrm2=enddata[x2][y2].begin();
					}
					cout<<"end"<<endl;
					
				}
				else if(x1==0){
					cout<<"lalax1:"<<x1<<"y1:"<<y1<<endl;
					
					itrm1=enddata[x1][y1].begin();
					cout<<"itrm1"<<itrm1->second.Cno()<<endl;					
					
				}
				
				if(x1==y1||rank[x1][y1-1]<sem)
				{
					cout<<"sem"<<sem<<endl;
					cout<<"x1:"<<x1<<"y1:"<<y1<<endl;
					cout<<"x2:"<<x2<<"y2:"<<y2<<endl;
					cout<<"itrm1"<<itrm1->second.Cno()<<endl;
					cout<<"itrm2"<<itrm2->second.Cno()<<endl;
				for(;itrm1!=enddata[x1][y1].end();)//ÿ����Ԫ�� 
				{
					cout<<"diyic3"<<endl;
					avesum+=itrm1->second.Cridit();
					if(avesum>cridit)
					{
						cout<<"svver"<<avesum<<endl;
						cout<<"cridit"<<cridit<<endl;
					
						sum+=avesum;
						break;
					}
					mulu[sem].insert(*itrm1);
					cout<<"jinru"<<itrm1->second.Cno()<<endl;
					itrm1++;
					if(itrm1==enddata[x1][y1].end())
					{
						rank[x1][y1]=sem;
					if(x1==y1)
					{
					y1=y1+1;
					x1=0;
					}
					else{
						x1++;
					}
					
					if(y1>sem)
					{
						cout<<"laa1"<<endl;
						break;
					}
					
					}
					
				}
					if(y1>size-1)
					{
						break;
						cout<<"laa2"<<endl;
					}
				}
				if(avesum<cridit)
					{
				x1++;
				itrm1=enddata[x1][y1].begin();
					}
				else
				{
					break;
				}
		
			
			}
		}

		if(avesum<cridit&&y1<size-1)
		{
			if(y2<=size)
			{
				if(x2==y2||rank[x2-1][y2]<sem)
				{
				for(;itrm2!=enddata[x2][y2].end();)//ÿ����Ԫ�� 
				{
					avesum+=itrm2->second.Cridit();
					if(avesum>cridit)
					{
						avesum=avesum-itrm2->second.Cridit();
						break;
					}
					mulu[sem].insert(*itrm2);
					itrm2++;
					if(itrm2==enddata[x2][y2].end())
					{
						rank[x2][y2]=sem;
						x2++;
						y2++;
						if(y2>=size-1)
						{
							if(y1=size-1)
							{
								break;
							}
							int dd=y2-x2+1;
							y2=y1;
							x2=y2+dd;
							itrm2=enddata[x2][y2].begin();
						}
						

					}
				}					
				}
				
			}
			sum+=avesum;
		}
		
	}
		int i=0;
		int jk=0;
			for(auto em:mulu)
	{
		cout<<"------"<<"i"<<i<<"---------"<<endl;
		
	

			for(auto bm:em)
			{
				bm.second.show();
			
			
		}
		i++;
	}
}
void ave(	vector<vector<map<string,course>>> &enddata,int n,double cridit)
{
	double sum=0;
	double avesum=0;
	int size=enddata.size();
	vector<map<string,course>> mulu;
	for(auto em:enddata)
	{
		for(auto am:em)
		{
			for(auto bm:am)
			{
				sum+=bm.second.Cridit();
			}
		}
	}
	double ave=sum/n;
	if(ave>cridit)
	{
		cout<<"�γ����ù��࣬�޷��ɹ�����"<<endl; 
		return ;
	 } 
	 if((cridit-ave)/2>4)
	 {
	 	ave+=4;
	 }
	 else
	 {
	 ave+=(cridit-ave)/2;	 	
	 }

	 int x1,x2,y1,y2,a;
	 map<string,course>::iterator itrm1,itrm2,itrm3;
	x2=0,y2=0,x1=0,y1=0;
	
	 for(int sem=0;sem<n;sem++)
	 {
	 
	 	while(x1<sem)
	 	{
	 		for(itrm1;itrm1!=enddata[x1][y1].end();itrm1++)
	 		{
	 			if(avesum+=itrm1->second.Cridit()<ave)
	 			{
	 			//	avesum+=itrm1.second.Credit();
	 				mulu[sem].insert(*itrm1);
	 				cout<<"fitr"<<endl;
				 }
				 else
				 {
				 	break;
				 }
			 }
			 if(itrm1==enddata[x1][y1].end())
			 {
			 	if(y1<x1)
				 {
				 	y1++;
				 	
				  } 
				  else 
				  {
				  	y1++;
				  	x1++;
				  }
			 	itrm1=enddata[x1][y1].begin();
			 }

		 }
		 if(avesum<ave&&x1>=sem)
			 {
			 		cout<<"fitr2"<<endl;
			itrm2=enddata[x2][y2].begin();
	 		while(itrm2!=enddata[x2][y2].end())
	 		{
	 			if(avesum+=itrm2->second.Cridit()<ave)
	 			{
	 			//	avesum+=itrm1.second.Credit();
	 				mulu[sem].insert(*itrm2);
				 }
				 else
				 {
				 	break;
				 }
				 itrm2++;
 			 if(itrm2==enddata[x2][y2].end())
			 {
			 	if(x2-y2<sem&&x2<x1)
			 	{
			 		y2++;
			 		itrm2=enddata[x2][y2].begin();
			 		
				 }
				 else
				 {
				 	x2++;
				 	y2=0;
				 	itrm2=enddata[x2][y2].begin();
				 	break;
				 }
			 }
			 }
			while(avesum<ave)
			{
					while(itrm1!=enddata[x1][y1].end())
						{
	 			if(avesum+=itrm1->second.Cridit()<ave)
	 			{
	 			//	avesum+=itrm1.second.Credit();
	 				mulu[sem].insert(*itrm1);
				 }
				 else
				 {
				 	break;
				 }
				 itrm1++;
		 	 if(itrm1==enddata[x1][y1].end())
			 {
			 	
			 	if(y1==x1)
				 {
				 	y1++;
				  	x1++;
				 	
				  } 
				
			 	itrm1=enddata[x1][y1].begin();
			 }
			 }
			}
			 }
			 
	 }
	 for(auto em:mulu)
	 {
	 	for(auto am:em)
	 	{
	 		am.second.show();
		 }
	 }

}

