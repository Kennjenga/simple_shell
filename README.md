# simple_shell

1.Displaying the prompt

2.Reading User inputs

3.Parsing the command
  splitting inputs into tokens
  a string of commands is separated into more easily processed components

4. Searching
  once commands and arguments are parsed, the shell searches for executable files corresponding to the comman.
   It looks for executable in directories specifired by the PATH environment variable.

5. Creating a child process
   If executable is found, the shell creates a child process using system calls like fork

6. Executing the command
   (exec) to replace its own  program with the program of the command to be executed.
The new program takes over child processess execution and command runs in this process.

7. Wait for command completion
 parent process waits for child process to complete using function like wait or waitpid.
This ensures shell doesnot run next prompt until command finishes executing.

8. Dispalying output

9. Returning to the prompt

10. Exiting the sell
