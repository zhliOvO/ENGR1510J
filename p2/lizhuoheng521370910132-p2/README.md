# Project 2
### Contributor (Individual) : Li ZhuoHeng 521370910132
### Based on C


## Introduction

   One Card is a rather simple game played by n persons over a pre-decided number of rounds r. A total of d decks of Poker cards, excluding Jokers, are shuffled and c cards are offered to each player. Before the game start each player is offered an extra card to determine the playing order. This game is then discarded. The game will be played counter-clockwise, starting with the player who received the extra card with lowest rank. Once the playing order has been decided all those initial n cards are directly put in the discard pile. Finally, the game starts with the first card of the stock pile being posed face-up, to initiate the rank and suit.


   As the game starts each player, following the defined order, plays exactly one card either following the rank or the suit defined by the previous card. Any played card directly goes into the discard pile, and anyone who is unable to play should draw a card from the top of the stock pile. If the stock pile is exhausted, the discard pile is shuffled and used as stock pile.


   As soon as a player has discarded all his cards the rounds stops. All other players receive a penalty equal to the number of cards left in their hands. The player who won the round initiates the following one, all the other rules remain unchanged. At the end of the r rounds the final score of each player is determined by summing up of all his penalties. The person with highest score wins. In case of equality more than one player can be declared winner.

## Cards
Cards split into four main categories:


**Attack:**


– Cards with rank 2: the next player draws two cards from the stock pile


– Cards with rank 3: the next player draws three cards from the stock pile

**Defense:**


– Cards with rank 7: cancel an attack, i.e. do not draw any card if a 2 or a 3 was played before


**Action:**


– Queen cards: reverse the playing order from counter-clockwise to clockwise or clockwise to counter-clockwise


– Jack cards: skip the next player


-Regular: any other card has no special effect and is only used to match the previous card’s rank or suit


Notes on cards and attacks:


• The effect of the attack cards is cumulative. (**In this game you can play a plus 2 (regardless of suit as I understand) after a plus 3 and the next player receives a plus 5 attack**)


• A Queen or a Jack, of same suit as the previous card, can be played to redirect an attack on the previous player, or the player after the next one, respectively


• When under an attack, a player not playing any special card (2, 3, 7, Q, J) must draw cards from the stock pile, and this ends his turn


## Operation Manual
Use shift+right click to open windows powershell in the directory （windows）

Use terminal in the directory (linux)

If you haven't compiled the files: gcc *.c -o onecard

Enter  **./onecard -h** to see the help and start the default mode

You can adjust the parameters by entering it

eg. **./onecard -n5 -c8 -r2** (set the player to 5 with 8 cards each and play 2 rounds)

eg.**./onecard -a**(start the auto mode with default parameters)

## Bugs:
1.Too big input may cause segmentation error

2.No other serious bug found yet

## Function features:
checkcard.c: check if a card is allowed to use

clearscreen.c: clears the screen

demomode.c: automatically play a game

distribute.c: distribute the cards to players

help.c: display the help message

initialize.c: initialize the cards

printcard.c: draw a single card

printcards.c: draw all the cards of a player

shuffle.c: shuffle the deck

usecard.c: use a card from a player and put it into the used deck

main.c: the main function which runs the game


## Changelog:
See Changelog.md


## Other
**Acknowledgement**
I would like to express my sincere gratitude to all those who helped me during the completion of the project. I gratefully acknowledge the help of Professor Manuel and TAs who has offered me academic knowledge and valuable suggestions. My peer classmates and friends has also inspired me a lot. Thank you all!