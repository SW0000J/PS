#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	set<int> s;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < M; i++) {
		int num; cin >> num;

		if (s.count(num)) {
			s.erase(num);
		}
		else {
			s.insert(num);
		}
	}

	cout << s.size() << "\n";

	return 0;
}