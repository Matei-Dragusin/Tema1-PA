#include <iostream>
#include <fstream>

using namespace std;

const int MOD = 1000000007;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    long long n;
    fin >> n;
    long long number;
    char type[2], prevType[2] = {'\0'};

    fin >> number >> type;
    long long cnt = 1;
    prevType[0] = type[0];

    if (type[0] == 'V') {
        cnt = (cnt * 3 % MOD * modExp(2, number - 1, MOD)) % MOD;
    } else {
        cnt = (cnt * 6 % MOD * modExp(3, number - 1, MOD)) % MOD;
    }
    for (int i = 0; i < n - 1; i++) {
        fin >> number >> type;
        if (type[0] == 'V') {
            if (prevType[0] == 'V') {
                cnt = (cnt * modExp(2, number, MOD)) % MOD;
            } else {
                cnt = (cnt * modExp(2, number - 1, MOD)) % MOD;
            }
        } else {
            if (prevType[0] == 'V') {
                cnt = (cnt * 2 % MOD * modExp(3, number - 1, MOD)) % MOD;
            } else {
                cnt = (cnt * modExp(3, number, MOD)) % MOD;
            }
        }
        prevType[0] = type[0];
    }
    fout << cnt % MOD;

    fin.close();
    fout.close();
    return 0;
}
