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
    a db 4
    b dw 3
    c dd 5
    d dq 7
; our code starts here
segment code use32 class=code
    start:
        ;9
        ;(d+d-b)+(c-a)+d=(7+7-3)+(5-4)=12
        ; ...
        mov eax, dword [d]
        mov edx, dword [d+4] ;edx:eax=d
        
        mov ebx, dword [d]
        mov ecx, dword [d+4] ;ecx:ebx=d
        
        clc
        add eax,ebx
        adc edx,ecx ;edx:eax=d+d
        
        mov ecx, edx
        mov ebx, eax ;ecx:ebx=d+d
        
        mov ax, [b]
       
        cwde
        sub ebx,eax ; ecx:ebx=d+d-b
        
        mov eax, [c]
        
        push ebx
        push ecx
        
        mov ebx, eax ;ebx=c
        mov al,[a]
        
        cbw
        cwde
        sub ebx,eax ;ebx=c-a
        
        pop edx
        pop eax ;edx:eax=(d+d-b)
        
        add eax,ebx 
        adc edx,0  ;edx:eax=(d+d-b)+(c-a)
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
