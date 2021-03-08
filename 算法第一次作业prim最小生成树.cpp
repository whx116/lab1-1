#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;
const int maxn = 1e3;
int mp[maxn][maxn];
int d[maxn];
bool v[maxn];
int N, M;
ifstream fin("input.txt");
ofstream fout("output.txt");
int prim()
{	
	v[1] = 1;//存入第一个节点
	for (int i = 2; i <= N; ++i)
	{
		v[i] = 0;//其他节点表示为未存入
		d[i] = mp[i][1];//权值赋值
	}
	int sum = 0;
	for (int i = 1; i <= N - 1; ++i)
	{
		int temp = INT_MAX, pos;
		for (int j = 1; j <= N; ++j)
		{
			if (!v[j] && d[j] < temp) {
				temp = d[j];
				pos = j;
			}//找到数值最小并且尚未存入数组v的权值
		}
		v[pos] = 1;//计入数组v代表已连通
		sum += d[pos];//权值累加
		for (int j = 1; j <= N; ++j)//遍历
		{
			if (!v[j] && d[j] > mp[pos][j] && mp[pos][j] != INT_MAX)//若未连通并且与pos距离更近，更新数组d
			{
				d[j] = mp[pos][j];
			}
		}
	}
	return sum;
}
int main()
{
	fin >> N >> M;
	int u, v, w;
	for (int i = 1; i <= N; ++i)
	{
		d[i] = INT_MAX;
		for (int j = 1; j <= N; ++j)
		{
			if (i != j)
				mp[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= M; ++i) {
		fin >> u >> v >> w;
		mp[u][v] = mp[v][u] = w;
	}
	fout << prim();
	fin.close();
	fout.close();
	return 0;
}