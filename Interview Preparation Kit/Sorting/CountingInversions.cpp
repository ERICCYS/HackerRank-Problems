#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, n-1)

unsigned long long NumInversion = 0;

void Merge(int A[], int l, int r, int m) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int B[n1];
    int C[n2];

    REP(i, n1) {
        B[i] = A[l + i];
    }

    REP(i, n2) {
        C[i] = A[i + m + 1];
    }

    int i = l;
    int j = 0;
    int k = 0;

    unsigned long long numinver = 0;
    while (j < n1 && k < n2) {
        if (B[j] <= C[k]) {
            A[i] = B[j];
            j++;
        }
        else {
            A[i] = C[k];
            k++;
            numinver += (n1 - j);
        }
        i++;
    }

    NumInversion += numinver;
    while (j < n1) {
        A[i] = B[j];
        i++;
        j++;
    }

    while (k < n2) {
        A[i] = C[k];
        i++;
        k++;
    }

}

void MergeSort(int A[], int l, int r) {
    if (r <= l) {
        return ;
    }
    int m = (l + r - 1) / 2;
    MergeSort(A, l, m);
    MergeSort(A, m + 1, r);
    Merge(A, l, r, m);
}
 


int main() {
    int d;
    cin >> d;
    

    while(d--) {
        int n;
        cin >> n;
        int A[n];
        REP(i, n) {
            cin >> A[i];
        }

        MergeSort(A, 0, n - 1);

        cout << NumInversion << endl;
        NumInversion = 0;
    }
}