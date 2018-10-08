#include <iostream>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n - 1)
int main() {
    int n;
    cin >> n;

    string S;
    cin >> S;

    int P[n];
    int h = 0;
    REP(i, n) {
        if (S[i] == 'U')
            h++;
        if (S[i] == 'D')
            h--;
        P[i] = h;
    }

    int cnt = 0;
    int i = 0;

    bool inVel = false;
    while(i < n) {
        if (P[i] < 0) {
            inVel = true;
        }
        else if (P[i] >= 0) {
            if (inVel)
                cnt++;
            inVel = false;
        }
        i++;
    }
    cout << cnt;
}