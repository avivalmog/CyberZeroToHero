/* including the c standard libraries */
#include <stdio.h>
#include <stdlib.h>
/* important in order to avoid calling the standard functions without declerations */

/* --- arrays --- */

void test_malloc_calloc(){
   printf("--- test_malloc_calloc\n");
   int *arr = malloc(3 * sizeof(int));
   int *arr2 = calloc(3, sizeof(int));

   printf("malloc arr assigned addresses in memory:\n");
   printf("%p \n" ,arr);
   printf("%p \n" , arr+1);
   printf("%p \n" , arr + 2); 

   printf("malloc arr values (dont have to be zeroes):\n");
   printf("%d \n" ,*(arr));
   printf("%d \n" , *(arr + 1));
   printf("%d \n" , *(arr + 2));

   printf("calloc arr2 assigned addresses in memory:\n");
   printf("%p \n" ,arr2);
   printf("%p \n" , arr2+1);
   printf("%p \n" , arr2 + 2); 

   printf("calloc arr2 values (should be zeroes):\n");
   printf("%d \n" ,*(arr2));
   printf("%d \n" , *(arr2 + 1));
   printf("%d \n" , *(arr2 + 2));

   
   *arr = 1;
   *(arr+1) = 2;
   *(arr+2) = 3;
   printf("malloc arr values after assigning values:\n");
   printf("%d \n" ,arr[0]);
   printf("%d \n" ,arr[1]);
   printf("%d \n" ,arr[2]);

   free(arr);
   printf("malloc arr values after freeing arr:\n");
   printf("%d \n" ,arr[0]);
   printf("%d \n" ,arr[1]);
   printf("%d \n" ,arr[2]); 
}

void test_arrays_initialization(){
   printf("--- test_arrays_initialization\n");
   int iarray[3] = {1,2,3};
   float farray[3];
   double darray[3];
   char carray[3];
   
   printf("int array addresses - \n");
   printf("%p \n" , iarray);
   printf("%p \n" , iarray+1);
   printf("%p \n" ,  iarray+2);  
   printf("float array addresses - \n");
   printf("%p \n" , farray);
   printf("%p \n" , farray+1);
   printf("%p \n" ,  farray+2); 
   printf("char array addresses - \n");
   printf("%p \n" , carray);
   printf("%p \n" , carray+1);
   printf("%p \n" ,  carray+2); 
   printf("double array addresses - \n");
   printf("%p \n" , darray);
   printf("%p \n" , darray+1);
   printf("%p \n" ,  darray+2); 

   char carray2[3] = "abc";
   printf("%s", carray2);


   /* 
      *iarray == iarray[0] 
      *(iarray+1) == iarray[1]

      printf("%d \n" , *iarray);
      printf("%d \n" , *(iarray+1));
      printf("%d \n" ,  *(iarray+2));

      printf("%d \n" , iarray[0]);
      printf("%d \n" , iarray[1]);
      printf("%d \n" , iarray[2]);
   */
   
   /*
   char * p;
   int * iarrayPtr = iarray;	
   printf("%d \n" , *iarrayPtr);
   printf("%d \n" , *(iarrayPtr+1));
   printf("%d \n" ,  *(iarrayPtr+2));

   printf("%p \n" , iarray);
   printf("%p\n" , iarray + 1);
   printf("%p\n" , farray);
   printf("%p\n" , farray + 1);
   printf("%p\n" , darray);
   printf("%p\n" , darray + 1);
   printf("%p\n" , carray);
   printf("%p\n" , carray + 1);

   char arr[3] = {'0','1','2'};
   printf("%x\n",&arr[0]);
   printf("%x\n", &arr[1]);
   printf("%x\n", &arr[2]);
   printf("%x\n", &arr[3]); 
   */
}

/* --- Memory allocation & free --- */
#include <stdio.h>
#include <stdlib.h>

void test_memory_allocation()
{
    double **cross_norm=(double**)malloc(150 * sizeof(double *));
    for(int i=0; i<150;i++)
    {
        cross_norm[i]=(double*)malloc(100*sizeof(double));
    }
    for(int i=0; i<150;i++)
    {
        free(cross_norm[i]);
    }

    free(cross_norm);
    
    return;
}



/* --- realloc --- */
#include <string.h>

void test_realloc () {
   char *str;

   /* Initial memory allocation */
   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);

   /* Deallocate allocated memory */
   free(str);
   
}
/* let us compile and run the above program that will produce the following result −

String = tutorialspoint, Address = 355090448
String = tutorialspoint.com, Address = 355090448 */



