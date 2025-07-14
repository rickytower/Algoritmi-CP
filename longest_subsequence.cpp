#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lui long unsigned int
vector < int >v = { 6, 2, 5, 1, 7, 4, 8, 3 };

/*
Input: i → limita il calcolo della longest increasing subsequence (LIS) fino all'indice i del vettore v
Output: dimensione della LIS di v da 0 a i
*/
int solve(int i, vector < int >&mxv)
{
	if (i == 0) {
		return 1;
	}
	if (mxv[i] > 0) {
		return mxv[i];
	}

	int mx = 1;
	for (int prev = 0; prev < i; prev++) {
		if (v[prev] < v[i]) {
			mx = max(mx, solve(prev, mxv) + 1);
		}
	}
	mxv[i] = mx;
	return mx;
}

int main()
{
	int res = 1;
	/* Genera risoluzione di tutti i problemi LIS su v da [0, 1] fino a [0, ..., v.size() - 1] di v, ciascuno restituisce una LIS.
	   Si prende la LIS massima valutando tutte le iterazioni
	 */
	vector < int >mxv(v.size(), 0);
	for (lui i = 1; i < v.size(); i++) {
		res = max(res, solve(i, mxv));
	}
	cout << res << endl;
	return 0;
}
