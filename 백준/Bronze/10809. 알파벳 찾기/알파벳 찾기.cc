#include <iostream>
#include <string>

std::string S;
int index[26];

int main() {
	std::cin >> S;

	for (int i = 'a'; i <= 'z'; i++) {
		std::cout << (int)S.find(i) << " ";
	}

	return 0;
}