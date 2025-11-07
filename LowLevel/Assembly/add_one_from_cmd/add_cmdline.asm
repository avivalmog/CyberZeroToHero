; this program gets and argument from the command line and add 1 to it and prints the result

section .data
    newline db 0xA

section .bss
    buf resb 12    ; buffer for int2str

section .text
    global _start

_start:
    ; Check argc
    mov eax, [esp]     ; argc
    cmp eax, 2
    jl exit_error

    mov esi, [esp+8]   ; argv[1]
    cmp esi, 0
    je exit_error

    ; Convert string to integer
    push esi
    call str2int       ; returns number in EAX
    add esp, 4

    ; Call add_one
    push eax
    call add_one
    add esp, 4         ; eax = result

    ; Convert number to string
    mov ebx, eax       ; number to convert
    lea edi, [buf+11]  ; pointer to end of buffer
    call int2str       ; returns ECX=start, EDX=length

    ; Print string
    mov eax, 4
    mov ebx, 1
    int 0x80

    ; Print newline
    mov eax, 4
    mov ebx, 1
    lea ecx, [newline]
    mov edx, 1
    int 0x80

    ; Exit
    mov eax, 1
    xor ebx, ebx
    int 0x80

exit_error:
    mov eax, 1
    mov ebx, 1
    int 0x80

; -------------------------------
; add_one: int add_one(int x)
; -------------------------------
add_one:
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]
    add eax, 1
    pop ebp
    ret

; -------------------------------
; str2int: convert string to integer
; -------------------------------
str2int:
    push ebp
    mov ebp, esp
    mov esi, [ebp+8]
    xor eax, eax
.next:
    mov bl, [esi]
    cmp bl, 0
    je .done
    sub bl, '0'
    cmp bl, 9
    ja .done
    imul eax, eax, 10
    add eax, ebx
    inc esi
    jmp .next
.done:
    pop ebp
    ret

; -------------------------------
; int2str: convert EBX to string in buf
; Returns: ECX=start, EDX=length
; -------------------------------
int2str:
    mov eax, ebx       ; number to convert
    lea edi, [buf+11]  ; write digits from end
    mov ecx, 0         ; length counter

    cmp eax, 0
    jne .loop
    mov byte [edi], '0'
    mov ecx, 1
    lea ecx, [edi]     ; start pointer
    mov edx, 1
    ret

.loop:
    xor edx, edx
.next_digit:
    mov edx, 0
    mov edx, eax
    mov ebx, 10
    xor edx, edx
    div ebx            ; eax=quotient, edx=remainder
    add dl, '0'
    dec edi
    mov [edi], dl
    test eax, eax
    jnz .next_digit

    lea ecx, [edi]        ; start of string
    mov eax, [buf+11]     ; end of buffer
    ; compute length
    mov edx, 0
    ; compute length manually
    mov esi, [buf+11]
    sub esi, edi
    mov edx, esi
    ret
