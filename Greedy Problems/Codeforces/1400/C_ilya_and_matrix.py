
'''
Problem Link : https://codeforces.com/problemset/problem/313/C
Note : I have got the main idea but its still gets me TLE so i have looked for other answers and then.
This solution is inspired from this answer : https://codeforces.com/contest/313/status/C
'''

if __name__ == '__main__':
    n = int(input())
    a = list(map(float, input().split()))
    a.sort(reverse=True)
    res = 0
    # a is sorted in desc
    while(a):
        res += sum(a)
        a = a[:len(a)//4]
 
    print(int(res))
