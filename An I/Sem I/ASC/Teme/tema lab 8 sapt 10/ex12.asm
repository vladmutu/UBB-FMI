bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    n dd 0
    message_1 db "n=", 0
    message_2 db "a=", 0
    message_3 db "(baza 10)", 0
    message_4 db "(baza 16)", 0
    format_1 db "%d", 0
    format_2 db "%x", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;afisam n=
        push dword message_1
        call [printf]
        add esp, 4*1
        
        ;citim numarul n negativ
        push dword n
        push dword format_1
        call [scanf]
        add esp, 4*2
        
        mov eax, [n]
        mov ebx, eax
        ;baza 10
        push dword message_2
        call [printf]
        add esp, 4*1
        
        mov eax, ebx
        push dword eax
        push dword format_1
        call [printf]
        add esp, 4*2
        
        push dword message_3
        call [printf]
        add esp, 4*1
        
        ;baza 16
        push dword message_2
        call [printf]
        add esp, 4*1
        
        mov eax, ebx
        push dword eax
        push dword format_2
        call [printf]
        add esp, 4*2
        
        push dword message_4
        call [printf]
        add esp, 4*1
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
