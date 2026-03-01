#!/usr/bin/env python3
import sys

def solve_case(arr):
    # dp0: max sum up to i where i not taken
    # dp1: i taken, streak=1
    # dp2: i taken, streak=2
    dp0 = 0
    dp1 = -10**30
    dp2 = -10**30
    for a in arr:
        ndp0 = max(dp0, dp1, dp2)
        ndp1 = dp0 + a
        ndp2 = dp1 + a
        dp0, dp1, dp2 = ndp0, ndp1, ndp2
    return max(dp0, dp1, dp2)

def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(map(int, data))
    T = next(it)
    out = []
    for _ in range(T):
        n = next(it)
        arr = [next(it) for _ in range(n)]
        out.append(str(solve_case(arr)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
