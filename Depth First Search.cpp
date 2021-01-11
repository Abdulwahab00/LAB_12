#include<iostream>
using namespace std;
int MAX_SIZE = 50;
class Stack { // stack for DFS
	int size;
	int* Arr;
public:
	Stack();
	bool isFull() const;
	bool isEmpty() const;
	int Top() const;
	void push(int);
	int pop();
	void Display();
	~Stack();
};
Stack::Stack()
{
	this->size = 0;
	this->Arr = new int[MAX_SIZE]; // allocation of array of 50 elements
}
bool Stack::isFull() const
{
	if (this->size >= MAX_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Stack::isEmpty() const
{
	if (this->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Stack::Top() const
{
	if (!this->isEmpty())
	{
		return this->Arr[this->size - 1];
	}
	else
	{
		return INT_MIN;
	}
}
void Stack::push(int val)
{
	if (!this->isFull())
	{
		this->Arr[this->size] = val;
		this->size++;
	}
	else
	{
		cout << "Error, OverFlow can`t insert new value" << endl;
	}
}
int Stack::pop()
{
	if (!this->isEmpty())
	{
		int n = this->Arr[this->size - 1];
		this->size--;
		return n;
	}
	else
	{
		cout << "Error, UnderFlow can`t pop from stack" << endl;
		return INT_MAX;
	}
}
void Stack::Display()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->Arr[i] << "  ";
	}
	cout << endl;
}

Stack::~Stack()
{
	delete[]this->Arr;
}

class Graph {
	int** MatArray;
	int VERTICES = 4;
	bool* VisitedVertices;
public:
	Stack stack;
	Graph();
	void SetGraph();
	void AddEdge(int, int);
	void ShowGraph();
	void DFTUtill(bool VN[], int s);
	void DFT(int);
	~Graph();

};
Graph::Graph()
{
	// allocation of memory for graph
	this->MatArray = new int* [VERTICES];
	for (int i = 0; i < VERTICES; i++)
	{
		this->MatArray[i] = new int[VERTICES];
	}
	this->SetGraph();
	this->VisitedVertices = new bool[VERTICES];
}
void Graph::SetGraph()
{
	// function to set array to 0
	for (int i = 0; i < VERTICES; i++)
	{
		for (int j = 0; j < VERTICES; j++)
		{
			this->MatArray[i][j] = 0;
		}
	}
}
void Graph::AddEdge(int v1, int v2)
{
	// in undirected graphs there is an Ordered pair of vertices
	this->MatArray[(v1)][(v2)] = 1;
}
void Graph::ShowGraph()
{
	// representing the graph as 2 dimentional array
	cout << "   ";
	for (int i = 0; i < VERTICES; i++)
	{
		cout << i << "  ";
	}
	cout << endl << endl;;
	for (int i = 0; i < VERTICES; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < VERTICES; j++)
		{
			cout << this->MatArray[i][j] << "  ";
		}
		cout << endl;
	}
}


void Graph::DFTUtill(bool VN[], int s)
{

	VN[s] = true;
	this->stack.push(s);
	cout << s << " ";
	int* AdjacentVertices = new int[VERTICES]; // array to store all the vertices
	int Alength = 0;
	for (int i = 0; i < VERTICES; i++)
	{
		if (this->MatArray[s][i] != 0)
		{
			AdjacentVertices[Alength] = i;
			Alength++;
		}
	}
	for (int i = 0; i < Alength; i++)
	{
		if (VN[AdjacentVertices[i]] == false)
		{
			this->DFTUtill(VN, AdjacentVertices[i]);
		}

	}
}

void Graph::DFT(int x) // function Depth first traversal 
{
	cout << "Depth First Search: ";
	for (int i = 0; i < this->VERTICES; i++)
	{
		this->VisitedVertices[i] = false;
	}
	//this->VisitedVertices[0] = true;
	for (int i = 0; i < VERTICES; i++)
	{
		if (this->VisitedVertices[i] == false)
		{
			this->DFTUtill(this->VisitedVertices, i);
		}
	}

}

Graph::~Graph()
{
	// deallocation of memory taken for graph
	for (int i = 0; i < VERTICES; i++)
	{
		delete[]this->MatArray[i];
	}
	delete[]this->MatArray;
}
int main(void)
{

	Graph G;
	G.AddEdge(0, 1);
	G.AddEdge(1, 0);
	G.AddEdge(2, 0);
	G.AddEdge(2, 3);
	G.AddEdge(3, 2);
	G.ShowGraph();
	G.DFT(0);
	cout << endl;
	system("pause");
	return 0;
}