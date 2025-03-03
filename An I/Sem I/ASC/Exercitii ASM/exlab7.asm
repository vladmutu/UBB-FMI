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
    ;sortare
    sir dd 4, 7, 1, 5, 2, 9, 2
    len equ ($-sir)/4
    dest resd len
; our code starts here
segment code use32 class=code
    start:
        mov ecx, len
        mov edi, dest
        
        repeta1:
            mov eax, -1
            
            push edi
            push ecx
            mov ecx, len
            mov edi, sir
            
            repeta2:
                scasd
                jb continua
                mov eax, [edi - 4]
                mov ebx, edi
                sub ebx, 4
                ;el min e in eax, iar pozitia in ebx
                continua:
            loop repeta2
        
        
            pop ecx
            pop edi
            
            stosd
            mov dword [ebx], -1
            
        loop repeta1
        
        
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        
        
        
        
        
        