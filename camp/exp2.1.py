# Craps Roller
# Demonstrates random number generation

 

import random

 

# generate random numbers 1 - 6
dice1 = random.randint(1, 6) 
dice2 = random.randrange(1, 6)

 

total = dice1 + dice2

 

print("You rolled a", dice1, "and a", dice2, "for a total of", total)

 

input("\n\nPress the enter key to exit.")