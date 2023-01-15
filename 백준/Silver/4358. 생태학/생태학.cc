#include<cstdio>
#include<iostream>
#include <map>
#include<string>
std::string name;
std::map<std::string, int> tree;
int main() {
	float tot = 0;
	float val;
	while (getline(std::cin,name)) {
		tree[name]++;
		tot++;

	}
	for (auto each = tree.begin(); each != tree.end(); each++) {
		val = each->second * 100 / tot;
		printf("%s %.4f\n", each->first.c_str(), val);
	}
	return 0;
}