import UI
import UI1
import getset
from operator import itemgetter

"""
adaugare/actualizare
"""

def creeazaTranzactie1(ziTranzactie,tipTranzactie,sumaTranzactie):
    return [ziTranzactie,tipTranzactie,sumaTranzactie]
def creeazaTranzactie():
    tranzactie = UI.dateTranzactie()
    return tranzactie
def adaugareTranzactie(lista_tranzactii,x):
    lista_tranzactii.append(x)
    UI.tranzactieAdaugata(lista_tranzactii)

def service_actualizareTranzactie1():
    tranzactie = UI.dateTranzactie()
    return tranzactie
def service_actualizareTranzactie2():
    tranzactieCautata = UI.dateTranzactieCautata()
    return tranzactieCautata
def actualizareTranzactie(lista_tranzactii,tranzactieCautata):
    index=-1
    i=0
    for tranzactie in lista_tranzactii:
        if getset.getZiTranzactie(tranzactieCautata) == getset.getZiTranzactie(tranzactie) and getset.getTipTranzactie(tranzactieCautata) == getset.getTipTranzactie(tranzactie) and getset.getSumaTranzactie(tranzactieCautata) == getset.getSumaTranzactie(tranzactie):
            index=i
        i += 1
    if index == -1:
        UI.tranzactieInexistenta()
        actualizareTranzactie(lista_tranzactii,service_actualizareTranzactie2())
    else:
        UI.tranzactieGasita()
        lista_tranzactii[index]=service_actualizareTranzactie1()
        UI.tranzactieActualizata(lista_tranzactii)


"""
stergere
"""

def serviceStergereTranzactieDupaZi():
    ziCautata = UI.dateTranzactieZi()
    return ziCautata

def stergereTranzactieDupaZi(lista_tranzactii,ziCautata):
    lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getZiTranzactie(tranzactie) != ziCautata]
    UI.tranzactieStearsa(lista_tranzactii)

def serviceStergereTranzactiePerioada():
    perioada = UI.dateTranzactiePerioada()
    return perioada
def stergereTranzactiePerioada(lista_tranzactii,perioada):
    lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getZiTranzactie(tranzactie) < perioada[0] or getset.getZiTranzactie(tranzactie) > perioada[1]]
    UI.tranzactieStearsa(lista_tranzactii)

def serviceStergereTranzactieTip():
    tipTranzactie = UI.dateTranzactieTip()
    return tipTranzactie

def stergereTranzactieTip(lista_tranzactii,tipTranzactie):
    lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) != tipTranzactie]
    UI.tranzactieStearsa(lista_tranzactii)


"""
cautare
"""

def serviceCautareSuma():
    sumaTranzactie = UI.dateTranzactieSuma()
    return sumaTranzactie

def cautareTranzactieDupaSuma(lista_tranzactii,sumaTranzactie):
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getSumaTranzactie(tranzactie) == sumaTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)
        return new_lista_tranzactii

def serviceCautareZiSuma():
    ziTranzactie = UI.dateTranzactieZi()
    sumaTranzactie = UI.dateTranzactieSuma()
    return [ziTranzactie,sumaTranzactie]
def cautareTranzactieZiSuma(lista_tranzactii,ziSumaTranzactie):
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getZiTranzactie(tranzactie) < ziSumaTranzactie[0] and getset.getSumaTranzactie(tranzactie) > ziSumaTranzactie[1]]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)
        return new_lista_tranzactii

def serviceCautareTip():
    tipTranzactie = UI.dateTranzactieTip()
    return tipTranzactie

def cautareTranzactieTip(lista_tranzactii,tipTranzactie):
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) == tipTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)
        return new_lista_tranzactii

"""
rapoarte
"""



def serviceRaportTip():
    tipTranzactie = UI.dateTranzactieTip()
    return tipTranzactie

def raportTranzactieTip(lista_tranzactii,tipTranzactie):
    s = 0
    for tranzactie in lista_tranzactii:
        if getset.getTipTranzactie(tranzactie) == tipTranzactie:
            if getset.getTipTranzactie(tranzactie) == "retragere":
                s -= getset.getSumaTranzactie(tranzactie)
            else:
                s += getset.getSumaTranzactie(tranzactie)
    UI.afisareSuma(s)
    return s

def serviceRaportSold():
    ziTranzactie = UI.dateTranzactieZi()
    return ziTranzactie


def raportTranzactieSold(lista_tranzactii,ziTranzactie):
    s = 0
    for tranzactie in lista_tranzactii:
        if getset.getZiTranzactie(tranzactie) <= ziTranzactie:
            if getset.getTipTranzactie(tranzactie) == "retragere":
                s -= getset.getSumaTranzactie(tranzactie)
            else:
                s += getset.getSumaTranzactie(tranzactie)
    UI.afisareSold(s)
    return s

def serviceRaportTipSuma():
    tipTranzactie = UI.dateTranzactieTip()
    return tipTranzactie

