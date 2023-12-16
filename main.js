const readline = require('readline');
const Lexer = require('./lib/Lexer');
const Parser = require('./lib/Parser');
const Evaluator = require('./lib/Evaluator');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('>> ', (input) => {
    const lexer = new Lexer(input);
    const tokens = lexer.lex();
  
    console.log('Tokens: ', tokens);
  
    const parser = new Parser(tokens);
    const ast = parser.parse();
  
    console.log('AST: ', ast);
  
    const evaluator = new Evaluator(ast);
    const result = evaluator.evaluate();
  
    console.log(result.evaluate());
  
    rl.close();
});