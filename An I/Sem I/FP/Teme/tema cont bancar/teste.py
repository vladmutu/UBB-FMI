import getset
import main

def test_creeazaAdaugaTranzactie():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie,tipTranzactie,sumaTranzactie)
    assert getset.getZiTranzactie(tranzactie) == ziTranzactie
    assert getset.getTipTranzactie(tranzactie) == tipTranzactie
    assert getset.getSumaTranzactie(tranzactie) == sumaTranzactie
    lista_tranzactie=[]
    lista_tranzactie.append(tranzactie)
    assert getset.getZiTranzactie(lista_tranzactie[0]) == ziTranzactie
    assert getset.getTipTranzactie(lista_tranzactie[0]) == tipTranzactie
    assert getset.getSumaTranzactie(lista_tranzactie[0]) == sumaTranzactie

def test_actualizeazaTranzactie():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie,tipTranzactie,sumaTranzactie)
    lista_tranzactie=[]
    lista_tranzactie.append(tranzactie)
    ziTranzactieDeModificat = 15
    tipTranzactieDeModificat = "depunere"
    sumaTranzactieDeModificat = 200
    tranzactieCautata = main.creeazaTranzactie1(ziTranzactieDeModificat,tipTranzactieDeModificat,sumaTranzactieDeModificat)
    main.actualizareTranzactie(lista_tranzactie,tranzactieCautata,tranzactie)
    assert getset.getZiTranzactie(lista_tranzactie[0]) == ziTranzactieDeModificat
    assert getset.getSumaTranzactie(lista_tranzactie[0]) == sumaTranzactieDeModificat
    assert getset.getTipTranzactie(lista_tranzactie[0]) != tipTranzactieDeModificat

def test_stergereTip():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie,tipTranzactie,sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    tipTranzactieNou="retragere"
    newListaTranzactii = main.stergereTranzactieTip(lista_tranzactii,tipTranzactieNou)
    assert newListaTranzactii != lista_tranzactii
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    newListaTranzactii = main.stergereTranzactieTip(lista_tranzactii,"depunere")
    assert newListaTranzactii != lista_tranzactii

def test_stergerePerioada():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    perioada=[14,20]
    newListaTranzactii = main.stergereTranzactiePerioada(lista_tranzactii,perioada)
    assert newListaTranzactii != lista_tranzactii
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    newListaTranzactii = main.stergereTranzactiePerioada(lista_tranzactii,[10,11])
    assert newListaTranzactii != lista_tranzactii

def test_stergereZi():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    newListaTranzactii = main.stergereTranzactieDupaZi(lista_tranzactii,15)
    assert newListaTranzactii != lista_tranzactii
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    newListaTranzactii = main.stergereTranzactieDupaZi(lista_tranzactii,11)
    assert newListaTranzactii != lista_tranzactii

def test_cautareSuma():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    sumaTranzactieNoua = 200
    new_lista_tranzactii = main.cautareTranzactieDupaSuma(lista_tranzactii,sumaTranzactieNoua)
    assert len(new_lista_tranzactii) == len(lista_tranzactii)
    sumaTranzactieNoua = 100
    new_lista_tranzactii = main.cautareTranzactieDupaSuma(lista_tranzactii, sumaTranzactieNoua)
    assert len(new_lista_tranzactii) != len(lista_tranzactii)

def test_cautareTip():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    tipTranzactieNoua = "retragere"
    new_lista_tranzactii = main.cautareTranzactieTip(lista_tranzactii, tipTranzactieNoua)
    assert len(new_lista_tranzactii) == len(lista_tranzactii)
    tipTranzactieNoua = "depunere"
    new_lista_tranzactii = main.cautareTranzactieTip(lista_tranzactii, tipTranzactieNoua)
    assert len(new_lista_tranzactii) != len(lista_tranzactii)

def test_cautareZiSuma():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    ziTranzactieNoua = 17
    sumaTranzactieNoua = 100
    new_lista_tranzactii = main.cautareTranzactieZiSuma(lista_tranzactii, [ziTranzactieNoua,sumaTranzactieNoua])
    assert len(new_lista_tranzactii) == len(lista_tranzactii)
    ziTranzactieNoua = 13
    sumaTranzactieNoua = 250
    new_lista_tranzactii = main.cautareTranzactieZiSuma(lista_tranzactii, [ziTranzactieNoua,sumaTranzactieNoua])
    assert len(new_lista_tranzactii) != len(lista_tranzactii)

def test_raportSold():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    ziTranzactieNoua = 17
    s=main.raportTranzactieSold(lista_tranzactii,ziTranzactieNoua)
    assert s == -200
    ziTranzactieNoua = 13
    s = main.raportTranzactieSold(lista_tranzactii, ziTranzactieNoua)
    assert s == 0

def test_raportTip():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    tipTranzactieNoua = "retragere"
    assert main.raportTranzactieTip(lista_tranzactii, tipTranzactieNoua) == -200
    tipTranzactieNoua = "depunere"
    assert main.raportTranzactieTip(lista_tranzactii, tipTranzactieNoua) == 0

def test_filtrareTip():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    tipTranzactieNoua = "retragere"
    assert main.filtrareTranzactieTip(lista_tranzactii,tipTranzactieNoua) != lista_tranzactii
    tipTranzactieNoua = "depunere"
    new_lista_tranzactii = main.filtrareTranzactieTip(lista_tranzactii,tipTranzactieNoua)
    assert main.filtrareTranzactieTip(lista_tranzactii,tipTranzactieNoua) != lista_tranzactii


def test_filtrareSumaTip():
    ziTranzactie = 15
    tipTranzactie = "retragere"
    sumaTranzactie = 200
    tranzactie = main.creeazaTranzactie1(ziTranzactie, tipTranzactie, sumaTranzactie)
    lista_tranzactii = []
    lista_tranzactii.append(tranzactie)
    tipTranzactieNoua = "retragere"
    sumaTranzactieNoua = 250
    assert main.filtrareTranzactieSumaTip(lista_tranzactii,[tipTranzactieNoua,sumaTranzactieNoua]) != lista_tranzactii
    tipTranzactieNoua = "retragere"
    sumaTranzactieNoua = 150
    assert main.filtrareTranzactieSumaTip(lista_tranzactii,[tipTranzactieNoua,sumaTranzactieNoua]) != lista_tranzactii


def ruleazaTeste():
    test_creeazaAdaugaTranzactie()
    test_actualizeazaTranzactie()
    test_stergereZi()
    test_stergerePerioada()
    test_stergereTip()
    test_raportSold()
    test_raportTip()
    test_filtrareTip()
    test_filtrareSumaTip()
    print("Toate testele au fost efectuate cu succes!")

#ruleazaTeste()
main.run2()
