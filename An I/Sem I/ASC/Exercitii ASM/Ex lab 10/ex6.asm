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
    A dd 11223344h, 55667788h, 12345678h
    lenA equ ($-A)/4
    B1 times lenA+1 db 0
    B2 times lenA+1 db 0 
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi, A
        mov edi, B2
        mov ebx, B1
        
        mov ecx, lenA
        jecxz final
        
        cld
        
        repeta:
            lodsd
            push eax
            and eax, 11111111b
            stosb
            pop eax
            push ebx
            push edi
            mov edi, ebx
            shr eax, 24
            stosb
            pop edi
            pop ebx
            inc ebx
            loop repeta
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
