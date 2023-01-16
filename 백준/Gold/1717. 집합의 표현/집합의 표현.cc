#include<iostream>
int n, m,cal,a,b,arr[1000002],aroot,broot;
int find(int a) {
	if (arr[a] == a) return a;
	else return arr[a] = find(arr[a]);
}
void unionF(int a, int b) {
	aroot = find(a);
	broot = find(b);
	arr[aroot] = broot;
	return;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &cal, & a, &b);
		if (cal == 0) {
			unionF(a, b);
		}
		else if (cal == 1) {
			if (find(a) == find(b))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}