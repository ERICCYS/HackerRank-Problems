#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define FOR(i, a, b) for(int (i) =  (a); (i) <= (b); (i)++) 
#define REP(i, n) FOR(i, 0, n - 1)
int Pairs(int n, vector<int> A) {
    int T[n];
    REP(i, n) {
        T[i] = 1;
    }

    FOR(i, 0, n - 2) {
        FOR(j, i + 1, n - 1) {
            if (A[j] == A[i])
                T[j]++;
        }
    }

    int cnt = 0;
    REP(i, n) {
        if (T[i] % 2 == 0)
            cnt++;
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    REP(i, n) {
        cin >> A[i];
    }

    cout << Pairs(n, A);

}