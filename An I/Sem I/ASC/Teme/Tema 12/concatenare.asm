bits 32 ; assembling for the 32 bits architecture

extern _printf

; declare the EntryPoint (a label defining the very first instruction of the program)
global _start

; declare external functions needed by our program

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 'a', 'b', 'c', '1', 'd', '2'
    lena dd $-a
    b db 'e', 'f', '3', '4', 'g', '5', 'h'
    lenb dd $-b
    rez times 100 db 0
    format_endl dd 10, 13, 0
    format_caracter db "%c ", 0
; our code starts here
segment code use32 class=code
    _start:
        ; ...
        push ebp
        mov ebp, esp
        sub esp, 132
        pushad
        ;esi -> offset-ul sirului la care se va concatena cel de-al doilea sir
        ;edi -> offset-ul sirului care va fi concatenat
        
        mov esi, a
        mov edi, rez
        
        mov ecx, [lena]
        mov edx, 0
        jecxz final_1
        
    ;concatenarea primului sir in rezultat 
    repeta_1:
        
        cld
        lodsb
        cmp al, '9'
        ja next
        cmp al, '0'
        jb next
        stosb
        inc edx
        next:
        
        loop repeta_1
        
        final_1:
        
        mov esi, b
        mov ecx, [lenb]
        
        jecxz final_2
    
    ;concatenarea celui de-al doilea sir in rezultat
    repeta_2:
        
        cld
        lodsb
        cmp al, '9'
        ja next_2
        cmp al, '0'
        jb next_2
        stosb
        inc edx
        next_2:
        
        loop repeta_2
        
        final_2:
        
        mov ecx, edx
        mov esi, rez
        
        jecxz final_3
        push edx
    ;afisare a+b
    repeta_3:
        
        cld
        push ecx
        mov eax, 0
        lodsb
        push eax
        push dword format_caracter
        call _printf
        add esp, 4*2
        
        pop ecx
        loop repeta_3
        
        final_3:
        
        push dword format_endl
        call _printf
        add esp, 4
        
        mov esi, b
        mov edi, rez
        
        mov ecx, [lenb]
        
        jecxz final_4
    ;concatenarea celui de-al doilea sir in rezultat
    repeta_4:
        
        cld
        lodsb
        cmp al, '9'
        ja next_3
        cmp al, '0'
        jb next_3
        stosb
        next_3:
        
        loop repeta_4
        
        final_4:
    
        mov esi, a
        mov ecx, [lena]
        
        jecxz final_5
        
    ;concatenarea primului sir in rezultat    
    repeta_5:
    
        cld
        lodsb
        cmp al, '9'
        ja next_4
        cmp al, '0'
        jb next_4
        stosb
        next_4:
        
        loop repeta_5
        
        final_5:
        
        mov esi, rez
        pop edx
        mov ecx, edx
        
        jecxz final_6
        
    repeta_6:
    
        cld
        push ecx
        mov eax, 0
        lodsb
        push eax
        push dword format_caracter
        call _printf
        add esp, 4*2
        
        pop ecx
        
        loop repeta_6
        
        final_6:
        
        
        
        popad
        add esp, 132
        mov esp, ebp
        pop ebp
        
        ret