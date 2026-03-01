#!/usr/bin/env python3
import sys

NEG = -10**18

def solve_grid(R, C, grid):
    # 1D rolling DP for memory
    dp = [NEG]*(C+1)
    dp[0] = NEG
    for i in range(R):
        new = [NEG]*(C+1)
        for j in range(C):
            val = grid[i][j]
            if val == -1:
                new[j+1] = NEG
                continue
            if i == 0 and j == 0:
                new[j+1] = val
                continue
            best = max(new[j], dp[j+1])  # left (new[j]) or up (dp[j+1])
            if best == NEG:
                new[j+1] = NEG
            else:
                new[j+1] = best + val
        dp = new
    return dp[C]

def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(map(int, data))
    T = next(it)
    out = []
    for _ in range(T):
        R = next(it); C = next(it)
        grid = [[next(it) for _ in range(C)] for __ in range(R)]
        out.append(str(solve_grid(R, C, grid)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
