global syscall

section .text

syscall:
  push ebp
  mov ebp, esp
  int 80h
  mov esp, ebp
  pop ebp
  ret
