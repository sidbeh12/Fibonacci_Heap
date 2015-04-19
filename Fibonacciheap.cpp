#include"Fibonacciheap.h"

void AddInList(FibHeapNode ** frst,FibHeapNode **scnd)
{
	(*frst)->left->right=(*scnd);
	(*scnd)->left=(*frst)->left;
	(*scnd)->right=(*frst);
	(*frst)->left=(*scnd);
	(*scnd)->parent=NULL;
	(*scnd)->ChildCut=false;
}
void FibHeap::InsertNode(FibHeapNode *node)
{
	if(minNode)
	{
		AddInList( &minNode,&node);
		if(node->weight<minNode->weight)
			minNode=node;

	}
	else
	{
		minNode=node;

	}
	nodecount++;
}

FibHeapNode *FibHeap::CreateHeapNode(int v,int data)
{
	FibHeapNode *tmp=new FibHeapNode;
	tmp->degree=0;
	tmp->weight=data;
	tmp->vertxId=v;
	tmp->parent=NULL;
	tmp->child=NULL;
	tmp->left=tmp;
	tmp->right=tmp;
	tmp->ChildCut=false;
	return tmp;
}
FibHeapNode *FibHeap::removeMin()
{
	FibHeapNode *tmpmin=minNode;
	if(!nodecount)
	{

		cout<<"No elements present.Hence remove min cant be performed"<<endl;

		return NULL ;
	}
	if(nodecount==1)
	{

		minNode=NULL;
		nodecount--;
		return tmpmin;

	}
	else
	{
		FibHeapNode *first=minNode->child;
		if(first!=NULL){


			FibHeapNode *scnd=first->right;
			while((first!=scnd)&&(first!=NULL))
			{
				FibHeapNode *tmp=scnd;
				scnd=scnd->right;
				AddInList(&minNode,&tmp);


			}
			AddInList(&minNode,&first);}
		tmpmin->left->right=tmpmin->right;
		tmpmin->right->left=tmpmin->left;
		minNode=tmpmin->right;
		pairwiseCombine();
		nodecount--;
		return tmpmin;

	};
}
void FibHeap::pairwiseCombine()
{
	vector<FibHeapNode *>degreeList(DEGREE_LMT,NULL);
	FibHeapNode *start=minNode;
	FibHeapNode  *it=minNode;
	do
	{
		FibHeapNode *x=it;
		int d=x->degree;
		it=it->right;
		while(degreeList[d]!=NULL)
		{
			FibHeapNode *y=degreeList[d];
			if(x->weight>y->weight)
			{
				FibHeapNode *tmp=x;
				x=y;
				y=tmp;
			}

			if(y==it)
				it=it->right;
			if(y==start)
				start=start->right;
			JoinFibHeap(y,x);

			degreeList[d]=NULL;
			d++;
		}
		degreeList[d]=x;
	}while(it!=start);

	minNode=NULL;
	for(int i=0;i<DEGREE_LMT;i++)
	{
		if(degreeList[i]!=NULL)
		{
			degreeList[i]->right=degreeList[i];
			degreeList[i]->left=degreeList[i];
			if (minNode==NULL)
			{
				minNode=degreeList[i];
			}
			else
			{
				AddInList(&minNode,&degreeList[i]);
				if(minNode->weight>degreeList[i]->weight)
					minNode=degreeList[i];
			}
		}
	}
}
void FibHeap::JoinFibHeap(FibHeapNode *y,FibHeapNode *x)
{
	y->left->right=y->right;
	y->right->left=y->left;
	y->parent=x;
	if(x->child!=NULL)
	{

		y->right=x->child;
		y->left=x->child->left;
		x->child->left->right=y;
		x->child->left=y;
	}
	else
	{

		y->right=y;
		y->left=y;
	}

	x->child=y;
	x->degree++;
	y->ChildCut=false;
}

void FibHeap::decreaseKey(FibHeapNode *node,int key)
{
	if(!node||!minNode||node->weight<key)
	{
		cout<<"Decrease key operation could not be performed successfully "<<endl;
		return ;
	}
	else
	{
		node->weight=key;
		FibHeapNode *parent=node->parent;
		if(parent!=NULL&&(parent->weight>node->weight))
		{
			cutNode(parent,node);
			cascadeCut(parent);
		}
		if(node->weight<minNode->weight)
		{
			minNode=node;

		}

	}

}
void FibHeap::cutNode(FibHeapNode *p,FibHeapNode *c)
{
	if(c->right==c)
	{
		p->child=NULL;
		AddInList(&minNode,&c);
	}
	else
	{
		c->left->right=c->right;
		c->right->left=c->left;
		if(p->child==c)
			p->child=c->right;
		AddInList(&minNode,&c);
		p->degree=p->degree-1;
	}

}

void FibHeap::cascadeCut(FibHeapNode *node)
{
	FibHeapNode *parent=node->parent;

	if(parent !=NULL)
	{
		if(!node->ChildCut)
		{
			node->ChildCut=true;
		}
		else{
			cutNode(parent,node);
			cascadeCut(parent);
		}
	}


}

