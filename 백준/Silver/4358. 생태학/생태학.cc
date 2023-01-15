#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> dogam;

int main() {

	//freopen("input.txt", "r", stdin);

	string inputstr;
	float treeCnt = 0;
	while (getline(cin, inputstr)){
		treeCnt++;
		dogam[inputstr]++;
	}

	float val;
	for (auto it = dogam.begin(); it != dogam.end(); it++) {
		val = it->second * 100 / treeCnt;
		printf("%s %.4f\n", it->first.c_str(), val);
	}

	return 0;
}