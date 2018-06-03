global syscall

section .text

syscall:
  push rbp
  mov rbp, rsp
  int 0x80
  mov rsp, rbp
  pop rbp
  ret

_div0:
    push rbp
    mov rbp, rsp
    int 0x00
    mov rsp, rbp
    pop rbp
    ret

_invalidOpcode:
    push rbp
    mov rbp, rsp
    int 0x06
    mov rsp, rbp
    pop rbp
    ret
