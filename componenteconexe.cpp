#include <iostream>
#include <fstream>
using namespace std;

int M[100][100], n, S[100], vf, last, V[100], top = 0, comp = 0, rem;
fstream f;

bool belongsto(int * V, int top, int val) {
    for(int i = 0; i < top; i++) {
        if(val == V[i]) return 1;
    }
    return 0;
}

void display(int * V, int top) {
    for(int i = 0; i < top; i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}

int tipar(int S[100],int vf) {
    return 1;
}

int solutie(int S[100], int vf) {
    if(!belongsto(V, top, S[vf-1])) {
        V[top] = S[vf-1];
        top++;
    }
    return vf == rem;
}

int succesor(int S[100], int vf) {
    for(int i = last; i < n; i++) {
        if(M[S[vf-1]][i]) {
            S[vf] = i;
            return 1;
        }
    }
    return 0;
}

int valid(int S[100], int vf) {
    for(int i = 0; i < vf; i++) {
        if(S[vf] == S[i]) {
            last = S[vf]+1;
            return 0;
        }
    }
    return 1;
}

int init(int S[100], int vf) {
    last = 0;
}

int DFS_REC(int S[100],int vf) {
    if (solutie(S,vf)) { return tipar(S,vf); }
    while ( succesor(S,vf) ) {
        if (valid(S,vf)) {
            init(S,vf+1);
            return DFS_REC(S,vf+1);
        }
    }
    return 0;
}

int main() {
    f.open("data.txt", ios::in);
    f >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            f >> M[i][j];
        }
    }
    f.close();
    for(int i = 0; i < n; i++) {
        if(!belongsto(V, top, i)) {
            rem = n - top;
            S[0] = i;
            comp++;
            if(DFS_REC(S, 1)) break;
            display(V, top);
        }
    }
    cout << comp;
    return 0;
}
