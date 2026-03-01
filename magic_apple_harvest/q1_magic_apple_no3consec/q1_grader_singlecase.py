#!/usr/bin/env python3
"""
Q1 grader (FORCE single-case mode)

ใช้เมื่อ "โค้ดของคุณแก้ได้แค่ 1 เคส" (อ่าน n + array) และยังไม่รองรับ T

Grader นี้จะ:
- อ่านไฟล์ *.in ที่มี T เคส
- แยกเป็นเคสย่อย แล้วรันโปรแกรมคุณ "ทีละเคส" เสมอ
- รวมผลลัพธ์ T บรรทัด แล้วเทียบกับ *.ans

Usage:
  python q1_grader_force_singlecase.py "./main"
  python q1_grader_force_singlecase.py "python main.py"
"""

import sys, subprocess, pathlib, time, shlex

TIME_LIMIT_SEC = 1.0

def parse_ints(s: str):
    s = s.strip()
    if not s:
        return []
    return list(map(int, s.split()))

def split_cases_q1(raw: str):
    a = list(map(int, raw.split()))
    if not a:
        return []
    T = a[0]
    idx = 1
    cases = []
    for _ in range(T):
        if idx >= len(a):
            break
        n = a[idx]; idx += 1
        arr = a[idx:idx+n]; idx += n
        cases.append((n, arr))
    return cases

def build_single_case_q1(case):
    n, arr = case
    return f"{n}\n" + " ".join(map(str, arr)) + "\n"

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

def main():
    if len(sys.argv) < 2:
        print("Usage: python q1_grader_force_singlecase.py <command>")
        sys.exit(2)

    cmd = " ".join(sys.argv[1:])
    here = pathlib.Path(__file__).resolve().parent
    tests_dir = here / "tests"  # วางไฟล์นี้ระดับเดียวกับ tests/
    ins = sorted(tests_dir.glob("*.in"))
    if not ins:
        print("No tests found in", tests_dir)
        print("Tip: move this file into your q1 folder (same level as tests/)")
        sys.exit(2)

    ok = 0
    for fin in ins:
        inp = fin.read_text(encoding="utf-8")
        expected = parse_ints(fin.with_suffix(".ans").read_text(encoding="utf-8"))
        cases = split_cases_q1(inp)
        T = len(cases)

        collected = []
        total_dt = 0.0
        ok_all = True
        last_err = ""

        for c in cases:
            single_inp = build_single_case_q1(c)
            try:
                code2, out2, err2, dt2 = run_cmd(cmd, single_inp, TIME_LIMIT_SEC)
            except subprocess.TimeoutExpired:
                ok_all = False
                last_err = f"TLE (>{TIME_LIMIT_SEC:.1f}s) on a single case"
                break
            total_dt += dt2
            if code2 != 0:
                ok_all = False
                last_err = f"RE (exit={code2})"
                if err2.strip():
                    last_err += f": {err2.strip().splitlines()[-1]}"
                break
            ints2 = parse_ints(out2)
            if len(ints2) != 1:
                ok_all = False
                last_err = f"Output format error: expected 1 integer per case, got {len(ints2)}"
                break
            collected.append(ints2[0])

        if ok_all and collected == expected:
            print(f"[OK ] {fin.name} (single-case x{T}, {total_dt:.3f}s)")
            ok += 1
        else:
            print(f"[WA ] {fin.name} (single-case x{T}, {total_dt:.3f}s)")
            print(" expected:", expected[:20], "..." if len(expected) > 20 else "")
            print(" got     :", (collected[:20] if collected else []), "..." if (collected and len(collected) > 20) else "")
            if last_err:
                print(" note    :", last_err)

    print(f"\nPassed {ok}/{len(ins)} tests")

if __name__ == "__main__":
    main()
