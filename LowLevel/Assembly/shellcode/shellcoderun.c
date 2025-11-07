char shellcode[] = "\x48\x31\xc0\x48\x31\xff\.....\x05";

void main(){

//cast the shellcode array to a function pointer

((void (*)(void))shellcode)();

}