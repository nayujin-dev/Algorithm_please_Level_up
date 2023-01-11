#include<iostream>
#define MAX (26)
using namespace std;
typedef struct st {
	char left;
	char right;
}node;

node tree[MAX];

//char arr[27];
void preOrder(char root) {
	if (root == '.') return;
	printf("%c", root);
	preOrder(tree[root - 'A'].left);
	preOrder(tree[root - 'A'].right);
}
void inOrder(char root) {
	if (root == '.') return;
	inOrder(tree[root - 'A'].left);
	printf("%c", root);
	inOrder(tree[root - 'A'].right);

}
void postOrder(char root) {
	if (root == '.') return;
	postOrder(tree[root - 'A'].left);
	postOrder(tree[root - 'A'].right);
	printf("%c", root);
}
int main() {
	int N;
	char node,left,right;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %c  %c  %c", &node, &left, &right);
		tree[node - 'A'].left = left;
		tree[node - 'A'].right = right;
		//printf("%c", arr[i]);
	}
	preOrder('A');
	printf("\n");
	inOrder('A');
	printf("\n");
	postOrder('A');
	//for (int i = 0; i < N; i++) {
	//	printf("%c", tree[i].right);
	//}

	return 0;
}