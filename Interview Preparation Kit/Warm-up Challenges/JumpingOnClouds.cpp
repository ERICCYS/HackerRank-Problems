#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++) 
#define REP(i, N) FOR(i, 0, N-1)
#define INF 100000000

int main() {
    int N;
    cin >> N;

    int C[N];
    REP(i, N) {
        cin >> C[i];
    }
    int D[N];
    REP(i, N) {
        if (C[i] == 1)
            D[i] = INF;
        else 
            D[i] = 0;
    }
    D[1]++; 
    FOR(i, 2, N - 1) {
        if (D[i] != INF)
            D[i] = min(D[i - 2], D[i - 1]) + 1;
    }
    cout << D[N - 1] << endl;
}