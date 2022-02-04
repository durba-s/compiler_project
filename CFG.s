IMPORTING : link file.q
MACRO : macro i int

PROGRAM -> DECL
        |  FUNCTION
        |  PROGRAM PROGRAM
        |  /* epsilon */
        // ADD NT FOR MACRO IN THIS ?
        // ADD SEPARTE NT FOR MAIN ??
        // WANT TO SUPPORT LINKER ??
        // ADD NT FOR DELIMITER ??
        // MAKE SEPARATE NT FOR INTEGRAL EXPRESSIONS , FLOATING EXPRESSIONS , BOOLEAN EXPRESSIONS , STRING EXPRESSIONS ?? ATTRIBUTE GRAMMAR ??

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
     |  SELECT
     |  FUNCTION_CALL_STMT
     // ADD NT FOR MACRO IN THIS ?
     // ADD JUMP STATEMENT return kaise hoga ????
     // ADD EXPR;

DECL -> SCOPE MODIFIER TYPE DECL_LIST;
DECL_LIST -> ID
          |  ID = EXPR
          |  ID[EXPR]
          |  ID[EXPR] = EXPR // NEED TO ADD SEPARATE NT FOR { EXPR , EXPR } : LIST
          |  ID[] = EXPR
          |  DECL_LIST , DECL_LIST
          // DOES NOT SUPPORT MULTI-DIMENSIONAL ARRAY

ASSIGNMENT -> ID = EXPR;

CONDITIONAL -> if ( EXPR ) CODE_BLOCK ELIF
   |  if ( EXPR ) CODE_BLOCK ELIF else CODE_BLOCK
ELIF -> elif ( EXPR ) CODE_BLOCK ELIF
     |  /* epsilon */

FOR -> for ID in ( EXPR ,  EXPR ) CODE_BLOCK
WHILE -> while ( EXPR ) CODE_BLOCK
DOWHILE -> do CODE_BLOCK while( EXPR );

SELECT -> select ( EXPR ) { CASE_LIST }
CASE_LIST -> case EXPR : STMTS CASE_LIST
          |  default : STMTS
          | /* epsilon */

FUNCTION -> def ID ( ARG_LIST ) => TYPE { STMTS }
ARG_LIST -> TYPE ID , ARG_LIST
         |  TYPE ID
         | /* epsilon */

FUNCTION_CALL_STMT -> FUNCTION_CALL_EXPR;
FUNCTION_CALL_EXPR -> ID ( PARAM_LIST )

PARAM_LIST -> EXPR , PARAM_LIST
           |  /* epsilon */
        
SCOPE -> global
      |  /* epsilon */

MODIFIER -> static
         |  const
         |  static const
         |  const static
         |  /* epsilon */

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
     | ID
     | LITERAL
     | FUNCTION_CALL_EXPR

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


// SAMPLE ARRAY [int , 3 , 3 , 3]
