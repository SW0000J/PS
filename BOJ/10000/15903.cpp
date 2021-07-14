#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	long long int card[1000];

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> card[i];

	for (int i = 0; i < m; i++) {
		sort(card, card + n);
		long long temp = card[0] + card[1];
		card[0] = temp;
		card[1] = temp;
	}

	long long int total = 0;
	for (int i = 0; i < n; i++)
		total += card[i];
	cout << total;

	return 0;
}