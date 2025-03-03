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
    b dw 1
    c dd 1
    d dq 7
; our code starts here
segment code use32 class=code
    start:
        ;9
        ;a-d+b+b+c=3-7+1+1+1=-1
        ; ...
        mov al, [a]
        cbw
        cwde 
        cdq ;edx:eax=a
        mov ebx,dword [d]
        mov ecx,dword [d+4];ecx:ebx=d
        sub eax,ebx
        sbb edx,ecx;edx:eax a-d
        push eax
        push edx
        mov ax,[b]
        cwde
        add eax,eax;eax=b+b
        cdq ;edx:eax=b+b
        pop ecx
        pop ebx;ecx:ebx=a-d
        add eax,ebx
        adc edx,ecx;edx:eax=a-d+b+b
        mov ebx,eax
        mov ecx,edx;ecx:ebx=a-d+b+b
        mov eax,[c]
        cdq ;edx:eax=c
        add ebx,eax
        adc ecx,edx;ecx:ebx=a-d+b+b+c
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
