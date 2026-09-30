# Printf is Turing-Complete

> Computing Fibonacci sequences using only `printf` format string side effects.  
> **Paged Out! Issue #10 Article**

## The Concept

Most people know `printf` format string vulnerabilities exist. But did you know `printf` is **Turing-complete**?

Using `%n` (writes character count to memory), width specifiers (`%*s` for controlled padding), and positional arguments (`$`), you get:
- **Memory write** → `%n`
- **Controlled values** → width specifiers
- **Addressing** → positional args

That's enough to compute **anything** — including Fibonacci sequences — with ZERO arithmetic operators!

## The Magic Line

```c
snprintf(NULL, 0, "%*s%*s%n", a, "", b, "", &next);
// next = a + b, computed purely via format string side effects!
```

## How to Run

```bash
gcc -O0 printf_fibonacci.c -o printf_fibonacci
./printf_fibonacci
```

## Output

```
=== DEMO 1: Basic %n ===
hello
  'hello' = 5 chars, so %n wrote: 5

=== DEMO 2: Controlled Value Write ===
  Wrote value 42 using printf: val = 42

=== DEMO 3: Addition via printf ===
  37 + 58 = 95 (computed by printf!)

=== DEMO 4: Fibonacci Sequence via printf ===
  0 1 1 2 3 5 8 13 21 34 55 89 144 233 377

=== CONCLUSION ===
  All math above was done by printf.
  No +, -, *, / operators were used.
  printf is Turing-complete!
```

## Files

| File | Description |
|------|-------------|
| `printf_fibonacci.c` | Complete PoC with all demos (basic %n, addition, Fibonacci) |
| `poc_basic_fibonacci.c` | Minimal Fibonacci-only PoC |

## Why It Matters

Format string attacks aren't just bugs — they reveal a miniature virtual machine hiding in libc. When you pass unchecked user input to `printf`, you're handing over a complete computing environment.

## License

CC-BY 4.0
