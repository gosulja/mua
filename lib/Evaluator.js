const IntType = require("../types/IntType");

class Evaluator {
    constructor(ast) {
        this.ast = ast;
        this.variables = {};
    }

    evaluate() {
        return this.evaluate_node(this.ast);
    }

    evaluate_node(node) {
        switch (node.type) {
            case 'Declaration':
                const variable_name = node.var_name;
                const expression_value = this.evaluate_node(node.expression);
                this.variables[variable_name] = expression_value;
                return expression_value;
            case 'BinaryExpression':
                return this.evaluate_binary(node);
            case 'DigitLiteral':
                return new IntType(node.value);
            default:
                throw new Error('Invalid AST node type: ' + node.type);
        }
    }

    evaluate_binary(node) {
        const left_value = this.evaluate_node(node.left);
        const right_value = this.evaluate_node(node.right);

        switch (node.operator) {
            case '+':
                return left_value.add(right_value);
            case '-':
                return left_value.subtract(right_value);
            case '*':
                return left_value.multiply(right_value);
            case '/':
                return left_value.divide(right_value);
            default:
                throw new Error('Invalid operator: ' + node.operator);
        }
    }

    evaluate_declaration(node) {
        const { data_type, var_name, expression } = node;
        const value = this.evaluate_node(expression);

        this.variables[var_name] = { data_type, value };

        return value;
    }
}

module.exports = Evaluator