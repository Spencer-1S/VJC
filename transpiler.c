#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include "ast.h"
#include "y.tab.h"

extern int yyparse(void);
extern nodeType *root;

static int gIndent = 0;

static void printIndent(void) {
    for (int i = 0; i < gIndent; i++) {
        fputs("    ", stdout);
    }
}

static const char *getTypeString(int t) {
    switch (t) {
        case 0: return "int";
        case 1: return "double";
        case 2: return "boolean";
        case 3: return "String";
        case 4: return "void";
        default: return "Object";
    }
}

nodeType *conNodeNumber(long value) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeCon;
    p->con.type = 0;
    p->con.iData = value;
    return p;
}

nodeType *conNodeDecimal(double value) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeCon;
    p->con.type = 1;
    p->con.dData = value;
    return p;
}

nodeType *conNodeTruth(bool value) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeCon;
    p->con.type = 2;
    p->con.bData = value;
    return p;
}

nodeType *idNode(char *name) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeId;
    p->id.name = strdup(name);
    return p;
}

nodeType *strNode(char *val, bool isF) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeStr;
    p->str.val = strdup(val);
    p->str.isFString = isF;
    return p;
}

nodeType *oprNode(int oper, int nops, ...) {
    va_list ap;
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    p->opr.op = (nodeType **)malloc((size_t)nops * sizeof(nodeType *));
    va_start(ap, nops);
    for (int i = 0; i < nops; i++) {
        p->opr.op[i] = va_arg(ap, nodeType *);
    }
    va_end(ap);
    return p;
}

nodeType *declNode(int typeType, char *name, nodeType *expr) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeDeclar;
    p->decl.typeType = typeType;
    p->decl.name = strdup(name);
    p->decl.expr = expr;
    return p;
}

nodeType *funcNode(int retType, char *name, nodeType *params, nodeType *body) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeFunc;
    p->func.retType = retType;
    p->func.name = strdup(name);
    p->func.params = params;
    p->func.body = body;
    return p;
}

nodeType *forNode(int typeType, char *iterName, nodeType *start, nodeType *end, nodeType *step, nodeType *body) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeFor;
    p->forLoop.typeType = typeType;
    p->forLoop.iterName = strdup(iterName);
    p->forLoop.start = start;
    p->forLoop.end = end;
    p->forLoop.step = step;
    p->forLoop.body = body;
    return p;
}

nodeType *arrayDeclNodeNew(int typeType, char *name, nodeType *size) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeArrayDecl;
    p->arrDecl.typeType = typeType;
    p->arrDecl.name = strdup(name);
    p->arrDecl.size = size;
    p->arrDecl.initList = NULL;
    return p;
}

nodeType *arrayDeclNodeInit(int typeType, char *name, nodeType *initList) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeArrayDecl;
    p->arrDecl.typeType = typeType;
    p->arrDecl.name = strdup(name);
    p->arrDecl.size = NULL;
    p->arrDecl.initList = initList;
    return p;
}

nodeType *arrayAccessNode(char *name, nodeType *index) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeArrayAccess;
    p->arrAccess.name = strdup(name);
    p->arrAccess.index = index;
    return p;
}

nodeType *castNode(int toType, nodeType *expr) {
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->type = typeCast;
    p->cast.toType = toType;
    p->cast.expr = expr;
    return p;
}

nodeType *coerceReadForType(int typeType, nodeType *expr) {
    if (!expr) return expr;
    if (expr->type != typeOpr) return expr;

    if (expr->opr.oper == READ) {
        switch (typeType) {
            case 0: return oprNode(OP_READ_INT, 1, expr->opr.op[0]);
            case 1: return oprNode(OP_READ_DOUBLE, 1, expr->opr.op[0]);
            case 2: return oprNode(OP_READ_BOOL, 1, expr->opr.op[0]);
            default: return expr;
        }
    }

    if (expr->opr.oper == READLINE) {
        return oprNode(OP_READ_LINE, 1, expr->opr.op[0]);
    }

    return expr;
}

static void genExpr(nodeType *p);
static void genStmt(nodeType *p);

