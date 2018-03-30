/*
cazuri particulare de grafuri neorientate
- arbori
- ponderate

fie G(X, U) graf neorientat. numim pondere o functie definita pe U cu valori in multimea numerelor reale pozitive (numite costuri)

metode de prezentare:
1. Matricea costurilor unde M[i][j] e costul muchiei i, j sau 0 daca muchia i, j nu exista
2. Colectie de muchii

problema APM (arbore partial de cost minim intr-un graf)

arbore = graf conex fara cicluri, conexitate minimala, aciclicitate maximala
arbore partial = graf partial al lui G(X, U) graf neorientat care este si arbore
graf partial = G(X', U') obtinut din G(X, U) daca U' inclus in U; se obtine prin eliminarea unor muchii

APM, in esenta, inseamna gasirea unui drum de cost total minim a unei traversari in graf astfel incat sa nu vizitam de doua ori acelasi nod

algoritmul utilizat exploateaza un rezultat matematic care afirma ca, prin unificarea a 2 arbori disjuncti, ceea ce rezulta e tot arbore

unificare = trasarea unei singure noi muchii intre cei 2 arbori

rezultatul matematic este aplicat cu o tehnica de tip greedy:
- criteriul de optim global e formulat prin costul total minim al arborelui partial ce urmeaza a fi depistat
- criteriul de optim local aplicat pana la indeplinirea criteriului de optim global este dat de selectia unei muchii de cost minim pentru a face o unificare intre 2 arbori disjuncti

sunt mai multe tehnici pentru aplicarea criteriului de optim local:
1. Kruskal
principiu: pornesc considerand initial un set de n arbori disjuncti singleton formati doar din nodurile grafului; execut o prima unificare alegand muchia de cost minim. toate celelalte unificari le execut alegand muchia de cost minim cu o extremitate in arborele rezultat al primii unificari si celalalt intr-un arbore disjunct

evident, algoritmul poate cunoaste o optimizare daca presortam crescator muchiile dupa costul lor (colectii de muchii)

("maturat cu o singura gramada")

2. Prim

("maturat cu mai mult de o gramada")

principiu: se alege muchia de cost minim indiferent de extremitati

1. exemplu:

   1
   *
 2/ \3
2*---*5
 | 9 |
 |1  |2
 |   |
3*---*4
   4

initial:
A1    A2    A3    A4    A5
*1    *2    *3    *4    *5

pas 1:
A1    A2          A4    A5
*1    *2----*3    *4    *5

pas 2:
A1                A4    A5
*1----*2----*3    *4    *5

pas 3:
A1                A4
*1----*2----*3    *4
|
*5

algoritmul ruleaza executand unificari pana cand arborele rezultat este graf partial al lui G (in urma unificarii ceea ce obtinem contine toate nodurile) (sunt executate n-1 unificari)

poate fi dificila reprezentarea in memorie reprezentarea arborilor disjuncti in care trebuie facute modificari

o solutie simpla este de a nu retine arborii efectiv, ci pentru fiecare nod numele arborelui din care face parte

asta ar insemna utilizarea unui vector in care index inseamna nume de nod si continut numele subarborelui din care face parte

M: 1|2|3|4|5
   1 2 3 4 5

pas 1: unificare alegand (2, 3)
M: 1|2|2|4|5

asadar, algoritmul dupa executia celor n-1 unificari, in vectorul n al codificarilor, va memora numele unui singur arbore.
ca rezultat al abordarii, arborele partial de cost minim ca o colectie de muchii
*/
#include<stdio.h>
using namespace std;

FILE * f;

int main() {
    int n;
    f = fopen("input.data", "r");
    fscanf(f, "%i", &n);
    int G[n][3];
    for(int i = 0; i < n; i++) {
        fscanf(f, "%i%i%i", &G[i][0], &G[i][1], &G[i][2]);
    }
    fclose(f);

    for(int i = 1; i < n; i++) {
        if(G[i][2] < G[i-1][2]) {
            for(int j = i; j > 0; j--) {
                if(G[j][2] < G[j-1][2]) {
                    swap(G[i][0], G[i-1][0]);
                    swap(G[i][1], G[i-1][1]);
                    swap(G[i][2], G[i-1][2]);
                } else {
                    break;
                }
            }
        }
    }

    int N[n], V[n][3], top;

    for(int i = 0; i < n; i++) {
        printf("%i %i %i\n", G[i][0], G[i][1], G[i][2]);
    }

    f = fopen("output.data", "w");

    fclose(f);
    return 0;
}
//optimizare FIFO: parcurg de unde am ramas
