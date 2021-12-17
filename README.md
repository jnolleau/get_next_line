# get_next_line
Function which reads content from an fd, line by line, taking `\n` as reference.

## Prototype
`int	get_next_line(int fd, char **line)`
- `int fd`: a valid fd you want to read from
- `char **line`: the pointer you want to write to

## Function returns
- `1` in case of newline available
- `0` when EOF
- `-1` in case of failiure (bad fd, memory allocation fail, etc.)

## Uses
- Compile the files with your own files
- Use it in a loop with the return of the function `> 0` as stop condition
- The `char **line` is dynamically allocated, needs to be freed at each turn of the loop
