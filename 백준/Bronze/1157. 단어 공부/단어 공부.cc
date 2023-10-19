#include <iostream>
#include <string>
#include <vector>

std::string s;
int alpha[26];
int max = 0;
std::vector<int> biggest;

int main() {
	std::cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char now = s[i];
;		if (now >= 'A' && now <= 'Z') {
			alpha[now - 'A']++;
		}
		else {
			alpha[now - 'a']++;	
		}
	}

	biggest.push_back(0);

	for (int i = 0; i < 26; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
			biggest.clear();
			biggest.push_back(i);
		}
		else if (max == alpha[i]) {
			biggest.push_back(i);
		}
	}
	if (biggest.size() > 1) {
		std::cout << '?';
	}
	else {
		std::cout << (char)(biggest[0] + 'A');
	}
	return 0;
}