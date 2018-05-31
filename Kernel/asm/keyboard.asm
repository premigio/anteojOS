Global getKey
section .text

getKey:
    push rbp
    mov rbp,rsp
    mov rax,0x0
    in al,0x60
    mov rsp,rbp
    pop rbp
    ret
