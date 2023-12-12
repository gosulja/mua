class Lexer {
    constructor(input) {
        this.input = input;
        this.pos = 0;
        this.current_char = this.input[0];
        this.tokens = [];
    }

    advance() {
        this.pos++;
        this.current_char = this.input[this.pos];
    }

    lex() {
        while (this.pos < this.input.length) {
            // Check and skip any whitespaces
            if (/\s/.test(this.current_char)) {
                this.advance();

            // Check and parse digits.
            } else if (/\d/.test(this.current_char)) {
                let digit = '';
                while (/\d/.test(this.current_char)) {
                    digit += this.current_char;
                    this.advance();
                }

                // Push to the tokens array
                this.tokens.push({ type: 'DIGIT', value: parseInt(digit) });
            
            // Check and parse open paren
            } else if (this.current_char === '(') {
                this.tokens.push({ type: 'OPEN_PAREN' });
                this.advance();
            // Check and parse closed paren
            } else if (this.current_char === ')') {    
                this.tokens.push({ type: 'OPEN_PAREN' });
                this.advance();
            // Check and parse operators
            } else {
                const operator = this.current_char;
                this.advance();
                this.tokens.push({ type: 'OPERATOR', value: operator });
            }
        }

        return this.tokens;
    }
}

module.exports = Lexer
