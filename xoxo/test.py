import random

choices = [0,1,2,3,4,5,6,7,8]
nopls = []
while True:
    if len(nopls) == len(choices): break

    choice = random.choice(choices)
    if choice in nopls: 
        print(choice)
    else: 
        print(choice)
        nopls.append(choice)

