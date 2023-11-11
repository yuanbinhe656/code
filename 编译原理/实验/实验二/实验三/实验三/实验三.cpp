#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
struct Node {//DFA节点
	int s;
	bool flag;//标记一个DFA节点集合是否包含NFA结束态,即表示DFA中是否是一个结束态 
	Node(int ss, bool f) {
		s = ss;
		flag = f;
	}
};
struct Edge {//DFA边 
	int from, to;
	char c;
	Edge(int x, int y, char z) {
		from = x;
		to = y;
		c = z;
	}
};
const int MAX = 101;
int zf;//字符数 
char zfj[MAX];//字符集 
int zt;//状态数，0开始 
int Begin, End;//起始和结束态
char G[MAX][MAX]; //存边 
int vis[MAX];//标记NFA状态是否被访问，求闭包用到 
vector<Node> V;//DFA节点集 
vector<Edge> edge;//DFA边集 
int eps_clos[MAX];//求过的闭包保存以后用 
queue<int> eq;
int E_closure(int x)//求eps闭包 
{
	if (eps_clos[x] != -1)
		return eps_clos[x];
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	int S = 0;
	S = S | (1 << x);
	q.push(x);
	while (!q.empty()) {//BFS求闭包 
		int v = q.front();
		q.pop();
		for (int w = 0; w < zt; w++) {
			if (G[v][w] == '#' && !vis[w]) {
				vis[w] = 1;
				S |= (1 << w);
				q.push(w);
			}
		}
	}
	eps_clos[x] = S;
	return S;
}
int set_edge(int s, char c)//求一个状态集消去字符到达的状态集 
{
	int i, j;
	int S = 0;
	for (i = 0; i < zt; i++) {
		if ((s >> i) & 1) {
			for (j = 0; j < zt; j++) {
				if (G[i][j] == c)
					S |= E_closure(j);
			}
		}
	}
	return S;
}
bool check(int s)//检查DFA节点集是否出现过 
{
	for (int i = 0; i < V.size(); i++) {
		if (V[i].s == s) return true;
	}
	return false;
}
bool is_end(int s)//状态集是否包含终结点 
{
	return (s >> End) & 1;
}
void ZJGZ()//子集构造算法 
{
	int i;
	queue<int> work;
	work.push(E_closure(0));
	V.push_back(Node(E_closure(0), is_end(E_closure(0))));//加入DFA节点集 
	while (!work.empty()) {
		int v = work.front();
		work.pop();
		for (i = 0; i < zf; i++) {//遍历字符集 
			int s = set_edge(v, zfj[i]);//生成NFA消去完该字符所能到达的所有状态 
			if (s != 0) {
				edge.push_back(Edge(v, s, zfj[i]));
				if (!check(s)) {
					V.push_back(Node(s, is_end(s)));
					work.push(s);
				}
			}
		}
	}
}

void out_put(int i, int s, bool f)
{
	printf("DFA状态：q%d 包含的NFA中的状态为：", i);
	for (int j = 0; j < zt; j++)
		if ((s >> j) & 1) printf("s%d ", j);
	if (f) printf("包含结束态\n");
	else printf("不包含结束态\n");
}
int main()
{
	memset(eps_clos, -1, sizeof(eps_clos));
	ifstream in("testin.txt");
	ofstream out("testout.txt");
	in >> zf;
	for (int i = 0; i < zf; i++)
		in >> zfj[i];
	in >> zt;
	in >> Begin >> End;
	int n;//NFA边数 
	in >> n;
	int x, y;
	char c;
	for (int i = 0; i < n; i++) {
		in >> x >> c >> y;
		G[x][y] = c;
	}
	in.close();
	ZJGZ();

	out << zf << endl;
	for (int i = 0; i < zf; i++)
		out << zfj[i] << ' ';
	out << endl;
	map<int, int> mp;//DFA状态集映射到从0开始的状态标号 
	out << V.size() << endl;
	for (int i = 0; i < V.size(); i++) {
		out << i << ' ' << V[i].flag << endl;
		mp[V[i].s] = i;
	}
	out << edge.size() << endl;
	for (int i = 0; i < V.size(); i++)
		out_put(i, V[i].s, V[i].flag);
	for (int i = 0; i < edge.size(); i++) {
		out << mp[edge[i].from] << ' ' << mp[edge[i].to] << ' ' << edge[i].c << endl;
		printf("状态q%d -> 状态q%d，消去字符%c\n", mp[edge[i].from], mp[edge[i].to], edge[i].c);
	}
	out.close();
}

