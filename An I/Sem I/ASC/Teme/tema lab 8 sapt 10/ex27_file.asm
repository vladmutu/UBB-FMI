bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fread,fclose,printf,fprintf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fprintf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nume_fisier db "input_2.txt", 0
    mod_acces db "a+", 0
    descriptor_fisier dd 0
    
    sir resb 50
    lungime_sir dd 0
    dimensiune dd 1
    count dd 100
    
    zece dd 10
    
    nr_min dd 7fffffffh
    format db ", %d", 0
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
        
        ;int fread(void * str, int size, int count, FILE * stream)
        push dword [descriptor_fisier]
        push dword [count]
        push dword [dimensiune]
        push dword sir
        call [fread]
        add esp, 4*4
        
        mov [lungime_sir], eax
        
        mov esi, sir
        mov ecx, [lungime_sir]
        cld
        mov eax, 0
        repeta:
            push ecx
            push eax
            lodsb ;al
            mov bl, al
            cmp al, ' '
            
            je next
                pop eax
                mul dword [zece]
                sub bl, '0'
                add al, bl
                jmp urm
            next:
                pop eax
                cmp eax, [nr_min]
                    jge salt 
                        mov [nr_min], eax
                    salt:
                mov eax, 0
            urm:
            pop ecx
            loop repeta
        sub esi, 1
        mov eax, 0
        lodsb
        sub al, '0'
        cmp eax, [nr_min]
        jge salt_1
            mov [nr_min], eax
        salt_1:
        
        ;int fprintf(FILE * stream, const char * format, <variabila_1>, <constanta_2>, <...>)
        mov ebx, [nr_min]
        push dword ebx
        push dword format
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*3
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
