#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        if (binary_search(v.begin(), v.end(), num))cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    map<int, bool> v;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.insert({ num, true });
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        if (v.find(num) != v.end())cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    unordered_map<int, bool> v;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.insert({ num, true });
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        if (v.find(num) != v.end())cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    set<int> v;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.insert(num);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        if (v.find(num) != v.end())cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}
