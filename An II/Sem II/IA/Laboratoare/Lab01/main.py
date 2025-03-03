import math
from collections import Counter
from math import sqrt, log

#O(n) O(n) n = lungimea stringului
def prob1(string="Ana are mere rosii si galbene"):
    tokens = string.split(' ')
    lastWordLexicographicaly = tokens.pop()
    for token in tokens:
        if token > lastWordLexicographicaly:
            lastWordLexicographicaly = token
    return lastWordLexicographicaly

print("Problema 1")
print(prob1())

#O(n) O(n) n = lungimea stringului
def prob1_with_gpt(text="Ana are mere rosii si galbene"):
    cuvinte = text.split()
    return max(cuvinte)

print("Problema 1 cu GPT")
print(prob1_with_gpt())

#O(1) O(1)
def prob2(x=(1,5), y=(4,1)):
    return sqrt((y[0]-x[0])*(y[0]-x[0])+(y[1]-x[1])*(y[1]-x[1]))

print("Problema 2")
print(prob2())

#O(1) O(1)
def prob2_with_gpt(p1=(1,5), p2=(4,1)):
    return math.sqrt((p2[0] - p1[0])**2 + (p2[1] - p1[1])**2)

print("Problema 2 cu GPT")
print(prob2_with_gpt())

#O(n) O(1) n = lungimea vectorilor
def prob3(v1=[1,0,2,0,3], v2=[1,2,0,3,1]):
    scalarProduct = 0
    for i in range(0, len(v1)):
        scalarProduct += v1[i] * v2[i]
    return scalarProduct

print("Problema 3")
print(prob3())


def prob3_with_gpt(v1=[1,0,2,0,3], v2=[1,2,0,3,1]):
    v1_dict = {i: v1[i] for i in range(len(v1)) if v1[i] != 0}
    v2_dict = {i: v2[i] for i in range(len(v2)) if v2[i] != 0}

    produs = sum(v1_dict[i] * v2_dict[i] for i in v1_dict if i in v2_dict)

    return produs

print("Problema 3 cu GPT")
print(prob3_with_gpt())

#O(n) O(n) n = lungimea stringului
def prob4(text="ana are ana are mere rosii ana"):
    tokens = text.split(' ')
    sol = Counter(tokens)
    for word, freq in sol.items():
        if freq == 1:
            print(word)

print("Problema 4")
prob4()

def prob4_with_gpt(text="ana are ana are mere rosii ana"):
    cuvinte = text.split()
    frecvente = Counter(cuvinte)
    return [cuvant for cuvant, frecventa in frecvente.items() if frecventa == 1]  # Filtrare

print("Problema 4 cu GPT")
print(prob4_with_gpt())

#O(n) O(1) n = lungimea listei
def prob5(list=[1,2,3,1,4]):
    suma = (len(list)-1) * (len(list)) // 2
    return sum(list) - suma

print("Problema 5")
print(prob5())


def prob5_with_gpt(lista=[1,2,3,4,2]):
    n = len(lista)
    suma_teoretica = (n - 1) * (n - 2) // 2  # Suma numerelor de la 1 la n-1
    suma_actuala = sum(lista)
    return suma_actuala - suma_teoretica

print("Problema 5 cu GPT")
print(prob5_with_gpt([1,2,3,4,2]))

#O(n) O(n) n = lungimea listei
def prob6(list=[2,8,7,2,2,5,2,3,1,2,2]):
    sol = Counter(list)
    for el, freq in sol.items():
        if freq > len(list)/2:
            return el
    return None

print("Problema 6")
print(prob6())


def prob6_with_gpt(lista=[2,8,7,2,2,5,2,3,1,2,2]):
    candidat, contor = None, 0
    for numar in lista:
        if contor == 0:
            candidat = numar
        contor += (1 if numar == candidat else -1)

    # Pas 2: Verificăm dacă este într-adevăr majoritar
    if lista.count(candidat) > len(lista) // 2:
        return candidat
    return None

