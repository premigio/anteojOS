Global getkey
section .text

getkey:
    push rbp
    mov rbp,rsp
    mov rax,0h
    in al,60h
    movzx rax, al
    mov rsp,rbp
    pop rbp
    ret
