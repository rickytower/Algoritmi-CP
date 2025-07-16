#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
int main()
{
	string dest;
	cout << "Nome sorgente: ";
	cin >> dest;
	dest = "/home/rtorre/Algoritmi-CP/" + dest + ".cpp";
	char destc[dest.length() + 1];
	for (unsigned long int i = 0; i < dest.size(); i++) {
		destc[i] = dest.at(i);
	}
	freopen("/home/rtorre/Algoritmi-CP/template.cpp", "r", stdin);

	cout << "Nome destinazione: " << destc << endl << endl;
	freopen(destc, "w", stdout);

	string line;
	while (getline(cin, line)) {
		cout << line << endl;
	}

	cout << endl;
	return 0;
}