print("Problema 6 cu GPT")
print(prob6_with_gpt())

#O(nlogn) O(1) n = lungimea listei
def prob7(list=[7,4,6,3,9,1], k=2):
    list = sorted(list)
    return list.pop(len(list) - k)

print("Problema 7")
print(prob7())

def prob7_with_gpt(lista=[7,4,6,3,9,1], k=2):
    return sorted(lista)[-k]

print("Problema 7 cu GPT")
print(prob7_with_gpt())

#O(n) O(1) n = numarul de numere
def prob8(n=10):
    for i in range(1, n + 1):
        print(bin(i).replace('0b', '', 1))

print("Problema 8")
prob8()

def prob8_with_gpt(n=10):
    return [bin(i)[2:] for i in range(1, n + 1)]

print("Problema 8 cu GPT")
print(prob8_with_gpt())

#O(n*m) O(n*m) n = numarul de linii, m = numarul de coloane
def prob9(pairList=[((1,1),(3,3)),((2,2),(4,4))]):
    matrix = [[0, 2, 5, 4, 1], [4, 8, 2, 3, 7], [6, 3, 4, 6, 2], [7, 3, 1, 8, 3], [1, 5, 7, 9, 4]]
    n = len(matrix)
    m = len(matrix[0])
    sumePartiale = [[0] * (n + 1) for i in range(m + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            sumePartiale[i][j] = sumePartiale[i - 1][j] + sumePartiale[i][j - 1] - sumePartiale[i - 1][j - 1] + matrix[i - 1][j - 1]
    for pair in pairList:
        print(sumePartiale[pair[1][0] + 1][pair[1][1] + 1] - sumePartiale[pair[0][0]][pair[1][1] + 1] - sumePartiale[pair[1][0] + 1][pair[0][1]] + sumePartiale[pair[0][0]][pair[0][1]])

print("Problema 9")
prob9()

#O(n*m*k) O(1) n = numarul de linii, m = numarul de coloane, k = numarul de coordonate ale submatricii
def prob9_with_copilot(pairList=[((1,1),(3,3)),((2,2),(4,4))]):
    matrix = [[0,2,5,4,1],[4,8,2,3,7],[6,3,4,6,2],[7,3,1,8,3],[1,5,7,9,4]]
    for pair in pairList:
        sum = 0
        for i in range(pair[0][0], pair[1][0] + 1):
            for j in range(pair[0][1], pair[1][1] + 1):
                sum += matrix[i][j]
        print(sum)

print("Problema 9 cu Copilot")
prob9_with_copilot()

#O(n*m) O(1) n = numarul de linii, m = numarul de coloane
def prob10():
    matrix = [[0,0,0,1,1],[0,1,1,1,1],[0,0,1,1,1]]
    maxCount = -1
    maxLineIndex = -1
    for line in matrix:
        if(sum(line) > maxCount):
            maxCount = sum(line)
            maxLineIndex = matrix.index(line)
    return maxLineIndex

print("Problema 10")
print(prob10())

import bisect


def prob10_with_gpt():
    matrix = [[0,0,0,1,1],[0,1,1,1,1],[0,0,1,1,1]]
    max_1s = -1
    index_max = -1

    for i, linie in enumerate(matrix):
        # Găsim prima apariție a lui 1 folosind căutarea binară
        first_one_index = bisect.bisect_left(linie, 1)

        # Dacă există cel puțin un 1 pe linie
        if first_one_index < len(linie):
            numar_1s = len(linie) - first_one_index
        else:
            numar_1s = 0

        # Comparăm numărul de 1 cu maximul
        if numar_1s > max_1s:
            max_1s = numar_1s
            index_max = i

    return index_max

print("Problema 10 cu GPT")
print(prob10_with_gpt())  # Output: 3 (indexul liniei care conține cei mai mulți 1)
