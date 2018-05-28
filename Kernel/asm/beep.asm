GLOBAL beep

SECTION .text

global _start


beep:
mov ecx,5                   ; Loop
loop:
xor eax,eax
xor ebx,ebx
xor ecx,ecx
xor edx,edx


mov eax, 0x7c837aa7 ;address of Beep
mov bx, 750         ;Frequency
mov dx, 50     ;Duration
push ebx
push edx
call eax     ;Call Beep
