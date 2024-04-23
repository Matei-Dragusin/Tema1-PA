#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int n;
    fin >> n;
    vector<string> words(n);
    vector<vector<int>> freq(n, vector<int>(26, 0));
    vector<int> totalFreq(26, 0);

    for (int i = 0; i < n; i++) {
        fin >> words[i];
        for (char c : words[i]) {
            int idx = c - 'a';
            freq[i][idx]++;
            totalFreq[idx]++;
        }
    }

    int maxLen = 0;

    // Verificam fiecare litera
    for (int charIndex = 0; charIndex < 26; charIndex++) {
        // Daca litera nu apare in niciun cuvant, trecem la urmatoarea litera
        if (totalFreq[charIndex] == 0)
            continue;

        vector<pair<int, int>> wordsForChar;  // {lungime cuvant, frec litera}
        for (int i = 0; i < n; i++) {
            wordsForChar.push_back({words[i].length(), freq[i][charIndex]});
        }

        // Sortarea dupa raportul frecventa litera / lungime cuvant
        sort(wordsForChar.begin(), wordsForChar.end(),
            [](pair<int, int> a, pair<int, int> b)
             { return a.second * b.first > b.second * a.first; });

        int currentLen = 0;
        int currentFreq = 0;
        for (int i = 0; i < wordsForChar.size(); i++) {
            int newLen = currentLen + wordsForChar[i].first;
            int newFreq = currentFreq + wordsForChar[i].second;
            // Daca frecventa litera * 2 > lungimea cuvantului, adaugam cuvantul
            if (newFreq * 2 > newLen) {
                currentLen = newLen;
                currentFreq = newFreq;
                maxLen = max(maxLen, currentLen);
            }
        }
    }

    fout << maxLen << endl;

    fin.close();
    fout.close();
    return 0;
}
