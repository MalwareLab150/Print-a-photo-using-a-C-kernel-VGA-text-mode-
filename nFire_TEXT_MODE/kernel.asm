bits 32
section .text
    align 4
    dd 0x1BADB002       
    dd 0x00             
    dd -(0x1BADB002 + 0x00)

global _start
extern k_main           ; The k_main function is defined in starter.C

_start:
    cli                 
    call k_main        
    hlt                 

section .bss
    ; Data section (optional)

