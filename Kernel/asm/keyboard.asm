Global getkey
section .text

getkey:
  push rbp
  mov rbp, rsp

  and al, 0h
  in al, 64h

  mov rsp, rbp
  pop rbp

  ret
