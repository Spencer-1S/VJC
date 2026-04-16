#ifndef AST_H
#define AST_H

#include <stdbool.h>

typedef enum {
    typeCon, typeId, typeOpr, typeStr, typeDeclar, typeFunc, typeFor, typeArrayDecl, typeArrayAccess, typeCast
} nodeEnum;

enum {
    OP_READ_INT = 10000,
    OP_READ_DOUBLE,
    OP_READ_BOOL,
    OP_READ_LINE
};

/* Constants */
typedef struct {
    int type; /* 0: number, 1: decimal, 2: truth */
    union {
        long iData;
        double dData;
        bool bData;
    };
} conNodeType;

/* Identifiers */
typedef struct {
    char *name;
} idNodeType;

/* Strings */
typedef struct {
    char *val;
    bool isFString;
} strNodeType;

/* Operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag **op;	/* operands, dynamically allocated array */
} oprNodeType;

/* Declarations */
typedef struct {
    int typeType; /* 0: number, 1: decimal, 2: truth, 3: string */
    char *name;
    struct nodeTypeTag *expr;
} declarNodeType;

/* Functions */
typedef struct {
    int retType;
    char *name;
    struct nodeTypeTag *params;
    struct nodeTypeTag *body;
} funcNodeType;

/* For Loop */
typedef struct {
    int typeType;
    char *iterName;
    struct nodeTypeTag *start;
    struct nodeTypeTag *end;
    struct nodeTypeTag *step;
    struct nodeTypeTag *body;
} forNodeType;

/* Array Declaration */
typedef struct {
    int typeType;
    char *name;
    struct nodeTypeTag *size; /* if null, it's an initializer list */
    struct nodeTypeTag *initList;
} arrayDeclNodeType;

/* Array Access */
typedef struct {
    char *name;
    struct nodeTypeTag *index;
} arrayAccessNodeType;

/* Type Casting */
typedef struct {
    int toType; /* 0: number, 1: decimal */
    struct nodeTypeTag *expr;
} castNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */
    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        strNodeType str;        /* strings */
        oprNodeType opr;        /* operators */
        declarNodeType decl;
        funcNodeType func;
        forNodeType forLoop;
        arrayDeclNodeType arrDecl;
        arrayAccessNodeType arrAccess;
        castNodeType cast;
    };
} nodeType;

extern nodeType *conNodeNumber(long value);
extern nodeType *conNodeDecimal(double value);
extern nodeType *conNodeTruth(bool value);
extern nodeType *idNode(char *name);
extern nodeType *strNode(char *val, bool isF);
extern nodeType *oprNode(int oper, int nops, ...);
extern nodeType *declNode(int typeType, char *name, nodeType *expr);
extern nodeType *funcNode(int retType, char *name, nodeType *params, nodeType *body);
extern nodeType *forNode(int typeType, char *iterName, nodeType *start, nodeType *end, nodeType *step, nodeType *body);
extern nodeType *arrayDeclNodeNew(int typeType, char *name, nodeType *size);
extern nodeType *arrayDeclNodeInit(int typeType, char *name, nodeType *initList);
extern nodeType *arrayAccessNode(char *name, nodeType *index);
extern nodeType *castNode(int toType, nodeType *expr);

extern void freeNode(nodeType *p);
extern void generateJava(nodeType *p);

#endif
