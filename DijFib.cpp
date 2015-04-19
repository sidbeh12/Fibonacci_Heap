#include"DijFib.h"
/*Header Files */
SSP DjkstraFibHeap(Graph g,int s)
{
	unordered_map<int ,FibHeapNode *>fmap;
	int cost=0,it=s+1,V;
	SSP tmp_path;

	V=g.getVertex();
	tmp_path.Dis.reserve(V);
	tmp_path.Par.reserve(V);
	bool visited[V];
	int parent[V];
	vector<int>res;
	int i=1;

	FibHeap fheap; 
	list<GraphNode> *adjList=g.getList();
	FibHeapNode *tmp=fheap.CreateHeapNode(s,0);
	fheap.InsertNode(tmp);
	fmap[s]=tmp;
	
	while(i<V)
	{   if(it<V){

	
		tmp=fheap.CreateHeapNode(it,INT_MAX);
		fheap.InsertNode(tmp);
		fmap[it]=tmp;
		it++;
		i++;
	}

	else
	{
		tmp=fheap.CreateHeapNode(it-V,INT_MAX);
		fheap.InsertNode(tmp);
		fmap[it-V]=tmp;
		it++;
		i++;

	}


	}
	while(fheap.getNodeCount())
	{
       tmp=fheap.removeMin();

	   int vrtxid=tmp->vertxId;
	   visited[vrtxid]=true;
	   /*
	   if(vrtxid==d)
	   {
          cout<<" "<<tmp->weight<<" "<<endl;
		  int p_it=tmp->vertxId;
		  //res.push_back(tmp->weight);
		  res.push_back(d);
		  while(p_it!=s)
		  {
			  res.push_back(parent[p_it]);
			  p_it=parent[p_it];
		  }

		  for (vector<int >::reverse_iterator it=res.rbegin();it!=res.rend();it++)
		  {
			  cout<<(*it)<<" ";
		  }

//		  cout<<" "<<s<<endl;
		  return ;

	   }
	   */
	  // vertex[i++]=vrtxid;
	   for(list<GraphNode>::iterator it=adjList[vrtxid].begin();it!=adjList[vrtxid].end();it++)
	   {
            FibHeapNode *tmp_nbr=fmap[it->des];
			if(tmp_nbr!=NULL){

			
			if((tmp_nbr->weight>(it->weight+tmp->weight))&&(!visited[it->des]))
			{
			//	it->parent=tmp->vertxId;
				tmp_path.Par[it->des]=tmp->vertxId;
				tmp_path.Dis[it->des]=it->weight+tmp->weight;
				fheap.decreaseKey(tmp_nbr,(it->weight+tmp->weight));
			}

	   }}


	}
    
	return tmp_path;
}
