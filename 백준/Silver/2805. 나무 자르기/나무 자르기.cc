#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int tree[1000000 + 3];

void input();
int binarySearch(int start, int end);

bool compare(const int& a, const int& b) {
	if (a < b) return true;
	else return false;
}

int main() {
	// 1. 입력받는다
	input();

	// 2. 나무 높이를 정렬한다
	sort(tree, tree + N, compare);

	// 3. 적절한 절단 높이를 이진탐색 하고 출력한다
	printf("%d", binarySearch(0, tree[N - 1]));

	return 0;
}

void input() {
	scanf("%d %d", &N, &M);
	// cin >> N>> M;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);
	}
}

int binarySearch(int start, int end) {
	int mid;
	long long ret;

	int ans = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		ret = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				ret += tree[i] - mid;
			}
		}

		// 정확히 일치할 경우 바로 답 출력
		if (ret == M) {
			return mid;
		}

		// 남는 경우 / 절단기 최대 높이 갱신
		else if (ret > M) {
			if (ans < mid) {
				ans = mid;
			}
			start = mid + 1;
		}

		else {
			end = mid - 1;
		}
	}
	return ans;
}