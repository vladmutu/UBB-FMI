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
    a db 2
    b db 4
    c dw 1
    e dd 1
    x dq 26
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;(a-b+c*128)/(a+b)+e-x; a,b-byte; c-word; e-doubleword; x-qword
        ;(2-4+1*128)/(4+2)+1-26=-4
        ;cu semn
        mov eax,0
        mov al, [a] ;al=a
        mov dl, [b] ;dl=b
        sub al,dl ;al=a-b
        cbw;ax=a-b
        push ax;
        ;stiva
        ;ax
        mov ax,[c]
        mov bx, 128
        imul bx
        pop bx
        ;stiva
        ;
        add ax,bx;ax=a-b+c*128
        
        push ax
        ;stiva
        ;ax
        
        mov al,[a]
        mov bl,[b]
        add al,bl;al=a+b
        
        mov dl,al;dl=a+b
        
        pop ax;a=a-b+c*128
        idiv dl ; 
        push ax;ax={ah=(a-b+c*128)%(a+b),al=(a-b+c*128)/(a+b)}
        ;stiva
        ;ax={ah=(a-b+c*128)%(a+b),al=(a-b+c*128)/(a+b)}
        mov eax,[e]
        cdq ;edx:eax=e
        mov ebx, dword [x]
        mov ecx, dword [x+4] ;ecx:ebx=x
        sub eax,ebx
        sbb edx,ecx ;edx:eax=e-x
        pop bx;bx={ah=(a-b+c*128)%(a+b),al=(a-b+c*128)/(a+b)}
        push eax
        push edx
        ;stiva
        ;edx
        ;eax e-x
        mov ax,bx;ax={ah=(a-b+c*128)%(a+b),al=(a-b+c*128)/(a+b)}
        mov dh,ah
        cbw
        cwde
        pop ecx
        pop ebx
        add eax,ebx
        mov bh,dh
        mov edx,0
        adc edx,ecx
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