static void genCommaList(nodeType *p) {
    if (!p) return;
    if (p->type == typeOpr && p->opr.oper == ',' && p->opr.nops == 2) {
        genCommaList(p->opr.op[0]);
        printf(", ");
        genCommaList(p->opr.op[1]);
        return;
    }
    if (p->type == typeOpr && p->opr.oper == ',' && p->opr.nops == 1) {
        genCommaList(p->opr.op[0]);
        return;
    }
    genExpr(p);
}

static void genParamDeclList(nodeType *p) {
    if (!p) return;

    if (p->type == typeOpr && p->opr.oper == ',' && p->opr.nops == 2) {
        genParamDeclList(p->opr.op[0]);
        printf(", ");
        genParamDeclList(p->opr.op[1]);
        return;
    }

    if (p->type == typeOpr && p->opr.oper == ',' && p->opr.nops == 1) {
        genParamDeclList(p->opr.op[0]);
        return;
    }

    if (p->type == typeDeclar) {
        printf("%s %s", getTypeString(p->decl.typeType), p->decl.name);
        return;
    }

    genExpr(p);
}

static void genStmtList(nodeType *p) {
    if (!p) return;
    if (p->type == typeOpr && p->opr.oper == ';') {
        if (p->opr.nops == 0) return;
        if (p->opr.nops == 1) {
            genStmt(p->opr.op[0]);
            return;
        }
        if (p->opr.nops == 2) {
            genStmtList(p->opr.op[0]);
            genStmt(p->opr.op[1]);
            return;
        }
    }
    genStmt(p);
}

static void genFStringExpr(const char *s) {
    bool inExpr = false;
    printf("(");
    printf("\"");
    for (size_t i = 0; s[i] != '\0'; i++) {
        if (!inExpr && s[i] == '{') {
            printf("\" + (");
            inExpr = true;
            continue;
        }
        if (inExpr && s[i] == '}') {
            printf(") + \"");
            inExpr = false;
            continue;
        }
        putchar(s[i]);
    }
    printf("\"");
    printf(")");
}

static void genExpr(nodeType *p) {
    if (!p) return;

    switch (p->type) {
        case typeCon:
            if (p->con.type == 0) {
                printf("%ld", p->con.iData);
            } else if (p->con.type == 1) {
                printf("%.17g", p->con.dData);
            } else {
                printf("%s", p->con.bData ? "true" : "false");
            }
            return;

        case typeId:
            printf("%s", p->id.name);
            return;

        case typeStr:
            if (p->str.isFString) {
                genFStringExpr(p->str.val);
            } else {
                printf("\"%s\"", p->str.val);
            }
            return;

        case typeArrayAccess:
            printf("%s[", p->arrAccess.name);
            genExpr(p->arrAccess.index);
            printf("]");
            return;

        case typeCast:
            printf("((%s)(", getTypeString(p->cast.toType));
            genExpr(p->cast.expr);
            printf("))");
            return;

        case typeOpr: {
            int oper = p->opr.oper;

            if (oper == LENGTH && p->opr.nops == 1) {
                genExpr(p->opr.op[0]);
                printf(".length");
                return;
            }

            if ((oper == READ || oper == OP_READ_INT) && p->opr.nops == 1) {
                printf("readInt(");
                genExpr(p->opr.op[0]);
                printf(")");
                return;
            }

            if (oper == OP_READ_DOUBLE && p->opr.nops == 1) {
                printf("readDouble(");
                genExpr(p->opr.op[0]);
                printf(")");
                return;
            }

            if (oper == OP_READ_BOOL && p->opr.nops == 1) {
                printf("readBool(");
                genExpr(p->opr.op[0]);
                printf(")");
                return;
            }

            if ((oper == READLINE || oper == OP_READ_LINE) && p->opr.nops == 1) {
                printf("readLine(");
                genExpr(p->opr.op[0]);
                printf(")");
                return;
            }

            if (oper == 'C') {
                genExpr(p->opr.op[0]);
                printf("(");
                if (p->opr.nops > 1) genCommaList(p->opr.op[1]);
                printf(")");
                return;
            }

            if (p->opr.nops == 1) {
                if (oper == UMINUS) {
                    printf("(-");
                    genExpr(p->opr.op[0]);
                    printf(")");
                    return;
                }
                if (oper == '!') {
                    printf("(!");
                    genExpr(p->opr.op[0]);
                    printf(")");
                    return;
                }
            }

            if (p->opr.nops == 2) {
                printf("(");
                genExpr(p->opr.op[0]);
                switch (oper) {
                    case '+': printf(" + "); break;
                    case '-': printf(" - "); break;
                    case '*': printf(" * "); break;
                    case '/': printf(" / "); break;
                    case '%': printf(" %% "); break;
                    case '<': printf(" < "); break;
                    case '>': printf(" > "); break;
                    case GE:  printf(" >= "); break;
                    case LE:  printf(" <= "); break;
                    case EQ:  printf(" == "); break;
                    case NE:  printf(" != "); break;
                    case AND: printf(" && "); break;
                    case OR:  printf(" || "); break;
                    default:  printf(" /*op %d*/ ", oper); break;
                }
                genExpr(p->opr.op[1]);
                printf(")");
                return;
            }

            printf("/*unsupported-expr*/");
            return;
        }

        case typeDeclar:
        case typeFunc:
        case typeFor:
        case typeArrayDecl:
        default:
            printf("/*unsupported*/");
            return;
    }
}

