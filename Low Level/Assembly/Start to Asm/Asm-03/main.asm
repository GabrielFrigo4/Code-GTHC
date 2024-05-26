;; ################################
;; # Write -> "$ Hello World!"
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

global _start

section .data
msg: db "Hello World!", 10, 0
msgLen: equ $ - msg

section .text
_start:
	mov rax, 1      ;; SYS_WRITE = 1
	mov rdi, 1      ;; STDOUT = 1
	mov rsi, msg    ;; buf = msg
	mov rdx, msgLen ;; count = msgLen
	syscall         ;; Inicia a Interrupção

	mov rax, 60     ;; SYS_EXIT = 60
	mov rdi, 0      ;; EXIT_CODE = 0
	syscall         ;; Inicia a Interrupção
	ret             ;; Fim da "Função"
