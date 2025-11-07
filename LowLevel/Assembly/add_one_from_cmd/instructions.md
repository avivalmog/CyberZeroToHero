# assemble
`nasm -f elf32 add_cmdline.asm -o add_cmdline.o`
# check file type
`file add_cmdline.o - 
add_cmdline.o: ELF 32-bit LSB relocatable, Intel 80386, version 1 (SYSV), not stripped
`
# link
`ld -m elf_i386 add_cmdline.o -o add_cmdline`
# execute
`./add_cmdline <int>`
