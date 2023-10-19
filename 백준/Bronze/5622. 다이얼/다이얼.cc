#include <iostream>
#include <string>

std::string s;

int main() {
	std::cin >> s;
	int tot = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i]>='A' && s[i]<'D') {
			tot += 3;
		}
		else if (s[i] >= 'D' && s[i] < 'G') {
			tot += 4;
		}
		else if (s[i] >= 'G' && s[i] < 'J') {
			tot += 5;
		}
		else if (s[i] >= 'J' && s[i] < 'M') {
			tot += 6;
		}
		else if (s[i] >= 'M' && s[i] < 'P') {
			tot += 7;
		}
		else if (s[i] >= 'P' && s[i] < 'T') {
			tot += 8;
		}
		else if (s[i] >= 'T' && s[i] < 'W') {
			tot += 9;
		}
		else {
			tot += 10;
		}
	}

	std::cout << tot;
	return 0;
}