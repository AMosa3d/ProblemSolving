# Problem Link : https://codeforces.com/problemset/problem/1292/A

if __name__ == '__main__':
    n, q = [int(x) for x in input().split()]
    maze = [(n+2) * [0] for _ in range(2)]
    blocks = 0
    res = []
    for _ in range(q):
        r, c = [int(x) for x in input().split()]
        r -= 1
        maze[r][c] ^= 1
        offset = -1 + 2 * maze[r][c]
        nr = 1 ^ r
        choices = [maze[nr][c] == 1, maze[nr][c+1] == 1, maze[nr][c-1] == 1]
        blocks += sum([offset for x in choices if x])
 
        res.append("Yes") if blocks == 0 else res.append("No")
 
    print("\n".join(map(str, res)))
