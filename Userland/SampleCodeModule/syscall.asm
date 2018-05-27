global syscall

section .text

syscall:
  enter
  int 80h
  leave
  ret
