#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

struct  urav
{
   long long int vv;
   long long int v;
   long long int n;

};

int main()
{
    urav lol[2];
    int owo[20];
	for (size_t i = 0; i < 20; i++)
	{
		owo[i] = rand();
	}
	sort(owo, owo + 20);
	for (size_t i = 0; i < 20; i++)
	{
		cout << owo[i] << endl;
	}
    int uwu;
    cin >> uwu;
    int left = 0; 
    int right = 19;
    int find = -1; 
    while (left <= right) 
    {
        int mid = (left + right) / 2; 
        if (uwu ==owo[mid]) {
            find = mid;     
            break;            
        }
        if (uwu < owo[mid])
            right = mid - 1; 
        else                  
            left = mid + 1;  
    }
    if (find == -1)
        cout << "not found" << endl;
    else
        cout << find;
    cout << "//////////////////" << endl;

    string kekw;
    cin >> kekw;
    cout << kekw.size() << endl;
    int size = kekw.size()/2;
  
    int x = 1;
    for (size_t i = 0; i < size-1; i++)
    {
        x = x * 10;
    }
    cout << x << endl;
    //string temp = 
    lol[0].n = stoi(kekw.substr(kekw.size() - size+1, size-1));
    
    cout << lol[0].n << endl;
    kekw.erase(size+1);
    lol[0].v = stoi(kekw.substr(kekw.size() - size + 1, size - 1));

    cout << lol[0].v << endl;
    kekw.erase(size + 1);
    lol[0].vv = stoi(kekw);
    cout << lol[0].vv << endl;
}
