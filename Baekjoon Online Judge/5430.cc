#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string p, temparr, tempnum; int T, n, templen;
	deque<int> arr;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int cnt = 0;
		arr.clear();
		cin >> p >> n;
		cin >> temparr; templen = temparr.length();
		for (int i = 1; i < templen; i++) {
			tempnum = temparr[i];
			if (i + 1 < templen && (temparr[i + 1] == ',' || temparr[i + 1] == ']')) {
				arr.push_back(stoi(tempnum));
				++i; cnt++;
				continue;
			}
			else if (i + 2 < templen && (temparr[i + 2] == ',' || temparr[i + 2] == ']')) {
				tempnum += temparr[i + 1];
				arr.push_back(stoi(tempnum));
				i += 2; cnt++;
				continue;
			}
			else if (i + 3 < templen && (temparr[i + 3] == ',' || temparr[i + 3] == ']')) {
				tempnum += temparr[i + 1];
				tempnum += temparr[i + 2];
				arr.push_back(stoi(tempnum));
				i += 3; cnt++;
				continue;
			}
			if (temparr[i] == ']') {
				break;
			}
		}
		bool chkerr = false, chkrev = false;
		for (auto it = p.begin(); it < p.end(); it++) {
			if (*it == 'R') {
				if (chkrev == false) chkrev = true;
				else chkrev = false;
			}
			else if (*it == 'D') {
				if (!arr.empty()) {
					if (chkrev == false) arr.pop_front();
					else arr.pop_back();
				}
				else {
					cout << "error\n";
					chkerr = true;
					break;
				}
			}
		}
		if (!chkerr && chkrev == true) reverse(arr.begin(), arr.end());
		if (!chkerr && !arr.empty()) {
			cout << '[';
			while (arr.size() != 1) {
				cout << arr.front() << ',';
				arr.pop_front();
			}
			cout << arr.front() << "]\n";
			arr.pop_front();
			continue;
		}
		if (!chkerr && arr.empty()) {
			cout << "[]\n";
			continue;
		}
	}
	return 0;
}
