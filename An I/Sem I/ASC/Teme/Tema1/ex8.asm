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
    a db 3
    b db 3
    c db 1
    d dw 6
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov AL, [a]
        mov DH, 10
        mul DH
        mov BX, AX
        mov AL, [b]
        mov DH, 5
        mul DH
        sub BX, AX
        mov AL, [c]
        mov DH, 5
        mul DH
        mov CX, [d]
        sub CX, AX
        add BX, CX
        mov AX, BX
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
