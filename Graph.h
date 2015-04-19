#ifndef _GraphNode_
#define _GraphNode_
#include<iostream>
#include<list>
#include<string>
#include<vector>
using namespace std;
struct GraphNode
{
	int des;
	int weight;
	int parent;
	GraphNode(int d,int w,int p)
	{
		des=d;
		weight=w;
		parent=p;
	}
};

class Graph
{
	int V;
	list<GraphNode> *adjlst;
	public:
	int getVertex();
	list<GraphNode>* getList();

	vector<string>Ip;
	Graph(string);
    bool EdgePresent(int s,int d);
	void addEdge(int ,GraphNode);
	friend bool is_connected(Graph graph);

};
int DFS(Graph,int);
#endif



