# Get_Next_Line

This function realized in C allows you to read line by line a content of an input, such as a file, the standard input or even a network connection.<br>
Realization of bonuses such as the management of several file descriptor, the management of several entries simultaneously.<br>

## Usage

- Clone Repository
```bash
git clone https://github.com/vvaucoul/Get_Next_Line && cd Get_Next_Line
```

- Compilation
```bash
gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -c
```

- Compilation with bonus
```bash
gcc -D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c -c
```

> BUFFER_SIZE: Size of the number of bytes read **(x > 0 && x < 4096)**.

Now with .o files you can compile it with your **main.c**

## Prototypes

```C
int get_next_line(int fd, char **line);
```

## Example

<img src="https://user-images.githubusercontent.com/66129673/198588505-9b36ccd1-8a63-4867-bb67-695ae191275f.png" width="50%"/>

- Compilation with main.c
```bash
gcc main.c get_next_line.o get_next_line_utils.o -o a.out
```

- Execution
```bash
echo "Hello World" | ./a.out
```

> Result: "Line: Hello World"
