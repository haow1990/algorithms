#include <string>

using namespace std;

int edit_distance(const string &from, const string &to)
{
	int **d;
	d = new int*[from.size() + 1];
	for (int i = 0; i <= from.size(); ++i) {
		d[i] = new int[to.size() + 1];
	}
	for (int i = 0; i <= from.size(); ++i) {
		d[i][0] = i;
	}
	for (int j = 0; j <= to.size(); ++j) {
		d[0][j] = j;
	}

	for (int i = 1; i <= from.size(); ++i) {
		for (int j = 1; j <= to.size(); ++j) {
			int add = d[i][j-1] + 1;
			int del = d[i-1][j] + 1;
			int substitute = d[i-1][j-1];
			if (from[i-1] != to[i-1]) {
				++substitute;
			}
			int min = add;
			if (del < min)	min = del;
			if (substitute < min) min = substitute;
			d[i][j] = min;
		}
	}
	return d[from.size()][to.size()];
}

