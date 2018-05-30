GLOBAL kernelBeep
section .text

kernelBeep:
  push rbp
  mov rbp, rsp

  mov al, 182
  out 0x43, al
  mov rax, 4560

  out 0x42, al
  mov al, ah
  out 0x42, al
  in al, 61h

  or al, 00000011b
  out 61h, al
  mov bx, 25

  mov rsp, rbp
  pop rbp
  ret
