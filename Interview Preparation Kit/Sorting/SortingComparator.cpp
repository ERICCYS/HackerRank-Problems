#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n-1)
struct Player {
    int score;
    string name;
};

class Checker {
public:
    static int comparator (Player a, Player b) {
        return (a.score > b.score) ? 1 : (a.score == b.score && a.name <= b.name) ? 1 : -1;
    }
}

bool compare (Player a, Player b) {
    if (Checker::comparator(a,b) == -1) 
        return false;
    else
        return true;
}

int main() {
    int n;
    cin >> n;
    vector<Player> players;

    string name;
    int score;

    REP(i, n) {
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }

    sort(players.begin(), players.end(), compare);

    REP(i, players.size()) {
        cout << players[i].name << " " << players[i].score;
    }

    return 0;
}
