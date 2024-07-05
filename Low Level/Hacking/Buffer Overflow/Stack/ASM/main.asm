;; ################################
;; # Buffer on Stack Overflow
;; ################################

;; Linux x86_64 System Call Reference Table:
;; https://hackeradam.com/x86-64-linux-syscalls/

;; System V AMD64 ABI:
;; https://hackeradam.com/x86-64-calling-conventions/

;; File Descriptor
;; https://mentebinaria.gitbook.io/assembly/a-base/ola-mundo-no-linux

;; STDIN = 0
;; STDOUT = 1
;; STDERR = 2

;; ################################
;; # Código Assembly X86-64
;; ################################

;; Deixa o Label _start visível no Header ELF
global _start

;; Variáveis
section .data
msg: db `Write your name:\n\0`
msg_len: equ $ - msg

;; Código
section .text
_start:
	push rbp				;; Salva o Registro RBP (Register Base Pointer)
	mov rbp, rsp			;; Salva o Registro RSP (Register Stack Pointer)
	sub rsp, 0x20			;; Aloca 32 Bytes no Stack

	mov rax, 1				;; SYS_WRITE = 1
	mov rdi, 1				;; fd = STDOUT
	mov rsi, msg			;; buf = msg
	mov rdx, msg_len		;; buflen = msg_len
	syscall					;; Inicia a Interrupção

	mov rax, 0				;; SYS_READ = 0
	mov rdi, 0				;; fd = STDIN
	mov rsi, rsp			;; buf = RSP (Register Stack Pointer)
	mov rdx, 0x200			;; buflen = 0x200
	syscall					;; Inicia a Interrupção

	push rcx				;; Salva o Registro RCX
	lea rcx, [rsi+0x20-1]	;; RCX = 0x20 - 1
	mov byte [rcx], `\n`	;; Muda o Byte RCX Para '\n'
	lea rcx, [rsi+0x40-1]	;; RCX = 0x40 - 1
	mov byte [rcx], `\n`	;; Muda o Byte RCX Para '\n'
	pop rcx					;; Recupera o Registro RCX

	mov rax, 1				;; SYS_WRITE = 1
	mov rdi, 1				;; fd = STDOUT
	mov rsi, rsp			;; buf = msg
	mov rdx, 0x40			;; buflen = msg_len
	syscall					;; Inicia a Interrupção

	mov rax, 60      		;; SYS_EXIT = 60
	mov rdi, 0       		;; EXIT_CODE = 0
	syscall					;; Inicia a Interrupção

	mov rsp, rbp			;; Recupera o Registro RSP (Register Stack Pointer)
	pop rbp					;; Recupera o Registro RBP (Register Base Pointer)
	ret						;; Fim da "Função"
