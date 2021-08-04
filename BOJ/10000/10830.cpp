#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<vector<long long>> Matrix;

long long N;
long long B;

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix ans(N, vector<long long>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ans[i][j] = ans[i][j] + m1[i][k] * m2[k][j];
            }
            ans[i][j] %= 1000;
        }
    }

    return ans;
}

Matrix pow(Matrix mat, long long n) {
    Matrix ans(N, vector<long long>(N));

    for (int i = 0; i < N; i++) {
        ans[i][i] = 1;
    }

    for (; n > 0; n /= 2) {
        if (n % 2 == 1) {
            ans = ans * mat;
        }

        mat = mat * mat;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> B;

    Matrix mat(N, vector<long long>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    Matrix ans = pow(mat, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}