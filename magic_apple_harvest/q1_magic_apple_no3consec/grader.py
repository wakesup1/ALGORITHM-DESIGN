#!/usr/bin/env python3
"""
Local grader (no special judge): compares integer outputs (whitespace-insensitive).

Usage examples:
  python grader.py "./a.out"
  python grader.py "python main.py"
  python grader.py "python3 solution.py"

It will run all tests in ./tests and report OK/WA/TLE/RE.
"""
import os, sys, subprocess, pathlib, time, shlex

TIME_LIMIT_SEC = 1.0  # adjust if needed

def parse_ints(s: str):
    s = s.strip()
    if not s:
        return []
    return list(map(int, s.split()))

def run_cmd(cmd: str, inp: str, timeout: float):
    # cmd is a shell-like string; we run it without shell for safety
    argv = shlex.split(cmd)
    t0 = time.time()
    p = subprocess.run(
        argv,
        input=inp.encode("utf-8"),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=timeout,
    )
    dt = time.time()-t0
    return p.returncode, p.stdout.decode("utf-8", errors="replace"), p.stderr.decode("utf-8", errors="replace"), dt

def main():
    if len(sys.argv) < 2:
        print("Usage: python grader.py <command-to-run-contestant>")
        print('Example: python grader.py "python main.py"')
        sys.exit(2)

    cmd = " ".join(sys.argv[1:])
    tests_dir = pathlib.Path(__file__).resolve().parent / "tests"
    ins = sorted(tests_dir.glob("*.in"))
    if not ins:
        print("No tests found in", tests_dir)
        sys.exit(2)

    ok = 0
    for fin in ins:
        fans = fin.with_suffix(".ans")
        inp = fin.read_text(encoding="utf-8")
        exp = fans.read_text(encoding="utf-8") if fans.exists() else ""

        try:
            code, out, err, dt = run_cmd(cmd, inp, TIME_LIMIT_SEC)
        except subprocess.TimeoutExpired:
            print(f"[TLE] {fin.name}  (>{TIME_LIMIT_SEC:.1f}s)")
            continue

        if code != 0:
            print(f"[RE ] {fin.name}  (exit={code}, {dt:.3f}s)")
            if err.strip():
                print(" stderr:", err.strip().splitlines()[-1])
            continue

        got = parse_ints(out)
        expected = parse_ints(exp)

        if got == expected:
            print(f"[OK ] {fin.name}  ({dt:.3f}s)")
            ok += 1
        else:
            print(f"[WA ] {fin.name}  ({dt:.3f}s)")
            print(" expected:", expected[:30], ("..." if len(expected) > 30 else ""))
            print(" got     :", got[:30], ("..." if len(got) > 30 else ""))
            if err.strip():
                print(" stderr:", err.strip().splitlines()[-1])
            print()

    print(f"\nPassed {ok}/{len(ins)} tests")

if __name__ == "__main__":
    main()
