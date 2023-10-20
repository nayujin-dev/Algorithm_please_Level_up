#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<long long> arr;

int main() {
	cin >> N;
	cin.tie(nullptr);
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> n;
		cout << binary_search(arr.begin(), arr.end(), n) << ' ';
	}
	
	return 0;
}