BITS 64
xor rax, rax
mov rbx, 0x0a6f6c6c6548   ; bytes: 48 65 6c 6c 6f 0a => "Hello\n"
push rbx

; prepare syscall: write(1, rsp, 6)
mov rax, 1        ; sys_write
mov rdi, 1        ; stdout
mov rsi, rsp      ; pointer to string on stack
mov rdx, 6        ; length
syscall

add rsp, 8        ; undo the push
ret               ; return to caller