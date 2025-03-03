def getZiTranzactie(tranzactie):
    return tranzactie[0]

def getTipTranzactie(tranzactie):
    return tranzactie[1]

def getSumaTranzactie(tranzactie):
    return tranzactie[2]

def setListaTranzactii():
    lista_tranzactii = []
    lista_tranzactii.append([15, "depunere", 300])
    lista_tranzactii.append([15, "retragere", 100])
    lista_tranzactii.append([20, "depunere", 200])
    lista_tranzactii.append([14, "retragere", 400])
    lista_tranzactii.append([13, "depunere", 500])
    return lista_tranzactii