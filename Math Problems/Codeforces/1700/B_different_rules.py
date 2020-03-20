# Problem Link : https://codeforces.com/problemset/problem/1313/B

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, x, y = [int(x) for x in input().split()]
        print(str(max(1, min(n,x+y-n+1))) + " " + str(min(n, x+y-1)))
