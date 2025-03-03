bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B 
    ;in ordine inversa urmate de elementele in ordine inversa ale lui A
    a db 2, 1, -3, 0
    L1 equ $-a
    b db 4, 5, 7, 6, 2, 1
    L2 equ $-b
    r times L1+L2 db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;a[i] ->r[L1-i]
        mov ecx,L1
        jecxz final
        mov esi,0
        mov edi,L1
        repeta1:
            mov al,[a+esi]
            mov [r+edi],al
            dec edi 
            inc esi
        loop repeta1
        ;b[i] -> r[L1+L2-i]
        mov ecx,L2
        jecxz final
        mov esi,0
        add edi,L1
        add edi,L2
        repeta2:
            mov al,[b+esi]
            mov [r+edi],al
            dec edi
            inc esi
        loop repeta2
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
