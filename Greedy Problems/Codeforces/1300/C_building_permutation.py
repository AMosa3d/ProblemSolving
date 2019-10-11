# Problem Link : https://codeforces.com/problemset/problem/285/C

if __name__ == "__main__":
    n = int(input())
    l = [int(x) for x in input().split()]
    l.sort()
    res = 0
    cur = 1
    for x in l:
        res += abs(cur - x)
        cur += 1
    print(res)
