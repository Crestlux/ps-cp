#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int CCW(const pair<ld, ld>& x, const pair<ld, ld>& y, const pair<ld, ld>& z) {
	ld ret = x.first * y.second + y.first * z.second + z.first * x.second;
	ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}
void intersection(const pair<ld, ld>& A, const pair<ld, ld>& B, const pair<ld, ld>& C, const pair<ld, ld>& D) {
	cout << fixed; cout.precision(10);
	pair<ld, ld> ret;
	double parl = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);
	if (parl == 0) {
		if (B == C && A <= C) { 
			ret = B;
			cout << ret.first << " " << ret.second << "\n";
		}
		else if (A == D && A >= C) { 
			ret = A; 
			cout << ret.first << " " << ret.second << "\n";
		}
	}
	else {
		ret.first = ((A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first)) / ((A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first));
		ret.second = ((A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first)) / ((A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first));
		cout << ret.first << " " << ret.second << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	pair<ld, ld> A, B, C, D;  pair<ld, ld> IP;
	cin >> A.first >> A.second >> B.first >> B.second;
	cin >> C.first >> C.second >> D.first >> D.second;
	if (CCW(A, B, C) * CCW(A, B, D) <= 0) {
		if (CCW(A, B, C) * CCW(A, B, D) == 0 && CCW(C, D, A) * CCW(C, D, B) == 0) {
			if (A > B)swap(A, B);
			if (C > D)swap(C, D);
			if (A <= D && B >= C) {
				cout<<"1\n";
				intersection(A, B, C, D);
			}
			else cout << "0\n";
		}
		else if (CCW(A, B, C) * CCW(A, B, D) <= 0 && CCW(C, D, A) * CCW(C, D, B) <= 0) {
			cout << "1\n";
			intersection(A, B, C, D);
		}
		else cout << "0\n";
	}
	else cout << "0\n";
	return 0;
}
