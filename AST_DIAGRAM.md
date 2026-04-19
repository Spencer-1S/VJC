# AST diagram (array decl + for loop)

This corresponds to the VJC snippet (as the contents of a block, e.g. inside `main`):

```vjc
number[] a = new number[n];
for(number i from(0 to n - 1)) {
    a[i] = v;
}
```

## Mermaid (view in VS Code Markdown Preview)

```mermaid
flowchart TD
    Root["stmt_list root<br/>(typeOpr ';', nops=2)"] --> LeftList["left: typeOpr ';'<br/>(nops=1)"]
    Root --> ForNode["right: typeFor<br/>iterName=i<br/>typeType=number"]

    LeftList --> ArrDecl["stmt: typeArrayDecl<br/>name=a<br/>typeType=number (0)"]

    ArrDecl --> SizeExpr["expr: idNode('n')"]

    ForNode --> Start["start: conNodeNumber(0)"]
    ForNode --> End["end: oprNode('-')"]
    End --> EndL["idNode('n')"]
    End --> EndR["conNodeNumber(1)"]
    ForNode --> Step["step: conNodeNumber(1)"]
    ForNode --> Body["body: typeOpr ';'<br/>(nops=1)"]

    Body --> Assign["stmt: oprNode('=')"]
    Assign --> LHS["lhs: typeArrayAccess<br/>name=a"]
    LHS --> Index["index: idNode('i')"]
    Assign --> RHS["rhs: idNode('v')"]
```

If Mermaid doesn’t render in preview, enable it in VS Code settings:
- `markdown.mermaid.enabled`: `true`

## ASCII (renders everywhere)

```
stmt_list root: oprNode(';', nops=2)
├── left: oprNode(';', nops=1)
│   └── stmt: typeArrayDecl  name=a  typeType=number (0)
│       └── size: idNode("n")
└── right: typeFor  iterName=i  typeType=number (0)
    ├── start: conNodeNumber(0)
    ├── end: oprNode('-')
    │   ├── idNode("n")
    │   └── conNodeNumber(1)
    ├── step: conNodeNumber(1)
    └── body: oprNode(';', nops=1)
        └── stmt: oprNode('=')
            ├── lhs: typeArrayAccess name=a
            │   └── index: idNode("i")
            └── rhs: idNode("v")
```
