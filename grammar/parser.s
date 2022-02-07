// IMPORT : link "[.*][\.q]"
// MACRO : macro IDENTIFIER REPLACEMENT_TEXT

PROGRAM:  DECL
     |    FUNCTION
     |    PROGRAM PROGRAM
     |    /* epsilon */


STMTS:    STMT STMTS
     |    STMT
CODE_BLOCK:    STMT
          |    { STMTS }


STMT:     DECL
     |    ASSIGNMENT
     |    CONDITIONAL
     |    FOR
     |    WHILE
     |    DOWHILE
     |    JUMP
     |    SELECT
     |    EXPR;

// STATEMENTS

     // DECLARATION
     DECL:     SCOPE MODIFIER TYPE DECL_LIST;
     DECL_LIST:     ID
               |    ID = EXPR
               |    DECL_LIST , DECL_LIST
                    // DOES NOT SUPPORT UNDEFINED DIMENSIONS
     // ASSIGNMENT
     ASSIGNMENT:    ID = EXPR;
               |    ID [ DIM ] = EXPR;

     // CONDITIONAL
     CONDITIONAL:   if ( EXPR ) CODE_BLOCK ELIF
               |    if ( EXPR ) CODE_BLOCK ELIF else CODE_BLOCK
     ELIF:     elif ( EXPR ) CODE_BLOCK ELIF
          |    /* epsilon */

     // LOOPS

          // FOR
          FOR: for ID in ( EXPR ,  EXPR ) CODE_BLOCK

          // WHILE
          WHILE:    while ( EXPR ) CODE_BLOCK

          // DO WHILE
          DOWHILE:  do CODE_BLOCK while( EXPR );

     // JUMP
     JUMP:     return EXPR;

     // SWITCH CASE
     SELECT:   select ( EXPR ) { CASE_LIST }
     CASE_LIST:     case EXPR : STMTS CASE_LIST
               |    default : STMTS
               |    /* epsilon */


// FUNCTION
FUNCTION: def ID ( ARG_LIST ) => TYPE { STMTS }
ARG_LIST: TYPE ID , ARG_LIST
     |    TYPE ID
     |    /* epsilon */

FUNCTION_CALL: ID ( PARAM_LIST )
PARAM_LIST:    EXPR , PARAM_LIST
          |    /* epsilon */



// LANGUAGE SPECIFIC DETAILS        
SCOPE:    global
     |    /* epsilon */


MODIFIER: static
     |    const
     |    static const
     |    const static
     |    /* epsilon */


TYPE:     D_TYPE | D_TYPE [ DIM ]
DIM: EXPR , DIM
|    EXPR
D_TYPE:   int
     |    float
     |    char
     |    bool
     |    string


EXPR:     EXPR ? EXPR : EXPR
     |    EXPR BIN_OP EXPR
     |    UNARY_OP EXPR
     |    EXPR UNARY_OP
     |    ( EXPR )
     |    FUNCTION_CALL
     |    ID
     |    LITERAL
     |    { LIST }
LIST:     EXPR , LIST
     |    EXPR


// LITERALS
LITERAL:  INTEGER_LITERAL
     |    FLOAT_LITERAL
     |    CHARACTER_LITERAL
     |    BOOLEAN_LITERAL
     |    STRING_LITERAL


// OPERATORS

     // BINARY OPERATORS
     BIN_OP:   ARTM_OP
          |    REL_OP
          |    LOGCL_OP
          |    BIT_OP

          // ARITHMETIC OPERATORS
          ARTM_OP:  +
               |    -
               |    *
               |    /
               |    %
          
          /// RELATIONAL OPERATORS
          REL_OP:   <
               |    <=
               |    >
               |    >=
               |    ==
               |    !=

          // LOGICAL OPERATORS
          LOGCL_OP: &&
               |    ||
               |    !

          // BITWISE OPERATORS
          BIT_OP:   &
               |    |
               |    <<
               |    >>
               |    ^

     // UNARY OPERATORS
     UNARY_OP: ++
          |    --
          |    ~

