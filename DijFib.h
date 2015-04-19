#ifndef _h_djkstra_
#define _h_djkstra_
#include "Fibonacciheap.h"
#include <unordered_map>
#include<climits>
#include "Graph.h"

typedef struct res
{
vector<int>Dis;
vector<int>Par;
}SSP;
SSP DjkstraFibHeap(Graph ,int s);

#endif
