#include <vector>
#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    vector < vector<int> > g; 
    const int n = 4; 
    int s = 0; 
    
    int Adj[n][n] = { {0,0,1,0},
                      {0,0,1,0},
                      {0,0,0,1},
                      {0,2,0,0} };
    for (int i = 0; i < n; i++)
    {
        g.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            if (Adj[i][j])
                g[i].push_back(j);
            
        }
    }
    queue<int> q;
    q.push(s);
    vector<bool> used(n);
    vector<int> d(n), p(n);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if (!used[to])
            {
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << d[i] << "  ";

    cout << endl;
    system("pause");
    return 0;
}
