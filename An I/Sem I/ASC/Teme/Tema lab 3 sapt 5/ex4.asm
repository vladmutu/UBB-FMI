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
    a db 10
    b dw 3
    c dd 1
    d dq 16
; our code starts here
segment code use32 class=code
    start:
        ;24
        ;(a+b+c)-d+(b-c)=(4+3+1)-16+(3-1)=-6
        ; ...
        mov al,[a]
        cbw
        add ax,[b]
        cwde
        add eax,[c];eax=(a+b+c)
        push eax
        mov eax,dword [d]
        mov edx,dword [d+4]
        mov ebx,eax
        mov ecx,edx ;ecx:ebx=d
        pop eax
        cdq ;edx:eax=(a+b+c)
        sub eax,ebx
        sbb edx,ecx ;edx:eax=(a+b+c)-d
        push eax
        push edx
        mov ax,[b]
        cwde
        sub eax,[c]
        mov ebx,eax
        pop edx
        pop eax
        add eax,ebx
        adc edx,0;edx:eax=(a+b+c)-d+(b-c)
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
