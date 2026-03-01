#!/usr/bin/env python3
# Interval DP with Knuth optimization for speed (O(n^2))
import sys

def solve_case(a):
    n = len(a)
    pref = [0]*(n+1)
    for i,x in enumerate(a,1):
        pref[i]=pref[i-1]+x
    def sum_lr(l,r):
        return pref[r]-pref[l-1]

    INF = 10**18
    dp = [[0]*(n+1) for _ in range(n+1)]
    opt = [[0]*(n+1) for _ in range(n+1)]

    for i in range(1,n+1):
        opt[i][i]=i

    for length in range(2, n+1):
        for l in range(1, n-length+2):
            r = l+length-1
            dp[l][r]=INF
            # Knuth: opt[l][r-1] <= opt[l][r] <= opt[l+1][r]
            start = opt[l][r-1] if r-1>=l else l
            end = opt[l+1][r] if l+1<=r else r
            if start < l: start = l
            if end > r-1: end = r-1
            bestk = start
            s = sum_lr(l,r)
            for k in range(start, end+1):
                v = dp[l][k] + dp[k+1][r] + s
                if v < dp[l][r]:
                    dp[l][r]=v
                    bestk=k
            opt[l][r]=bestk
    return dp[1][n]

def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(map(int, data))
    T = next(it)
    out=[]
    for _ in range(T):
        n = next(it)
        arr = [next(it) for __ in range(n)]
        out.append(str(solve_case(arr)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
