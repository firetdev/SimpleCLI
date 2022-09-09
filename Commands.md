To add a command, follow these steps:
1. Create a (name of command).h file (e.g. "list.h")
2. Include string and output.h
3. Create a function with return type std::string and two parameters:
  A. std::string params (parameters of command--use these as you want)
  B. Output &out--use this to print text to output.
4. Write command code in function--use parameters as you need
5. Include your header file in commandIncludes.h
6. Add your command name (what user enters to run it) and function name in the corresponding vectors in commands.h  
