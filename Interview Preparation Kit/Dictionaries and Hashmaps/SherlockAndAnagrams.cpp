#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n - 1)

unordered_map<string, int>::iterator it;

int AnagramCount(string s){
    unordered_map<string,int> map;
    string temp;
    FOR(i, 1, s.size() - 1) {
        REP(j, (s.size() - i + 1)) {
            temp = s.substr(j, i);
            sort(temp.begin(), temp.end());

            it = map.find(temp);

            if (it == map.end()) {
                map.insert(pair<string, int> (temp, 1));
            }
            else {
                map[temp]++;
            }
        }
    }

    int cnt = 0; 
    for(it = map.begin(); it != map.end(); ++it) {
        // cout << (it->first) << " " << it->second << "times" <<endl;
        cnt += (it->second) * ((it->second) - 1) / 2;
    }
    return cnt;
}

int main(){
    int T;
    cin >> T;
    REP(t,T){
        string s;
        cin >> s;
        cout << AnagramCount(s)<<endl;
    }
}