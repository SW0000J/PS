#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> isPrime;
vector<int> primeNum;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N; cin >> N;

    isPrime.resize(N + 1, true);

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primeNum.push_back(i);
        }
    }

    int ans = 0;
    int total = 0;
    int low = 0;
    int high = 0;

    while (true) {
        //cout << total << "\n";
        if (total >= N) {
            total -= primeNum[low++];
        }
        else if (high == primeNum.size()) {
            break;
        }
        else {
            total += primeNum[high++];
        }

        if (total == N) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}