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
    ;Se da un sir de cuvinte s. Sa se construiasca sirul de octeti d, astfel incat d sa contina pentru fiecare pozitie din s:
    ;- numarul de biti de 0, daca numarul este negativ
    ;- numarul de biti de 1, daca numarul este pozitiv
    s dw -22, 145, -48, 127
    len equ ($-s)/2
    d times len db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,len
        mov esi,s
        mov edi,d
        cld
        jecxz final
        repeta1:
            lodsw
            mov dx,ax
            and dx,1000000000000000b
            shr dx,15
            cmp dx,1
            jne pozitiv
            not ax
            pozitiv:
                push ecx
                mov ecx,8
                mov dl,0
                repeta2:
                    shr ah,1
                    adc dl,0
                    shr al,1
                    adc dl,0
                loop repeta2
                mov al,dl
                stosb
                pop ecx
        loop repeta1
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
