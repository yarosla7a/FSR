#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int n, i, j; double xx, yy;
	cin >> n;
	ofstream input;
	input.open("input.dzn");
	input << "n = " << n << ';' << endl;
	/*input << "E_n = " << n * (n - 1) << ';' << endl;
	input << "E = array2d(1..E_n, 1..2,[ " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j) {
				input << i + 1 << ',' << j + 1 << ',' << endl;
			}
		}
	}
	input << "]);" << endl;*/
	vector <double> x(n), y(n);
	for (i = 0; i < n; i++) {
		cin >> xx >> yy;
		x[i] = xx;
		y[i] = yy;
	}

	input << "dist = [" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j) {
				input << round(sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) * 1000); input << ","; //<< ',' << endl;
			}
			if (i == j) { input << 0; input << ","; };// << endl;
		}
			input << "\n";
	}
	input << "];\n";
	input << "start_city = " << 1 << ';' << endl;
	input << "end_city = " << 1 << ';' << endl;
	input.close();
	system("minizinc --solver Gecode TSP7.mzn input.dzn --time-limit 360000");
	return 0;
}