#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include "GCsolver.h"

using namespace std;


int main() {
    string s1, s2;
	ifstream File;

	string name;
	cout << "Enter file number:\n(for example: 1000_1)\n";
	cin >> name;

	int V, E;


	File.open("./data/gc_" + name);
	File >> s1 >> s2;
	istringstream os1(s1);
	os1 >> V;

	istringstream os2(s2);
	os2 >> E;

	vector<int> adj[V];

	for (int i = 0; i < E; ++i) {
		int e1, e2;
		File >> s1 >> s2;
		istringstream os3(s1);
		os3 >> e1;
		istringstream os4(s2);
		os4 >> e2;
		addEdge(adj, e1, e2);
	}

	File.close();

	find_colors(V,adj);

	return 0;
}
