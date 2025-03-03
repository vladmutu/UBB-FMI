bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    sir dq 1110111b, 100000000h, 0abcd0002e7fch, 5
    len equ ($-sir)/8
    len2 dd 0
    check dd 2
    rez resd 10
    format db "%s", 0
    sol times 100 db 0
    len3 db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi, sir
        mov edi, rez
        mov ecx, len
        jecxz final
    repeta_1:
        cld
        lodsd;eax am dublucuvantul inferior
        push ecx
        push eax
        mov ebx, 0
        mov ecx, 9
        ;verificam de cat ori apare 111b in eax
    repeta_2:
        cld
        cmp eax, 0
        je gata;daca e 0 am terminat cu asta
        mov dl, al
        shl dl, 5
        shr dl, 5
        cmp dl, 7;punem in dl cei 3 biti izolati
        jne not_ok
        add ebx, 1
        shr eax, 3
        jmp salt
        not_ok:
        shr eax, 1
        salt:
        ;eliminam cei mai din dreapta 3 biti deja verificati
        loop repeta_2
        gata:
        pop eax
        cmp ebx, [check]
        jl next
        stosd
        add dword [len2], 1
        next:
        pop ecx
        add esi, 4
        loop repeta_1
        final:
        
        mov ebx, [len2] 
        add ebx, ebx
        add ebx, ebx
        add ebx, ebx
        lea esi, [esi+ebx-4]
        lea edi, [sol+98]
        mov ecx, [len2]
    repeta_3:
        std
        lodsd
        push ecx
        mov ecx, 32
    repeta_4:
        cmp eax, 0
        je gata_1
        shr eax,1
        jc unu
        push eax
        mov al, '0'
        stosb
        add byte[len3], 1
        pop eax
        jmp urm
        unu:
        push eax
        mov al, '1'
        stosb
        add byte[len3], 1
        pop eax
        urm:
        loop repeta_4
        gata_1:
        push eax
        mov al, ' '
        add byte[len3], 1
        stosb
        pop eax
        pop ecx
        loop repeta_3
        movzx cx, byte[len3]
        movzx ecx, cx
        mov ebx, sol
        add ebx, 100
        sub ebx, ecx
        push ebx
        push dword format
        call [printf]
        add esp,4*2
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
