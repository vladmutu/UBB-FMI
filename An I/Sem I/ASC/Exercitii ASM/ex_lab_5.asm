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
    s db 1,2,3,4,5,6,7,8
    L equ $-s
    jumatateL equ (L+1)/2
    d times L db 0
    ;Se da un sir de octeti S. Sa se construiasca sirul D astfel: sa se puna mai intai elementele ;de pe pozitiile pare din S iar apoi elementele de pe pozitiile impare din S.
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,L ;punem in ecx lungimea pentru a repeta bucla de ecx=L ori
        mov esi,0
        mov edi,0
        jecxz Sfarsit
        Repeta:
            mov edx,0
            mov eax,esi
            mov ebx,2
            div ebx
            cmp edx,0
            je pozPara
            mov al,[s+esi]
            mov [d+edi+jumatateL],al
            inc edi
            jmp dupa
            pozPara:
            mov al,[s+esi]
            mov [d+edi],al
            dupa:
            inc esi
        loop Repeta
        ; exit(0)
        Sfarsit:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
