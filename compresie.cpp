#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n, sum_v = 0, sum_w = 0;
    fin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
        sum_v += v[i];
    }

    int m;
    fin >> m;

    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        fin >> w[i];
        sum_w += w[i];
    }

    int cnt = 0;
    if (sum_v != sum_w) {
        fout << -1;
        return 0;
    } else {
        int i, j;
        i = j = 0;
        int sum_i = v[i], sum_j = w[j];

        while (i < n && j < m) {
            if (sum_i == sum_j) {
                cnt++;
                i++;
                j++;
                sum_i = v[i];
                sum_j = w[j];
            } else if (sum_i < sum_j) {
                i++;
                sum_i += v[i];
            } else {
                j++;
                sum_j += w[j];
            }
        }
    }
    fout << cnt;
    return 0;
}