static void genStmt(nodeType *p) {
    if (!p) return;

    if (p->type == typeOpr && p->opr.oper == ';') {
        genStmtList(p);
        return;
    }

    switch (p->type) {
        case typeDeclar:
            printIndent();
            printf("%s %s", getTypeString(p->decl.typeType), p->decl.name);
            if (p->decl.expr) {
                printf(" = ");
                genExpr(p->decl.expr);
            }
            printf(";\n");
            return;

        case typeArrayDecl:
            printIndent();
            printf("%s[] %s = ", getTypeString(p->arrDecl.typeType), p->arrDecl.name);
            if (p->arrDecl.size) {
                printf("new %s[", getTypeString(p->arrDecl.typeType));
                genExpr(p->arrDecl.size);
                printf("]");
            } else {
                printf("{ ");
                genCommaList(p->arrDecl.initList);
                printf(" }");
            }
            printf(";\n");
            return;

        case typeFor:
            printIndent();
            printf("for (%s %s = ", getTypeString(p->forLoop.typeType), p->forLoop.iterName);
            genExpr(p->forLoop.start);
            printf("; %s <= ", p->forLoop.iterName);
            genExpr(p->forLoop.end);
            printf("; %s += ", p->forLoop.iterName);
            genExpr(p->forLoop.step);
            printf(") {\n");
            gIndent++;
            genStmtList(p->forLoop.body);
            gIndent--;
            printIndent();
            printf("}\n");
            return;

        case typeOpr: {
            int oper = p->opr.oper;

            if (oper == '=') {
                printIndent();
                genExpr(p->opr.op[0]);
                printf(" = ");
                genExpr(p->opr.op[1]);
                printf(";\n");
                return;
            }

            if (oper == WRITE && p->opr.nops == 1) {
                printIndent();
                printf("System.out.print(");
                genExpr(p->opr.op[0]);
                printf(");\n");
                return;
            }

            if (oper == WRITELINE && p->opr.nops == 1) {
                printIndent();
                printf("System.out.println(");
                genExpr(p->opr.op[0]);
                printf(");\n");
                return;
            }

            if (oper == IF) {
                printIndent();
                printf("if (");
                genExpr(p->opr.op[0]);
                printf(") {\n");
                gIndent++;
                genStmtList(p->opr.op[1]);
                gIndent--;
                printIndent();
                printf("}");
                if (p->opr.nops > 2) {
                    printf(" else {\n");
                    gIndent++;
                    genStmtList(p->opr.op[2]);
                    gIndent--;
                    printIndent();
                    printf("}");
                }
                printf("\n");
                return;
            }

            if (oper == WHILE && p->opr.nops == 2) {
                printIndent();
                printf("while (");
                genExpr(p->opr.op[0]);
                printf(") {\n");
                gIndent++;
                genStmtList(p->opr.op[1]);
                gIndent--;
                printIndent();
                printf("}\n");
                return;
            }

            if (oper == BREAK) {
                printIndent();
                printf("break;\n");
                return;
            }

            if (oper == CONTINUE) {
                printIndent();
                printf("continue;\n");
                return;
            }

            if (oper == RETURN) {
                printIndent();
                printf("return");
                if (p->opr.nops == 1) {
                    printf(" ");
                    genExpr(p->opr.op[0]);
                }
                printf(";\n");
                return;
            }

            if (oper == 'C') {
                printIndent();
                genExpr(p);
                printf(";\n");
                return;
            }

            printIndent();
            genExpr(p);
            printf(";\n");
            return;
        }

        default:
            printIndent();
            printf("/*unsupported-stmt*/\n");
            return;
    }
}

