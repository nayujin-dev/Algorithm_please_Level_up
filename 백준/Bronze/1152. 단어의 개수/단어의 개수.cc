#include <iostream>
#include <string>

std::string s;
int tot = 0;

int main() {
	getline(std::cin, s);

	for (int i = 0; i < s.size()-1; i++) {
		int idx = i + 1;
		if (s[i] != ' ' && s[idx]==' ') {
			tot++;
		}
	}
	if (s.back() == ' ')
		std::cout << tot;
	else
		std::cout << tot + 1;
	return 0;
}