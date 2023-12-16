#pragma once

#include <cctype>
#include <string>

enum TokenType {
    INTEGER,
    IDENTIFIER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    ASSIGN,
    SEMICOLON,
    ENDOF,
    UNKNOWN,
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::string input;
    size_t position;

    char current_char();
    void advance();
    void skip_whitespace();
    Token parse_ii();

public:
    Lexer(const std::string& input);
    Token get_next_token();
};
