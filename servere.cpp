#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

// Functia de comparare pentru sortarea serverelor in functie de curentul optim
bool compare(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

// Functia care calculeaza puterea minima pentru un curent universal dat
double calculateMinPower(const vector<vector<int>> &servere, double current) {
    double minPower = 1e9;
    for (size_t i = 0; i < servere.size(); ++i) {
        double power = servere[i][0] - fabs(current - servere[i][1]);
        if (power < minPower) {
            minPower = power;
        }
    }
    return minPower;
}

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int n;
    fin >> n;

    vector<vector<int>> servere(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        fin >> servere[i][0];
    }

    for (int i = 0; i < n; i++) {
        fin >> servere[i][1];
    }

    // Sortam serverele in functie de curentul optim
    sort(servere.begin(), servere.end(), compare);

    // Cautam curentul universal optim folosind binary search
    double left = servere.front()[1];
    double right = servere.back()[1];
    double max_min_power = -1e9;

    while (left + 0.05 < right) {
        double mid = (left + right) / 2;
        double minPowerMid = calculateMinPower(servere, mid);

        double minPowerMidPlus = calculateMinPower(servere, mid + 0.05);

        if (minPowerMidPlus > minPowerMid) {
            left = mid;
        } else {
            right = mid;
        }

        max_min_power = max(max_min_power, minPowerMid);
    }

    fout << fixed << setprecision(1) << max_min_power;

    fin.close();
    fout.close();
    return 0;
}