static void genFunction(nodeType *p) {
    if (!p || p->type != typeFunc) return;

    if (strcmp(p->func.name, "main") == 0) {
        printIndent();
        printf("public static void main(String[] args) {\n");
        gIndent++;
        genStmtList(p->func.body);
        gIndent--;
        printIndent();
        printf("}\n\n");
        return;
    }

    printIndent();
    printf("public static %s %s(", getTypeString(p->func.retType), p->func.name);
    if (p->func.params) genParamDeclList(p->func.params);
    printf(") {\n");
    gIndent++;
    genStmtList(p->func.body);
    gIndent--;
    printIndent();
    printf("}\n\n");
}

static void genTopLevel(nodeType *p) {
    if (!p) return;

    if (p->type == typeOpr && p->opr.oper == ';' && p->opr.nops == 2) {
        genTopLevel(p->opr.op[0]);
        genTopLevel(p->opr.op[1]);
        return;
    }

    if (p->type == typeOpr && p->opr.oper == ';' && p->opr.nops == 1) {
        genTopLevel(p->opr.op[0]);
        return;
    }

    if (p->type == typeFunc) {
        genFunction(p);
    }
}

void generateJava(nodeType *p) {
    (void)p;
    /* Not used directly; generation is handled by genTopLevel(root). */
}

int main(int argc, char **argv) {
    if (argc == 3) {
        if (!freopen(argv[1], "rb", stdin)) {
            perror(argv[1]);
            return 1;
        }
        if (!freopen(argv[2], "wb", stdout)) {
            perror(argv[2]);
            return 1;
        }
    } else if (argc != 1) {
        fprintf(stderr, "Usage: %s [inputFile outputFile]\n", argv[0]);
        return 2;
    }

    printf("import java.util.*;\n\n");
    printf("public class Main {\n");

    gIndent = 1;
    printIndent();
    printf("private static final Scanner scanner = new Scanner(System.in);\n\n");

    printIndent();
    printf("private static int readInt(String prompt) {\n");
    gIndent++;
    printIndent();
    printf("System.out.print(prompt);\n");
    printIndent();
    printf("String s = scanner.nextLine();\n");
    printIndent();
    printf("return Integer.parseInt(s.trim());\n");
    gIndent--;
    printIndent();
    printf("}\n\n");

    printIndent();
    printf("private static double readDouble(String prompt) {\n");
    gIndent++;
    printIndent();
    printf("System.out.print(prompt);\n");
    printIndent();
    printf("String s = scanner.nextLine();\n");
    printIndent();
    printf("return Double.parseDouble(s.trim());\n");
    gIndent--;
    printIndent();
    printf("}\n\n");

    printIndent();
    printf("private static boolean readBool(String prompt) {\n");
    gIndent++;
    printIndent();
    printf("System.out.print(prompt);\n");
    printIndent();
    printf("String s = scanner.nextLine();\n");
    printIndent();
    printf("return Boolean.parseBoolean(s.trim());\n");
    gIndent--;
    printIndent();
    printf("}\n\n");

    printIndent();
    printf("private static String readLine(String prompt) {\n");
    gIndent++;
    printIndent();
    printf("System.out.print(prompt);\n");
    printIndent();
    printf("return scanner.nextLine();\n");
    gIndent--;
    printIndent();
    printf("}\n\n");

    if (yyparse() == 0) {
        genTopLevel(root);
    }

    printf("}\n");
    return 0;
}
