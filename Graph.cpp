#include<iostream>
#include<fstream>
#include<cstring>
#include<stack>
#include"Graph.h"
using namespace std;

Graph::Graph(string inputfile)
{
	ifstream in;
	int vertex[3];
	int nlines=0;
	string line;
	char input[3];
	in.open(inputfile.c_str());
	while(getline(in,line))
	{
		nlines++;
		char *tmp=strtok(&line[0]," ");
		if(nlines==1)
		{
			this->V=stoi(tmp);
			this->adjlst= new list<GraphNode>[this->V];
			continue ;
		}
		if(tmp==NULL)
			continue;
		else
		{ int i=0;
			vertex[i++]=stoi(tmp);
			while(tmp!=NULL)
			{
				tmp=strtok(NULL," ");
				if(tmp!=NULL)
				vertex[i++]=stoi(tmp);
			}
		}
        if(!EdgePresent(vertex[0],vertex[1]))
		{
        GraphNode node(vertex[1],vertex[2],-1);
		addEdge(vertex[0],node);
        }

	}

	in.close();

};
void Graph::addEdge(int s,GraphNode node)
{
	adjlst[s].push_back(node);
	GraphNode  rev_node(s,node.weight,node.parent);
	adjlst[node.des].push_back(rev_node);
}
int Graph::getVertex()
{
	return this->V;
}

list<GraphNode >*  Graph::getList()
{
  return adjlst;
}
bool is_connected(Graph graph)
{
	int v=graph.V;
	if(v>DFS(graph,0))
		return false;
	else
		return true;
}

bool Graph::EdgePresent(int s,int d)
{
	for(list<GraphNode>::iterator it=adjlst[s].begin();it != adjlst[s].end();it++)
	{
		if(it->des==d)
			return true;
	}
	return false;
}

int DFS(Graph obj,int s)
{
	bool v[obj.getVertex()];
	int count=0;
	list<GraphNode > *adjlst=obj.getList();

	v[s]=true;
	count++;
	stack<int>stck;
	stck.push(s);
	while(!stck.empty())
	{
		int top=stck.top();
		stck.pop();
		for(list<GraphNode>:: iterator it=adjlst[top].begin();it!=adjlst[top].end();it++)
		{
			if(!v[it->des])
			{
				v[it->des]=true;
				stck.push(it->des);
				count++;

			}
			else
				continue;

		}


	}
return count ;

}
