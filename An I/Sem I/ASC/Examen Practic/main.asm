bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,printf,fopen,fread,fclose               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nume_fisier db 0
    descriptor_fisier dd 0
    n dd 0 
    message_1 db "Introduceti numarul n: ", 0
    message_2 db "Introduceti numele fisierului: ", 0
    format_1 db "%d", 0
    format_2 db "%s", 0
    mod_acces db "r", 0
    sir resb 100
    dimensiune dd 1
    count dd 100
    lungime_sir db 0
    masca dd 01h
    dif equ 0
    spatiu db ' '
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword message_1
        call [printf]
        add esp, 4
        
        push dword n
        push dword format_1
        call [scanf]
        add esp, 4*2
        
        push dword message_2
        call [printf]
        add esp, 4
        
        push dword nume_fisier
        push dword format_2
        call [scanf]
        add esp, 4*2
        
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        
        mov [descriptor_fisier], eax
        
        push dword [descriptor_fisier]
        push dword [count]
        push dword [dimensiune]
        push dword sir
        call [fread]
        add esp, 4*4
        
        mov [lungime_sir], eax
        
        mov esi, sir
        cld
        mov ecx, [lungime_sir]
        jecxz final
        mov ebx, 0
        repeta:
            
            lodsb
            cmp al, ' '
            je gata
            cmp al, '0'
            jb urm
            cmp al, '9'
            ja urm
            inc ebx
            
            jmp urm
            
            gata: 
            mov dl, [esi-2]
            and dl, [masca]
            cmp dl, 0
            jne urm
            cmp ebx, [n] 
            je afisare
            jmp urm
            afisare:
            
            push ecx
            mov ecx,ebx
            
            repeta2:
            
                add ecx, 1
                mov [dif], ecx
                sub ecx, 1 
                push dword [esi-dif]
                push dword format_1
                call [printf]
                add esp, 4*2
            
            loop repeta
            pop ecx
            mov ebx, 0
            push dword spatiu
            call [printf]
            add esp, 4
            
            urm:
        loop repeta
        
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
