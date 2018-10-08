#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n - 1)

unordered_map<char, int>::iterator it;
bool HaveCommon(string S1, string S2) {
    char a;
    unordered_map<char, int> map;
    REP(i, S1.size()) {
        it = map.find(S1[i]);

        if (it == map.end()) {
            map.insert(pair<char, int> (S1[i],1));
        }

        else 
            map[S1[i]]++;
    }

    REP(i, S2.size()) {
        it = map.find(S2[i]);

        if (it == map.end())
            continue;
        else
            return true;
    }

    return false;
}


int main() {
    int T;
    cin >> T;
    REP(t, T) {
        string S1;
        string S2;
        cin >> S1;
        cin >> S2;

        if (HaveCommon(S1, S2))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}