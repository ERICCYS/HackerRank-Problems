#include <iostream>
#include <queue>

using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++) 
#define REP(i, N) FOR(i, 0, N-1)

int main() {
    int n, d;
    cin >> n >> d;
    int num;
    queue <int> q;

    REP(i, n) {
        cin >> num;
        q.push(num);
    }

    REP(i, d) {
        num = q.front();
        q.pop();
        q.push(num);
    }

    REP(i, n) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}