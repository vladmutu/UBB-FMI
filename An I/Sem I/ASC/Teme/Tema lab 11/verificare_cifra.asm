bits 32 ; assembling for the 32 bits architecture

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    global verificare_cifra
    verificare_cifra:
        ; ...
        sub eax, '0'
        cmp eax, 10
        jnl nu_e
        cmp eax, 0
        jng nu_e
        jmp e
        nu_e:
        mov eax, 0
        jmp final
        e:
        mov eax, 1
        final:
        ret