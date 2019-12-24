# Problem Link : https://codeforces.com/problemset/problem/1169/B

if __name__ == '__main__':
    n, m = [int(x) for x in input().split()]
    firstPair = [int(x) for x in input().split()]
    arrNotX, arrNotY = [0] * (n+1), [0] * (n+1)
    countX, countY = 1, 1
    for i in range(1,m):
        x,y = [int(x) for x in input().split()]
        if(x != firstPair[0] and y != firstPair[0]):
            arrNotX[x] += 1
            arrNotX[y] += 1
        else:
            countX += 1
        if (x != firstPair[1] and y != firstPair[1]):
            arrNotY[x] += 1
            arrNotY[y] += 1
        else:
            countY += 1

    print("yes" if max(arrNotX) + countX == m or max(arrNotY) + countY == m else "no")
