#!/usr/bin/env python3
"""
Local grader (FORCE single-case mode) for Q2 (Grid Max Sum)

Input file format (per .in):
T
R C
grid (R lines, each C ints)
(repeat T times)

Grader:
- splits each .in into T single cases
- runs contestant once per case (expects exactly 1 integer per run)
- compares collected outputs with .ans

Usage:
  python grader.py "./a.out"
  python grader.py "python main.py"
"""

import sys, subprocess, pathlib, time, shlex

TIME_LIMIT_SEC = 2.0  # per single-case run

def parse_ints(s: str):
    s = s.strip()
    if not s:
        return []
    return list(map(int, s.split()))

def run_cmd(cmd: str, inp: str, timeout: float):
    argv = shlex.split(cmd)
    t0 = time.time()
    p = subprocess.run(
        argv,
        input=inp.encode("utf-8"),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=timeout,
    )
    dt = time.time() - t0
    return p.returncode, p.stdout.decode("utf-8", errors="replace"), p.stderr.decode("utf-8", errors="replace"), dt

# Q2 format: T, then for each case: R C, then R*C integers (usually arranged in R lines)
def split_cases_q2(raw: str):
    a = raw.split()
    if not a:
        return []
    ints = list(map(int, a))
    T = ints[0]
    idx = 1
    cases = []
    for _ in range(T):
        if idx + 1 >= len(ints):
            break
        R = ints[idx]; C = ints[idx+1]; idx += 2
        need = R * C
        grid = ints[idx:idx+need]; idx += need
        cases.append((R, C, grid))
    return cases

def build_single_case_q2(case):
    R, C, grid = case
    lines = [f"{R} {C}"]
    for i in range(R):
        row = grid[i*C:(i+1)*C]
        lines.append(" ".join(map(str, row)))
    return "\n".join(lines) + "\n"

def main():
    if len(sys.argv) < 2:
        print('Usage: python grader.py "python main.py"')
        sys.exit(2)

    cmd = " ".join(sys.argv[1:])
    tests_dir = pathlib.Path(__file__).resolve().parent / "tests"
    ins = sorted(tests_dir.glob("*.in"))
    if not ins:
        print("No tests found in", tests_dir)
        sys.exit(2)

    ok = 0
    for fin in ins:
        inp = fin.read_text(encoding="utf-8")
        expected = parse_ints(fin.with_suffix(".ans").read_text(encoding="utf-8"))

        cases = split_cases_q2(inp)
        T = len(cases)

        collected = []
        total_dt = 0.0
        ok_all = True
        note = ""

        for c in cases:
            single_inp = build_single_case_q2(c)
            try:
                code, out, err, dt = run_cmd(cmd, single_inp, TIME_LIMIT_SEC)
            except subprocess.TimeoutExpired:
                ok_all = False
                note = f"TLE (>{TIME_LIMIT_SEC:.1f}s) on a single case"
                break

            total_dt += dt
            if code != 0:
                ok_all = False
                note = f"RE (exit={code})"
                if err.strip():
                    note += f": {err.strip().splitlines()[-1]}"
                break

            ints_out = parse_ints(out)
            if len(ints_out) != 1:
                ok_all = False
                note = f"Output format error: expected 1 integer per case, got {len(ints_out)}"
                break

            collected.append(ints_out[0])

        if ok_all and collected == expected:
            print(f"[OK ] {fin.name}  (single-case x{T}, {total_dt:.3f}s)")
            ok += 1
        else:
            print(f"[WA ] {fin.name}  (single-case x{T}, {total_dt:.3f}s)")
            print(" expected:", expected[:30], ("..." if len(expected) > 30 else ""))
            print(" got     :", (collected[:30] if collected else []), ("..." if collected and len(collected) > 30 else ""))
            if note:
                print(" note    :", note)
            print()

    print(f"\nPassed {ok}/{len(ins)} tests")

if __name__ == "__main__":
    main()