#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int n = 5;

bool* visited = new bool[n];

int graph[n][n] =
{
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0},
{0, 1, 0, 0, 1},
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0}
};

void DFS(int st)
{
	int r;
	cout << st +1 << " ";
	visited[st] = true;
	for (r = 1; r <= n; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int owo;

	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		for (int j = 0; j < n; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Стартовая вершина >> "; cin >> owo;

	DFS(owo-1);
	
	system("pause");
}


