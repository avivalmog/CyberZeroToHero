// run_shellcode.c  (compile with: gcc -Wall run_shellcode.c -o run_shellcode)
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

unsigned char shellcode[] =
  "\x48\x31\xc0\x48\xbb\x48\x65\x6c\x6c\x6f\x0a\x00\x00\x53\xb8\x01"
  "\x00\x00\x00\xbf\x01\x00\x00\x00\x48\x89\xe6\xba\x06\x00\x00\x00"
  "\x0f\x05\x48\x83\xc4\x08\xc3";
  

int main(void) {
    size_t len = sizeof(shellcode) - 1; // exclude trailing '\0' if present

    // allocate RWX memory
    void *mem = mmap(NULL, len, PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    memcpy(mem, shellcode, len);

    // ensure instruction cache coherence on some architectures if needed
    // (x86/x86_64 generally don't need explicit cache flush here)

    // call it
    ((void(*)(void))mem)();

    // if shellcode returns, unmap and exit
    munmap(mem, len);
    return 0;
}
