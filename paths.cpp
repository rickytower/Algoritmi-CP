#include <bits/stdc++.h>
#define ll long long
#define lui long unsigned int
using namespace std;

const int grid[5][5] = {
	{3, 7, 9, 2, 7},
	{9, 8, 3, 5, 5},
	{1, 7, 9, 8, 5},
	{3, 8, 6, 4, 10},
	{6, 3, 9, 7, 8}
};

void printsum(int sum[][5])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int sum(int y, int x)
{
	if (x < 0 || y < 0) {
		return 0;
	}

	return max(sum(y, x - 1), sum(y - 1, x)) + grid[y][x];
}

int main()
{
	cout << sum(4, 4) << endl;
	return 0;
}
