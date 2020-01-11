# Problem Link : https://codeforces.com/problemset/problem/1272/D

class X:
 
    def __init__(self, d):
        self.start = d
        self.end = d
        self.before_end = d
        self.after_start = d
        self.size = 1
 
    def add(self, d):
        self.before_end = self.end
        if self.after_start == self.start:
            self.after_start = d
        self.end = d
        self.size += 1
 
 
def compare(a, b):
    res = [a.size, b.size]
    if a.before_end < b.start or a.end < b.after_start:
        res.append(a.size + b.size - 1)
 
    return max(res)
 
 
if __name__ == "__main__":
    n = int(input())
    arr = [int(x) for x in input().split()]
    l = [X(arr[0])]
    l_index = 0
 
    # build contacted list
    for i in range(1,n):
        if arr[i] > l[l_index].end:
            l[l_index].add(arr[i])
        else:
            l_index += 1
            l.append(X(arr[i]))
 
    res = l[0].size
    for i in range(len(l) - 1):
        res = max(res, compare(l[i], l[i+1]))
 
    print(res)
