# Problem Link : https://codeforces.com/problemset/problem/1283/C

if __name__ == "__main__":
    n = int(input())
    a = [int(x) for x in input().split()]
    ll = []
 
    arr = [0] * (n+1)
    for x in a:
        arr[x] = 1
    for i in range(1,n+1):
        if arr[i] == 0:
            ll.append(i)
 
    last_edited_index = 0
    ll_index = 0
 
    for i in range(n):
        if a[i] == 0:
            if i+1 != ll[ll_index]:
                a[i] = ll[ll_index]
            else:
                if ll_index+1 < len(ll):
                    a[i] = ll[ll_index+1]
                    ll[ll_index+1] = ll[ll_index]
                else:
                    a[i] = a[last_edited_index]
                    a[last_edited_index] = ll[ll_index]
            ll_index += 1
            last_edited_index = i
 
    print(*a)
