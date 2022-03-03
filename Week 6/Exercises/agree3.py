from cs50 import get_string

c = get_string("Do you agree?[Y/N] ").lower()

if c in ["yes", "y"]:
    print("Agreed.")
elif c in ["no", "n"]:
    print("Not agreed.")