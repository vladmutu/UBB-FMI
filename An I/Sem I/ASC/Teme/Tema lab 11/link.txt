nasm -fobj main.asm
nasm -fobj concatenare.asm
nasm -fobj afisare.asm
nasm -fobj verificare_cifra.asm
alink main.obj concatenare.obj afisare.obj verificare_cifra.obj -oPE -subsys console -entry start