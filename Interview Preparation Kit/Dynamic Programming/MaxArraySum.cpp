#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n-1)


int main() {
    int n;
    cin >> n;

    int A[n];
    REP(i, n) {
        cin >> A[i];
    }

    if (n == 1) {
        cout << A[0] << endl;
        return 0;
    }

    if (n == 2) {
        cout << max(A[0], A[1]) << endl;
        return 0;
    }

    int result = -1000000;
    int availableSum = 0;
    int nonavailaSum = 0;

    FOR(i, 0, n - 1) {
        result = max(result, availableSum + A[i]);

        int nextAvailableSum = max(availableSum, nonavailaSum);
        int nextNonavailaSum = availableSum + A[i];

        availableSum = nextAvailableSum;
        nonavailaSum = nextNonavailaSum;
    }
    cout << result << endl;
} 