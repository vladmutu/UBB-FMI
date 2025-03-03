bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fread,fclose,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;pb4
    ;Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de cifre impare si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.
    nume_fisier db "input.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd 0
    
    dimensiune dd 1
    count dd 100
    
    sir resb 100
    lungime_sir dd 0
    cifra_max dd -1
    
    format db "%d ",0
    
    dest resd 100
    
    zece dd 10
    
; our code starts here
segment code use32 class=code
    start:
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
        jecxz iesireBucla
        
        mov eax, 0
        
        bucla:
            push eax
            lodsb ;al
            mov bl, al
            pop eax
            
            cmp bl, ' '
            je afisareNumar
            
            cmp bl, 0
            je afisareNumar
            
            mul dword [zece]
            sub bl, '0'
            add al, bl
            
            finalBucla:
            loop bucla
        
        jmp iesireBucla
        
        afisareNumar:
        
        push ecx
        
        push eax
        push dword format
        call [printf]
        add esp, 4*2
        
        mov eax, 0
        pop ecx
        jmp finalBucla
        
        iesireBucla:
        
        ;int printf(const char * format, variabila_1, constanta_2, ...);
        
        
        ;int fclose(FILE * descriptor)
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        
        
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
