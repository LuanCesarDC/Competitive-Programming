#include <bits/stdc++.h>

using namespace std;

int main() {
    int h,w; cin >> h >> w;
    int ci, cj;
    int centros = 0;
    int pontosCruz = 1, pontosAst = 0;
    vector<vector<char>> v(h, vector<char>(w));

    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            char aux; cin >> aux;
            v[i][j] = aux;
            if(aux == '*') {
                pontosAst++;
            }
        }
    }

    for(int i=1;i<h-1;i++) {
        for(int j=1;j<w-1;j++) {
            bool centro = v[i][j] == '*' && v[i-1][j] == '*' && v[i+1][j] == '*' && v[i][j-1] == '*' && v[i][j+1] == '*' && v[i-1][j-1] == '.' && v[i-1][j+1] == '.' && v[i+1][j-1] == '.' && v[i+1][j+1] == '.';
            if(centro) {
                centros++;
                ci = i;
                cj = j;
            }
        }
    }

    if(centros == 1) {
        int aux = 1;
        while(ci-aux >= 0 && v[ci-aux][cj] == '*') {
            v[ci-aux][cj] = '$';
            aux++;
            pontosCruz++;
        }
        aux = 1;
        while(ci+aux < h && v[ci+aux][cj] == '*') {
            v[ci+aux][cj] = '$';
            aux++;
           pontosCruz++;
        }
        aux = 1;
        while(cj-aux >= 0 && v[ci][cj-aux] == '*') {
            v[ci][cj-aux] = '$';
            aux++;
            pontosCruz++;
        }
        aux = 1;
        while(cj+aux < w && v[ci][cj+aux] == '*') {
            v[ci][cj+aux] = '$';
            aux++;
            pontosCruz++;
        }
        if(pontosAst == pontosCruz) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}