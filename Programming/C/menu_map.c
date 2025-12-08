#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char censor(char c) {
  if(c == '!')
    return '.';
  else
    return c;
}
char encrypt(char c) /* Gets a char c and returns its encrypted form by adding 3 to its value. 
          If c is not between 0x20 and 0x7E it is returned unchanged */
{
    if(0x20 <= c && c <= 0x7E)
        c = c + 3;
    return c;
}
char decrypt(char c) /* Gets a char c and returns its decrypted form by reducing 3 to its value. 
            If c is not between 0x20 and 0x7E it is returned unchanged */
{
    if(0x20 <= c && c <= 0x7E)
        c = c - 3;
    return c;
}
char dprt(char c) /* dprt prints the value of c in a decimal representation followed by a 
           new line, and returns c unchanged. */
{
    printf("%d\n", c);
    return c;
}
char cprt(char c) /* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed 
                    by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns 
                    the value of c unchanged. */
{
    if(0x20 <= c && c <= 0x7E)
        printf("%c\n", c);
    else
        printf("%c\n", '.');

    return c;
}
char my_get(char c) /* Ignores c, reads and returns a character from stdin using fgetc. */
{
    return fgetc(stdin);
}
char quit(char c) /* Gets a char c,  and if the char is 'q' , ends the program with exit code 0. Otherwise returns c. */
{
    if(c == 'q')
        exit(0);
    return c;
}

struct fun_desc {
  char *name;
  char (*fun)(char);
};

char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  for(int i = 0; i < array_length; i++)
  {
      mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}
 

int main(int argc, char **argv){
  
    char * carray = (char*)(malloc(5*sizeof(char)));
    carray[0] = '\0';
    struct fun_desc menu[] = {{"Censor", censor} ,{ "Encrypt", encrypt}, { "Decrypt", decrypt},{"Print dec",dprt},
    {"Print string",cprt},{"Get string",my_get} ,{"Quit",quit}, { NULL, NULL }};

    int lowerBound = 0;
    int upperBound = sizeof(menu) / sizeof(struct fun_desc) - 2;

    char * choice  = (char*)(malloc(2*sizeof(char)));
    int num;

    printf("%s\n", "Please choose a function:");
    for(int i = 0; i < upperBound +1; i ++)
    {
        printf("%d) %s\n",i, menu[i].name);
    }
    printf("%s", "Option: ");
    fgets(choice,2,stdin);
    num = atoi(choice);
    getchar();
    
    while(lowerBound <= num && num <= upperBound){
        printf("%s\n" , "Within bounds");
        carray = map(carray, 5, menu[num].fun);

        printf("%s\n", "Please choose a function:");
        for(int i = 0; i < upperBound +1; i ++)
        {
           printf("%d) %s\n",i, menu[i].name);
        }
        printf("%s", "Option: ");
        fgets(choice,2,stdin);
        num = atoi(choice);
        getchar(); // clears the enter from stdin
    }
    printf("%s\n" , "Not Within bounds");
    free(carray);
    free(choice);

}