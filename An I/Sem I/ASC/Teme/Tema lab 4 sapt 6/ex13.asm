bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 112
    b db 112
    c db 112
    d db 112
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;Dandu-se 4 octeti, sa se obtina in AX suma numerelor intregi reprezentate de bitii 4-6 ai celor 4 octeti.
        and ax,0000h;zeroizam registrii
        and bx,0000h;zeroizam registrii
        and cx,0000h;zeroizam registrii
        and dx,0000h;zeroizam registrii
        mov al,[a];al=a
        mov bl,[b];bl=b
        mov cl,[c];cl=c
        mov dl,[d];dl=d
        and al, 01110000b ;utilizam masca pentru a ramane doar cu bitii 4-6 al=01110000b
        and bl, 01110000b ;utilizam masca pentru a ramane doar cu bitii 4-6 bl=01110000b
        and cl, 01110000b ;utilizam masca pentru a ramane doar cu bitii 4-6 cl=01110000b
        and dl, 01110000b ;utilizam masca pentru a ramane doar cu bitii 4-6 dl=01110000b
        shr al,4 ;rotim bitii spre dreapta pentru a obtine numarul intreg format din bitii 4-6 aflati pe primele pozitii al=00000111b
        shr bl,4 ;rotim bitii spre dreapta pentru a obtine numarul intreg format din bitii 4-6 aflati pe primele pozitii bl=00000111b
        shr cl,4 ;rotim bitii spre dreapta pentru a obtine numarul intreg format din bitii 4-6 aflati pe primele pozitii cl=00000111b
        shr dl,4 ;rotim bitii spre dreapta pentru a obtine numarul intreg format din bitii 4-6 aflati pe primele pozitii dl=00000111b
        add ax,bx ;adaugam numerele intregi in ax
        add ax,cx ;adaugam numerele intregi in ax
        add ax,dx ;adaugam numerele intregi in ax
        ;rezultatul se afla in ax = 001Ch
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
