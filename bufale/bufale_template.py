#!/usr/bin/env python3
from sys import stderr,stdout

from math import comb

BASE = 10**9 + 7

def bufale(voti1, voti2):
    assert len(voti1) == len(voti2)
    n = len(voti1)
    assert n % 2 == 0
    #print(f"called bufale({voti1=}, {voti2=})", file=stderr)
    LB = 0
    worst_val = 0
    opt_val = 0
    opt_sol = [2] * (n//2) +  [1] * (n//2)
    num_opt_sols = comb(5,2) % BASE
    return LB, worst_val, opt_val, opt_sol, num_opt_sols 


T = int(input())
for t in range(1, 1 + T):
    n = int(input())
    voti1 = []
    voti2 = []
    for i in range(n):
        voto1,voto2 = map(int, input().strip().split())
        voti1.append(voto1)
        voti2.append(voto2)
    LB, UB, opt_val, opt_sol, num_opt_sols = bufale(voti1,voti2)
    print(f"{LB} {UB} {opt_val}")
    print(" ".join(map(str,opt_sol)))
    print(num_opt_sols)

