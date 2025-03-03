bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s dd 01150017h, 1025000bh, 00321025h, 000ba006h, 0014001ah
    len1 equ ($-s)/4
    d1 resw 20
    len2 dd 0
    d2 resw 20
    len3 dd 0
    maxval dw 0
    format db "%d", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi, s
        mov edi, d1
        mov ecx, len1
        jecxz final_1
    ;loop pentru a determina cuvintele high din dublucuvintele din s care sunt prime
    repeta_1:
        cld
        lodsd ;eax avem dublucuvantul
        shr eax, 16; lasam in eax doar cuvantul high
        
        push ecx
        mov ecx, eax
        cmp ecx, 0
        je not_ok
        cmp ecx, 1
        je not_ok
        sub ecx, 1
        
        
    ;loop pentru a verifica daca sunt numere prime
    repeta_2:
        cld
        push eax
        cmp ecx, 1
        je ok
        mov edx, 0
        div ecx
        cmp edx, 0
        je not_ok
        pop eax
        
        loop repeta_2
        
        ok:
        pop eax
        stosw
        add byte [len2], 1
        jmp salt
        not_ok:
        pop eax
        salt:
        pop ecx
        loop repeta_1
        
        final_1:
        
        
        ;cream sirul d2
        mov esi, s
        mov edi, d2
        mov ecx, len1
        jecxz final_2
       
    repeta_3:
        cld
        lodsd
        mov ebx,0
        mov bx,ax; ebx cuvantul low
        shr eax, 16; eax cuvantul high
        push ecx
        push eax
        mov ecx, 5
    repeta_4:
        cld
        cmp eax, 0
        je ok_2
        
        mov dl, al
        shl dl, 4
        shr dl, 4
        cmp dl, 0ah
        jge not_ok_1
        shr eax, 4
        
        loop repeta_4
        
        ok_2:
        pop eax
        stosw
        add byte [len3], 1
        jmp salt_2
        not_ok_1:
        pop eax
        salt_2:
        
        mov eax, ebx
        push eax
        mov ecx, 5
        
    repeta_5:
        cld
        cmp eax, 0
        je ok_3
        
        mov dl, al
        shl dl, 4
        shr dl, 4
        cmp dl, 0ah
        jge not_ok_2
        shr eax, 4
    
        loop repeta_5 
        ok_3:
        pop eax
        stosw
        add byte [len3], 1
        jmp salt_3
        not_ok_2:
        pop eax
        salt_3:
        
        pop ecx
        
        loop repeta_3
        
        final_2:
        
        ;cautam val max din d1
        
        mov esi, d1
        mov ecx, [len2]
        jecxz final_3
        
    repeta_6:
        cld
        lodsw
        cmp ax, [maxval]
        jb not_ok_3
        
        mov [maxval], ax
        
        not_ok_3:
        
        loop repeta_6
        
        final_3:
        
        ;verificam frecventa maxval in d2
        
        mov ebx, 0
        mov esi, d2
        mov ecx, [len3]
        jecxz final_4
        
    repeta_7:
        cld
        lodsw
        cmp ax, [maxval]
        jne next
        inc ebx
        next:
        loop repeta_7
        
        final_4:
        
        
        ; afisam frecventa lui maxval
        
        push ebx
        push dword format
        call [printf]
        add esp, 4*2
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
