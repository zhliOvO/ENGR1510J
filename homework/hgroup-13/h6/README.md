

# README

### Contributor: 
### Zhang Maizhe  521370910157

### Li Zhuoheng      521370910132

### Yao Xiaorong    521370910126

### Zhang Leyan     521370910040

## Date  :November 2021


## USAGE
# ex1
scanf through an array of integers and display the numbers larger than a given random integer smaller than the max of the array
intput: int number of the integers string spaces seperated integers 
3
123 3 5435
output: 
the numbers larger than a given random integer smaller than the max of the array
e.g.random number 4
output 123 5435

# ex2
convert between polar and cartesian complex form
output: original complex converted complex(in 5 decimals) e.g.3.00000+0.80000i 3.10483e0.26060

structure:
cartesian two doubles
polar two doubles one degree and one distance
reason: this is the definiton


# ex3
count the ocurrance of a word in a sentence practice file io
word.txt sentence.txt: a word a sentence (e.g. the 
 the dog and the cat)
output: 2 in count.txt

# ex4
matrix operation
read matrix from matrices.txt
output result in result.txt

# ex5 
define a set and related operations
practice dynamic array

# ex6
input: string str, int option, char letter, char replace(if option is 1)
output: prompt and string newstr.


# ex7
Linked list is a linear data structure. It is a collection of data elements, called nodes pointing to the next node by means of a pointer.

usage: trees and graphs

types:
Singly Linked List
Doubly Linked List(or more)
Circular Linked List

reference:
https://www.tutorialride.com/data-structures/linked-list-in-data-structure.htm

https://www.programiz.com/dsa/linked-list-types#:~:text=Types%20of%20Linked%20List%20-%20Singly%20linked%2C%20doubly,last%20element%20is%20linked%20to%20the%20first%20element.

## COMPILING
For command line, run 

`gcc -Wall -Wextra -pedantic -Werror main.c ex1.c ex2.c ex3.c ex4.c -o out`

For IDE users:

Figure out where the compiler options can be adjusted and make sure you include at 
least `-Wall -Wextra -pedantic -Werror`

## RUNNING
Run your output executable. Either (in command line) with

`./out.exe -exi` or `./out -exi`

For exercise i, or (For IDEs) click "Run" then input the exercise number
(an integer) into program to run a specific exercise.


