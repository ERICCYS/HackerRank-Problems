#include <iostream>

using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n-1)

void swap(int i, int j, int A[]) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    REP(i, n)  {
        cin >> A[i];
    }
    int cnt = 0;
    REP(i, n - 1) {
        REP(j, n - (i + 1)) {
            if (A[j] > A[j + 1]) {
                cnt++;
                swap(j, j + 1, A);
            }
        }
    }

    cout << "Array is sorted in " << cnt << " swaps." <<endl;
    cout << "First Element: " << A[0] << endl;
    cout << "Last Element: " << A[n - 1] << endl;

}   