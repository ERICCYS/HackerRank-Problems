#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define REP(i, N) FOR(i, 0, N-1)

int main() {
    int t, n;
    cin >> t;
    REP(a, t) {
        cin >> n;
        int A[n];
        bool valid = true;
        int dif = 0;
        REP(i, n) {
            cin >> A[i];
            if ((A[i] - (i + 1)) > 2) {
                valid = false;
            }
        }

        if (valid) {
            int cnt = 0;
            FOR(i, 1, n - 1) {
                if (A[i] > (i + 1))
                    continue;
                int start = (A[i] > 2) ? (A[i] - 2) : 0;
                FOR(j, start, i - 1) {
                    if (A[i] < A[j])
                        cnt++;
                }
            }

            cout << cnt << endl;
        }
            
        else 
            cout << "Too chaotic" << endl;
    }

}