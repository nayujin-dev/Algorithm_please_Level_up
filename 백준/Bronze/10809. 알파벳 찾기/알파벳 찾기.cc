#include <iostream>
#include <string>

std::string S;
int index[26];

int main() {
	std::cin >> S;

	for (int i = 0; i < 26; i++) {
		index[i] = -1;
	}
	for (int i = 0; i < S.size(); i++) {
		int idx = S[i] - 'a';
		if (index[idx]<0) 
			index[idx] = i;
	}

	for (int i = 0; i <26; i++) {
		std::cout << index[i] << ' ';
	}

	return 0;
}