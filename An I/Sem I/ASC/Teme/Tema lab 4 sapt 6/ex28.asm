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
    a dq 9fffffffffffffffh
    N resb 1
    B resw 2
    C resb 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, [a]
        mov edx, [a+4];edx:eax=a
        mov ecx,edx;ecx=9fffffffh
        and ecx, 000E0000h;folosim masca pentru a avea in ecx doar bitii 17-19 care se afla pentru qword a in registrul ecx:000e0000h
        shr ecx, 17;ecx=00000007h
        mov [N], cl ; in N avem rezultatul 07h
        rol edx,cl ;edx=ffffffcfh
        mov [B],dx
        and edx,11111111111111110000000000000000b
        shr edx,16
        mov [B+2],dx;B=edx=ffffffcfh
        mov ecx,[B];ecx=ffffffcfh
        and ecx,00000E00h;ecx=00000e00h
        shr ecx,9;ecx=00000007h
        mov edx,[B];edx=ffffffcfh
        and edx,001F0000h;edx=001f0000h
        shr edx,16;edx=0000001fh
        shl edx,3;edx=000000f8h
        add edx,ecx;edx=000000ffh
        mov [C],dl;[C]=0000000fh
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
