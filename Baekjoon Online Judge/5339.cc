#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1[] = { "     /~\\", "    ( oo|", "    _\\=/_", "   /  _  \\",   "  //|/.\\|\\\\", " ||  \\ /  ||", "============", "|          |", "|          |", "|          |" };
	for (const auto&ele : s1) {
		cout << ele<<"\n";
	}
	return 0;
}
