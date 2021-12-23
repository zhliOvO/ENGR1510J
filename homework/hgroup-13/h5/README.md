# README

### Contributor: Zhang Maizhe  521370910157

### Li Zhuoheng      521370910132

### Yao Xiaorong    521370910126

### Zhang Leyan     521370910040

## Ex1

- ### Input

  ​	 one line with one integer n (e.g. 6)

- ### Output

  ​	a space separated list of all the primes less the n on one line (e.g. 2 3 5)

## Ex2

- ### Input

  ​	 one line with one integer representing month and the three first letters of the first day of the month (e.g. 6 Fri)

- ### Output

  ​	a calender of this month

## Ex3

- ### Input

  ​	two lines, the sentence on the first and the word on the second

- ### Output

  ​	one line showing the number of times a given string occurs in a sentence

## Ex4

- ### Introduction

  ​	A projectile is fired into the air at an initial speed v0 = 30 m.s^−1 and an initial angle θ0 = 30◦ , with an initial height of 1.5m. Its trajectory can be expressed as y = 1.5 + tan(θ0)x − ( g /2/v0^2 /cos(θ0)^2 )*x^2 , where g = 9.81 is the gravitational acceleration constant.

- ### Input

  ​	 one line with a space separated list in the order v0 θ0 height range_min range_max (e.g. 30 30 1.5 75 85)

- ### Output

  ​	one line showing the x with six decimals when y=0 (e.g. 81.970131)

## Ex5

- ### Input

  ​	press the enter for three times

- ### Output

  -  First enter: printing the cards in the following order, 2 < 3 < ... < 10 < Jack < Queen < King < Ace assuming Spades < Hearts < Diamonds < Clubs
  -  Second enter: the cards after being shuffled
  -  Third enter : the cards after being sorted to the correct order

## Ex6

- ### Algorithm

  - Input : two big numbers   x , y

  - Output : the product

  - Step

    1.  Spilt x, y into two parts:  x=x1 * 10^m + x0, 

       ​											 y=y1 * 10^m + y0,   x0, y0 should be less than 10^m

    2. z0=x0*y0

    3. z1=x1*y1

    4. z2=(x1+x0) * (y1+y0) - z0 - z1

    5. x*y= z2 * 10^2m + z1 * 10^m +z0

- ### Improvement

  ​	almost all calculation are done at low binary level, which makes it very fast 

## JOJ SCORE : 440/470



## Bug : There is no bug for now



