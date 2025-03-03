import getset

def inputs():
        ex = input()
        ex.strip()
        x = ex.split(" ")
        erori = ""
        overflow = []
        lista_instructiuni = []
        #if x[0] != "add" and x[0] != "sterge" and x[0] != "cauta" and x[0] != "filtrare":
            #erori += "comanda invalida"
        if len(erori) <= 0:
            for i in range(0,len(x)-1):
                if x[i] == "add":
                    try:
                        x[i+1] = int(x[i+1])
                    except:
                        erori += "comanda invalida!"
                    try:
                        if x[i+2] != "retragere" and x[i+2] != "depunere":
                            erori += "comanda invalida!"
                    except:
                        erori+="comanda invalida!"
                    try:
                        x[i+3] = int(x[i+3])
                    except:
                        erori += "comanda invalida!"
                    if len(erori) > 0:
                        print("comanda invalida!")
                        break
                    else:
                        lista_instructiuni.append([1,x[i+1],x[i+2],x[i+3]])
                    try:
                        i += 3
                        overflow.append(x[i])
                    except:
                        erori += "comanda invalida!"
                    if len(erori) > 0:
                        print("comanda invalida!")
                        break
                if x[i] == "sterge":
                    try:
                        if x[i + 1] != "retragere" and x[i + 1] != "depunere":
                            erori += "comanda invalida!"
                    except:
                        erori+="comanda invalida"
                    if len(erori)>0:
                        print("comanda invalida!")
                        break
                    else:
                        lista_instructiuni.append([2,x[i+1]])
                    try:
                        i += 2
                        overflow.append(x[i])
                    except:
                        erori += "comanda invalida!"
                    if len(erori) > 0:
                        print("comanda invalida!")
                        break
                if x[i] == "cauta":
                    if x[i+1] != "retragere" and x[i+1] != "depunere":
                        erori += "comanda invalida!"
                    if len(erori) > 0:
                        print("comanda invalida!")
                        break
                    else:
                        lista_instructiuni.append([3,x[i+1]])
                    try:
                        i += 2
                        overflow.append(x[i])
                    except:
                        erori += "comanda invalida!"
                    if len(erori) > 0:
                        print("comanda invalida!")
                        break
                if x[i] == "filtrare":
                    if x[i+1] != "retragere" and x[i+1] != "depunere":
                        erori += "comanda invalida!"
                    if len(erori) > 0:
                        print("comanda invalida!")
                        break
                    else:
                        lista_instructiuni.append([4,x[i+1]])
                    try:
                        i += 2
                        overflow.append(x[i])
                    except:
                        erori += "comanda invalida!"
                    if len(erori) > 0:
                        print("comanda invalida!")
                        break
        else:
            print("comanda invalida!")
        return lista_instructiuni




