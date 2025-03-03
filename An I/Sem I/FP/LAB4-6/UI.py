import getset

def menu():
    print("\nMeniu")
    print("1.Adaugare/Actualizare tranzactii")
    print("2.Stergere tranzactii")
    print("3.Cautare tranzactii")
    print("4.Rapoarte tranzactii")
    print("5.Filtrare tranzactii")
    print("6.Undo")
    print("0.Exit")
    print()
def choice():
    exec=0
    try:
        exec=int(input())
        return exec
    except:
        print("Comanda invalida!")

def alegereTipAdaugare():
    exec=0
    while True:
        print("1.Adaugare tranzactie")
        print("2.Actualizare tranzactie")
        try:
            exec=int(input())
            if exec !=1 and exec != 2:
                assert False
            return exec
        except:
            print("Comanda invalida!")

def alegereTipStergere():
    exec = 0
    while True:
        print("1.Sterge tranzactiile de la o anumita zi")
        print("2.Sterge tranzactiile dintr-o anumita perioada")
        print("3.Sterge tranzactiile de un anumit tip")
        try:
            exec = int(input())
            if exec != 1 and exec != 2 and exec != 3:
                assert False
            return exec
        except:
            print("Comanda invalida!")

def alegereTipCautare():
    exec = 0
    while True:
        print("1.Tiparaste tranzactiile mai mari decat o anumita suma")
        print("2.Tipareste tranzactiile efectuate inainte de o zi si mai mari decat o anumita suma")
        print("3.Tipareste tranzactiile de un anumit tip")
        try:
            exec = int(input())
            if exec != 1 and exec != 2 and exec != 3:
                assert False
            return exec
        except:
            print("Comanda invalida!")

def alegereTipRaport():
    exec = 0
    while True:
        print("1.Suma tranzactiilor de un anumit tip")
        print("2.Soldul contului la o anumita data")
        print("3.Tranzactiile de un anumit tip ordonate dupa suma")
        try:
            exec = int(input())
            if exec != 1 and exec != 2 and exec != 3:
                assert False
            return exec
        except:
            print("Comanda invalida!")

def alegereTipFiltrare():
    exec = 0
    while True:
        print("1.Filtreaza tranzactiile de un anumit tip")
        print("2.Filtreaza tranzactiile mai mici decat o anunmita suma si de un anumit tip")
        try:
            exec = int(input())
            if exec != 1 and exec != 2:
                assert False
            return exec
        except:
            print("Comanda invalida!")

def verificareTip(tip):
    if tip == "depunere" or tip == "retragere":
        return tip
    else:
        assert False
def verificareInt(valoare):
    if int(valoare) > 0:
        return int(valoare)
    else:
        assert False

def inputDateTranzactie(prompt, f, msg):
    while True:
        try:
            return f(input(prompt))
        except:
            print(msg)

def dateTranzactie():
    ziTranzactie = inputDateTranzactie("Introduceti ziua tranzactiei:",verificareInt,"Zi invalida!")
    tipTranzactie = inputDateTranzactie("Introduceti tipul tranzactiei:",verificareTip,"Tip invalid!")
    sumaTranzactie = inputDateTranzactie("Introduceti suma tranzactiei:", verificareInt, "Suma invalida!")
    return [ziTranzactie,tipTranzactie,sumaTranzactie]

def dateTranzactieCautata():
    ziTranzactie = inputDateTranzactie("Introduceti ziua tranzactiei cautate:",verificareInt,"Zi invalida!")
    tipTranzactie = inputDateTranzactie("Introduceti tipul tranzactiei cautate:",verificareTip,"Tip invalid!")
    sumaTranzactie = inputDateTranzactie("Introduceti suma tranzactiei cautate:", verificareInt, "Suma invalida!")
    return [ziTranzactie,tipTranzactie,sumaTranzactie]

def tranzactieAdaugata(lista_tranzactii):
    print("\nTranzactie adaugata cu succes!\n")
    print("Lista de tranzactii:")
    indice = 1
    for tranzactie in lista_tranzactii:
        print(indice, ". Ziua: ", getset.getZiTranzactie(tranzactie), " Tip: ", getset.getTipTranzactie(tranzactie),
              " Suma: ", getset.getSumaTranzactie(tranzactie))
        indice += 1
    print()

def tranzactieActualizata(lista_tranzactii):
    print("\nTranzactie actualizata cu succes!\n")
    print("Lista de tranzactii:")
    indice = 1
    for tranzactie in lista_tranzactii:
        print(indice, ". Ziua: ", getset.getZiTranzactie(tranzactie), " Tip: ", getset.getTipTranzactie(tranzactie),
              " Suma: ", getset.getSumaTranzactie(tranzactie))
        indice += 1
    print()

def dateTranzactieZi():
    ziTranzactie = inputDateTranzactie("Introduceti ziua tranzactiei:",verificareInt,"Zi invalida!")
    return ziTranzactie

def dateTranzactiePerioada():
    ziTranzactieInceput = inputDateTranzactie("Introduceti ziua de inceput a perioadei:",verificareInt,"Zi invalida!")
    ziTranzactieSfarsit = inputDateTranzactie("Introduceti ziua de sfarsit a perioadei:",verificareInt,"Zi invalida!")
    return [ziTranzactieInceput,ziTranzactieSfarsit]

def dateTranzactieTip():
    tipTranzactie = inputDateTranzactie("Introduceti tipul tranzactiei cautate:", verificareTip, "Tip invalid!")
    return tipTranzactie

def dateTranzactieSuma():
    sumaTranzactie = inputDateTranzactie("Introduceti suma tranzactiei cautate:", verificareInt, "Suma invalida!")
    return sumaTranzactie

def tranzactieStearsa(lista_tranzactii):
    print("\nTranzactii sterse cu succes!\n")
    print("Lista de tranzactii:")
    indice = 1
    for tranzactie in lista_tranzactii:
        print(indice, ". Ziua: ", getset.getZiTranzactie(tranzactie), " Tip: ", getset.getTipTranzactie(tranzactie),
              " Suma: ", getset.getSumaTranzactie(tranzactie))
        indice += 1
    print()

def printLista(lista_tranzactii):
    print("\nLista de tranzactii:")
    indice = 1
    for tranzactie in lista_tranzactii:
        print(indice, ". Ziua: ", getset.getZiTranzactie(tranzactie), " Tip: ", getset.getTipTranzactie(tranzactie),
              " Suma: ", getset.getSumaTranzactie(tranzactie))
        indice += 1
    print()

def nicioTranzactie():
    print("\nNicio tranzactie de acest fel gasita!\n")

def afisareSuma(s):
    print("\nSuma este: ",s)

def afisareSold(s):
    print("\nSoldul contului la aceasta data este: ",s)

def tranzactieInexistenta():
    print("\nTranzactie inexistenta!\n")

def tranzactieGasita():
    print("\nTranzactie Gasita!\n")

def undoImposibil():
    print("\nUndo imposibil!\n")