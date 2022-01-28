#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; string s1; vector<string> v;
    cin >> N;
    cin.ignore();
    while (N--) {
        v.clear();
        vector<string>().swap(v);
        getline(cin, s1);
        char *ptr = strtok(const_cast<char *>(s1.c_str()), " ");
        while (ptr != NULL) {
            v.push_back(string(ptr));
            ptr = strtok(NULL, " ");
        }
        int vsize = v.size();
        for (int i = 0; i < vsize - 1; i++) {
            reverse(v[i].begin(), v[i].end());
            cout << v[i] << " ";
        }
        if (vsize > 1) {
            reverse(v[vsize - 1].begin(), v[vsize - 1].end());
            cout << v[vsize - 1] << "\n";
        }
        else if (vsize == 1) {
            reverse(v[0].begin(), v[0].end());
            cout << v[0] << "\n";
        }
    }
    return 0;
}
