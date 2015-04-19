#include<iostream>
#include"Graph.h"
#include"DijFib.h"
using namespace std;
int main(int argc ,char  *argv[])
{
	int s,d;
	SSP res;
	if(argc!=4)
	{
		cout<<"Wrong no of arguments "<<endl;
		return 0;
	}
	int tmp=stoi(argv[3]);
	string inputfile="input_1000000.txt";
	Graph g(argv[1]);
//	if(!is_connected(g))
//cout<<"The graph is not connected";
//	else
//	{
//	cout <<"Enter source and destination of graph"<<endl;
  //  cin>>s>>d;
    res=DjkstraFibHeap(g,stoi(argv[2]));
	cout<<" "<<res.Dis[tmp]<<" "<<endl;
    while(tmp!=stoi(argv[2]))
	{
		cout<<" "<<res.Par[tmp]<<" ";
		tmp=res.Par[tmp];

	}

//	}
	return 0;
}
