const Lexer = require('./lib/Lexer');
const Parser = require('./lib/Parser');
const Evaluator = require('./lib/Evaluator');

// Implement a command like usage for test purposes.

const lexer = new Lexer(input);
const tokens = lexer.lex();

console.log('Tokens: ', tokens);

const parser = new Parser(tokens);
const ast = parser.parse();

console.log("AST: ", ast);

const evaluator = new Evaluator(ast);
const result = evaluator.evaluate();

console.log('Result:', result.evaluate());
