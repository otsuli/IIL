# Interesting Interpreted Language

IIL. The newest, best, and most advanced interpreted coding language.

### What is IIL?

IIL is a piece of art, a compiler, a learning experiment, and most importantly a programming language. 

# Feautures

## Keywords
Almost all keywords in IIL start with ```i```, this stands for *interesting*. Because IIL is the most interesting programming language out there. 
```
iprint("Hello World")
```

## Exporting functions, methods, and variables

Like keywords, in IIL methods that you want to be exported is are begun with ```i``` so if you want to export a function to another file it can be done like this. 
```
ifunc foo()
```
## Comments 
Single line comments: 
```
## This is a single line comment
```
Multi-line comments: 
```
### This 
### is 
### a 
### multi-line
### comment
```

## Dynamic Types
IIL is dynamically typed. Meaning that you don't need to specify the type of a variable. Types are determined at runtime.

## Custom Errors
IIL makes producing custom exceptions very simple. To throw a custom exception you must first define an exception: 
```
iexception myException {
    message 
    errorCode
}
```
Then to throw the exception you use the ```explode``` keyword:
```
explode(myException("An error happened during execution", 67))
```
You can also add personalized messages for a certain throw: 

```
explode(myException("An error happened during execution", 67), "this is a custom message")
```

### Sometimes you want the interpreter to throw your own messages for syntax errors and bugs:
To throw a custom error for the entire duration of a certain code snippet it can be done like this using the ```explode``` keyword: 
```
explode myException("An error happened during this chunk", 69) {
    ifunc foo(): 
        iprint("foo")
    
    ifunc main(): 
        name = "Hello" 
        foo(name) ## This will throw the custom error we defined. 

}
```

### Sometimes you want a certain function to throw a custom error: 
First define the exception: 
```
iexception myException = "an error was thrown during this function"
```
Call the function and use the name of your exception: 
```
ifunc foo():
    iprint(foo) ## This is invalid meaning the function will throw an error

myException foo() ## The function will throw a myException that we defined
```
## Automatic quote insertion
If you forget the ending quote at the end of a string. The IIL lexer will automatically insert it for you 
```
iprint("Hello World) ## This will work
```


With IIL 
## Documentation

Read these:

- [Syntax](docs/SYNTAX.md)

## Contributing

Read this:
[Contributing](CONTRIBUTING.md)

## Code of Conduct

Read this:
[Code of Coduct](CODE_OF_CONDUCT.md)

> [!IMPORTANT]
> IIL is still under development and nowhere near done.

## License

Once IIL gets farther into development, the standard library will have a MIT license and the interpreter will have GLPv3 license. But until then the whole project is GLPv3.

## To learn more about interpreters:

This project is a learning experiment for me and I want to thank Robert Nystrom for his awesome book: **[Crafting Interpreters](https://craftinginterpreters.com)**

Without this book I wouldn't have finished this project.
