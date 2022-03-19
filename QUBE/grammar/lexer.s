keywords = {
    if
    elif
    else
    for
    in
    while
    do
    return
    break
    continue
    select
    case
    default
    def
    global
    static
    const
    int
    float
    char
    bool
    void
    string
    true
    false
}

SPECIAL_SYMBOLS = {
    {
    }
    ;
    =
    ,
    [
    ]
    (
    )
    :
    =>
    ?
}   

OPERATORS = {
    +
    -
    *
    /
    %
    >
    >=
    <
    <=
    ==
    !=
    &&
    ||
    !
    &
    |
    <<
    >>
    ^
    +=
    -=
    *=
    /=
    %=
    &=
    |=
    ^=
    ++
    --
    ~
}

INTEGER_LITERAL -> [0-9]+
FLOAT_LITERAL -> [0-9]*\.?[0-9]+
CHARACTER_LITERAL -> '.'
BOOLEAN_LITERAL -> true|false
STRING_LITERAL -> \"(\\.|[^"\\])*\"



  lexeme           token_name       token_id
  ----------------------------------------------
    +               OP_AR_add           1
    -               OP_AR_sub           2
    *               OP_AR_mul           3
    /               OP_AR_div           4
    %               OP_AR_mod           5
    >               OP_REL_gt           6
    >=              OP_REL_ge           7
    <               OP_REL_lt           8
    <=              OP_REL_le           9
    ==              OP_REL_eq           10
    !=              OP_REL_neq          11
    &&              OP_LOG_and          12
    ||              OP_LOG_or           13
    !               OP_LOG_not          14
    &               OP_BIT_and          15
    |               OP_BIT_or           16
    <<              OP_BIT_ls           17
    >>              OP_BIT_rs           18
    ^               OP_BIT_xor          19
    +=              OP_ASSGN1           20
    -=              OP_ASSGN2           21
    *=              OP_ASSGN3           22
    /=              OP_ASSGN4           23
    %=              OP_ASSGN5           24
    &=              OP_ASSGN6           25
    |=              OP_ASSGN7           26
    ^=              OP_ASSGN8           27
    ++              OP_INCR             28
    --              OP_DECR             29
    ~               OP_BIT4             30
    {               SYM_P1              31
    }               SYM_P2              32
    ;               SYM_SEMICOLON       33
    =               OP_ASSGN            34
    ,               OP_COMMA            35
    [               SYM_SB1             36
    ]               SYM_SB2             37
    (               SYM_B1              38
    )               SYM_B2              39
    :               OP_TERN1            40
    =>              OP_FUNC             41
    ?               OP_TERN2            42
    if              KEYWD_IF            43
    elif            KEYWD_ELIF          44
    else            KEYWD_ELSE          45
    for             KEYWD_FOR           46
    in              KEYWD_IN            47
    while           KEYWD_WHILE         48
    do              KEYWD_DO            49
    return          KEYWD_RETURN        50
    break           KEYWD_BREAK         61
    continue        KEYWD_CONTINUE      62
    select          KEYWD_SELECT        63
    case            KEYWD_CASE          64
    default         KEYWD_DEFAULT       65
    def             KEYWD_DEF           66
    global          KEYWD_GLOBAL        67
    static          KEYWD_STATIC        68
    const           KEYWD_CONST         69
    int             KEYWD_INT           70
    float           KEYWD_FLOAT         81
    char            KEYWD_CHAR          82
    bool            KEYWD_BOOL          83
    void            KEYWD_VOID          84
    string          KEYWD_STRING        85
    true            KEYWD_TRUE          86
    false           KEYWD_FALSE         87
__________________________________________________________________


|---------------------------------------------------------------
| REGEX                        |   TYPE               | id
|------------------------------|----------------------|---------
| [0-9]+                       |   INTEGER_LITERALid  | 88
| [0-9]*\.?[0-9]+              |   FLOAT_LITERALid    | 89
| '.'                          |   CHAR_LITERALid     | 90
| \"(\\.|[^"\\])*\"            |   STRING_LITERALid   | 91
| [_a-zA-Z][_a-zA-Z0-9]{0,30}  |   IDENTIFIER_id      | 93
|---------------------------------------------------------------
