#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; stack<int> st; string ans;
    cin >> N;
    vector<bool> chk(N + 1, false);
    for (int i = 0; i < N; i++) {
        static int start = -1, max_idx_used = 0;
        int num;
        cin >> num;
        auto push = [&]() -> void {
            start = max_idx_used + 1;
            for (int i = start; i <= num; i++) {
                st.push(i);
                chk[i] = true;
                max_idx_used = max(i, max_idx_used);
                ans += "+\n";
            }
            st.pop();
            ans += "-\n";
            chk[num] = true;
        };
        if (st.empty()) {
            push();
        }
        else {
            if (st.top() > num) {
                cout << "NO\n";
                return 0;
            }
            else {
                if (st.top() < num) {
                    push();
                }
                else if (st.top() == num) {
                    chk[st.top()] = true;
                    st.pop();
                    ans += "-\n";
                }
            }
        }
    }
    cout << ans;
    return 0;
}
