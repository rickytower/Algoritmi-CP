#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lui long unsigned int

int solve(const vector < int >&v)
{
	int n = v.size();
	/*r  contiene i risultati */
	vector < int >r;
	/* aggiungiamo ad r il primo elemento di v */
	r.push_back(v[0]);

	for (int i = 0; i < n; i++) {
		if (v[i] > r.back()) {
			// Se il numero corrente è maggiore
			// dell'ultimo elemento del vettore di risposta,
			// significa che abbiamo trovato una
			// sottosequenza crescente più lunga.
			// Quindi, aggiungiamo il numero corrente
			// al vettore di risposta.
			r.push_back(v[i]);
		} else {
			// Se il numero corrente non è
			// maggiore dell'ultimo elemento del
			// vettore di risposta, eseguiamo
			// una ricerca binaria per trovare il più piccolo
			// elemento nel vettore di risposta che
			// sia maggiore o uguale al
			// numero corrente.

			// La funzione lower_bound restituisce
			// un iteratore che punta al primo
			// elemento che non è minore del
			// numero corrente.
			int low =
			    lower_bound(r.begin(), r.end(), v[i]) - r.begin();
			// Aggiorniamo l'elemento nella
			// posizione trovata con il numero corrente.
			// In questo modo, manteniamo
			// un ordinamento nel vettore delle risposte.
			r[low] = v[i];
		}

	}
	// La lunghezza del vettore di risposta
	// rappresenta la lunghezza della
	// sottosequenza crescente più lunga.
	return r.size();
}

int main()
{
	vector < int >v = { 10, 22, 9, 33, 21, 50, 41, 60 };
	cout << solve(v) << endl;
	return 0;
}
