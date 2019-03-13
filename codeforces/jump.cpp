#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 1;
int n, c[N], Next[N], last[N];
queue<int> qu;
bool vis[N];
 
int BFS() {
    if (n == 1)
        return 0;
	while (!qu.empty())
		qu.pop();
	qu.push(0);
	int cost = 1;
	while (!qu.empty()) {
		for (int size = qu.size(); size >= 1; --size) {
			int cur = qu.front();
			qu.pop();
			if (!vis[cur + 1]) {
				if (cur + 1 == n - 1)
					return cost;
				vis[cur + 1] = true;
				qu.push(cur + 1);
			}
			if (Next[cur] != -1 && !vis[Next[cur]]) {
				if (Next[cur] == n - 1)
					return cost;
				vis[Next[cur]] = true;
				qu.push(Next[cur]);
			}
		}
		++cost;
	}
	assert(false);
	return -1;
}
 
int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &c[i]);
		memset(last, -1, sizeof last);
		for (int i = 0; i < n; ++i)
			vis[i] = false;
		for (int i = n - 1; i >= 0; --i) {
			Next[i] = last[c[i]];
			last[c[i]] = i;
		}
		printf("%d\n", BFS());
	}
	return 0;
}
