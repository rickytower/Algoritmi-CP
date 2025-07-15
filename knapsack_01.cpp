#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapsackRec(int capacity, vector < int >&value, vector < int >&weight,
		int n, vector < vector < int >>&memo)
{

	// Base Case
	if (n == 0 || capacity == 0)
		return 0;

	// Check if we have previously calculated the same subproblem
	if (memo[n][capacity] != -1)
		return memo[n][capacity];

	int pick = 0;

	// Pick nth item if it does not exceed the capacity of knapsack
	if (weight[n - 1] <= capacity) {
		pick =
		    value[n - 1] + knapsackRec(capacity - weight[n - 1], value,
					       weight, n - 1, memo);
	}
	// Don't pick the nth item
	int notPick = knapsackRec(capacity, value, weight, n - 1, memo);

	// Store the result in memo[n][W] and return it
	return memo[n][capacity] = max(pick, notPick);
}

int knapsack(int capacity, vector < int >&value, vector < int >&weight)
{
	int n = value.size();

	// Memoization table to store the results
	vector < vector < int >>memo(n + 1, vector < int >(capacity + 1, -1));

	return knapsackRec(capacity, value, weight, n, memo);
}

int main()
{
	vector < int >value = { 1, 2, 3 };
	vector < int >weight = { 4, 5, 1 };
	int capacity = 4;

	cout << knapsack(capacity, value, weight) << endl;
	return 0;
}
