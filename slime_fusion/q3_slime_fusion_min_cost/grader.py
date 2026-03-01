#!/usr/bin/env python3
"""
Q3 grader (FORCE single-case execution), BUT auto-detect whether input starts with T.

- If the .in can be parsed as:
    T, then (n + n ints) repeated T times
  -> run contestant T times, each time with:
    n \n arr...

- Otherwise (no T / different format)
  -> treat whole file as ONE single case, run contestant ONCE

Output expected in .ans: integers (1 per case)
"""

import sys, subprocess, pathlib, time, shlex

TIME_LIMIT_SEC = 2.0  # per run

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

def try_split_as_T_format(ints):
    # returns list of cases [(n, arr)] if valid, else None
    if not ints:
        return None
    T = ints[0]
    if T < 1:
        return None
    idx = 1
    cases = []
    for _ in range(T):
        if idx >= len(ints):
            return None
        n = ints[idx]; idx += 1
        if n < 1:
            return None
        if idx + n > len(ints):
            return None
        arr = ints[idx:idx+n]; idx += n
        cases.append((n, arr))
    # valid ONLY if consumed exactly
    if idx != len(ints):
        return None
    return cases

def build_single_case_q3(case):
    n, arr = case
    return f"{n}\n" + " ".join(map(str, arr)) + "\n"

def main():
    if len(sys.argv) < 2:
        print('Usage: python grader.py "./a.out"')
        sys.exit(2)

    cmd = " ".join(sys.argv[1:])
    tests_dir = pathlib.Path(__file__).resolve().parent / "tests"
    ins = sorted(tests_dir.glob("*.in"))
    if not ins:
        print("No tests found in", tests_dir)
        sys.exit(2)

    ok = 0
    for fin in ins:
        raw_inp = fin.read_text(encoding="utf-8")
        expected = parse_ints(fin.with_suffix(".ans").read_text(encoding="utf-8"))

        # Decide split strategy
        ints = None
        try:
            ints = list(map(int, raw_inp.split()))
        except:
            ints = None

        cases = None
        note = ""
        if ints is not None:
            cases = try_split_as_T_format(ints)

        if cases is None:
            # NO-T or unknown format -> treat whole file as ONE case
            cases = [("RAW", raw_inp)]
            note = "no-T/unknown format: run once with the whole file"
        else:
            note = f"detected T-format: split into {len(cases)} cases"

        collected = []
        total_dt = 0.0
        ok_all = True
        last_err = ""

        for c in cases:
            if c[0] == "RAW":
                single_inp = c[1]
            else:
                single_inp = build_single_case_q3(c)

            try:
                code, out, err, dt = run_cmd(cmd, single_inp, TIME_LIMIT_SEC)
            except subprocess.TimeoutExpired:
                ok_all = False
                last_err = f"TLE (>{TIME_LIMIT_SEC:.1f}s)"
                break

            total_dt += dt
            if code != 0:
                ok_all = False
                last_err = f"RE (exit={code})"
                if err.strip():
                    last_err += f": {err.strip().splitlines()[-1]}"
                break

            got = parse_ints(out)
            if len(got) != 1:
                ok_all = False
                last_err = f"Output format error: expected 1 integer, got {len(got)}"
                break
            collected.append(got[0])

        if ok_all and collected == expected:
            print(f"[OK ] {fin.name}  (single-run x{len(cases)}, {total_dt:.3f}s)")
            ok += 1
        else:
            print(f"[WA ] {fin.name}  (single-run x{len(cases)}, {total_dt:.3f}s)")
            print(" expected:", expected[:30], ("..." if len(expected) > 30 else ""))
            print(" got     :", collected[:30], ("..." if len(collected) > 30 else ""))
            print(" note    :", note)
            if last_err:
                print(" error   :", last_err)
            print()

    print(f"\nPassed {ok}/{len(ins)} tests")

if __name__ == "__main__":
    main()