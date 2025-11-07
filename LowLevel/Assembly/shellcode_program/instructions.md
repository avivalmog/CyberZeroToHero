```bash
# assemble
nasm -f elf32 shellcode.asm -o shellcode.o
# check file type
file shellcode.o
"shellcode.o: ELF 32-bit LSB relocatable, Intel 80386, version 1 (SYSV), not stripped"
# link
ld -m elf_i386 shellcode.o -o shellcode
# execute
./shellcode
id
exit
# chown
sudo chown root shellcode
# chmod 
sudo chmod +s shellcode
# check 
ls -la
# execute
./shellcode
id
exit
```