#include <bits/stdc++.h>
using namespace std;

#define d 256   

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    long long p = 0;   
    long long t = 0;   
    long long h = 1;   

    for (int i = 0; i < m - 1; i++)
        h = h * d;


    for (int i = 0; i < m; i++) {
        p = p * d + pattern[i];
        t = t * d + text[i];
    }

    
    for (int i = 0; i <= n - m; i++) {

        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m) {
            t = d * (t - text[i] * h) + text[i + m];
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";

    rabinKarp(text, pattern);
    return 0;
}