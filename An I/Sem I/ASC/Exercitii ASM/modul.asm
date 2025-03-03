bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
extern a   



; our code starts here
segment code use32 class=code
    global modul
    modul:
        ; ...
        mov eax, [a]
        ret