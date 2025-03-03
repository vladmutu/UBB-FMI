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
    b dw 4
    c dd 5
    d dq 7
; our code starts here
segment code use32 class=code
    start:
        ;((a+b)+(a+c)+(b+c))-d=((3+4)+(3+5)+(4+5))-7=17
        ;24
        ; ...
        mov al,[a]
        cbw ;ax=a
        add ax,[b];ax=a+b
        push ax
        ;stiva:
        ;ax
        mov al,[a]
        cbw
        cwde;eax=a
        mov edx,0;edx:eax=a
        add eax,[c]
        adc edx,0;edx:eax=a+c
        push eax
        push edx
        ;stiva:
        ;edx
        ;eax
        ;ax
        mov ax, [b]
        cwde;eax=b
        mov edx,0
        add eax,[c]
        adc edx,0;edx;eax=b+c
        pop ecx
        pop ebx ;ecx:ebx=a+c
        add eax,ebx
        adc edx,ecx;edx:eax=(b+c)+(a+c)
        mov ebx,eax
        mov ecx,edx ;ecx:ebx=(b+c)+(a+c)
        pop ax;ax=a+b
        cwde ;eax=(a+b)
        mov edx,0
        add eax,ebx
        adc edx,ecx;edx:eax=(a+b)+(b+c)+(a+c)
        mov ebx, dword [d]
        mov ecx, dword [d+4]
        sub eax,ebx
        sbb edx,ecx;edx:eax=((a+b)+(b+c)+(a+c))-d
        ;17=11
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
