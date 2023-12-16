#include "Parser.h"

Parser::Parser(const std::vector<Token>& tokens, std::shared_ptr<Registry> registry)
	: tokens(tokens), current_index(0), registry(registry) { }

Token Parser::current_token() {
	if (current_index < tokens.size()) return tokens[current_index];

	return { TokenType::ENDOF, "" };
}

void Parser::advance() {
	current_index++;
}

std::shared_ptr<ASTNode> Parser::parse() {
	return parse_statement();
}

std::shared_ptr<ASTNode> Parser::parse_declaration(const std::string& keyword) {
	if (current_token().type == TokenType::IDENTIFIER) {
		std::string identifier = current_token().value;
		advance();

		if (current_token().type == TokenType::ASSIGN) {
			advance();
			auto expression_node = parse_expression();
			return std::make_shared<DeclarationNode>(keyword, identifier, expression_node);
		} else {
			throw std::runtime_error("Expected assingment operator \"=\"");
		}
	} else {
		throw std::runtime_error("Expected identifier after data type");
	}
}

std::shared_ptr<ASTNode> Parser::parse_statement() {
	if (current_token().type == TokenType::IDENTIFIER) {
		std::string data_type = current_token().value;
		advance();
		return parse_declaration(data_type);
	}
}
