#include <stdio.h>

#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-security"
#pragma GCC diagnostic ignored "-Wformat-extra-args"

int main() {
    int a = 0;
    int b = 1;
    int next = 0;
    
    printf("Fibonacci sequence computed via printf addition:\n");
    for(int i = 0; i < 15; i++) {
        printf("%d ", a);
        // next = a + b using width specifiers and %n
        // snprintf discards output, purely executing the %n side effect
        snprintf(NULL, 0, "%*s%*s%n", a, "", b, "", &next);
        a = b;
        b = next;
    }
    printf("\n");
    return 0;
}
