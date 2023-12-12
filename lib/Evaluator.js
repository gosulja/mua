class Evaluator {
    constructor(ast) {
        this.ast = ast;
    }

    evaluate() {
        return this.evaluate_node(this.ast);
    }

    evaluate_node(node) {
        switch (node.type) {
            case 'BinaryExpression':
                return this.evaluate_binary(node);
            case 'DigitLiteral':
                return node.value;
            default:
                throw new Error('Invalid AST node type: ' + node.type);
        }
    }

    evaluate_binary(node) {
        const left_value = this.evaluate_node(node.left);
        const right_value = this.evaluate_node(node.right);

        switch (node.operator) {
            case '+':
                return left_value + right_value;
            case '-':
                return left_value - right_value;
            case '*':
                return left_value * right_value;
            case '/':
                if (right_value == 0) throw new Error('Cannot divide by 0');

                return left_value / right_value;
            default:
                throw new Error('Invalid operator: ' + node.operator);
        }
    }
}

module.exports = Evaluator