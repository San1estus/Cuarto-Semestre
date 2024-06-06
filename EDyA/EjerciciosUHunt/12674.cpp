/*Utilizamos un Segment Tree para calcular las alturas minimas entre los intervalos
calculamos la prominencia comparando la altura de un nuevo pico con las alturas
minimas si su prominencia es mayor a 150000 como indica el problema entonces es un ultra
y se añade.*/
#include <bits/stdc++.h>
using namespace std;

#define INF 10000000
#define ULTRA 150000

class SegmentTree {
    vector<int> h;
    vector<int> rmq;
    int n;

public:
    SegmentTree(const vector<int>& heights) : h(heights) {
        n = heights.size();
        rmq.resize(4 * n, INF);  // Initialize with INF
        build(1, 0, n - 1);
    }

    void build(int i, int l, int r) {
        if (l == r) {
            rmq[i] = h[l];
        } else {
            int mid = (l + r) / 2;
            build(2 * i, l, mid);
            build(2 * i + 1, mid + 1, r);
            rmq[i] = min(rmq[2 * i], rmq[2 * i + 1]);
        }
    }

    int query(int i, int l, int r, int lo, int hi) {
        if (l > hi || r < lo) {
            return INF;
        }
        if (lo <= l && r <= hi) {
            return rmq[i];
        }
        int mid = (l + r) / 2;
        int leftQuery = query(2 * i, l, mid, lo, hi);
        int rightQuery = query(2 * i + 1, mid + 1, r, lo, hi);
        return min(leftQuery, rightQuery);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int getIndex(int i, int j, const vector<int>& h, const vector<int>& arr) {
    if (j == -1) {
        return -1;
    } else if (h[j] > h[i]) {
        return j;
    } else {
        return getIndex(i, arr[j], h, arr);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int N;
    while (cin >> N) {
        vector<int> h(N);
        vector<int> d(N, 0), l(N, -1), r(N, -1);
        vector<int> peaks;

        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }

        SegmentTree st(h);

        for (int i = 1; i < N - 1; i++) {
            if (h[i - 1] < h[i] && h[i] > h[i + 1]) {
                peaks.push_back(i);
            }
        }

        if (!peaks.empty()) {
            l[peaks[0]] = -1;
            for (size_t i = 1; i < peaks.size(); i++) {
                l[peaks[i]] = getIndex(peaks[i], peaks[i - 1], h, l);
            }

            size_t M = peaks.size();
            r[peaks[M - 1]] = -1;
            for (int i = M - 2; i >= 0; i--) {
                r[peaks[i]] = getIndex(peaks[i], peaks[i + 1], h, r);
            }

            for (size_t i = 0; i < M; i++) {
                int j = peaks[i];
                if (l[j] == -1 && r[j] == -1) {
                    d[j] = h[j];
                } else if (r[j] == -1) {
                    d[j] = h[j] - st.query(l[j], j - 1);  // Changed range
                } else if (l[j] == -1) {
                    d[j] = h[j] - st.query(j + 1, r[j]);  // Changed range
                } else {
                    int a = st.query(l[j], j - 1);  // Changed range
                    int b = st.query(j + 1, r[j]);  // Changed range
                    d[j] = h[j] - max(a, b);
                }
            }

            bool first = true;
            for (size_t i = 0; i < M; i++) {
                if (d[peaks[i]] >= ULTRA) {
                    if (!first) cout << ' ';
                    first = false;
                    cout << peaks[i] + 1;
                }
            }
            cout << endl;
        } else {
            cout << endl;
        }
    }

    return 0;
}
