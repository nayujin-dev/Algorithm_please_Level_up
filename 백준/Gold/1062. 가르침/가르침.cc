#include <iostream>
#include <vector>
#include <string>
int N, K;
std::string thisWord;
std::vector<std::string> word;
bool alpha[26 + 2];
int max = 0;
char need[6] = { 'a', 'c', 'i', 'n', 't' };
int numoflearn() {
	int tot = 0;
	for (int i = 0; i < N; i++) {
		bool isLearn = true;
		for (int j = 0; j < word[i].size(); j++) {
			if (alpha[word[i][j] - 'a'] == false) {
				isLearn = false;
				break;
			}
		}
		if (isLearn==true) tot++;
	}
	return tot;
}
void dfs(int learn,int thisPt) {
	if (learn == 0) {
		int thisnum = numoflearn();
		if (max < thisnum) {
			max = thisnum;
		}
		return;
	}
	if (thisPt >= 26) return;
	if (alpha[thisPt]==false) {
		alpha[thisPt] = true;
		dfs(learn - 1, thisPt + 1);
		alpha[thisPt] = false;
	}
	dfs(learn, thisPt + 1);
	
}
int main() {
	// N, K 주어짐
	std::cin >> N >> K;

	// N개의 단어 주어짐 (루프)
	for (int i = 0; i < N; i++) {
		std::cin >> thisWord;
		word.push_back(thisWord);
	}
	if (K < 5) {
		std::cout << 0;
		return 0; // 의미 없는 경우
	}
		
	
	for (int i = 0; i < 5; i++) {
		alpha[need[i] - 'a'] = true;
	}

	// K>=5라 의미 있는 경우
	dfs(K - 5, 0);
	std::cout << max;

	return 0;
}
