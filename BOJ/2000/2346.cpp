#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(make_pair(i + 1, num));
	}

	while (!v.empty()) {
		cout << v[0].first << " ";
		int num = v[0].second;
		v.erase(v.begin());

		if (v.empty()) {
			break;
		}
		else if (num > 0) {
			for (int i = 0; i < num - 1; i++) {
				v.push_back(v[0]);
				v.erase(v.begin());
			}
		}
		else {
			for (int i = 0; i < abs(num); i++) {
				v.insert(v.begin(), v.back());
				v.erase(v.end() - 1);
			}
		}
	}

	return 0;
}