/* --- macro --- */
#include <stdio.h>
#define PI 3.1415
#define circleArea(r) (PI*r*r)

void test_macro() {
    float radius, area;

    printf("Enter the radius: ");
    scanf("%f", &radius);
    area = circleArea(radius);
    printf("Area = %.2f", area);
}

/* --- conditional --- */

// How to use conditional? To use conditional, #ifdef, #if, #defined, #else and #elseif directives are used. 
#ifdef MACRO     
   // conditional codes
#endif
/* Here, the conditional codes are included in the program only if MACRO is defined.*/

// The following example shows how to use the #ifndef directive in the C language:
/* Example using #ifndef directive by TechOnTheNet.com */

void test_conditional()
{
   #define YEARS_OLD 12
   #ifndef YEARS_OLD
   #define YEARS_OLD 10
   #endif
   printf("TechOnTheNet is over %d years old.\n", YEARS_OLD);

   return;
}
/* In this example, if the macro YEARS_OLD is not defined before the #ifndef directive is encountered, 
it will be defined with a value of 10.

Here is the output of the executable program:
TechOnTheNet is over 12 years old.

If you remove the line #define YEARS_OLD 12,
you will see the following output from the executable program:

TechOnTheNet is over 10 years old. */



/* --- enum in C --- */
#include<stdio.h>
  
enum year{Jan, Feb, Mar, Apr, May, Jun, Jul, 
          Aug, Sep, Oct, Nov, Dec};
  
void test_enum()
{
   int i;
   for (i=Jan; i<=Dec; i++)      
      printf("%d ", i);
        
   return;
}
/* Output:0 1 2 3 4 5 6 7 8 9 10 11 */

/* --- optional args --- */
#include <stdarg.h>

double average(int num,...) {

   va_list valist;
   double sum = 0.0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int);
   }
	
   /* clean memory reserved for valist */
   va_end(valist);

   return sum/num;
}

void test_optional_args(){
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
   printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
}


/* --- structs --- */

struct dot {
  int x;
  int y;
};


struct fun_desc {
  char *name;
  void (*fun)(char);
};


typedef struct virus {
    unsigned short SigSize;
    char virusName[16];
    unsigned char* sig;
} virus;

void coolfunc (char c){
   printf("cool func got called with arg:%c!\n", c);
} 

void coolfunc2 (char c){
   printf("cool func2 got called with arg:%c!\n", c);
} 

void test_structs() {
   struct dot d1 = {1,2};
   printf("%d\n", d1.x);
   printf("%d\n", d1.y);


   virus vs;
   virus * vir = (virus*)(calloc(1,sizeof(virus)));
   vir->SigSize=10;
   printf("%d\n", vir->SigSize);

   
   struct fun_desc * fun = (struct fun_desc *)(calloc(1,sizeof(struct fun_desc)));
   fun->name = "coolfunc";
   fun->fun = coolfunc;
   printf("%s\n", fun->name);
   fun->fun('a');

   struct fun_desc functionTable[] = {
        {"coolfunc", coolfunc},
        {"coolfunc2", coolfunc2}
   };

   size_t length = sizeof(functionTable) / sizeof(functionTable[0]); 
   for(int i=0; i < length; i++){
      functionTable[i].fun('B');
   }

}

/* --- union ---  */
   
#include <string.h>
 
union Data {
   int i;
   float f;
   char str[20];
};

void test_union() {

   union Data data;        

   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");

   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
}
/* When the above code is compiled and executed, it produces the following result −

data.i : 1917853763
data.f : 4122360580327794860452759994368.000000
data.str : C Programming
Here, we can see that the values of i and f members of union got corrupted because 
the final value assigned to the variable has occupied the memory location 
and this is the reason that the value of str member is getting printed very well.

Now let's look into the same example once again where we will use one variable at a time
which is the main purpose of having unions − */

#include <stdio.h>
#include <string.h>
 
union Data2 {
   int i;
   float f;
   char str[20];
};
 
void test_union2() {

   union Data2 data;        

   data.i = 10;
   printf( "data.i : %d\n", data.i);
   
   data.f = 220.5;
   printf( "data.f : %f\n", data.f);
   
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);

   return;
}
/*
When the above code is compiled and executed, it produces the following result −

data.i : 10
data.f : 220.500000
data.str : C Programming
Here, all the members are getting printed very well because one member is being used at a time. */



