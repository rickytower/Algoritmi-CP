#include <bits/stdc++.h>
#define ll long long
#define lui long unsigned int
#define INPUT "input.txt"
#define OUTPUT "output.txt"
#define MONICA 0
#define PAOLA 1
#define buf_t  vector < vector < int >>

using namespace std;

/*soluzione*/
int solve1(buf_t & bufale, int N)
{
	int sodMonica = 0, sodPaola = 0;
	for (int i = 0; i < N; i++) {

		if (bufale[MONICA][i] < bufale[PAOLA][i]) {
			sodMonica += bufale[MONICA][i];
		} else {
			sodPaola += bufale[PAOLA][i];
		}
	}
	return sodMonica + sodPaola;
}

int main()
{
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		/* caso test t */
		int N;
		cin >> N;
		buf_t bufale(2, vector < int >(N));
		for (int i = 0; i < N; i++) {
			int m, p;
			cin >> m >> p;
			bufale[MONICA][i] = m;
			bufale[PAOLA][i] = p;
		}
		cout << solve1(bufale, N) << "\n";
	}
	return 0;
}
