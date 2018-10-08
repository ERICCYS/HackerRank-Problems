#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++) 
#define REP(i, N) FOR(i, 0, N-1)
#define SIZE 6

int Sum (int A[][SIZE], int a, int b) {
    int sum = A[a][b] + A[a][b + 1] + A[a][b + 2] + A[a + 1][b + 1] + A[a + 2][b] + A[a + 2][b + 1] + A[a + 2][b + 2];
    return sum;
}

int MaxSum (int A[][SIZE]) {
    int M = -100000000;
    FOR(i, 0, SIZE - 3) {
        FOR(j, 0, SIZE - 3) {
            M = max(M, Sum(A, i, j));
        }
    }
    return M;
}

int main() {
    int A[SIZE][SIZE];

    FOR(i, 0, SIZE - 1) {
        FOR(j, 0, SIZE - 1) {
            cin >> A[i][j];
        }
    }

    cout << MaxSum(A) << endl;
}