#include <stdio.h>


int main() 
{
    char c_fifty_unused[50];
    char c_fifty_used[50] = "Foo Bar";
    char c_lazy[] = "Foo Bar";
    int mem_unused = sizeof(c_fifty_unused);
    int mem_used = sizeof(c_fifty_used);
    printf("sizeof 50 char string: %i", sizeof(c_fifty_unused) );
    printf("\n");
    printf("sizeof 50 char string, 7 chars used: %i", sizeof(c_fifty_used));
    printf("\n");
    printf(
        "sizeof string of undefined length, 7 chars used: %i",
        sizeof(c_lazy)
    );
    printf("\n");
    return 0;
}