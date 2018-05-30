GLOBAL sysCallHandler
EXTERN syscaller

sysCallHandler:

  ;pusheo todo salvo rax ya que este tendra un cambio en el retorno de syscaller
;  push rax
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
;  pop rax
  iretq ;fin de interrupcion. no corria por el q que dice que la int es de 64 bits
