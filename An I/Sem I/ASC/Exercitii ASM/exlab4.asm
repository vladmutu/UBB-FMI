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
    a dw 2
    b db -3
    c dd -4
    x dq 5
  ;(a*a+b+x)/(b+b)+c*c  
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ax,[a]
        imul word [a]; rezultatul e in dx:ax
        push dx
        push ax
        pop ebx ; ebx=a*a=4
        mov al, [b]
        cbw; ax=b
        cwde ;eax=b
        add eax,ebx ;eax=a*a+b=1
        cdq
        mov ebx, [x]
        mov ecx, [x+4] ;edx:ebx=x=5
        clc
        add eax,ebx
        adc edx,ecx
        push eax
        mov al, [b]
        add al, [b]
        cbw
        cwde
        mov ebx,eax
        pop eax
        idiv ebx ;eax =(a*a+b+x)/(b+b)
        cdq ;edx:eax=(a*a+b+x)/(b+b)
        mov ebx,eax
        mov ecx,edx ;ecx:ebx=(a*a+b+x)/(b+b)
        mov eax,[c]
        imul dword [c]; edx:eax=c*c
        add eax,ebx
        adc edx,ecx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
