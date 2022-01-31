#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2, s3; map<string, pair<ll, ll>> m;
    cin >> s1 >> s2 >> s3;
    m.insert({ "black", { 0,1 } });
    m.insert({ "brown", { 1,1e1 } });
    m.insert({ "red", { 2,1e2 } });
    m.insert({ "orange", { 3,1e3 } });
    m.insert({ "yellow", { 4,1e4 } });
    m.insert({ "green", { 5,1e5 } });
    m.insert({ "blue", { 6,1e6 } });
    m.insert({ "violet", { 7,1e7 } });
    m.insert({ "grey", { 8,1e8 } });
    m.insert({ "white", { 9,1e9 } });
    cout << stoll(to_string(m[s1].first) + to_string(m[s2].first)) * m[s3].second << "\n";
    return 0;
}
