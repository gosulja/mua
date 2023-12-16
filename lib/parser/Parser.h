#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "../lexer/Lexer.h"
#include "../types/Registry.h"

enum class NodeType {
	Delcaration,
	BinaryExpression,
	DigitLiteral,
};

struct Node {
	NodeType type;
};

struct ASTNode {
	virtual ~ASTNode() = default;
};

struct BinaryExpressionNode : public ASTNode {
	char operator_sym;
	std::shared_ptr<ASTNode> left;
	std::shared_ptr<ASTNode> right;

	BinaryExpressionNode(char op, std::shared_ptr<ASTNode> l, std::shared_ptr<ASTNode> r)
		: operator_sym(op), left(l), right(r) {}
};

struct DigitLiteral : ASTNode {
	int value;

	DigitLiteral(int value) : value(value) {}
};

struct DeclarationNode : ASTNode {
	std::string data_type;
	std::string variable_name;
	std::shared_ptr<ASTNode> expression;

	DeclarationNode(const std::string& dt, const std::string& vn, std::shared_ptr<ASTNode> exp)
		: data_type(dt), variable_name(vn), expression(exp) {}
};



class Parser {
private:
	std::vector<Token> tokens;
	size_t current_index;
	std::shared_ptr<Registry> registry;

	Token current_token();
	void advance();

	std::shared_ptr<ASTNode> parse_declaration(const std::string& keyword);
	std::shared_ptr<ASTNode> parse_statement();
	std::shared_ptr<ASTNode> parse_expression();
	std::shared_ptr<ASTNode> parse_term();
	std::shared_ptr<ASTNode> parse_factor();

public:
	Parser(const std::vector<Token>& tokens, std::shared_ptr<Registry> registry);

	std::shared_ptr<ASTNode> parse();
};
