#include <iostream>
#include <string>
using namespace std;
int main() {
	string arr[5];
	arr[0] = "       _.-;;-._";
	arr[1] = "'-..-'|   ||   |";
	arr[2] = "'-..-'|_.-;;-._|";
	arr[3] = "'-..-'|   ||   |";
	arr[4] = "'-..-'|_.-''-._|";
	for (const auto& ele : arr) {
		cout << ele << "\n";
	}
	return 0;
}
