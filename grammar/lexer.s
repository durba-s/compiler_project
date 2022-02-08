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
    string
    true
    false
}

OTHER_SYMBOLS = {
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
    ++
    --
    ~
}

INTEGER_LITERAL -> [+-]?[0-9]+
FLOAT_LITERAL -> [+-]?[0-9]*\.?[0-9]+
CHARACTER_LITERAL -> '.'
BOOLEAN_LITERAL -> true|false
STRING_LITERAL -> \"(\\.|[^"\\])*\"