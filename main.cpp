#include <iostream>
#include <cmath>

using namespace std;
int *tree;

int find_pow(int n) {
    int a = 1;
    while (a < n) {
        a *= 2;
    }
    return a * 2;
}

void build_tree(int *a, int n) {
    for (int i = 2 * n - 2; i >= n - 1; i--){
        a[i] = a[i - n + 1];
    }
    for (int i = n - 2; i >= 0; i--){
        a[i] = a[2 * i + 1] + a[2 * i + 2];
    }
}

long long sum(int l, int r, int x, int lx, int rx) {
    if (lx >= r or rx <= l) {
        return 0;
    }
    if (lx >= l && rx <= r) {
        return tree[x];
    }
    int m = round(((double) (lx + rx)) / 2.0);
    long long ls = sum(l, r, 2 * x + 1, lx, m);
    long long rs = sum(l, r, 2 * x + 2, m, rx);
    return ls + rs;
}

void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        tree[x] = v;
        return;
    }
    int m = round(((double) (lx + rx)) / 2.0);
    if (i < m) {
        set(i, v, 2 * x + 1, lx, m);
    } else {
        set(i, v, 2 * x + 2, m, rx);
    }
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}

int main() {
    int n, p, left, right;
    string query;
    cin >> n;
    p = find_pow(n);
    tree = new int[p];
    for (int i = 0; i < p / 2; i++) {
        if (i < n) {
            cin >> tree[i];
        } else {
            tree[i] = 0;
        }
    }
    build_tree(tree, p / 2);
    while (cin >> query) {
        if (query[1] == 'u') {
            cin >> left >> right;
            cout << sum(left - 1, right, 0, 0, p / 2 - 1) << endl;
        }
        else if (query[1] == 'e'){
            cin >> left >> right;
            set(left - 1, right, 0, 0, p/2 - 1);
        }
    }
    return 0;
}
