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
    b db 2
    c dw 1
    e dd 6
    x dq 3
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;(a-b+c*128)/(a+b)+e-x; a,b-byte; c-word; e-doubleword; x-qword
        ;(4-2+1*128)/(4+2)+6-3=24 rest 4
        ;fara semn
        mov al, [a] ;al=a
        mov dl, [b] ;dl=b
        sub al,dl ;al=a-b
        cbw
        push ax
        ;stiva
        ;ax
        mov al, [c]
        mov dh,128
        mul dh ;ax=c*128
        push ax
        pop bx;bx=c*128
        pop ax ;ax=a-b
        add ax,bx;ax=a-b+c*128
        mov bl,[a]
        mov cl,[b]
        add bl,cl
        div bl
        push ax;ax={ah=(a-b+c*128)%(a+b),al=(a-b+c*128)/(a+b)}
        ;stiva
        ;ax
        mov eax,[e]
        cdq ;edx:eax=e
        mov ebx, dword [x]
        mov ecx, dword [x+4] ;ecx:ebx=x
        sub eax,ebx
        sbb edx,ecx ;edx:eax=e-x
        pop bx
        push eax
        push edx
        ;stiva
        ;edx
        ;eax
        mov ax,bx;ax={ah=(a-b+c*128)%(a+b),al=(a-b+c*128)/(a+b)}
        mov dh,ah
        cbw
        cwde
        pop ecx
        pop ebx
        add eax,ebx
        mov bh,dh
        adc edx,ecx
        ;edx:eax=(a-b+c*128)/(a+b)+e-x , bh=(a-b+c*128)%(a+b)
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
