#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct Edge
{
	int x, y, weight;
	Edge() {};
	Edge(int x,int y,int w) : x(x),y(y),weight(w){}
};


bool cmp(Edge &a, Edge &b)
{
	return a.weight < b.weight;
}

vector<int> leader;

int getLeader(int x)
{
	if (x == leader[x])
		return x;
	return leader[x] = getLeader(leader[x]); //вроде тоже ретернит х
}

bool unite(int x, int y)
{
	x = getLeader(x);
	y = getLeader(y);

	if (x == y)
		return false;
	/*if (rand() % 2 == 0)
		swap(x, y);*/
	leader[x] = y;
	return true;
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;
	vector<Edge> e(edges);
	for (int i = 0; i < edges; i++)
	{
		cin >> e[i].x >> e[i].y >> e[i].weight;
	}
	sort(e.begin(), e.end(), cmp);
	leader.resize(nodes);
	for (int i = 0; i < nodes; i++)
	{
		leader[i] = i;
	}

	vector<Edge> ans;
	for (int i = 0; i < edges; i++)
	{
		int x = e[i].x;
		int y = e[i].y;
		if (unite(x, y))
			ans.push_back(e[i]);
	}
	int sum = 0;
	for (int i = 0; i < ans.size(); i++)
	{
		sum += ans[i].weight;
	}
	cout << sum << endl;
}