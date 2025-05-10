import random

point = 0
moves = {1: "rock", 2: "paper", 3: "scissors"}

while True:
    try:
        user_input = input("Choose your option:\n1 - Rock\n2 - Paper\n3 - Scissors\n0 - Quit\nEnter option: ").strip()
        if not user_input:
            print("No input provided. Try again.\n")
            continue

        if not user_input.isdigit():
            print("Invalid input. Please enter a number.\n")
            continue

        k = int(user_input)

        if k == 0:
            print("Thanks for playing! Your score:", point)
            break

        if k not in moves:
            print("Invalid choice. Choose 1, 2, or 3.\n")
            continue

        m = random.choice([1, 2, 3])

        print(f"\nYou chose \"{moves[k]}\"")
        print(f"Computer chose \"{moves[m]}\"")

        if k == m:
            print("It's a draw!\n")
        elif (k == 1 and m == 3) or (k == 2 and m == 1) or (k == 3 and m == 2):
            print("You win!\n")
            point += 1
        else:
            print("Computer wins!\n")

    except Exception as e:
        print("An unexpected error occurred. Try again.\n")
