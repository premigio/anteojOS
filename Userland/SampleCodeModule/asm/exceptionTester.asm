GLOBAL invalidOpcodeException
GLOBAL zeroDivisionException

section .text

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

invalidOpcodeException:
  pushState
  ;ud2 ; ud genera invalidOpcode exceptions. uso el de tipo 2 que no tiene operandos
  RSM
  popState
  ret

zeroDivisionException:
  pushState
  mov rax,0
  mov rbx,0
  div rbx
  popState
  ret
