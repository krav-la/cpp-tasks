# Data types and control flow operators
You can find a code snippet for each task in a separate directory named respectively.

Feel free to change, compile and run the code to check out its behaviour. 

> Don't forget to recompile the code once it's been modified to get a new binary with a changed behaviour.

To compile the code use Ubuntu terminal in WSL:

- Open WSL
- Invoke the following commands to install the compiler and it's dependencies
    ```
    $ sudo apt-get install g++ 
    ```
- Go to the source folder and compile the code
    > Replace the content in angled brackets with the relevant information.
    >
    > For ex., `<name_of_a_source_file>` should be replaced with `task1` to compile `task1.cpp` in the command below
    ```
    $ g++ <name_of_a_source_file>.cpp -o <name_of_a_compiled_binary>
    ```
- You can launch the compiled binary as follows
    ```
    $ ./<name_of_a_compiled_binary>
    ```
    

### Task 1
You're given the following code snippet

```    
size_t sz = 1000;
while ( --sz >= 0 )
{
	/* do something */
}
```

Can you figure out when this while loop is going to stop iterating and why?

### For loop
You're given the following code snippet

```
unsigned char half_limit = 150;

for (unsigned char i = 0; i < 2 * half_limit; ++i)
{
    // do something;
}
```

Try to figure out how many times this loop is going to execute and why.
