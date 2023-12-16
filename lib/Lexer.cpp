#include "Lexer.h"

char Lexer::current_char() {
    if (position < input.length()) {
        return input[position];
    }
    return EOF;
}

void Lexer::advance() {
    position++;
}

void Lexer::skip_whitespace() {
    while (std::isspace(current_char())) advance();
}

// Parse integers or identifiers
Token Lexer::parse_ii() {
    std::string result;
    while (std::isalnum(current_char())) {
        result += current_char();
        advance();
    }

    if (result.empty()) return { UNKNOWN, "" };

    if (std::isdigit(result[0])) return { INTEGER, result };
    else return { IDENTIFIER, result };
}

Lexer::Lexer(const std::string& input) : input(input), position(0) {}

Token Lexer::get_next_token() {
    skip_whitespace();

    if (position >= input.length()) return { ENDOF, "" };

    switch (current_char()) {
    case '+':
        advance();
        return { PLUS, "+" };
    case '-':
        advance();
        return { MINUS, "-" };
    case '*':
        advance();
        return { MULTIPLY, "*" };
    case '/':
        advance();
        return { DIVIDE, "/" };
    case '=':
        advance();
        return { ASSIGN, "=" };
    case ';':
        advance();
        return { SEMICOLON, ";" };
    default:
        return parse_ii();
    }
}
