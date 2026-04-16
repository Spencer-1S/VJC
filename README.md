# VJC

VJC is a source-to-source compiler (transpiler) for a small, statically-typed, procedure-oriented custom language. It parses VJC input using a Flex lexer and a Bison parser, builds an Abstract Syntax Tree (AST), and generates formatted, executable Java code (a `public class Main` with `public static void main`).

## Repository contents

Core sources:
- [ast.h](ast.h): AST node definitions and function prototypes.
- [lexer.l](lexer.l): Flex lexer (tokens, strings, numbers, identifiers, comments).
- [parser.y](parser.y): Bison grammar with operator precedence and `%nonassoc` handling for the dangling-`else` ambiguity; builds the AST.
- [transpiler.c](transpiler.c): AST allocation + Java code generator (depth-first AST walk).

Generated/intermediate files (created by Flex/Bison):
- [lex.yy.c](lex.yy.c)
- [y.tab.c](y.tab.c)
- [y.tab.h](y.tab.h)

Example input program:
- [program.vjc](program.vjc)

## Language features (VJC → Java)

### Types
- `number` → `int`
- `decimal` → `double`
- `truth` → `boolean` (`true`/`false`)
- `string` → `String`

### Arrays
- Allocation: `number[] arr = new number[n];` → `int[] arr = new int[n];`
- Literal init: `number[] arr = {1, 2, 3};` → `int[] arr = { 1, 2, 3 };`
- Indexing/assignment: `arr[i]`, `arr[i] = 5;`
- Length: `arr.length`

### I/O
- `write(x);` → `System.out.print(x);`
- `writeline(x);` → `System.out.println(x);`
- `read("prompt")` and `readline("prompt")` are compiled to helper methods in Java:
  - `readInt(prompt)`, `readDouble(prompt)`, `readBool(prompt)`, `readLine(prompt)`

Note: `read(...)` is type-resolved at variable declaration time (e.g., `number n = read("...");` becomes `readInt("...")`, `decimal x = read("...");` becomes `readDouble("...")`). If you assign `read(...)` to an already-declared variable later, it currently defaults to integer input.

### Control flow
- `if (...) { ... } else { ... }`
- `while (...) { ... }`
- `for (number i from(START to END step STEP)) { ... }` → `for (int i = START; i <= END; i += STEP) { ... }`
- `break;`, `continue;`, `return;`

### Operators
Arithmetic: `+ - * / %`

Relational: `== != < > <= >=`

Logical: `&& || !`

### Functions
C/Java-style declarations:

```text
truth checkPrime(number x) {
    ...
}
```

becomes:

```java
public static boolean checkPrime(int x) {
    ...
}
```

### Casting
- `to_decimal(x)` → `((double)(x))`
- `to_number(y)` → `((int)(y))`

### Comments
- `// ...` and `/* ... */` are ignored by the lexer.

### f-strings
VJC supports a simple `f"...{expr}..."` syntax. It is transpiled into Java string concatenation.

Example:

```text
writeline(f"Enter element {count}: ");
```

becomes:

```java
System.out.println(("Enter element " + (count) + ": "));
```

## Build and run (Windows)

### Prerequisites
You need:
- A C compiler (MinGW GCC works on Windows)
- Flex and Bison (either via MSYS2 or a Windows Flex/Bison distribution)
- A JDK for compiling/running the generated Java (`javac`, `java`)

### Build the transpiler
From `E:\Compiler Design\VJC`:

1) Regenerate the lexer/parser C files (requires `flex` and `bison` on PATH):

```powershell
bison -d -y parser.y
flex lexer.l
```

2) Compile everything into `transpiler.exe`:

```powershell
gcc -o transpiler.exe transpiler.c y.tab.c lex.yy.c
```

If your Flex distribution requires it, add `-lfl`:

```powershell
gcc -o transpiler.exe transpiler.c y.tab.c lex.yy.c -lfl
```

### Use the transpiler
Transpile a VJC program to Java:

```powershell
.\transpiler.exe program.vjc Main.java
```

### Compile and run the generated Java

```powershell
javac Main.java
java Main
```

## Notes
- The parser uses `%nonassoc IFX` / `%nonassoc ELSE` to resolve the dangling-`else` ambiguity.
- The Java output includes `Scanner` input helpers and generates a single `Main` class.
