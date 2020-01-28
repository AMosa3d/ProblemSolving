# Problem Link : https://codeforces.com/contest/1280/problem/A

if __name__ == "__main__":
 
    t = int(input())
    mod = 10**9 + 7
 
    for i in range(t):
        x = int(input())
        s = input()
        j = 0
        while len(s) < x:
            s += s[j + 1:] * (int(s[j])-1)
            j+=1
        length = len(s)
        for jj in range(j, x):
            length = (length + (length-jj-1) * (int(s[jj])-1)) % mod
 
        print(length % mod)
