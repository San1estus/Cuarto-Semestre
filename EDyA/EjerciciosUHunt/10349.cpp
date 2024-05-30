#include <bits/stdc++.h>
using namespace std;

class FordFulkerson {
public:
    FordFulkerson(vector<vector<pair<int, long long>>> &graph) : g(graph) { }
    
    long long getMaxFlow(int s, int t) {
        init();
        long long f = 0;
        while (findAndUpdate(s, t, f)) { }
        return f;
    }

private:
    struct Edge {
        long long c, f;
        int to;
    };

    vector<vector<pair<int, long long>>> g; 
    vector<Edge> edges; 
    vector<vector<int>> eIndexes; 
    
    void init() {
        edges.clear();
        eIndexes.clear(); 
        eIndexes.resize(g.size());
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                edges.push_back({g[i][j].second, 0, g[i][j].first});
                edges.push_back({0, 0, i});
                eIndexes[i].push_back(edges.size() - 2);
                eIndexes[g[i][j].first].push_back(edges.size() - 1);
            }
        }
    }

    bool findAndUpdate(int s, int t, long long &flow) {
        queue<int> pending;
        vector<pair<int, int>> from(g.size(), make_pair(-1, -1));
        pending.push(s);
        from[s] = make_pair(s, -1);
        bool found = false;
        while (!pending.empty() && !found) {
            int u = pending.front(); pending.pop();
            for (int i = 0; i < eIndexes[u].size(); i++) {
                int eI = eIndexes[u][i];
                if ((edges[eI].c > edges[eI].f) && (from[edges[eI].to].first == -1)) {
                    from[edges[eI].to] = make_pair(u, eI);
                    pending.push(edges[eI].to);
                    if (edges[eI].to == t) found = true;
                }
            }
        }
        if (!found) return false;
        
        long long uFlow = LLONG_MAX;
        int current = t;
        while (current != s) {
            uFlow = min(uFlow, edges[from[current].second].c - edges[from[current].second].f);
            current = from[current].first;
        }
        current = t;
        while (current != s) {
            edges[from[current].second].f += uFlow;
            edges[from[current].second ^ 1].f -= uFlow;
            current = from[current].first;
        }
        flow += uFlow;
        return true;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, h, w;
    cin >> n;
    while (n--) {
        cin >> h >> w;
        vector<string> grid(h);
        for (int i = 0; i < h; ++i) {
            cin >> grid[i];
        }

        int S = h * w, T = S + 1;
        vector<vector<pair<int, long long>>> graph(T + 1);

        int numOfStar = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == '*') {
                    numOfStar++;
                    if ((i + j) % 2 == 0) {
                        graph[S].push_back(make_pair(i * w + j, 1));
                        if (i > 0 && grid[i - 1][j] == '*') graph[i * w + j].push_back(make_pair((i - 1) * w + j, 1));
                        if (j > 0 && grid[i][j - 1] == '*') graph[i * w + j].push_back(make_pair(i * w + j - 1, 1));
                        if (i + 1 < h && grid[i + 1][j] == '*') graph[i * w + j].push_back(make_pair((i + 1) * w + j, 1));
                        if (j + 1 < w && grid[i][j + 1] == '*') graph[i * w + j].push_back(make_pair(i * w + j + 1, 1));
                    } else {
                        graph[i * w + j].push_back(make_pair(T, 1));
                    }
                }
            }
        }

        FordFulkerson ff(graph);
        int result = ff.getMaxFlow(S, T);
        cout << numOfStar - result << endl;
    }

    return 0;
}
