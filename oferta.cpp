#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, K;
    fin >> n >> K;
    vector<double> prices(n + 1);
    vector<double> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
        fin >> prices[i];
    }

    // dp[i] = pretul minim pentru a cumpara i produse
    dp[0] = 0;
    dp[1] = prices[1];  // Caz de baza

    if (n > 1)
        dp[2] = prices[1] + prices[2] - min(prices[1], prices[2]) / 2;

    for (int i = 3; i <= n; ++i) {
        double opt1 = dp[i - 1] + prices[i];
        double opt2 = dp[i - 2] + prices[i] + prices[i - 1] -
                      min(prices[i], prices[i - 1]) / 2;
        double opt3 = dp[i - 3] + prices[i] + prices[i - 1] + prices[i - 2] -
                      min(prices[i], min(prices[i - 1], prices[i - 2]));
        dp[i] = min(opt1, min(opt2, opt3));
    }

    fout << fixed << setprecision(1) << dp[n];

    fin.close();
    fout.close();
    return 0;
}
