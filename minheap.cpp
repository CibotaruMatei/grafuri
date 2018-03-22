/*
-pt i = 2 la n executa
    -determina tata = [i/2]
    -atata timp v[tata] > v[i] si tata >= 1
        -interschimb v[tata] si v[i]
        -fiu = tata
        -tata = [fiu/2]
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 2; i <= n; i++) {
        int tata = i/2, fiu;
        while(v[tata] > v[i] && tata >= 1) {
            swap(v[tata], v[i]);
            fiu = tata;
            tata = fiu/2;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}
