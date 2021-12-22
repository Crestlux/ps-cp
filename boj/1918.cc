#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	string exp; stack<char> s1;
	cin >> exp;
	for (auto it = exp.begin(); it < exp.end(); it++) {
		if (*it >= 'A' && *it <= 'Z') {
			cout << *it;
		}
		else {
			if (*it == '(') {
				s1.push(*it);
				continue;
			}
			else if (*it == ')') {
				while (!s1.empty() && s1.top() != '(') {
					cout << s1.top();
					s1.pop();
				}
				s1.pop();
				continue;
			}
			else if (*it == '+' || *it == '-') {
				while (!s1.empty() && s1.top() != '(') {
					cout << s1.top();
					s1.pop();
				}
				s1.push(*it);
				continue;
			}
			else if (*it == '*' || *it == '/')
			{
				while (!s1.empty() && (s1.top() == '*' || s1.top() == '/')) {
					cout << s1.top();
					s1.pop();
				}
				s1.push(*it);
				continue;
			}
		}
	}
	while (!s1.empty()) {
		cout << s1.top();
		s1.pop();
	}
	return 0;
}
