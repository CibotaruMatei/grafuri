/*
n
S ________________
D ________________
S[i] = 0 inseamna ca nu are descendent
*/
#include <iostream>
#include <fstream>
using namespace std;

fstream f;
int n, mover = 1;
int *S, *D, *varfuri, **display, *coada;

void rec(int val, int *S, int *D, int **display, int *varfuri) {
    cout << val << endl;
    display[mover][varfuri[mover]] = val;
    varfuri[mover]++;

    if(S[val] != 0) {
        mover++;
        rec(S[val], S, D, display, varfuri);
        mover--;
    }
    if(D[val] != 0) {
        mover++;
        rec(D[val], S, D, display, varfuri);
        mover--;
    }
}

int main() {
    f.open("data.txt", ios::in);
    f >> n;

    for(int i = 0; i < n; i++) {
        f >> S[i+1];
    }
    for(int i = 0; i < n; i++) {
        f >> D[i+1];
    }
    f.close();

    S = D = varfuri = coada = new int[n+1];
    display = new int[n+1];

    cout << "done" << endl;

    for(int i = 0; i <= n; i++) {
        varfuri[i] = 1;
    }
    for(int i = 0; i <= n; i++) {
        cout << i << endl;
        for(int j = 0; j <= n; j++) {
            display[i][j] = 0;
        }
    }

    rec(1, S, D, display, varfuri);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << display[i][j] << " ";
        }
        cout << endl;
    }
}
