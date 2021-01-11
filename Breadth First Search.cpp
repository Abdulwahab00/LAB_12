#include<iostream>
#include<queue>
using namespace std;
int c = 0;
int Arr[7][7];
int MaxSize = 7;


class Graph
{
    
public:
    
    void InsertEdge(int a, int b);
    void ShowGraph();
    void BFS(int data);
};

void Graph::InsertEdge(int a, int b)
{
    Arr[a][b] = 1;
    Arr[b][a] = 1;
    c++;
}



void Graph::ShowGraph()
{
    
    cout << "   ";
    for (int i = 0; i < MaxSize; i++)
    {
        cout << i << "  ";
    }
    cout << endl << endl;;
    for (int i = 0; i < MaxSize; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < MaxSize; j++)
        {
            cout <<Arr[i][j] << "  ";
        }
        cout << endl;
    }
}


void Graph::BFS(int Data)
{
    bool* visited_Node = new bool[c];
    for (int a = 0; a < c; a++)
    {
        visited_Node[a] = false;
    }
    queue<int> Q;
    visited_Node[Data] = true;
    Q.push(Data);
    while (!Q.empty())
    {
        Data = Q.front();
        cout << Data<<" ";
        
       
        Q.pop();
        for (int a = 0; a < c; a++)
        {
            if (!visited_Node[a])
            {
                visited_Node[a] = true;
                Q.push(a);
            }
        }
    }
}

int main()
{
    Graph obj;
    obj.InsertEdge(0, 1);
    obj.InsertEdge(0, 4);
    obj.InsertEdge(0, 5);
    obj.InsertEdge(1, 2);
    obj.InsertEdge(2, 3);
    obj.InsertEdge(5, 6);
    obj.ShowGraph();
    cout << endl;
    cout << "Breadth First Search: ";

    obj.BFS(2);
    
    system("pause");
    return 0;
}
