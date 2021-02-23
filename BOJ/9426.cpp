#include <iostream>
#include <algorithm>

class smt {
public:
	smt() { }

	int update(int node, int start, int end, int index, int num) {
		if (index < start || index > end) {
			return mTree[node];
		}
		else if (start == end) {
			mTree[node] += num;
			return mTree[node];
		}

		int mid = (start + end) / 2;

		mTree[node] = update(node * 2, start, mid, index, num) + update(node * 2 + 1, mid + 1, end, index, num);

		return mTree[node];
	}

	int query(int node, int start, int end, int num) {
		if (start == end) {
			return start;
		}

		int mid = (start + end) / 2;

		if (mTree[node * 2] >= num) {
			return query(node * 2, start, mid, num);
		}
		else {
			return query(node * 2 + 1, mid + 1, end, num - mTree[node * 2]);
		}
	}

private:
	int mTree[65536 * 4];
};

int arr[250001] = { 0, };
smt seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int K;
	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	for (int i = 0; i < K; i++) {
		seg.update(1, 0, 65536, arr[i], 1);
	}

	long long ans = seg.query(1, 0, 65536, (K + 1) / 2);

	for (int i = K; i < N; i++) {
		seg.update(1, 0, 65536, arr[i], 1);
		seg.update(1, 0, 65536, arr[i - K], -1);

		int mid = seg.query(1, 0, 65536, (K + 1) / 2);

		ans += mid;
	}

	std::cout << ans << "\n";

	return 0;
}