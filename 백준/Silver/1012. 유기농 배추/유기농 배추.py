import sys
sys.setrecursionlimit(10000)


def dfs(m, n):
    if (n > N - 1) or (m > M - 1) or (m < 0) or (n < 0):
        return
    if visited[m][n] == 0 and cabbage[m][n] == 1:
        visited[m][n] = 1
        dfs(m + 1, n)
        dfs(m, n + 1)
        dfs(m-1, n)
        dfs(m, n-1)
    visited[m][n] = 1


T = int(input())
for i in range(T):
    M, N, K = map(int, input().split())

    cabbage = [[0 for j in range(N)] for k in range(M)]
    visited = [[0 for j in range(N)] for k in range(M)]

    for k in range(K):
        x, y = map(int, input().split())
        cabbage[x][y] = 1

    cnt = 0
    for y in range(N):
        for x in range(M):
            if visited[x][y] == 0 and cabbage[x][y] == 1:
                dfs(x, y)
                cnt += 1

    print(cnt)
