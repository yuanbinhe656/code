#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef class treenote* listnote;
class treenote{
	public:
		int data,cneg;
		listnote par;
		vector<listnote> son;
		vector<listnote> neg;
		vector<listnote> sub;

	public:
		treenote(int par):data(par),cneg(0)
		{
			this->par=NULL;
		}

		void parset(listnote pa)
		{
			this->par=pa;
			listnote far=pa;
			pa->son.push_back(this);
			while(far!=NULL)
			{

				if(this->data<far->data)
				{
					this->neg.push_back(far);
					this->cneg++;
					cout<<'<'<<far->data<<','<<this->data<<'>'<<" "<<endl;
					
				}
				else 
				{
					this->sub.push_back(far);
				}
				if(far->par==NULL)
				{
					far->cneg+=this->cneg;
				}
											far=far->par;
	
				//cout<<"this:"<<this->data<<"far:"<<far->data<<endl; 

			}


			
			
		}
		void parset()
		{
			this->par=NULL;
			
		}
		int cnegs()
		{
			return cneg;
		}

};
void test()
{
		int n,m,data,post;
	cin>>n>>m;
	vector<listnote> tree;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		tree.push_back(new treenote(data));
	}
	for(int i=1;i<n;i++)
	{
		cin>>data;
		data--;
		tree[i]->parset(tree[data]);
	}
	for (int i=0;i<m;i++)
	{
		cin>>data;
		if(data==1)
		{
			
			cin>>post>>data;
			tree.push_back(new treenote(data));
			vector<listnote>::iterator itr=tree.end()-1;
			(*(itr))->parset(tree[post-1]) ;
			
		}
		else if(data==2)
		{
			cout<<"em:";
			int sa=0;
			for(auto em:tree)
			{
				 
				cout<<sa++<<":"<<em->cnegs()<<' ';
			}
			cout<<endl;
			cin>>post;
			post--;
			queue<listnote> tre;
			tre.push(tree[post]);
			cout<<"treepos"<<tree[post]->cnegs()<<endl; 
			int	num=tree[0]->cnegs();;
			int cun=0;
			cout<<"tree:"<<tree[0]->cnegs()<<endl;
			while(!tre.empty())
			{
				listnote s=tre.front();
				tre.pop();
				cun++;
				if(s->par!=NULL)
				{
				num=num-s->cnegs();
				}

				cout<<s->cnegs()<<' ';
				for(listnote em:s->son)
				{
	
					tre.push(em);
				}

			}
							cout<<endl;
			cout<<"count"<<cun<<endl;
			cout<<"put"<<num<<endl;
		}
	}
}
void test1()
{
		int n,m,data,post;
	cin>>n>>m;
	vector<listnote> tree;
	for(int i=0;i<n;i++)
	{
		cout<<"put-ing"<<endl;
		cin>>data;
		tree.push_back(new treenote(data));
	}
	for(int i=1;i<n;i++)
	{
		cout<<"set-ing"<<endl;
		cin>>data;
		data--;
		tree[i]->parset(tree[data]);
	}
}
int main()
{

test();


	return 0;
}
