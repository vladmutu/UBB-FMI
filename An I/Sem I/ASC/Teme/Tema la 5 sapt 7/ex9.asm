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
    ;Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte diferenta dintre fiecare 2 elemente consecutive din S
    s db 1, 2, 4, 6, 10, 20, 25
    L equ $-s
    d times L-1 db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,L-1 ;bucla se va repeta doar de L-1 ori pentru ca doar atatea diferente se executa si aceasta va fi lungimea sirului d
        mov esi,0
        jecxz final
        repeta:
            mov al,[s+esi+1] 
            mov bl,[s+esi];punem in al valoarea din s din care se va scadea valoarea anterioara din s
            sub al,bl;punem in al diferenta celor doua valori consecutive
            mov [d+esi],al ;punem in sirul d rezultatul
            inc esi 
        loop repeta 
        final:
        ;d[i]=s[i+1]-s[i]
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
