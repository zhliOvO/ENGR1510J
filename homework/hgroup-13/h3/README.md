# README

### Contributor: Zhang Maizhe( Michael.Zhang ) 521370910157
###                                             Li Zhuoheng    521370910132

###                                                       Yao Xiaorong    521370910126

###                           Zhang Leyan   521370910040



## Ex1



- ### Output

	The result of the game(The exact number of  2^64-1)

## Ex2
- ### Output
	a picture containing a house and a car
## Ex3
- ### Output
	two lines: First: the form"type colour" whose quantity is the most( e.g. "Trousers Black")
	        Second: the rounded-down average age of these clothes
## Ex4
- ### Input
	an integar n
- ### Output
	It will display n x i = ... (0<=i<=10) in a txt file
## Ex5
- ### Input
  two lines, the fist one containing a function (e.g. @(x) x^2-3*x+1), and the second

one showing an interval with a root (e.g. [0 1])

- ### Output

	root of the function in the interval (accuracy is 0.001)
	
- ### Algorithm

  - function: root=bisection(f,x1,x2)

  - Input: f (function handle)          interval [x1 x2]

  - Step 1: x3=(x1+x2)/2

  -  Step 2: If f(x3)=0     return x3

  -  Step 3: If f(x3)*f(x2)<0  run root=bisection(f,x3,x2)
  
  -  ​             If f(x3)*f(x1)<0 run root=bisection(f,x1,x3)

  - end
  
  - Output: root
  
     

## Ex6

- ### Input
	an integar n
	
- ### Output
	It will draw an n lines pascal's triangle in a txt file

### JOJ test score: 120/120

### Bug:  There is no bug for now

