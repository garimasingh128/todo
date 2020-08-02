# Todo

Todo is a simplistic CLI tool to manage a list of todos. The todos are listed in the order in which they were added. Internally the todos will be saved to a `.todo.db` file located in the HOME directory of the user, so `/home/<username>/.todo.db` by default. If the tool is unable to open the file for writing, there will be an error message.

## Compile

The tool has been tested to compile with a recent version of GCC. To compile the tool, run `make`.

## Usage

To see all todos, run the tool with no arguments.

```
$ ./todo
1. Feed the cat
2. Buy groceries
3. Clean the floors
```

To add a new todo, run the tool with arguments `add <text for the todo>`. The new todo will be added to the end of the list and the list of todos will be printed.

```
$ ./todo add Feed the dog
1. Feed the cat
2. Buy groceries
3. Clean the floors
4. Feed the dog
```

To mark a todo as done, run the tool with arguments `done <number of the todo>`. If a todo can be found with the given number, it will be removed from the list and the list of todos will be printed.

```
$ ./todo done 2
1. Feed the cat
2. Clean the floors
3. Feed the dog
```

All invalid commands will be silently ignored.