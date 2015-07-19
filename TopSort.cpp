#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct _AdjNode{
	int position;
	struct _AdjNode* next;
} AdjNode;

typedef struct {
	int data;
	int indegree;
	int isSort;
	AdjNode* list;
} Node;

typedef struct {
	Node node[MAX];
	int nodeNum;
	int edgeNum;
} Graph;

void createGraph(Graph* g)
{
	int i;
	int s, e;
	AdjNode* adjNode = NULL;

	scanf("%d", &(g->nodeNum));
	scanf("%d", &(g->edgeNum));

	for(i = 0; i < g->nodeNum; ++i)
	{
		g->node[i].data = i + 1;
		g->node[i].indegree = 0;
		g->node[i].isSort = 0;
		g->node[i].list = NULL;
	}

	for(i = 0; i < g->edgeNum; ++i)
	{
		scanf("%d", &s);
		scanf("%d", &e);

		adjNode = (AdjNode*) malloc (sizeof(AdjNode));
		adjNode->position = e - 1;
		adjNode->next = g->node[s - 1].list;
		g->node[s - 1].list = adjNode;
		g->node[e - 1].indegree++;
	}
}

void destroyGraph(Graph* g)
{
	int i = 0;
	AdjNode* adjNode = NULL;

	for(i = 0; i < g->nodeNum; ++i)
	{
		adjNode = g->node[i].list;
		while(adjNode != NULL)
		{
			adjNode = adjNode->next;
			free(adjNode);
			adjNode = NULL;
		}
	}
}

void printGraph(Graph* g)
{
	int i = 0;
	AdjNode* adjNode = NULL;

	for(i = 0; i < g->nodeNum; ++i)
	{
		printf("%d -> ", g->node[i].data);
		adjNode = g->node[i].list;
		if(NULL == adjNode)
		{
			printf("NULL");
		}

		while(NULL != adjNode)
		{
			printf("%d ", adjNode->position + 1);
			adjNode = adjNode->next;
		}
		printf("\n");
	}
}

Node* getZeroIndegree(Graph* g)
{
	int i = 0;
	
	for(i = 0; i < g->nodeNum; ++i)
	{
		if(g->node[i].indegree == 0 && g->node[i].isSort == 0)
		{
			g->node[i].isSort = 1;
			return &(g->node[i]);
		}
	}

	return NULL;
}

void topSort(Graph* g)
{
	int i = 0;
	AdjNode* adjNode = NULL;
	Node* node = NULL;

	for(i = 0; i < g->nodeNum; ++i)
	{
		node = getZeroIndegree(g);
		if(node == NULL)
		{
			printf("graph is cycle");
		}
		printf("%d ", node->data);
		adjNode = node->list;
		while(adjNode != NULL)
		{
			g->node[adjNode->position].indegree--;
			adjNode = adjNode->next;
		}
		
	}
	printf("\n");
}


int main()
{
	Graph p;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	createGraph(&p);
	//printGraph(&p);
	topSort(&p);
	destroyGraph(&p);

	return 0;
}
