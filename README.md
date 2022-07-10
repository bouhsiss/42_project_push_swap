# 42_project_push_swap
personal implementation of a sorting algorirhm
## what does this project do ?
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. 
## the rules 
• You have 2 stacks named a and b.<br/>
• At the beginning:<br/>
&emsp;&emsp;◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.<br/>
&emsp;&emsp;◦ The stack b is empty.<br/>
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:<br/>
&emsp;-sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.<br/>
&emsp;-sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.<br/>
&emsp;-ss : sa and sb at the same time<br/>
&emsp;-pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.<br/>
&emsp;-pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.<br/>
&emsp;-ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.<br/>
&emsp;-rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.<br/>
&emsp;-rr : ra and rb at the same time.
&emsp;-rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.<br/>
&emsp;-rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.<br/>
&emsp;-rrr : rra and rrb at the same time.<br/>

## why is this project useful ?
&emsp; - since sorting can often reduce the complexity of a problem, it is an important algorithm in Computer Science. So you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Usage
clone the repo, execute ```make``` command and then execute ./push_swap followed by (as arguments) the stack ```a``` formatted as a list of (not sorted) integers.
**the first argument should be a the top of stack**

# Checker !
as an extra feature i implemented a programed named ```./checker``` that check if the stack ```a``` is sorted properly .
It will wait and read instructions on the standard input, each instruction will
be followed by ’\n’. Once all the instructions have been read, the program has to
execute them on the stack received as an argument.
## Usage
clone the repo, execute ```make bonus``` command and then execute ```./push_swap [random numbers] | ./checker [same random numbers]``` 
or ```./checker [random number] ``` and it reads instructions from the standard input <br/>
_If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard
output.<br/>
_In every other case, it must display "KO" followed by a ’\n’ on the standard output.<br/>
_In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or
is incorrectly formatted
