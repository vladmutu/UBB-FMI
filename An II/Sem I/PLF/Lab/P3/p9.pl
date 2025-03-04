/*
    generate_permutations(N)=valida(perm(generate_list(N)))

    generate_permutations(N: Int, Rez: Lista)
    Modele de flux: (i, o), (i, i)
    N - lungimea listei de intrare, generata ca [1, 2, ..., N]
    Rez - permutare valida a listei [1..N]
*/
generate_permutations(N, Rez) :-
    perm(N, P),
    verifica_conditie(P),        
    Rez = P.

/*
    generate_list(Start, End) =
        Start (+) generate_list(Start+1,End),Start<=End
        vida                          , Start > End

    generate_list(Start: Int, End: Int, List: Lista)
    Modele de flux: (i, i, o), (i, i, i)
    Start - elementul de pornire
    End - elementul final
    List - lista de numere de la Start la End
*/
generate_list(Start, End, []) :-
    Start > End,
    !.
generate_list(Start, End, [Start | Rest]) :-
    Start =< End,
    Next is Start + 1,
    generate_list(Next, End, Rest).

/*
    insereaza(E, l1,l2,...,ln) = E+l1,l2,...ln
                                l1+insereaza(l2,...,ln)


    insereaza(E: Element, L: Lista, Rez: Lista)
    Modele de flux: (i, i, o), (i, i, i)
    E - elementul de inserat
    L - lista in care se insereaza
    Rez - rezultatul listei dupa inserare
*/
insereaza(E, L, [E | L]).
insereaza(E, [H | T], [H | Rez]) :-!,
    insereaza(E, T, Rez).

/*
    perm(l1,l2,...ln) =
        vida                          daca l e vida
        insereaza(l1, perm(l2...ln))          , altfel

    perm(L: Lista, P: Lista)
    Modele de flux: (i, o), (i, i)
    L - lista initiala pentru care se genereaza permutarile
    P - o permutare a listei L
*/
perm([], []).
perm([E | T], P) :-
    perm(T, L),
    insereaza(E, L, P).

/*
    verifica_conditie(l1, l2, ..., ln) =
        adevarat                    daca n=1
        abs(l1 - l2) = 1            daca n=2
        verifica_conditie_aux(l2,...,ln, [l1])  , altfel

    verifica_conditie(L: Lista)
    Modele de flux: (i), (i)
    L - lista de numere care trebuie verificat
*/
verifica_conditie([_]). 
verifica_conditie([H1, H2]) :-
    abs(H1 - H2) =< 3,!. 
verifica_conditie([H1, H2 | T]) :-
    abs(H1 - H2) =< 3,
    verifica_conditie([H2 | T]).

/*
    verifica_conditie_aux(l1, l2, ..., ln, a1, a2, ..., am) =
        fals, daca n = 0
        adevarat                        daca a vida
        verifica_conditie_aux(l2,...ln,l1,a1,a2,...,am)  , daca cautare_sublista([a1,...,am],l) este true

    verifica_conditie_aux(Sublist: Lista)
    Modele de flux: (i, i), (i, o)
    Sublist - lista care urmeaza a fi verificata
*/
verifica_conditie_aux([], _).
verifica_conditie_aux([H | T], Sublist) :-
    cautare_sublista(Sublist, H),
    verifica_conditie_aux(T, [H | Sublist]).

/*
    cautare_sublista(a1, a2, ..., an, l) =
        false, daca n = 0
        true, daca abs(a1-l)=1
        cautare_sublista(a2, a3, ..., an, l)  , altfel

    cautare_sublista(Sublist: Lista, Element: Intreg)
    Modele de flux: (i, i), (o)
    Sublist - lista de elemente anterioare
    Element - elementul curent de comparat
*/
cautare_sublista([X | _], Y) :-
    abs(X - Y) =< 3.

cautare_sublista([_ | T], Y) :-
    cautare_sublista(T, Y).

