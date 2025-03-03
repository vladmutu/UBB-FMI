bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf              ; tell nasm that exit exists even if we won't be defining it
extern concatenare
extern afisare
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 'a', 'b', 'c', '1', 'd', '2'
    lena dd $-a
    b db 'e', 'f', '3', '4', 'g', '5', 'h'
    lenb dd $-b
    rez times 100 db 0
    format_endl dd 10, 13, 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;esi -> offset-ul sirului la care se va concatena cel de-al doilea sir
        ;edi -> offset-ul sirului care va fi concatenat
        mov esi, a
        mov edi, b
        push dword [lena]
        push dword [lenb]   
        push edi
        push esi
        push dword rez
        call concatenare
        
        mov eax, [lena]
        add eax, [lenb]
        
        push dword rez
        push eax
        call afisare
        
        push dword format_endl
        call [printf]
        add esp, 4
        
        mov edi, a
        mov esi, b
        
        push dword [lenb]
        push dword [lena]   
        push edi
        push esi
        push dword rez
        call concatenare
        
        mov eax, [lena]
        add eax, [lenb]
        
        push dword rez
        push eax
        call afisare
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
