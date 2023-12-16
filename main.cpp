#include <string>
#include <iostream>
#include "lib/lexer/Lexer.h"

int main() {
	
	std::string input = "int x = 42; y = x + 10;";
	Lexer lexer(input);

	Token token;
	do {
		token = lexer.get_next_token();
		std::cout << "Token: [ type: " << token.type << ", value: " << token.value << " ]\n";
	} while (token.type != ENDOF);

	return 0;
}