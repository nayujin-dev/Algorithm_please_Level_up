#include <iostream>
#include <string>

bool done[26];

int main() {
	int N;
	std::string s;
	std::cin >> N;
	int tot = N;
	for (int i = 0; i < N; i++) {
		std::cin >> s;
		bool isgroup = true;
		for (int j = 0; j < 26; j++) {
			done[j] = false;
		}
		for (int j = 0; j < s.size() - 1; j++) {
			char thischar = s[j];
			
			if (done[thischar - 'a']) {
				isgroup = false;
				break;
			}
			if (thischar != s[j + 1]) {
				done[thischar - 'a'] = true;
			}
		}
		if (done[s.back()-'a'] || !isgroup) {
			tot--;
		}
	}

	std::cout << tot;
	return 0;
}