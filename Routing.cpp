#include "Routing.h"
int getNextHop(vector<int> &P,int s,int d)
{
	while(P[d]!=s)
	{
		d=P[d];
	}

	return  d;
}

void routing_table(Graph gg,int s,int d)
{
	SSP res=DjkstraFibHeap(gg,s);
	int it=d;
	int V=gg.getVertex();
	vector<Trie>Rtable(V);
	while(1)
	{
		Trie tmp;
		SSP tmp_res=DjkstraFibHeap(gg,it);
		for (int _d=0;_d<V;_d++)
		{
			if(it!=_d)
			{
				int nextHop=getNextHop(tmp_res.Par,it,_d);
				string Ip=gg.Ip[_d];
				Rtable[it].InsertPair(Ip,nextHop);
			}
		}
		Rtable[it].OptimizePath();
		if(it==s)
			break;
		else
			it=res.Par[it];
	}
	int next=s;
	cout<<res.Dis[d]<<endl;
	while (1)
	{
		if(next==d)
			break;
		TrieResult Tres= Rtable[next].Search(gg.Ip[d]);
		cout<<" "<<Tres.IpPrefix<<" ";
		next=Tres.nextHop;
	}

}
