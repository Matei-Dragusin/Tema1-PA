#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

int main()
{
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int n;
    fin >> n;
    vector<vector<int>> servers(n, 2);
    for (int i = 0; i < n; ++i)
    {
        fin >> servers[i][0];
    }
    for (int i = 0; i < n; ++i)
    {
        fin >> servers[i][1];
    }
}
