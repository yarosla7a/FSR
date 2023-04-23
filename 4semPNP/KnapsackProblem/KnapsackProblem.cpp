// KnapsackDynamo
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
	string s1, s2;
	ifstream File;

	string name;
	cout << "Enter file number:\n(for example: 1000_0)\n";
	cin >> name;



	File.open("./data/ks_" + name);
	int n, maxWeight;
	File >> s1 >> s2;
	istringstream os1(s1);
	os1 >> n;

	istringstream os2(s2);
	os2 >> maxWeight;


	vector<int> v(n);//values
	vector<int> w(n);//weights

	int d;
	for (int i = 0; i < n; ++i) {
		File >> s1 >> s2;
		istringstream os1(s1);
		os1 >> d;
		v[i] = d;

		istringstream os2(s2);
		os2 >> d;
	    w[i] = d;
	}
	File.close();


	vector<vector<int>> V(n, vector<int>(maxWeight + 1, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= maxWeight; ++j) {
			if (w[i] <= j) {
				if (i > 0)
					V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
				else
					V[i][j] = v[i];
			}
			else {
				if (i > 0)
					V[i][j] = V[i - 1][j];
			}
		}
	}

	// the problem solved dynamically, output remains
	vector<int> items;// array of items taken(indexes)

	int k, wt;
	k = n - 1; wt = maxWeight;
	while (V[k][wt]) {
		if (V[k][wt] == V[k - 1][wt]) {
			k = k - 1;
		}
		else if (V[k][wt] == v[k] + V[k - 1][wt - w[k]]) {
			items.push_back(k);
			wt = wt - w[k];
			k = k - 1;
		}
		else
			cout << "error\n";
	}

	reverse(items.begin(), items.end());

	cout << endl;
	cout << "Indexes of taken items: ";
	int vSum = 0, wSum = 0;
	for (int i : items) {
		cout << i << ' ';
		vSum += v[i];
		wSum += w[i];
	}
	cout << endl;
	cout << "Best value: " << vSum << endl;
	cout << "Remaining space: " << maxWeight - wSum << endl;

	
	return 0;
}