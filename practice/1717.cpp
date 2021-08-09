#include <iostream>
using namespace std;

#define MAX 1000001

int parent[MAX];

int find_parent(int r){
    if(parent[r] != r){
        parent[r] = find_parent(parent[r]);
    }
    return parent[r];
}

void unions(int r1, int r2){
    r1 = find_parent(r1);
    r2 = find_parent(r2);

    if(r1 < r2)
        parent[r2] = r1;
    else{
        parent[r1] = r2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }

    int op, a, b;
    for(int i = 0; i < m; i++){
        cin >> op >> a >> b;

        if(op == 0)
            unions(a, b);
        else if(op == 1){
            if (find_parent(a) == find_parent(b)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}