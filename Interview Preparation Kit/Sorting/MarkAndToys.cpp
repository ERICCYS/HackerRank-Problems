#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n-1)


int main () {
    int n, k;
    cin >> n >> k;

    int P[n];
    
    REP(i, n) {
        cin >> P[i];
    }

    sort(P, P  + n);

    int cnt = 0;
    while (k >= 0) {
        k -= P[cnt];
        cnt++;
    }

    cout << --cnt << endl;

}