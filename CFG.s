// IMPORT : link "[.*][\.q]"
// MACRO : macro IDENTIFIER REPLACEMENT_TEXT

PROGRAM -> DECL
        |  FUNCTION
        |  PROGRAM PROGRAM
        |  /* epsilon */

STMTS -> STMT STMTS
      |  STMT
CODE_BLOCK -> STMT
           |  { STMTS }

STMT -> DECL
     |  ASSIGNMENT
     |  CONDITIONAL
     |  FOR
     |  WHILE
     |  DOWHILE
     |  JUMP
     |  SELECT
     |  EXPR;

// STATEMENTS
DECL -> SCOPE MODIFIER TYPE DECL_LIST;
DECL_LIST -> ID
          |  ID = EXPR
          |  DECL_LIST , DECL_LIST
          // DOES NOT SUPPORT UNDEFINED DIMENSIONS

ASSIGNMENT -> ID = EXPR;

CONDITIONAL -> if ( EXPR ) CODE_BLOCK ELIF
   |  if ( EXPR ) CODE_BLOCK ELIF else CODE_BLOCK
ELIF -> elif ( EXPR ) CODE_BLOCK ELIF
     |  /* epsilon */

FOR -> for ID in ( EXPR ,  EXPR ) CODE_BLOCK
WHILE -> while ( EXPR ) CODE_BLOCK
DOWHILE -> do CODE_BLOCK while( EXPR );

JUMP -> return EXPR;

SELECT -> select ( EXPR ) { CASE_LIST }
CASE_LIST -> case EXPR : STMTS CASE_LIST
          |  default : STMTS
          | /* epsilon */

FUNCTION -> def ID ( ARG_LIST ) => TYPE { STMTS }
ARG_LIST -> TYPE ID , ARG_LIST
         |  TYPE ID
         | /* epsilon */

FUNCTION_CALL -> ID ( PARAM_LIST )

PARAM_LIST -> EXPR , PARAM_LIST
           |  /* epsilon */
        
SCOPE -> global
      |  /* epsilon */

MODIFIER -> static
         |  const
         |  static const
         |  const static
         |  /* epsilon */

TYPE -> D_TYPE | D_TYPE [ DIM ]
DIM -> EXPR , DIM
    |  EXPR
D_TYPE -> int
     | float
     | char
     | bool
     | string

EXPR -> EXPR ? EXPR : EXPR
     | EXPR BIN_OP EXPR
     | UNARY_OP EXPR
     | EXPR UNARY_OP
     | ( EXPR )
     | FUNCTION_CALL
     | ID
     | LITERAL
     | { LIST }
LIST -> EXPR , LIST
     |  EXPR

BIN_OP -> ARTM_OP
       |  REL_OP
       |  LOGCL_OP
       |  BIT_OP
ARTM_OP -> +
        |  -
        |  *
        |  /
        |  %
REL_OP -> <
       |  <=
       |  >
       |  >=
       |  ==
       |  !=
LOGCL_OP -> &&
         |  ||
         |  !
BIT_OP -> &
       |  |
       |  <<
       |  >>
       |  ^

UNARY_OP -> ++
         |  --
         |  ~

