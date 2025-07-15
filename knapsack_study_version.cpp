#include <bits/stdc++.h>
#define ll long long
#define lui long unsigned int
using namespace std;
#define N 6
// per semplicità, consideriamo il caso 0 w, 0 v come il caso base
// in cui nessun oggetto viene selezionato
const int w[N] = { 0, 1, 2, 4, 2, 5 };
const int v[N] = { 0, 5, 3, 5, 3, 2 };

/* cache */
int m[N][N];

/* Approccio brute force (no memoizzazione) */
int solve(int item, int capacity)
{
	int result = 0;
	if (item == 0 || capacity == 0) {
		return 0;
	} else if (w[item] > capacity) {
		return solve(item - 1, capacity);
	} else {
		int sol1 = solve(item - 1, capacity);
		int sol2 = solve(item - 1, capacity - w[item]) + v[item];
		result = max(sol1, sol2);
	}
	return result;
}

int solve_memo(int item, int capacity)
{
	int result = 0;

	if (m[item][capacity] != -1) {
		return m[item][capacity];
	}
	if (item == 0 || capacity == 0) {
		return 0;
	} else if (w[item] > capacity) {
		return solve_memo(item - 1, capacity);
	} else {
		int sol1 = solve_memo(item - 1, capacity);
		int sol2 = solve_memo(item - 1, capacity - w[item]) + v[item];
		result = max(sol1, sol2);
	}
	m[item][capacity] = result;
	return result;
}

int main()
{
	int capacity = 0;
 for (auto i:w) {
		capacity += i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = -1;
		}
	}

	cout << solve(N - 1, capacity) << endl;
	cout << solve_memo(N - 1, capacity) << endl;
	return 0;
}
