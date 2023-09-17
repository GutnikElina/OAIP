#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <locale>

using namespace std;

struct AdjListNode
{
	int vertex{};
	struct AdjListNode* next{};
};

struct AdjList
{
	struct AdjListNode* list{};
};

struct Graph
{
	int v{};
	struct AdjList* array{};
};

struct AdjListNode* newAdjListNode(int vertex)
{
	AdjListNode* newNode = new AdjListNode;
	newNode->vertex = vertex;
	newNode->next = nullptr;
	return newNode;
}

void printMatrix(Graph * graph, int** matrix, int ammount)
{
	for (int i = 0; i < graph->v; i++) 
	{
		cout << graph->array[i].list->vertex << "| ";
		for (int j = 0; j < ammount; j++) 
		{
			cout << "   " << matrix[i][j];
		}
		cout << endl;
	}
}

void createMatrix(Graph* graph)
{
	int** matrix = new int* [graph->v];
	for (int i = 0; i < graph->v; i++)
	{
		matrix[i] = new int[graph->v];
	}
	for (int i = 0; i < graph->v; i++)
	{
		for (int j = 0; j < graph->v; j++) {
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < graph->v; i++)
	{
		AdjListNode* current = graph->array[i].list;
		current = current->next;
		while (current)
		{
			matrix[i][current->vertex] = 1;
			current = current->next;
		}
	}
	printMatrix(graph, matrix, graph->v);
}



void addEdge(struct Graph* graph, int vertex_1, int vertex_2)
{
	struct AdjListNode* newNode = newAdjListNode(vertex_2);
	newNode->next = graph->array[vertex_1].list;
	graph->array[vertex_1].list = newNode;
}

void deleteEdge(struct Graph* graph, int vertex_1, int vertex_2)
{
	for (int i = 0; i < graph->v; i++)
	{
		if (graph->array[i].list->vertex == vertex_1)
		{
			AdjListNode* current = graph->array[i].list;
			AdjListNode* previous = NULL;
			while (current != NULL)
			{
				if (current->vertex == vertex_2)
				{
					previous->next = current->next;
					AdjListNode* temp = current;
					current = current->next;
					delete temp;
				}
				else
				{
					previous = current;
					current = current->next;
				}
			}
		}
	}
}

void deleteVertex(struct Graph* graph, int v)
{
	struct AdjList* adjList = graph->array;

	for (int i = 0; i < graph->v; i++)
	{
		struct AdjListNode* node = adjList[i].list;
		if (node != nullptr && node->vertex == v)
		{
			adjList[i].list = node->next;
			free(node);
			continue;
		}

		struct AdjListNode* prevNode = node;
		while (node != nullptr)
		{
			if (node->vertex == v)
			{
				prevNode->next = node->next;
				free(node);
				break;
			}
			prevNode = node;
			node = node->next;
		}
	}

	for (int i = v; i < graph->v; i++)
	{
		adjList[i] = adjList[i + 1];
	}
	graph->v--;
	graph->array = (struct AdjList*)realloc(adjList, graph->v * sizeof(struct AdjList));
}

void printGraph(struct Graph* graph)
{
	cout << "\n";
	for (int v = 0; v < graph->v; v++)
	{
		struct AdjListNode* current = graph->array[v].list;
		while (current)
		{
			cout << current->vertex;
			current = current->next;
			if (current)
			{
				cout << "->";
			}
		}
		cout << "\n";
	}
}

void menu()
{
	cout << "\n------ ÌÅÍÞ ------\n";
	cout << "1) Âûâåñòè ãðàô\n";
	cout << "2) Óäàëèòü âñå ðåáðà ñ íîìåðîì 1 - (0->3); (1->3); (2->3);\n";
	cout << "3) Óäàëèòü âåðøèíó 3\n";
	cout << "4) Âûâåñòè ìàòðèöó ñìåæíîñòè\n";
	cout << "5) Âûéòè\n";
}

int main()
{
	setlocale(0, "rus");
	int v = 5, choice;


	Graph* graph = new Graph;
	graph->v = v;
	graph->array = new AdjList[v];
	for (int i = 0; i < v; i++)
	{
		graph->array[i].list = nullptr;
	}

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);
	addEdge(graph, 0, 0);
	addEdge(graph, 1, 1);
	addEdge(graph, 2, 2);
	addEdge(graph, 3, 3);
	addEdge(graph, 4, 4);

	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "------ ÃÐÀÔ -------: ";
			printGraph(graph);
			break;
		case 2:
			deleteEdge(graph, 0, 3);
			deleteEdge(graph, 1, 3);
			deleteEdge(graph, 2, 3);
			cout << "\n------ ÓÑÏÅØÍÎ ÂÛÏÎËÍÅÍÎ ------\n";
			break;
		case 3:
			deleteVertex(graph, 3);
			cout << "\n------ ÓÑÏÅØÍÎ ÂÛÏÎËÍÅÍÎ ------\n";
			break;
		case 4:
			createMatrix(graph);
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}