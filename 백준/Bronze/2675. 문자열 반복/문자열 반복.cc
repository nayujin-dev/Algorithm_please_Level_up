#include <iostream>
#include <string>

int T, R;

int main() {
	std::cin >> T;
	while (T-- > 0) {
		std::string S;
		std::string newS="";
		std::cin >> R>> S;
		int size = S.size();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < R; j++) {
				newS += S[i];
			}
		}
		std::cout << newS<<std::endl;
	}
	return 0;
}