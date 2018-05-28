GLOBAL getHour
GLOBAL getMin
GLOBAL getSec
section .text

getTime:
	out 70h, al
	in al, 71h
	ret

getHour:
    push rbp
    mov rbp, rsp
    call configStatusRegisterB
    mov rax, 0h
    mov al, 4h
    call getTime
    mov rsp, rbp
    pop rbp
    ret

getMin:
	push rbp
  	mov rbp, rsp
  	call configStatusRegisterB
	mov rax, 0h
    mov al, 2h
	call getTime
	mov rsp, rbp
	pop rbp
	ret

getSec:
 	push rbp
  	mov rbp, rsp
  	call configStatusRegisterB
	mov rax, 0h
	call getTime
	mov rsp, rbp
  	pop rbp
	ret

configStatusRegisterB:
	push rbp
  	mov rbp, rsp
	mov al,0x0B ; RTC Status Register B
	out 70h,al
	in al, 71h
	or al, 0x04 ; Second bit = 1
	out 71h, al
	mov rsp, rbp
  	pop rbp
	ret
