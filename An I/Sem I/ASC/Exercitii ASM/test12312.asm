bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf
extern vocale              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s1 dq 2222111133334444h,6666555577778888h
    len equ ($-s1)/8
    s2 times 100 dd 0
    len2 dd 0
    format db "%d", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx, len
        jecxz final
        mov esi, s1
        mov edi, s2
        
        repeta:
        
            cld
            add esi, 4
            lodsd
            push eax
            push eax
            clc
            shl eax, 16
            clc
            shr eax, 16
            mov ebx, eax
            pop eax
            clc
            shr eax, 16
            
            cmp eax, ebx
            
            jle not_ok
            pop eax
            stosd
            add dword [len2], 1
            jmp next
            not_ok:
            pop eax
            next:
        loop repeta
        
        push ebx
        
        push dword s2
        push dword [len2]
        call vocale
        
        pop ebx
        
        push eax
        push dword format
        call [printf]
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
