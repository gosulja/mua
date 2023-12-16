const Registry = require("./Registry");

class IntType {
    constructor(value) {
        this.value = value;
    }

    add(other) {
        return new IntType(this.value + other.value);
    }

    subtract(other) {
        return new IntType(this.value - other.value);
    }

    multiply(other) {
        return new IntType(this.value * other.value);
    }

    divide(other) {
        if (other.value === 0) {
            throw new Error('Cannot divide by zero');
        }
        return new IntType(Math.floor(this.value / other.value));
    }

    equals(other) {
        return this.value === other.value;
    }

    evaluate() {
        return this.value;
    }
}

module.exports = IntType;
