# create shellcode hello.asm
```as
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
```
# generate opcodes
nasm hello.asm

# write the hex into a file (replace the hex with your string)
```bash
xxd -ps hello

printf '4831c048bb48656c6c6f0a000053b801000000bf010000004889e6ba060000000f054883c408c3' > payload.hex

printf '4831c048bb48656c6c6f0a000053b801000000bf010000004889e6ba060000000f054883c408c3' > payload.hex
```

# convert hex to raw bytes
xxd -r -p payload.hex > payload.bin

# show a canonical hexdump to verify
hexdump -C payload.bin

# generate shellcode
```bash
python3 hex2c.py payload.hex

# example output
python3 hex2c.py payload.hex
"\x48\x31\xc0\x48\xbb\x48\x65\x6c\x6c\x6f\x0a\x00\x00\x53\xb8\x01"
  "\x00\x00\x00\xbf\x01\x00\x00\x00\x48\x89\xe6\xba\x06\x00\x00\x00"
  "\x0f\x05\x48\x83\xc4\x08\xc3"
```
# copy shellcode into shellcoderun_withmmap.c

# compile with new shellcode
gcc -Wall shellcoderun_withmmap.c -o shellcoderun_withmmap

# run program to execute new shellcode
./shellcoderun_withmmap
Hello
