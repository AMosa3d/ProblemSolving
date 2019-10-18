# Problem Link : https://codeforces.com/contest/219/problem/C

if __name__ == '__main__':
    n, k = [int(x) for x in input().split()]
    s = input()
 
    if(k == 2):
        str1 = "AB"*n  # good trick by another person's solution
        str2 = "BA"*n  # good trick by another person's solution
        diff1 = 0
        diff2 = 0
        for i in range(n):
            #str1 += chr(ord('A') + i%2)
            #str2 += chr(ord('B') - i%2)
            if(s[i] != str1[i]):
                diff1 += 1
            else:
                diff2 += 1
        if(diff1 < diff2):
            print(diff1)
            print(str1[:n])  # good trick by another person's solution
        else:
            print(diff2)
            print(str2[:n])  # good trick by another person's solution
    else:
        l = [chr(i + ord('A')) for i in range(k)]
        s += "_"
        s = "_" + s
        s = list(s)
        resVal = 0
        for i in range(1,n+1):
            if(s[i] != s[i-1]):
                continue
            resVal += 1
            possible_changes = [x for x in l if x != s[i-1] and x != s[i+1]]
            s[i] = possible_changes[0]
 
        del s[0]
        del s[-1]
        s = ''.join(s)
        print(resVal)
        print(s)
