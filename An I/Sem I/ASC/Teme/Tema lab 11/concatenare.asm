bits 32 ; assembling for the 32 bits architecture     

extern verificare_cifra

segment code use32 class=code
    global concatenare
    concatenare:
        ; ...
        mov edi, [esp + 4] ;rez
        mov esi, [esp + 8] ;offset-ul primului sir
        mov edx, [esp + 12] ;offset-ul celui de-al doilea sir
        mov ebx, [esp + 16] ;lungimea celui de-al doilea sir
        mov ecx, [esp + 20] ;lungimea primului sir
        
        jecxz final
        
        cld
        ;adaugam primul sir
    repeta_1:
        
        mov eax, 0
        lodsb ; al caracterul
        push eax
        call verificare_cifra ;verificam daca e cifra zecimala
        cmp eax, 0
        je next_1
        pop eax
        stosb ;punem in rez octetul din al daca e cifra zecimala
        jmp done_1
        next_1:
        pop eax
        done_1:
        loop repeta_1
        
        ;adaugam al doilea sir
        mov esi, edx
        mov ecx, ebx
        jecxz final
        
        cld
    repeta_2:
        
        mov eax, 0
        lodsb ; al caracterul
        push eax
        call verificare_cifra ;verificam daca e cifra zecimala
        cmp eax, 0
        je next_2
        pop eax
        stosb ;punem in rez octetul din al daca e cifra zecimala
        jmp done_2
        next_2:
        pop eax
        done_2:
        loop repeta_2
        
        final:
        ret 4*5
