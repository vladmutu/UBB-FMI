bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, scanf, fopen, fprintf, fclose             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nume_fisier db "AdivB.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    
    message_1 db "cat = ", 0
    message_2 db "rest = ", 0
    
    a dd 0
    b dd 0
    cat dd 0
    r dd 0
    
    endl db 13, 10 ,0
    
    format_1 db "%d", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword a
        push dword format_1
        call [scanf]
        add esp, 4*2
        
        push dword b
        push dword format_1
        call [scanf]
        add esp, 4*2
        
        mov edx, 0
        mov eax, [a]
        mov ebx, [b]
        cmp ebx, 0
        je final
        
        push eax
        add eax, '0'
        
        mov [nume_fisier], eax
        
        pop eax
        
        mov byte [nume_fisier+1], 'd'
        mov byte [nume_fisier+2], 'i'
        mov byte [nume_fisier+3], 'v'
        
        push ebx
        add ebx, '0'
        
        mov [nume_fisier+4], ebx
        
        pop ebx
        
        div ebx
        
        mov [cat], eax
        mov [r], edx
        
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptor_fisier], eax
        
        cmp eax, 0 
        je final
        
        push dword message_1
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*2
        
        push dword [cat]
        push dword format_1
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*3
        
        push dword endl
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*2
        
        push dword message_2
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*2
        
        push dword [r]
        push dword format_1
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*3
        
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
