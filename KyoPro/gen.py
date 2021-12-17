import random
import sys

f = open("input.txt", "w")
N = 100
Q = 100
f.write(f"{N} {Q}\n")
for i in range(N):
    f.write(str(random.randint(0, 5)))
    if i != N - 1:
        f.write(" ")
    else:
        f.write("\n")
for i in range(Q):
    T = random.randint(1, 3)
    if T == 1 or T == 3:
        X = random.randint(1, N)
        V = random.randint(1, 5)
        f.write(f"{T} {X} {V}\n")
    else:
        L = random.randint(1, N)
        R = random.randint(L, N)
        f.write(f"{T} {L} {R}\n")
f.close()

sys.stdin = open("input.txt", "r")
sys.stdout = open("ans.txt", "w")

# paste python answer code here
