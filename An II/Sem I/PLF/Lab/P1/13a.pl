aparitii([],_,0).%Pentru lista vida se returneaza 0
aparitii([E | T],E,Nr):-%daca elemntul cautat este gasit  in capul listei atunci incrementam Nr
    !,
    aparitii(T,E,Nr1),
    Nr is Nr1+1.
aparitii([_ | T],E,Nr):-
    aparitii(T,E,Nr).% daca elementul cautat nu se aafla in capul listei atunci continuam apelul

eliminaRep([], []). 
eliminaRep([H | T], R) :-
        T1 = T,
        aparitii(T1, H, Nr), %Pentru fiecare cap al listei calculam nr de aparitii in coada listei iar daca este mai mare ca 0 atunci nu il adaugam in rezultat
        Nr > 0,
        !,
        eliminaRep(T, R).
eliminaRep([H | T], [H | R]) :-
        eliminaRep(T, R). %altfel il adaugam in lista rezultat