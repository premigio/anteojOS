Global getKey
section .text

getKey:
    push rbp
    mov rbp,rsp
    mov rax,0h
    in al,60h
;    movzx rax, al ;??? quien lo hizo?? preguntar
    mov rsp,rbp
    pop rbp
    ret
