import random

point = 0

while True:
    try:
        k = int(input("Choose your option:\n1 - Rock\n2 - Paper\n3 - Scissors\n0 - Quit\nEnter option: "))
        
        if k == 0:
            print("Thanks for playing! Your score:", point)
            break

        if k not in [1, 2, 3]:
            print("Invalid choice. Try again.")
            continue

        moves = {1: "rock", 2: "paper", 3: "scissors"}
        m = random.choice([1, 2, 3])

        print(f"\nYou chose \"{moves[k]}\"")
        print(f"Computer chose \"{moves[m]}\"")

        # Game Rules:
        # Rock beats Scissors
        # Paper beats Rock
        # Scissors beats Paper
        # Same move results in a draw

        if k == m:
            print("It's a draw!\n")
        elif (k == 1 and m == 3) or (k == 2 and m == 1) or (k == 3 and m == 2):
            print("You win!\n")
            point += 1
        else:
            print("Computer wins!\n")

    except ValueError:
        print("Please enter a valid number.")
