#include<stdio.h>
using namespace std;

FILE * f;

int findmax(int * V, int x) {
    int maximum = V[0];
    for(int i = 1; i < x; i++) {
        if(maximum < V[i]) maximum = V[i];
    }
    return maximum;
}

int main() {
    int n;
    f = fopen("input.data", "r");
    fscanf(f, "%i", &n);
    int L[n];
    for(int i = 0; i < n; i++) {
        fscanf(f, "%i", &L[i]);
    }
    int M[n][findmax(L, n)];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < L[i]; j++) {
            fscanf(f, "%i", &M[i][j]);
        }
    }
    fclose(f);

    int P[n], sum = 0;
    for(int i = 0; i < n; i++) {
        P[i] = 0;
        sum += L[i];
    }
    int V[sum];

    /*
    pass through all M[i][P[i]] available while copy of n > 0
    find the minimum value and place it in V, then:
        P[i]++
        if P[i] == L[i]
            take line i from M and values of index i from P and L
    */

    while(n) {
        int maxloc = 0;
        for(int i = 0; i < n; i++) {

        }
    }

    f = fopen("output.data", "w");

    fclose(f);
    return 0;
}
