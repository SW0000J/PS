#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N; cin >> N;
    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);

    for (int i = 1; i < N; i++) {
        if (v[i].first >= pq.top()) {
            pq.pop();
        }

        pq.push(v[i].second);
    }

    cout << pq.size() << "\n";

    return 0;
}