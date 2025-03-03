import math


def prim(x):
    if x < 2:
        return False
    if x % 2 == 0 and x != 2:
        return False
    for d in range(3, int(math.sqrt(x))+1, 2):
        if x % d == 0:
            return False
    return True


def partitii(n):
    stiva = [(0, [], 2)]
    while stiva:
        suma_curenta, solutie_curenta, nr_prim = stiva.pop()
        while nr_prim <= n:
            if prim(nr_prim) and suma_curenta + nr_prim <= n:
                if suma_curenta + nr_prim == n:
                    print(solutie_curenta + [nr_prim])
                else:
                    stiva.append((suma_curenta + nr_prim, solutie_curenta + [nr_prim], nr_prim))
            nr_prim += 1


def partitii_back(i, sp, n, s):
    if sp == n:
        print("[", end='')
        print(str(s[1]), end='')
        for j in range(2, i):
            print(', ' + str(s[j]), end='')
        print("]", end='')
        print()
    else:
        for j in range(s[i-1], n-sp+1):
            if prim(j):
                try:
                    s[i] = j
                except IndexError:
                    s.append(j)
                partitii_back(i + 1, sp + j, n, s)


def main_back():
    s = []
    n = int(input("Introduceti numarul n: "))
    if n == 3:
        print("[3]")
    elif n == 2:
        print("[2]")
    else:
        s.append(2)
        partitii_back(1, 0, n, s)


def main():
    n = int(input("Introduceti numarul n: "))
    partitii(n)


def run():
    print("1.Iterativ")
    print("2.Recursiv")
    cmd = input()
    try:
        cmd = int(cmd)
    except ValueError:
        print("Comanda invalida!")
        exit()
    if cmd != 2 and cmd != 1:
        print("Comanda invalida!")
        exit()
    if cmd == 1:
        main()
    elif cmd == 2:
        main_back()


run()
