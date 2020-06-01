// In The Name Of Allah

#include <string>
#include "STK.h"
#include "Queue.h"

using namespace std;

const int max = 10;

struct vertex
{
	int num = -1;
	vertex *e[max];
};

class Graph
{
	vertex v[max];
	int noV;
	int noE;
	
public:
	Graph();
	vertex getV(int);
	int NumOfV();
	int NumOfE();
	void addV();
	void addE(int,int);
	void delV();
	void delE(int, int);
	int degree(int);
	int maxDegreeOfGraph();
	bool hasDistance(int, int);
	int hasDistance(int, int, string);
	bool hasLoop(int);
	bool hasLoop();
	bool isConnective();
	string matris();
	string DFS();
	string BFS();
};

Graph::Graph()
{
	noV = 0;
	noE = 0;
	for (int i = 0; i < max; i++)
		for (int j = 0; j < max; j++)
			v[i].e[j] = nullptr;
}

vertex Graph::getV(int n)
{
	if (n >= 0 && n < noV)
		return v[n];
	
	vertex ver;
	for (int i = 0; i < max; i++)
		ver.e[i] = nullptr;
	return ver;
}

int Graph::NumOfV()
{
	return noV;
}

int Graph::NumOfE()
{
	return noE;
}

void Graph::addV()
{
	if (noV < max)
	{
		v[noV].num = noV;
		noV++;
	}
	return;
}

void Graph::addE(int a, int b)
{
	if (a < noV && b < noV && a >= 0 && b >= 0 && a != b)
	{
		v[a].e[b] = &v[b];
		v[b].e[a] = &v[a];
		noE++;
	}
	return;
}

void Graph::delV()
{
	if (noV > 0)
	{
		noE -= degree(noV - 1);
		v[noV - 1].num = -1;
		for (int i = 0; i < noV; i++)
			v[noV - 1].e[i] = nullptr;
		for (int i = 0; i < noV - 1; i++)
			v[i].e[noV - 1] = nullptr;
		noV--;
	}
	return;
}

void Graph::delE(int a, int b)
{
	if (noE > 0 && noV > 1 && a < noV && b < noV && a >= 0 && b >= 0 && a != b && v[a].e[b] && v[b].e[a])
	{
		v[a].e[b] = nullptr;
		v[b].e[a] = nullptr;
		noE--;
	}
	return;
}

int Graph::degree(int n)
{
	if (n >= 0 && n < noV)
	{
		int d = 0;
		for (int i = 0; i < noV; i++)
			if (v[n].e[i])
				d++;
		return d;
	}
	return -1;
}

int Graph::maxDegreeOfGraph()
{
	int d = 0;
	for (int i = 0; i < noV; i++)
		if (degree(i) > d)
			d = degree(i);
	return d;
}

bool Graph::hasDistance(int a, int b)
{
	if (a < noV && b < noV && a >= 0 && b >= 0)
	{
		if (v[a].e[b])
			return true;

		for (int i = a + 1; i < noV; i++)
			if (v[a].e[i])
				if (hasDistance(v[a].e[i]->num, b) == 1)
					return true;
	}

	return false;
}

int Graph::hasDistance(int a, int b, string s)
{
	int n = 0;
	if (v[a].e[b])
		n++;
	for (int i = a + 1; i < noV; i++)
		if (v[a].e[i])
			if (hasDistance(v[a].e[i]->num, b, "loop") >= 1)
				n += hasDistance(v[a].e[i]->num, b, "loop");
	return n;
}

bool Graph::hasLoop(int n)
{
	int i = hasDistance(n, n, "loop");
		if (i >= 2)
			return true;
	return false;
}

bool Graph::hasLoop()
{
	if (isConnective() && noE >= noV)
		return true;
	if (isConnective() && noE < noV)
		return false;
	if (!isConnective() && noE >= noV -1)
		return true;
	if (!isConnective() && noE < noV - 1)
	{
		for (int i = 0; i < noV; i++)
			if (hasLoop(i))
				return true;
	}
	return false;
}

bool Graph::isConnective()
{
	for (int i = 1; i < noV; i++)
			if (!hasDistance(0, i))
				return false;
	return true;
}

string Graph::matris()
{
	if (noV == 0)
		return "Graf rasi nadarad.";

	string m = "  ";

	for (int i = 0; i < noV; i++)
	{
		m += char(v[i].num + 48);
		m += " ";
	}
	m += "\n";
	for (int i = 0; i < noV; i++)
	{
		m += char(v[i].num + 48);
		m += " ";
		for (int j = 0; j < noV; j++)
			m += (v[i].e[j] ? "1 " : "0 ");
		m += "\n";
	}

	return m;
}

string Graph::DFS()
{
	if (noV <= 0)
		return "Graf rasi nadarad.";

	string dfs = "";
	STK s;
	bool m[max];
	for (int j = 0; j < max; j++)
		m[j] = true;
	int i = 0;

	s.push(v[0].num);
	m[0] = false;
	while (s.showTop() > -1)
	{
		i = s.pop();
		dfs += char(i + 48);
		dfs += ' ';
		for (int j = 0; j < noV; j++)
		{
			if (v[i].e[j])
			{
				if (m[j])
				{
					s.push(v[i].e[j]->num);
					m[j] = false;
				}
			}
		}
	}

	return dfs;
}

string Graph::BFS()
{
	if (noV <= 0)
		return "Graf rasi nadarad.";

	string bfs = "";
	Queue q;
	bool m[max];
	for (int j = 0; j < max; j++)
		m[j] = true;
	int i = 0;

	q.push(v[0].num);
	m[0] = false;
	while (q.showFront() <= q.showBack())
	{
		i = q.pop();
		bfs += char(i + 48);
		bfs += ' ';
		for (int j = 0; j < noV; j++)
		{
			if (v[i].e[j])
			{
				if (m[j])
				{
					q.push(v[i].e[j]->num);
					m[j] = false;
				}
			}
		}
	}

	return bfs;
}