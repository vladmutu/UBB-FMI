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
    a db 2, 1, 3, 3, 4, 2, 6
    L1 equ $-a
    b db 4, 5, 7, 6, 2, 1
    L2 equ $-b
    r times L1+L2 db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,L2
        jecxz final
        mov esi,0
        mov edi,L2
        repeta1:
            mov al,[b+esi]
            mov [r+edi],al
            dec edi 
            inc esi
        loop repeta1
        mov ecx,L1
        jecxz final
        mov esi,0
        mov edi,L2
        add edi, 1
        repeta2:
            mov al,[a+esi]
            mov bl,al
            and bl,00000001b
            cmp bl, 1
            je next
            mov [r+edi],al
            inc edi
            next:
            inc esi
        loop repeta2
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