def raportTranzactieTipSuma(lista_tranzactii,tipTranzactie):
    new_lista_tranzactii = []
    for tranzactie in lista_tranzactii:
        if getset.getTipTranzactie(tranzactie) == tipTranzactie:
            new_lista_tranzactii.append(tranzactie)
    sorted_lista_tranzactii = sorted(new_lista_tranzactii, key=itemgetter(2))
    UI.printLista(sorted_lista_tranzactii)

"""
filtrare
"""

def serviceFiltrareTip():
    tipTranzactie = UI.dateTranzactieTip()
    return tipTranzactie

def filtrareTranzactieTip(lista_tranzactii,tipTranzactie):
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) != tipTranzactie]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)

def serviceFiltrareSumaTip():
    sumaTranzactie = UI.dateTranzactieSuma()
    tipTranzactie = UI.dateTranzactieTip()
    return [sumaTranzactie,tipTranzactie]

def filtrareTranzactieSumaTip(lista_tranzactii,sumaTipTranzactie):
    new_lista_tranzactii = [tranzactie for tranzactie in lista_tranzactii if getset.getTipTranzactie(tranzactie) != sumaTipTranzactie[1] and getset.getSumaTranzactie(tranzactie) != sumaTipTranzactie[0]]
    if new_lista_tranzactii == []:
        UI.nicioTranzactie()
    else:
        UI.printLista(new_lista_tranzactii)


def run1():
    lista_tranzactii = []
    stack_lista_tranzactii = ([0,"Lista de tranzactii este goala",0],)
    i=1
    while True:
        UI.menu()
        exec = UI.choice()
        i += 1
        if exec == 0:
            exit()
        if exec == 1:
            exec1 = UI.alegereTipAdaugare()
            if exec1 == 1:
                adaugareTranzactie(lista_tranzactii,creeazaTranzactie())
                new_lista_tranzactii = tuple(lista_tranzactii,)
                stack_lista_tranzactii += new_lista_tranzactii
            if exec1 == 2:
                actualizareTranzactie(lista_tranzactii,service_actualizareTranzactie2())
                new_lista_tranzactii = tuple(lista_tranzactii,)
                stack_lista_tranzactii += new_lista_tranzactii
        if exec == 2:
            exec1 = UI.alegereTipStergere()
            if exec1 == 1:
                stergereTranzactieDupaZi(lista_tranzactii,serviceStergereTranzactieDupaZi())
                new_lista_tranzactii = tuple(lista_tranzactii,)
                stack_lista_tranzactii += new_lista_tranzactii
            if exec1 == 2:
                stergereTranzactiePerioada(lista_tranzactii,serviceStergereTranzactiePerioada())
                new_lista_tranzactii = tuple(lista_tranzactii,)
                stack_lista_tranzactii += new_lista_tranzactii
            if exec1 == 3:
                stergereTranzactieTip(lista_tranzactii,serviceStergereTranzactieTip())
                new_lista_tranzactii = tuple(lista_tranzactii,)
                stack_lista_tranzactii += new_lista_tranzactii
        if exec == 3:
            exec1 = UI.alegereTipCautare()
            if exec1 == 1:
                cautareTranzactieDupaSuma(lista_tranzactii,serviceCautareSuma())
            if exec1 == 2:
                cautareTranzactieZiSuma(lista_tranzactii,serviceCautareZiSuma())
            if exec1 == 3:
                cautareTranzactieTip(lista_tranzactii,serviceCautareTip())
        if exec == 4:
            exec1 = UI.alegereTipRaport()
            if exec1 == 1:
                raportTranzactieTip(lista_tranzactii,serviceRaportTip())
            if exec1 == 2:
                raportTranzactieSold(lista_tranzactii,serviceRaportSold())
            if exec1 == 3:
                raportTranzactieTipSuma(lista_tranzactii,serviceRaportTipSuma())
        if exec == 5:
            exec1 = UI.alegereTipFiltrare()
            if exec1 == 1:
                filtrareTranzactieTip(lista_tranzactii,serviceFiltrareTip())
            if exec1 == 2:
                filtrareTranzactieSumaTip(lista_tranzactii,serviceFiltrareSumaTip())
        if exec == 6:
            new_stack_lista_tranzactii = list(stack_lista_tranzactii)
            new_stack_lista_tranzactii.pop()
            lista_tranzactii = new_stack_lista_tranzactii[len(new_stack_lista_tranzactii)-2:len(new_stack_lista_tranzactii)-1]
            stack_lista_tranzactii = tuple(new_stack_lista_tranzactii)
            UI.printLista(lista_tranzactii)



def run2():
    lista_tranzactii = []
    while True:
        lista_instructiuni = UI1.inputs()
        for instructiune in lista_instructiuni:
            if instructiune[0] == 1:
                adaugareTranzactie(lista_tranzactii,[instructiune[1],instructiune[2],instructiune[3]])
            elif instructiune[0] == 2:
                stergereTranzactieTip(lista_tranzactii,instructiune[1])
            elif instructiune[0] == 3:
                cautareTranzactieTip(lista_tranzactii,instructiune[1])
            elif instructiune[0] == 4:
                filtrareTranzactieTip(lista_tranzactii,instructiune[1])
