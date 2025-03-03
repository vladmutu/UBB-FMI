bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global _esteCifra       

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
; our code starts here
segment code use32 class=code
    _esteCifra:
        ; ...
        
        push ebp 
        mov ebp, esp
        
        mov eax, [ebp+8]
        cmp eax, '9'
        ja gresit
        cmp eax, '0'
        jb gresit
        
        mov eax, 1
        jmp gata
        
        gresit:
        mov eax, 0
        
        gata:
        
        mov esp ,ebp
        pop ebp
        ret 