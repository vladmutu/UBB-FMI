cmmdc(0, Y, Y) :- !. %Rez este Y daca X este 0
cmmdc(X, 0, X) :- !. %Rez este X daca Y este 0
cmmdc(X, Y, R) :-
        X >= Y, !,
        Rest is X mod Y,
        cmmdc(Y, Rest, R). %Conform algoritmului lui euclid, daca X>=Y intram pe cmmdc(Y, X mod Y, R)
cmmdc(X, Y, R) :-
        X < Y, !,
        Rest is Y mod X,
        cmmdc(X, Rest, R). %Conform algoritmului lui euclid, daca Y>X intram pe cmmdc(X, Y mod X, R)


cmmdcLista([H], H) :- !. %Cazul in care lista contine un singur element atunci acela este cmmdc
cmmdcLista([H | T], R) :-
        cmmdcLista(T, R1),
        cmmdc(H, R1, R). % facem cmmdc doua cate doua elemente din lista incepand de la ultimele doua
