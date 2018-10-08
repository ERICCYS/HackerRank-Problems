#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++) 
#define REP(i, N) FOR(i, 0, N-1)

ll CountA (string S, int n) {
    ll cnt = 0;
    REP(i, S.length()) {
        if (i > n - 1)
            break;
        if (S[i] == 'a')
            cnt++;
    }
    return cnt;
}

int main() {
    string S;
    ll N;
    cin >> S;
    cin >> N;

    ll cnt = (N / S.length()) * CountA(S, S.length()) + CountA(S, (N % S.length()));
    cout << cnt << endl;
}