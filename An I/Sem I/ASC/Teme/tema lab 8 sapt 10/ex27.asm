bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s db "candbaduwa"
    len equ $-s
    c dd 0
    freq dd 0
    message db "Introduceti caracterul: ", 0
    format_1 db "%c", 0
    format_2 db ", %d", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;afisam mesaj
        push dword message
        call [printf]
        add esp, 4*1
        
        ;citim caracterul
        push dword c
        push dword format_1
        call [scanf]
        add esp, 4*2
        
        cld
        mov esi, s
        mov ebx, [c]
        mov edx, 0
        mov ecx, len
        jecxz final
        repeta:
            lodsb
            cmp al, [c]
            jne next
            inc edx
            next:
            loop repeta
            
        mov [freq], edx ; freq = frecventa caracterului citit
        
        ;afisam caracterul
        push dword [c]
        push dword format_1
        call [printf]
        add esp, 4*2
        
        
        ;afisam frecventa caracterului
        push dword [freq]
        push dword format_2
        call [printf]
        add esp, 4*2
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