/* --- system call --- */
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

/* syscall table can be printed with: ausyscall --dump */

void test_unix_systemcall(){
   int rc;
   rc = syscall(SYS_chmod, "/etc/passwd", 0444);
   if (rc == -1)
   {
      fprintf(stderr, "chmod failed, errno = %d\n", errno);
   }
   rc = syscall(SYS_getpid);
   if (rc == -1)
   {
      fprintf(stderr, "getpid failed, errno = %d\n", errno);
   }
   else{
      fprintf(stdout, "getpid result: %d\n", rc);
   }

   const char *message = "Hello, direct sys_write!\n";
   // Invoke the sys_write system call directly
   // SYS_write is the system call number for write on Linux
   // 1 is the file descriptor (STDOUT_FILENO)
   // message is the buffer
   // strlen(message) is the number of bytes
   long result = syscall(SYS_write, STDOUT_FILENO, message, strlen(message));

   if (result == -1) {
      // Handle error
      perror("syscall(SYS_write)");
   }

}


/* --- fork ---*/
#include <sys/wait.h>
void test_fork()
{
   int pid;
   if (!(pid = fork())){
      printf("this is the child process\n");
      printf("going to sleep for 3 seconds..\n");
      sleep(3);
      printf("child process finished sleep, and now  exiting..\n");
      exit(1);
   }
   printf("this is father process\n");
   printf("waiting for child to finish..\n");
   waitpid(pid, NULL, 0);
   printf("father process here, can continue after child process exited\n");
}

/* --- fds and dup --- */
#include <unistd.h>
#include <fcntl.h>

void test_fds_dup(){

   // Step 1: open the file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }

    // Step 2: save a copy of current stdout (terminal)
    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1) {
        perror("dup");
        return;
    }

    // Step 3: redirect stdout to the file
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        return;
    }
    close(fd); // no longer needed

    // Step 4: print to the file (goes into output.txt)
    printf("This goes into output.txt\n");
    fflush(stdout);

     // You can also use write() directly on fd 1
    write(STDOUT_FILENO, "Direct write to fd=1\n", 21);

    // Step 5: restore stdout back to the terminal
    if (dup2(saved_stdout, STDOUT_FILENO) == -1) {
        perror("dup2 restore");
        return;
    }
    close(saved_stdout);

    // Step 6: now print to terminal again
    printf("Restored stdout to terminal.\n");

    // Step 7: open the file for reading
    int fd_read = open("output.txt", O_RDONLY);
    if (fd_read == -1) {
        perror("open read");
        return;
    }

    // Step 8: read and print file contents to terminal
    printf("File contents:\n");
    char buffer[128];
    ssize_t bytes;
    while ((bytes = read(fd_read, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = '\0'; // null-terminate
        printf("%s", buffer);
    }
    close(fd_read);

}

/* --- function pointers --- */

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) { 
   return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) { 
   return b ? a / b : 0; 
}

// Function that takes a function pointer as parameter 
void operate(int x, int y, int (*func)(int, int)) {
    printf("Result: %d\n", func(x, y));
}

// Function returning a function pointer 
int (*chooseOperation(char op))(int, int) {
    if (op == '+')
        return add;
    else
        return multiply;
}

void test_function_pointers() {
    
    int (*fp)(int, int); // Declare pointer to function taking (int, int) returning int

    fp = add; // Assign function address
    printf("add via pointer: %d\n", fp(3, 4));

    // Passing a function pointer as argument 
    operate(10, 5, subtract);

    // Returning a function pointer ---
    int (*selected)(int, int) = chooseOperation('*');
    printf("selected op result: %d\n", selected(3, 5));

    // Array of function pointers 
    int (*operations[4])(int, int) = { add, subtract, multiply, divide };
    char *names[] = { "add", "subtract", "multiply", "divide" };

    for (int i = 0; i < 4; i++) {
        printf("%s(10, 2) = %d\n", names[i], operations[i](10, 2));
    }

}



int main(){

   printf("its compiling!\n");
   // test_malloc_calloc();
   // test_arrays_initialization();
   // test_macro();
   // test_conditional();
   // test_enum();
   // test_memory_allocation();
   // test_structs();
   // test_union();
   // test_union2();
   // test_unix_systemcall();
   // test_fork();
   // test_fds_dup();
   // test_function_pointers();

   return 0;
}
