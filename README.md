# mol

* A very simple and flexible static scripting language which shares similar features to C++ and Rust.

# Version 0.01

* I have made the `Lexer`, `Parser` and `Evaluator` to handle very basic calculations in the terminal.
### These are very barebones and will most likeey be improved
* Right now it may have some bugs but works just fine.

### Multiplication is always carried out first! (hopefully)

![image](https://github.com/petxmr/mol/assets/111649405/02ed6bdf-5a74-4186-8384-74634e716798)

![image](https://github.com/petxmr/mol/assets/111649405/b3d16e88-07a6-4c64-a250-61a3f630f064)

# Version 0.02

* I have made some progress with the `Lexer`, `Parser`, and `Evaluator`. They each handle identifiers and data types.
* I've made one data type `IntType` and is can be declared by typing `int`.

![image](https://github.com/petxmr/mol/assets/111649405/b168da1f-baf8-45f8-9f6c-f795a8cba49c)

### As you can see here, 5 + 5 does equal to 10! :)

![image](https://github.com/petxmr/mol/assets/111649405/0489f194-b0ee-4d17-9988-7cebaf190922)

* But we can see the parser has found the random `a` after the semicolon; it sets it's value to `aundefined` which is very handy for error logging!
