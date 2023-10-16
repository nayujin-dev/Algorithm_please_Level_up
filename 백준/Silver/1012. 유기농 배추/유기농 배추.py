import sys
sys.setrecursionlimit(10000)


def dfs(m, n):
    cabbage[m][n] = 0
    for j in range(4):
        nx = m+dx[j]
        ny = n+dy[j]
        if(nx >= 0) and (ny >= 0) and (nx < M) and (ny < N):
            if cabbage[nx][ny] == 1:
                dfs(nx, ny)


dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]


T = int(input())
for i in range(T):
    M, N, K = map(int, input().split())

    cabbage = [[0 for j in range(N)] for k in range(M)]

    for k in range(K):
        x, y = map(int, input().split())
        cabbage[x][y] = 1

    cnt = 0
    for x in range(M):
        for y in range(N):
            if cabbage[x][y] == 1:
                dfs(x, y)
                cnt += 1
    print(cnt)