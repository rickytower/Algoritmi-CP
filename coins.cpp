#include <bits/stdc++.h>
#include <cmath>
#include <ostream>
using namespace std;
/* Monete */
vector < int >coins = { 1, 3, 4 };

/* Contiene il numero di soluzioni per ottenere la somma x */
vector < int >solVec;
/* Contiene tutti i best per x. Da inizializzare nel main */
vector < float >b;
/* solve(x) = foreach c:coins solve(x) = min(solve(x-c)+1)*/
int nSol(int x)
{
	/* La somma zero si ottiene non usando monete → n°sol = 1 */
	if (x == 0) {
		return 1;
	}
	/* Se la somma x è negativa, non esiste alcuna soluzione → n°sol = 0 */
	if (x < 0) {
		return 0;
	}
	if (solVec[x - 1] > 0) {
		return solVec[x - 1];
	}
	solVec[0] = 1;
	//binint sol = 0;
 for (auto c:coins) {
		if (x - c >= 0)
			solVec[x - 1] += nSol(x - c);
	}
	//solVec[x - 1] = sol;
	return solVec[x - 1];
}

float solve(int x)
{
	/* La somma è zero, quindi ci sono zero modi per combinare le monete */
	if (x == 0) {
		return 0;
	}
	/* In questo caso la somma delle monete non è maggiore di zero, errore */
	if (x < 0) {
		return INFINITY;
	}
	/* Recupero valore best per ottenere la somma x */
	if (b[x - 1] != INFINITY) {
		return b[x];
	}
	float best = INFINITY;
 for (auto c:coins) {
		best = min(best, solve(x - c) + 1);
	}
	/* Memoizzazione */
	b[x - 1] = best;
	return best;
}

int main()
{
	int x = 10;
	for (int i = 0; i < x; i++) {
		b.push_back(INFINITY);
		solVec.push_back(0);
	}
	solVec[0] = 1;
	cout << solve(x) << endl;
	cout << nSol(x) << endl;
	return 0;
}
