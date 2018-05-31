GLOBAL beepon
GLOBAL beepoff

section .text
  
beepon:
    mov al, 182
    out 0x43,al
    mov ax, 1193
    out 0x42,al
    mov al,ah
    out 0x42, al
    in al, 0x61
    mov al, 0x03
    out 0x61,al
    ret

beepoff:
    in al, 0x61
    mov al, 0x00
    out 0x61, al
    ret
