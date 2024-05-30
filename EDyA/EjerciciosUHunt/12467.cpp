/*Cuarta edición*/
#include <bits/stdc++.h>
using namespace std;

vector<int> kmpPreprocess(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m + 1, 0);
    int i = 0, j = -1;
    lps[0] = -1;

    while (i < m) {
        while (j >= 0 && pattern[i] != pattern[j])
            j = lps[j];
        i++;
        j++;
        lps[i] = j;
    }

    return lps;
}

int kmpSearch(const string& text, const string& pattern, const vector<int>& lps) {
    int n = text.size();
    int m = pattern.size();
    int i = 0, j = 0;
    int anslen = -1;

    while (i < n) {
        while (j >= 0 && text[i] != pattern[j])
            j = lps[j];
        i++;
        j++;
        if (j > anslen)
            anslen = j;
        if (j == m)
            j = lps[j];
    }

    return anslen;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        string P, T;
        cin >> P;
        T = P;
        reverse(T.begin(), T.end());

        vector<int> lps = kmpPreprocess(P);
        int anslen = kmpSearch(T, P, lps);

        for (int i = anslen - 1; i >= 0; i--) {
            cout << P[i];
        }
        cout << endl;
    }

    return 0;
}
