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
    ;Dandu-se un sir de cuvinte sa se obtina sirul (de octeti) cifrelor in baza zece ale fiecarui cuvant din acest sir
    sir dw 12345, 20778, 4596
    len1 equ ($-sir)/2
    zece dw 10d
    d times len1*8 db 0
    len2 equ $-d
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,len1
        jecxz final
        mov esi,sir
        add esi,len1
        mov ebx,len1
        and ebx,1
        cmp ebx,1
        jne par
            add esi,1
        par:
        mov edi,d
        add edi,len2
        repeta:
        
            std
            lodsw
            cif:
                mov dx,0
                div word[zece]
                push ax
                mov ax,dx
                std
                stosb
                pop ax
                cmp ax,0
                je sf_cif
                
            jmp cif
            
            sf_cif:
            
        
        loop repeta
        
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
