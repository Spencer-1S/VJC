# VJC

VJC is a source-to-source compiler (transpiler) for a small, statically-typed, procedure-oriented custom language. It parses VJC input using a Flex lexer and a Bison parser, builds an Abstract Syntax Tree (AST), and generates formatted, executable Java code (a `public class Main` with `public static void main`).

## Quick start (compile a .vjc program)

The transpiler generates a Java file named `Main.java` (class name is always `Main`).

### Windows (PowerShell)

If you are not already in the compiler folder:

```powershell
Set-Location -Path "E:\Compiler Design\VJC\Compiler\Executable Compiler (Windows)"
```

Transpile → compile Java → run:

```powershell
.\transpiler.exe "..\..\Example Programs\bubblesort.vjc" Main.java
javac Main.java
java Main
```

### Linux (bash)

If you are not already in the compiler folder:

```bash
cd "./Compiler/Executable Compiler (Linux)"
```

Transpile → compile Java → run:

```bash
./transpiler "../../Example Programs/bubblesort.vjc" Main.java
javac Main.java
java Main
```

## Repository contents

Core sources:
- [Compiler/ast.h](Compiler/ast.h): AST node definitions and function prototypes.
- [Compiler/lexer.l](Compiler/lexer.l): Flex lexer (tokens, strings, numbers, identifiers, comments).
- [Compiler/parser.y](Compiler/parser.y): Bison grammar with operator precedence and `%nonassoc` handling for the dangling-`else` ambiguity; builds the AST.
- [Compiler/transpiler.c](Compiler/transpiler.c): AST allocation + Java code generator (depth-first AST walk).

Generated/intermediate files (created by Flex/Bison):
- [Compiler/lex.yy.c](Compiler/lex.yy.c)
- [Compiler/y.tab.c](Compiler/y.tab.c)
- [Compiler/y.tab.h](Compiler/y.tab.h)

Example programs:
- [Example Programs/HelloWorld.vjc](Example%20Programs/HelloWorld.vjc)
- [Example Programs/Add.vjc](Example%20Programs/Add.vjc)
- [Example Programs/bubblesort.vjc](Example%20Programs/bubblesort.vjc)
- [Example Programs/PrimeNumbers.vjc](Example%20Programs/PrimeNumbers.vjc)

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

## Build and run

This repo supports building a Windows executable transpiler and a Linux executable transpiler.

Executables are kept in:
- Windows: [Compiler/Executable Compiler (Windows)/transpiler.exe](Compiler/Executable%20Compiler%20(Windows)/transpiler.exe)
- Linux: [Compiler/Executable Compiler (Linux)/transpiler](Compiler/Executable%20Compiler%20(Linux)/)

### Prerequisites
You need:
- A C compiler (MinGW GCC works on Windows)
- Flex and Bison (either via MSYS2 or a Windows Flex/Bison distribution)
- A JDK for compiling/running the generated Java (`javac`, `java`)

### Build the transpiler (Windows executable)
From `E:\Compiler Design\VJC` in PowerShell:

1) Regenerate the lexer/parser C files (requires `flex` and `bison` on PATH):

```powershell
Set-Location -Path "E:\Compiler Design\VJC\Compiler"
bison -d -y parser.y
flex lexer.l
```

2) Compile everything into the Windows executable (written into the Windows output folder):

```powershell
gcc -O2 -Wall -o ".\Executable Compiler (Windows)\transpiler.exe" transpiler.c y.tab.c lex.yy.c
```

If your Flex distribution requires it, add `-lfl`:

```powershell
gcc -O2 -Wall -o ".\Executable Compiler (Windows)\transpiler.exe" transpiler.c y.tab.c lex.yy.c -lfl
```

### Build the transpiler (Linux executable)

Option 1: Native Linux

```bash
cd "./Compiler"
bison -d -y parser.y
flex -o lex.yy.c lexer.l

gcc -O2 -Wall -o "./Executable Compiler (Linux)/transpiler" transpiler.c y.tab.c lex.yy.c

# If your distro needs libfl:
gcc -O2 -Wall -o "./Executable Compiler (Linux)/transpiler" transpiler.c y.tab.c lex.yy.c -lfl
```

Option 2: Build the Linux executable from Windows using WSL

This writes an ELF binary into your Windows drive via `/mnt/...`.

```powershell
wsl bash -lc 'cd "/mnt/e/Compiler Design/VJC/Compiler" && bison -d -y parser.y && flex -o lex.yy.c lexer.l && gcc -O2 -Wall -o "/mnt/e/Compiler Design/VJC/Compiler/Executable Compiler (Linux)/transpiler" transpiler.c y.tab.c lex.yy.c'
```

To verify the Linux binary format in WSL:

```powershell
wsl file "/mnt/e/Compiler Design/VJC/Compiler/Executable Compiler (Linux)/transpiler"
```

### Use the transpiler
Transpile a VJC program to Java:

```powershell
Set-Location -Path "E:\Compiler Design\VJC"
".\Compiler\Executable Compiler (Windows)\transpiler.exe" "Example Programs\bubblesort.vjc" Main.java
```

On Linux:

```bash
./Compiler/Executable\ Compiler\ \(Linux\)/transpiler "Example Programs/bubblesort.vjc" Main.java
```

### Compile and run the generated Java

```powershell
javac Main.java
java Main
```

## Notes
- The parser uses `%nonassoc IFX` / `%nonassoc ELSE` to resolve the dangling-`else` ambiguity.
- The Java output includes `Scanner` input helpers and generates a single `Main` class.

## Author / Developer
Vishal Anand (Spencer1s)

## License
Copyright (c) 2026 Vishal Anand (Spencer-1S) <br>
All rights reserved.
