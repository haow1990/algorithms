#include <iostream>
using namespace std;

int edit_distance(const string &from, const string &to);

int main(int argc, char **argv)
{
	if (argc != 3) {
		cerr << "usage: " << argv[0] << " <from> <to>\n";
		return 1;
	}

	cout << edit_distance(argv[1], argv[2]) << endl;

	return 0;
}

