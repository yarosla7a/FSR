
#include <vector>
#include <cmath>

using namespace std;

void addEdge(vector<int> adj[], int v, int u) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool repeat(vector<int> a, int x) {
    long long unsigned i;
	for (i = 0; i < a.size(); ++i) {
		if (a[i] == x)
			return true;
	}
	return false;
}


vector<int> generate_gene(int n) {
	vector<int> gene;
	gene.resize(n, 0);
	for (int i = 1; i < n;) {
		int temp = rand() % n;
		if (!repeat(gene, temp)) {
			gene[i] = temp;
			++i;
		}
	}
	return gene;
}


void find_colors(int V, vector<int> adj[]) {
    int res[V];
    int max_c = 0;

    res[0]  = 0;
    for (int i = 1; i < V; ++i)
        res[i] = -1;

    bool used[V];
    for (int c = 0; c < V; ++c)
        used[c] = false;

    for (int v = 1; v < V; ++v)  {
        for (auto x : adj[v])
            if (res[x] != -1)
                used[res[x]] = true;

        int c = 0;
        while (used[c]==true) ++c;

        res[v] = c;
        max_c = max(c,max_c);

        for (auto x : adj[v])
            if (res[x] != -1)
                used[res[x]] = false;
    }

    cout << "Number of colors: " << max_c+1 << endl;
}
