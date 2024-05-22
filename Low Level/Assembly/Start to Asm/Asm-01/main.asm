;; ################################
;; # Exit -> "Exit Code = 0"
;; ################################

;; Linux x86_64 System Call Reference Table:
;; https://hackeradam.com/x86-64-linux-syscalls/

;; System V AMD64 ABI:
;; https://hackeradam.com/x86-64-calling-conventions/

global _start

section .text
_start:
	mov rax, 60     ;; SYS_EXIT = 60
	mov rdi, 0      ;; EXIT_CODE = 0
	syscall         ;; Inicia a Interrupção
	ret             ;; Fim da "Função"
