#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n - 1)

unordered_map<string, int>::iterator it;

bool MadeFrom(vector<string> Magz, vector<string> Note) {
    unordered_map <string, int> map;
    REP (i, Magz.size()) {
        it = map.find(Magz[i]);

        if (it == map.end()) {
            map.insert(pair<string, int> (Magz[i], 1));
        } else {
            map[Magz[i]]++;
        }
    }

    REP(i, Note.size()) {
        it = map.find(Note[i]);

        if (it == map.end())
            return false;
        else if (it->second == 0){
            return false;
        }
        map[Note[i]]--;
    }
    return true;
    
}


int main() {
    int m, n;
    cin >> m >> n;
    vector <string> Magz(m); 
    vector <string> Note(n);
    REP(i, m) {
        cin >> Magz[i];
    }

    REP(i, n) {
        cin >> Note[i];
    }

    if (m < n) {
        cout << "No" << endl;
        return 0;
    }

    else {
        if (MadeFrom(Magz, Note))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }
}