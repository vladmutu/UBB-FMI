bits 32
    

segment code use32 class=code
    global vocale
    vocale:
        ; ...
        mov ecx, [esp+4]
        mov esi, [esp+8]
        mov ebx, 0
        jecxz final
        
        repeta_2:
        cld
        lodsd
        clc
        shl eax, 16
        shr eax, 24
        cmp eax, 'a'
        je gasit
        cmp eax, 'e'
        je gasit
        cmp eax, 'i'
        je gasit
        cmp eax, 'o'
        je gasit
        cmp eax, 'u'
        je gasit
        
        cmp eax, 'A'
        je gasit
        cmp eax, 'E'
        je gasit
        cmp eax, 'I'
        je gasit
        cmp eax, 'O'
        je gasit
        cmp eax, 'U'
        je gasit
        
        jmp nu_am_gasit
        
        gasit:
        
        add ebx, 1
        
        nu_am_gasit:
        
        loop repeta_2
        mov eax, ebx
        final:
        ret 4*2
