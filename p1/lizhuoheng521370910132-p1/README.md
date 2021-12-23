# Project 1
### Contributor (Individual) : Li ZhuoHeng 521370910132
### Based on MATLAB


## Introduction
1.At a cross road cars are either moving if the light is green or waiting if it is red


2.A road is composed of two lanes, for cars going in opposite directions while the light is located on the right hand side of the cars, before the cross


  **EXPLANATION**
  
  
  Lane 1 : the upper lane
  
  
  Lane 2 : the left lane
  
  
  Lane 3 : the lower lane 
  
  
  Lane 4 : the right lane
  
  
3.The main part of this project is to animate the displacement of the cars with respect to the traffic lights


4.The choice and input of the user will impact the risk for a car crash to happen


5.If a crash occurs, the player loses


  **NOTIFICATION**
  
  
  As is required, the animation should **stop as soon a crash occurs**
  
  
  I could use "break" to cancel the main loop and stop the animation
  
  
  However, I think it may be better to **let the animation go on and see what happens next**
  
  
  You should **not manually** close the figure window otherwise it may cause errors
  
  
6.If all the cars have gone through without any problem, the player wins



## Implementation
1.Open "Project1.m" in matlab command window and run it


2.Choose the difficulty of the game by entering the number 1~4 as requested


3.If you choose to customize the parameters, please input the parameters **as recommended**


4.After running the program, **please WAIT for a few seconds** patiently before the car comes out


5.Observe how the car goes 


6.Information of the crashes and the cars which jumps the red light will be displayed in the command area


7.Please **WAIT patiently**, the figure window will automatically close soon after all the cars disappear 


8.**Do not manually** close the figure window otherwise it may cause errors


## Input
1.mode  Choice of the game's difficulty


2.n  The total number of cars


3.w  The width of the road 


4.p  The probability that a cars does not stop at the red light


5.g o r  The color cycle of a traffic light is green for g s, orange for o s, and red for r s

## Output
1.The whole animation of the crossroad in graph


2.The crash accidents (Lane and sequence)


3.The cars which **jump the red light** and their corresponding plate


## Illustration
1.The number of cars on each line is randomly decided with respect to n


2.Lights in the diagonal of the cross road have the same color


3.Each time a light changes from green to orange the cars before the light stop and
the ones which have already passed it finish crossing


4.Cars appear at the beginning of the road with respect to where they come from


4.Every second all the non-waiting cars move by one unit


## Bonus
1.Allow the player to choose a difficulty level and automatically adjust all the parameters accordingly


2.Design more realistic cars of various sizes


## Algorithms
### The whole animation of the cross road
1.Design the main loop regarding time (variable t)


2.Change the traffic light when mod(t,g+o+r)=g or g+o or 0


  We know that traffic light 1 equals light 3 and light 2 equals light 4
  
  
  So we operate 1,3 and 2,4 in groups 
  
  
  Details:
  
  
   If 0 <= mod(t,g+o+r) < g green
   
   
   If g <= mod(t,g+o+r) < g+o orange 
   
   
   If g+o <= mod(t,g+o+r) < g+o+r red
   
   
3.The cars are drawn by the function "rectangle" and moved by changing the position of it


  Details:
  
  
   Every car (eg. car1{2} for Lane 1 Car 2) is a rectangle
   
   
   Check each car's current position
   
   
   Move it by changing its position (eg. car1{1}.Position(1)=car1{1}.Position(1)+1)
   
   
   Refresh each car every 0.1 second
   
   
4.When a car reaches the front of the crossroad, if the light is green or it decides to jump the red light, it goes across the road, otherwise it stops


  Details:
  
  
   If the car is the first one to go and the light is green, move
   
   
   If the car is the first one to go and the light is red or orange and it decides to jump the red light, move
   
   
   If the car is not the first one to go and there's enough space in front of it, move
   
   
   otherwise it waits
   
   
5.Crash accidents are judged by using the function "rectint" (calculate the shared area of two rectangles). If that area is positive, a crash happens


6.To ensure that the animation runs smoothly and meanwhile easy to observe, I choose to pause **0.1 second for every scene**  (fewer second will lead to difficulty in observing)


### Car plate generating algorithm
**a) Permutation**


1.Input a set of numbers or letters as a combination (and the length l)


2.The recursive function takes s and l as input : s is the combination and n is the step number


3.For each step, exchange the position of s(n) and every s(i)  (n<=i<=l) 


4.n add by 1 and recurse to 3


5.If n reaches l, the function stops and returns the car plate


6.In all, there are l! permutations in total


  See *ex2_algorithm_generateplates.m* for implementation in MATLAB
  
  

```matlab
s=input('Please input a set of letters and numbers(No space):','s');  % a set of letters and numbers
n=1;l=length(s);
solve(s,n,l);
function  solve(s,n,l)
if n==l
    disp(s);
else
    for i=n:l
        t=s(n);s(n)=s(i);s(i)=t;
        solve(s,n+1,l);
        t=s(n);s(n)=s(i);s(i)=t;
    end
end
end
```

**b)Car plate**


1.Randomly select 6 numbers or letters as the alternative


2.Use the previous recursive function (permutation) to generate the combination


3.Randomly choose one as the car plate.


4.Check if there's a repetition


## Function features
1."Project1.m"  **The main program**


2."draw.m"  Draw the crossroad


3."generateplates.m"  Generate the plates


4."ex2_algorithm_generateplates.m" The algorithm mentioned before


## Bugs
1.When a crash happens, there would be several **same** warnings


2.The function *pause* is applied to simulate the flow of time. However, there are other commands besides pause. So the actual running time (which also varies considerably among different computers) may be larger than the ideal time


3.Haven't found bug three so far

## Changelog
See Changelog.md


## Other
**Acknowledgement**


I would like to express my sincere gratitude to all those who helped me during the completion of the project. I gratefully acknowledge the help of Professor Manuel and TAs who has offered me academic knowledge and valuable suggestions. My peer classmates and friends has also inspired me a lot. Thank you all!