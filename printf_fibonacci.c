/*
 * Printf is Turing-Complete — Paged Out! Article PoC
 * ===================================================
 * This program computes the Fibonacci sequence using ONLY printf.
 * No arithmetic operators (+, -, *, /) are used for the computation.
 *
 * HOW TO COMPILE & RUN:
 *   gcc -g -O0 printf_fibonacci.c -o printf_fibonacci
 *   ./printf_fibonacci
 */

#include <stdio.h>

#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-security"
#pragma GCC diagnostic ignored "-Wformat-extra-args"

int main() {

    /* ============================================
     * DEMO 1: %n writes character count to memory
     * ============================================ */
    printf("=== DEMO 1: Basic %%n ===\n");
    int count = 0;
    printf("hello%n\n", &count);
    printf("  'hello' = 5 chars, so %%n wrote: %d\n\n", count);

    /* ============================================
     * DEMO 2: Width specifiers control the value
     * ============================================
     * %*s prints 'width' number of spaces
     * %n then captures that count
     * Result: we can write ANY number we want!
     */
    printf("=== DEMO 2: Controlled Value Write ===\n");
    int val = 0;
    snprintf(NULL, 0, "%*s%n", 42, "", &val);
    printf("  Wrote value 42 using printf: val = %d\n\n", val);

    /* ============================================
     * DEMO 3: Addition using printf
     * ============================================
     * Print A spaces + B spaces = A+B total chars
     * %n captures A+B into result variable
     * WE JUST DID ADDITION WITHOUT THE + OPERATOR!
     */
    printf("=== DEMO 3: Addition via printf ===\n");
    int a = 37, b = 58, result = 0;
    snprintf(NULL, 0, "%*s%*s%n", a, "", b, "", &result);
    printf("  %d + %d = %d (computed by printf!)\n\n", a, b, result);

    /* ============================================
     * DEMO 4: FIBONACCI via printf — THE PAYOFF
     * ============================================
     * next = a + b is computed by:
     *   snprintf(NULL, 0, "%*s%*s%n", a, "", b, "", &next)
     * 
     * This prints 'a' spaces + 'b' spaces = a+b chars
     * Then %n writes a+b into 'next'
     * NO ARITHMETIC OPERATORS USED!
     */
    printf("=== DEMO 4: Fibonacci Sequence via printf ===\n");
    printf("  ");

    int fib_a = 0;
    int fib_b = 1;
    int next = 0;

    for (int i = 0; i < 15; i++) {
        printf("%d ", fib_a);

        /* This is the magic line:
         * next = fib_a + fib_b
         * Done entirely via printf format string side effects!
         * snprintf discards output (NULL buffer), 
         * but %n still writes the character count */
        snprintf(NULL, 0, "%*s%*s%n", fib_a, "", fib_b, "", &next);

        fib_a = fib_b;
        fib_b = next;
    }

    printf("\n\n");
    printf("=== CONCLUSION ===\n");
    printf("  All math above was done by printf.\n");
    printf("  No +, -, *, / operators were used.\n");
    printf("  printf is Turing-complete!\n");

    return 0;
}
