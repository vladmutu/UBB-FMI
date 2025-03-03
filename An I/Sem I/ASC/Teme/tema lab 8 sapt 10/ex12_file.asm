bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fread,fclose,printf,scanf,fprintf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nume_fisier db "input_1.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd 0
    
    val dd 0
    format_1 db "%d",0
    format_2 db "%c ",0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;FILE * fopen(const char* nume_fisier,const char* mod_acces)
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        
        mov [descriptor_fisier], eax
        
        
        repeta:
            ;citim valorile una cate una
            push dword val
            push dword format_1
            call [scanf]
            add esp, 4*2
            
            mov eax, [val]
            cmp eax, 0
            je iesire
            
            ;int fprintf(FILE * stream, const char * format, <variabila_1>, <constanta_2>, <...>)
            mov ebx, [val]
            add ebx, '0'
            push dword ebx
            push dword format_2
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 4*3
            
            jmp repeta
            
        iesire:
        
        ;int fclose(FILE * descriptor)
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4*1
            
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
