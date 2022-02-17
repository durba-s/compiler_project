#include <regex>
#include <set>
#include <map>
using namespace std;

const regex INT("[0-9]+");
const regex FLOAT("[0-9]*\\.?[0-9]+");
const regex CHAR("'.'");
const regex BOOL("true|false");
const regex STRING("\"(\\\\.|[^\"\\\\])*\"");
const regex IDENTIFIER("[_a-zA-Z][_a-zA-Z0-9]{0,30}");
const regex FILENAME("[/_a-zA-Z0-9]+\\.q");

const set<string> keys = {
        "if",
        "elif",
        "for",
        "in",
        "while",
        "do",
        "return",
        "break",
        "continue",
        "select",
        "case",
        "default",
        "def",
        "global",
        "static",
        "const",
        "int",
        "float",
        "char",
        "bool",
        "void",
        "string",
        "true",
        "false"
    };

const set<string> operators = {
        "+",
        "-",
        "*",
        "/",
        "%",
        ">",
        ">=",
        "<",
        "<=",
        "==",
        "!=",
        "&&",
        "||",
        "!",
        "&",
        "|",
        "<<",
        ">>",
        "^",
        "+=",
        "-=",
        "*=",
        "/=",
        "%=",
        "&=",
        "|=",
        "^=",
        "++",
        "--",
        "~"
};

const set<string> special_symbols = {
            " ",
            "\n",
            "\"",
            "#",
            "{",
            "}",
            ";",
            "=",
            ",",
            "[",
            "]",
            "(",
            ")",
            ":",
            "=>",
            "?"
        };