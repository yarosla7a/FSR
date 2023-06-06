// CPP program to implement traveling salesman
// problem using naive approach.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
//#include "tspSolver.h"
using namespace std;


// implementation of traveling Salesman Problem
int travllingSalesmanProblem(vector<vector<double> > graph, int V, int s)
{
	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}


int main()
{
	string s1, s2;
	ifstream File;

	string name;
	cout << "Enter file number:\n(for example: 1000_1)\n";
	cin >> name;
	if (name == "1000_1") cout << "wait long please\n";



	File.open("./data/tsp_" + name);
	int n;
	File >> s1;
	istringstream os(s1);
	os >> n;



	vector<int> x(n);
	vector<int> y(n);

	int d;
	for (int i = 0; i < n; ++i) {
		File >> s1 >> s2;
		istringstream os1(s1);
		os1 >> d;
		x[i] = d;

		istringstream os2(s2);
		os2 >> d;
		y[i] = d;
	}
	File.close();

	//Distances between nodes
	vector<vector<double> > map(n, vector<double>(n, 0));
	for (int i = 0; i < n; ++i) {
		map[i][i] = 0;
		for (int j = i + 1; j < n; ++j) {
			map[i][j] = map[j][i] = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);//SQUARED distances for better accuracy
		}
	}



	int s = 0;
	cout << "Summary path:" << travllingSalesmanProblem(map, n, s) << endl;
	
	return 0;
}








	vector<int> x(n);
	vector<int> y(n);

	int d;
	for (int i = 0; i < n; ++i) {
		File >> s1 >> s2;
		istringstream os1(s1);
		os1 >> d;
		x[i] = d;

		istringstream os2(s2);
		os2 >> d;
		y[i] = d;
	}
	File.close();

	//Distances between nodes
	vector<vector<double> > map(n, vector<double>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			map[i][j] = map[j][i] = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);//SQUARED distances for better accuracy
		}
	}


	individual A;

	A = solve(map, n);
	double sum = 0;
	for (int i = 0; i < n - 1; i++) {
		double temp;
		temp = map[A.gene[i]][A.gene[i + 1]];
		sum += sqrt(temp);
	}


	cout << "Summary path:" << sum << endl;
	return 0;
}
