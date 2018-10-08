#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define SIZE 32

string getBitString (unsigned int n) {
    char bitString[SIZE];
    FOR(i, 0, SIZE - 1)  {
        bitString[i] = '0';
    }
    int pos = 31;
    while (n != 0) {
        if (n % 2 == 1)
            bitString[pos] = '1';
        n /= 2;
        pos--;
    }
    // FOR(i, 0, SIZE - 1)  {
    //     cout << bitString[i];
    // }
    // cout << endl;
    string s(bitString);
    return s;
}


string flipBits (string s) {
    char flipString[SIZE];
    FOR(i, 0, SIZE - 1) {
        if (s[i] == '0')
            flipString[i] = '1';
        else
            flipString[i] = '0';
    }
    string fs(flipString);
    return fs;
}

unsigned int getNumber (string s) {
    unsigned int r = 0;
    ROF(i, SIZE - 1, 0) {
        if (s[i] == '1')
            r += pow(2, (SIZE - 1 - i));
    }
    return r;
}


int main() {
    int q;
    cin >> q;
    unsigned int n;
    string s;
    while (q--) {
        cin >> n;
        string bitString = getBitString(n);
        // cout << bitString << endl;
        string flippedString = flipBits(bitString);
        // cout << flippedString << endl;
        cout << getNumber(flippedString) << endl;
    }
}


