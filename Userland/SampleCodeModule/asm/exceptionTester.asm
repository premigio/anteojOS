GLOBAL invalidOpcodeException
GLOBAL zeroDivisionException

section .text

%macro pushState 0
	push r15
	push r14
	push r13
	push r12
	push r11
	push r10
	push r9
	push r8
	push rsi
	push rdi
	push rbp
	push rdx
	push rcx
	push rbx
	push rax
%endmacro

%macro popState 0
	pop rax
	pop rbx
	pop rcx
	pop rdx
	pop rbp
	pop rdi
	pop rsi
	pop r8
	pop r9
	pop r10
	pop r11
	pop r12
	pop r13
	pop r14
	pop r15
%endmacro

invalidOpcodeException:
	push rbp
	mov rbp, rsp
	pushState
  ud2 ; ud genera invalidOpcode exceptions. uso el de tipo 2 que no tiene operandos
  ;RSM
  popState
	mov rsp, rbp
	pop rbp
  ret

zeroDivisionException:
  push rbp
  mov rbp, rsp
  pushState
  mov rax,0
  mov rbx,0
  div rbx
  popState
	mov rsp, rbp
	pop rbp
  ret
