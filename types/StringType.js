class StringType {
    constructor(value) {
        this.value = value;
    }

    concat(other) {
        return new StringType(this.value + other.value);
    }

    equals(other) {
        return this.value === other.value;
    }

    evaluate() {
        return this.value;
    }

}

module.exports = StringType
