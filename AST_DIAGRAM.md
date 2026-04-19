# AST diagram (array decl + for loop)

This corresponds to the VJC snippet:

```vjc
number[] a = new number[n];
for(number i from(0 to n - 1)) {
    a[i] = v;
}
```

## Mermaid (view in VS Code Markdown Preview)

```mermaid
flowchart TD
    Root["program root<br/>(typeOpr ';')"] --> Seq1["Seq<br/>(typeOpr ';')"]
    Seq1 --> ArrDecl["typeArrayDecl<br/>name=a<br/>typeType=number"]
    Seq1 --> ForNode["typeFor<br/>iterName=i<br/>typeType=number"]

    ArrDecl --> SizeExpr["expr: idNode('n')"]

    ForNode --> Start["start: conNodeNumber(0)"]
    ForNode --> End["end: oprNode('-')"]
    End --> EndL["idNode('n')"]
    End --> EndR["conNodeNumber(1)"]
    ForNode --> Step["step: conNodeNumber(1)"]
    ForNode --> Body["body: typeOpr ';'"]

    Body --> Assign["stmt: oprNode('=')"]
    Assign --> LHS["lhs: typeArrayAccess<br/>name=a"]
    LHS --> Index["index: idNode('i')"]
    Assign --> RHS["rhs: idNode('v')"]
```

If Mermaid doesn’t render in preview, enable it in VS Code settings:
- `markdown.mermaid.enabled`: `true`

## ASCII (renders everywhere)

```
program root (typeOpr ';')
└── ';' sequence
    ├── typeArrayDecl  name=a  typeType=number
    │   └── size: idNode("n")
    └── typeFor  iterName=i  typeType=number
        ├── start: conNodeNumber(0)
        ├── end: oprNode('-')
        │   ├── idNode("n")
        │   └── conNodeNumber(1)
        ├── step: conNodeNumber(1)
        └── body: typeOpr ';'
            └── oprNode('=')
                ├── lhs: typeArrayAccess name=a
                │   └── index: idNode("i")
                └── rhs: idNode("v")
```
