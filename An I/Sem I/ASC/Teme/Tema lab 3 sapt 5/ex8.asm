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
    a dd 8
    b db 2
    c db 5
    d db 1
    x dq 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;a-(7+x)/(b*b-c/d+2); a-doubleword; b,c,d-byte; x-qword
        ;5-(7+1)/(2*2-(5/1)+2)=-3
        ;cu semn
        mov eax, dword [x]
        mov edx, dword [x+4];edx:eax=x
        push eax
        push edx
        ;stiva
        ;edx
        ;eax
        mov al,[b]
        imul al;ax=b*b
        push ax
        ;stiva
        ;ax
        ;edx
        ;eax
        mov al,[c]
        cbw;ax=c
        mov dh,[d];dh=d
        idiv dh;al=c/d ah=c%d
        cbw;ax=c/d
        mov bl,ah;bl=c%d
        mov cx,ax;cx=c/d
        pop ax;ax=b*b
        ;stiva
        ;edx
        ;eax
        sub ax,cx;ax=b*b-c/d
        add ax,2;ax=b*b-c/d+2
        cwde;eax=b*b-c/d+2
        mov ecx,eax;ecx=b*b-c/d+2
        pop edx
        pop eax;edx:eax=x
        add eax,7
        adc edx,0;edx:eax=7+x
        idiv ecx;eax=(7+x)/(b*b-c/d+2) ,edx=(7+x)%(b*b-c/d+2)
        mov ecx,[a];ecx=a
        sub ecx,eax;ecx=a-(7+x)/(b*b-c/d+2)
        mov eax,ecx;eax=a-(7+x)/(b*b-c/d+2)
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
