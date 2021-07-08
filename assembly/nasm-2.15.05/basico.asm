; Executar -> nasm.exe -f elf64 basico.asm
; Comentario assembly

; Onde declaramos as variáveis 
; Variavel e endereço de memória

section .data:
    msg db 'Hello World', 0xa
    ; Tamaho da variável
    len equ $ - msg

section .text:

global _start

_start:
    mov edx, len
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    ;Endereço do Kernel (Pedi para o kernel executar) - https://en.wikipedia.org/wiki/Interrupt_vector_table
    int 0x80
; Saida
    mov eax, 1
    mov ebx, 0
    int 0x80
