#include <cstdio>
#include <vector>
#include<iostream>
using namespace std;
int main() {
    int N;
    for (;;) {
        scanf("%d", &N);
        if (!N) return 0;
        vector<vector<char> > adj(2*N, vector<char>(2*N));
        for (int i = 0; i < N; i++) {
            int j; char s[10];
            cin>>j>>s; j--;
            if (s[0] == 't') {
                adj[i][j] = true; adj[j+N][i+N] = true;
                adj[i+N][j+N] = true; adj[j][i] = true;
            } else {
                adj[i][j+N] = true; adj[j][i+N] = true;
                adj[i+N][j] = true; adj[j+N][i] = true;
            }
        }
        for (int k = 0; k < 2*N; k++) {
            for (int i = 0; i < 2*N; i++) {
                for (int j = 0; j < 2*N; j++) {
                    adj[i][j] |= adj[i][k] && adj[k][j];
                }
            }
        }
        bool paradox = false;
        for (int i = 0; i < N; i++) {
            paradox |= adj[i][i+N];
        }
        if (paradox) {
            cout<<"PARADOX\n";
        } else {
            cout<<"NOT PARADOX\n";
        }
    }
}
