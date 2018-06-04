GLOBAL sysCallHandler
EXTERN syscaller

sysCallHandler:
  push rbx
  push rcx
  push rdx
  push rdi
  push rsi
  push rbp
  push r9
  push r10
  push r11
  push r12
  push r13
  push r14
  push r15
  call syscaller
  pop r15
  pop r14
  pop r13
  pop r12
  pop r11
  pop r10
  pop r9
  pop rbp
  pop rsi
  pop rdi
  pop rdx
  pop rcx
  pop rbx

  iretq
