#include <iostream>
#include <string>
using namespace std;
int cnt;
string s;

int main() {
	std::cin >> s;
	cnt = s.size();
	for (int i = 1; i < s.size(); i++) {
		if (s[i]=='=') {
			if (i >= 2 && s[i - 1] == 'z' && s[i - 2] == 'd')
				cnt -= 2;
			else if (s[i-1] == 'c' || s[i-1] == 's' || s[i - 1] == 'z') 
				cnt--;
			
		}
		else if (s[i] == '-') {
			if (s[i - 1] == 'c' || s[i - 1] == 'd') 
				cnt--;
		}
		else if (s[i] == 'j') {
			if (s[i - 1] == 'l' || s[i - 1] == 'n') 
				cnt--;
		}
	}
	cout << cnt;
	return 0;
}