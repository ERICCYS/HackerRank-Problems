#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define REP(i, N) FOR(i, 0, N-1)


int main() {
    int n;
    cin >> n;
    int A[n + 1];
    int P[n + 1];

    
    FOR(i, 1, n) {
        cin >> A[i];
        if (A[i] > n) A[i] = n;
        P[A[i]] = i;
    }

    int cnt = 0;
    int temp;
    int tepi;
    FOR(i, 1, n) {
        if (A[i] == i)
            continue;
        
        // Swap the number A[i] and number i's position.
        temp = A[i];
        A[i] = i;
        A[P[i]] = temp; // P[i] is the previous position of i; 

        P[temp] = P[i];
        P[i] = i;
        cnt++;
    }

    cout << cnt << endl;

}