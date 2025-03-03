bits 32 ; assembling for the 32 bits architecture

extern printf
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    format_caracter db "%c ", 0
; our code starts here
segment code use32 class=code
    global afisare
    afisare:
        mov ecx, [esp+4]
        mov esi, [esp+8]
        jecxz final
    repeta:
        
        mov eax, 0
        lodsb
        
        push ecx
        
        push eax
        push dword format_caracter
        call [printf]
        add esp, 4*2
        
        pop ecx
        
        loop repeta
        final:
        ret 2*4
