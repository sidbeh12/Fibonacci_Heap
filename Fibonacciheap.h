#ifndef _FibHeap_H_
#define _FibHeap_H_
#include<iostream>
#include<vector>
#define DEGREE_LMT 40
using namespace std;
struct FibHeapNode
{
	int degree;
	int weight;
	int vertxId;
	FibHeapNode *parent;
	FibHeapNode *left;
	FibHeapNode *right;
	FibHeapNode *child;
	bool ChildCut;
};
class FibHeap
{
	FibHeapNode *minNode;
	int nodecount;
	public:
	int getNodeCount()
	{
		return nodecount;
	}
	FibHeapNode *getRoot()
	{
		return minNode;
	}

	FibHeap()
	{
		minNode=NULL;
		nodecount=0;
	}
	void InsertNode(FibHeapNode*);
	FibHeapNode* removeMin();
	FibHeapNode *CreateHeapNode(int ,int );
	void decreaseKey(FibHeapNode *,int  );
	void pairwiseCombine();
	void cascadeCut(FibHeapNode*);
	void cutNode(FibHeapNode *,FibHeapNode *);
	void JoinFibHeap(FibHeapNode *,FibHeapNode *);


};
void AddInList(FibHeapNode **,FibHeapNode**);
#endif
