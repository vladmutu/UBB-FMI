import UI
import getset
from operator import itemgetter
def creeazaTranzactie():
    tranzactie = UI.dateTranzactie()
    return tranzactie
def adaugareTranzactie(lista_tranzactii):
    lista_tranzactii.append(creeazaTranzactie())
    UI.tranzactieAdaugata(lista_tranzactii)


def actualizareTranzactie(lista_tranzactii):
    tranzactieCautata = UI.dateTranzactieCautata()
    index=-1
    i=0
    for tranzactie in lista_tranzactii:
        if getset.getZiTranzactie(tranzactieCautata) == getset.getZiTranzactie(tranzactie) and getset.getTipTranzactie(tranzactieCautata) == getset.getTipTranzactie(tranzactie) and getset.getSumaTranzactie(tranzactieCautata) == getset.getSumaTranzactie(tranzactie):
            index=i
        i += 1
    if index == -1:
        UI.tranzactieInexistenta()
        actualizareTranzactie(lista_tranzactii)
    else:
        UI.tranzactieGasita()
        tranzactie=UI.dateTranzactie()
        lista_tranzactii[index]=tranzactie
        UI.tranzactieActualizata(lista_tranzactii)


def stergereTranzactieDupaZi(lista_tranzactii):
    ziCautata = UI.dateTranzactieZi()
    lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getZiTranzactie(tranzactie) != ziCautata]
    UI.tranzactieStearsa(lista_tranzactii)


def stergereTranzactiePerioada(lista_tranzactii):
    perioada = UI.dateTranzactiePerioada()
    lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getZiTranzactie(tranzactie) < perioada[0] or getset.getZiTranzactie(tranzactie) > perioada[1]]
    UI.tranzactieStearsa(lista_tranzactii)

def stergereTranzactieTip(lista_tranzactii):
    tipTranzactie = UI.dateTranzactieTip()
    lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) != tipTranzactie]
    UI.tranzactieStearsa(lista_tranzactii)


def cautareTranzactieDupaSuma(lista_tranzactii):
    sumaTranzactie = UI.dateTranzactieSuma()
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getSumaTranzactie(tranzactie) == sumaTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)

def cautareTranzactieZiSuma(lista_tranzactii):
    ziTranzactie = UI.dateTranzactieZi()
    sumaTranzactie = UI.dateTranzactieSuma()
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getZiTranzactie(tranzactie) < ziTranzactie and getset.getSumaTranzactie(tranzactie) > sumaTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)

def cautareTranzactieTip(lista_tranzactii):
    tipTranzactie = UI.dateTranzactieTip()
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) == tipTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)


def raportTranzactieTip(lista_tranzactii):
    tipTranzactie = UI.dateTranzactieTip()
    s = 0
    for tranzactie in lista_tranzactii:
        if getset.getTipTranzactie(tranzactie) == tipTranzactie:
            if getset.getTipTranzactie(tranzactie) == "retragere":
                s -= getset.getSumaTranzactie(tranzactie)
            else:
                s += getset.getSumaTranzactie(tranzactie)
    UI.afisareSuma(s)


def raportTranzactieSold(lista_tranzactii):
    ziTranzactie = UI.dateTranzactieZi()
    s = 0
    for tranzactie in lista_tranzactii:
        if getset.getZiTranzactie(tranzactie) <= ziTranzactie:
            if getset.getTipTranzactie(tranzactie) == "retragere":
                s -= getset.getSumaTranzactie(tranzactie)
            else:
                s += getset.getSumaTranzactie(tranzactie)
    UI.afisareSold(s)


def raportTranzactieTipSuma(lista_tranzactii):
    tipTranzactie = UI.dateTranzactieTip()
    new_lista_tranzactii = []
    for tranzactie in lista_tranzactii:
        if getset.getTipTranzactie(tranzactie) == tipTranzactie:
            new_lista_tranzactii.append(tranzactie)
    sorted_lista_tranzactii = sorted(new_lista_tranzactii, key=itemgetter(2))
    UI.printLista(sorted_lista_tranzactii)


def filtrareTranzactieTip(lista_tranzactii):
    tipTranzactie = UI.dateTranzactieTip()
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) != tipTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)


def filtrareTranzactieSumaTip(lista_tranzactii):
    sumaTranzactie = UI.dateTranzactieSuma()
    tipTranzactie = UI.dateTranzactieTip()
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) != tipTranzactie and getset.getSumaTranzactie(tranzactie) < sumaTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)


def undo(stack_lista_tranzactii):
    pass


def run():
    lista_tranzactii = []
    stack_lista_tranzactii = []
    #lista_tranzactii = getset.setListaTranzactii()
    while True:
        UI.menu()
        exec = UI.choice()
        if exec == 0:
            exit()
        if exec == 1:
            exec1=UI.alegereTipAdaugare()
            if exec1 == 1:
                adaugareTranzactie(lista_tranzactii)
            if exec1 == 2:
                actualizareTranzactie(lista_tranzactii)
        if exec == 2:
            exec1=UI.alegereTipStergere()
            if exec1 == 1:
                stergereTranzactieDupaZi(lista_tranzactii)
                stack_lista_tranzactii.append(lista_tranzactii)
            if exec1 == 2:
                stergereTranzactiePerioada(lista_tranzactii)
                stack_lista_tranzactii.append(lista_tranzactii)
            if exec1 == 3:
                stergereTranzactieTip(lista_tranzactii)
                stack_lista_tranzactii.append(lista_tranzactii)
        if exec == 3:
            exec1=UI.alegereTipCautare()
            if exec1 == 1:
                cautareTranzactieDupaSuma(lista_tranzactii)
            if exec1 == 2:
                cautareTranzactieZiSuma(lista_tranzactii)
            if exec1 == 3:
                cautareTranzactieTip(lista_tranzactii)
        if exec == 4:
            exec1=UI.alegereTipRaport()
            if exec1 == 1:
                raportTranzactieTip(lista_tranzactii)
            if exec1 == 2:
                raportTranzactieSold(lista_tranzactii)
            if exec1 == 3:
                raportTranzactieTipSuma(lista_tranzactii)
        if exec == 5:
            exec1 = UI.alegereTipFiltrare()
            if exec1 == 1:
                filtrareTranzactieTip(lista_tranzactii)
            if exec1 == 2:
                filtrareTranzactieSumaTip(lista_tranzactii)
        if exec == 6:
            undo(stack_lista_tranzactii)

run()