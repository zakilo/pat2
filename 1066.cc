// Thank great Ted
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x6fffffff;
#define MAX 25

struct point {
	int value;
	int left, right;
	int height;
}node[MAX];

int idx;

int getHeight(int root)
{
	if(root==-1) return -1;
	else return node[root].height;
}

int rotateLL(int root)
{
	int child = node[root].left;
	node[root].left = node[child].right;
	node[child].right = root;
	node[root].height = max( getHeight(node[root].left), getHeight(node[root].right) )+1;
	node[child].height = max( getHeight(node[child].left), getHeight(node[child].right) )+1;
	return child;
}
int rotateRR(int root)
{
	int child = node[root].right;
	node[root].right = node[child].left;
	node[child].left = root;
	node[root].height = max( getHeight(node[root].left), getHeight(node[root].right) )+1;
	node[child].height = max( getHeight(node[child].left), getHeight(node[child].right) )+1;
	return child;
}
int rotateLR(int root)
{
	int child = node[root].left;
	node[root].left = rotateRR(child);
	return rotateLL(root);
}
int rotateRL(int root)
{
	int child = node[root].right;
	node[root].right = rotateLL(child);
	return rotateRR(root);
}

bool isBalance(int root)
{
	return abs( getHeight(node[root].left) - getHeight(node[root].right) ) < 2;
}

int insertNode(int root, int x)
{
	if(root == -1) {	// first node
		node[idx].value = x;
		node[idx].left = node[idx].right = -1;
		node[idx].height = 0;
		root = idx;
		++idx;
	} else {
		if(x > node[root].value) {	// right
			node[root].right = insertNode(node[root].right, x);
			if(!isBalance(root)) {
				if(x > node[ node[root].right ].value)	// right of right
					root =rotateRR(root);
				else						// left of right
					root = rotateRL(root);
			}
		} else {
			node[root].left = insertNode(node[root].left, x);
			if(!isBalance(root)) {
				if(x > node[ node[root].left ].value)	// right of left
					root = rotateLR(root);
				else					// left of left
					root = rotateLL(root);
			}
		}
	}
	node[root].height = max( getHeight(node[root].left), getHeight(node[root].right) ) + 1;

	return root;
}

int main(void)
{
#ifdef DEBUG
	freopen("1066.txt", "r", stdin);
#endif
	int n, x, root;
	scanf("%d", &n);
	idx = 0;
	root = -1;
	for(int i=0; i < n; ++i) {
		scanf("%d", &x);
		root = insertNode(root, x);
	}
	printf("%d\n", node[root].value);

	return 0;
}
