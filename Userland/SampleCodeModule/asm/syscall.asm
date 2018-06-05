global syscall

section .text

syscall:
  push rbp
  mov rbp, rsp
  int 0x80
  mov rsp, rbp
  pop rbp
  ret
