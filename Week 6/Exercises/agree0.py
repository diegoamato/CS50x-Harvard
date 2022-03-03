from cs50 import get_string

c = get_string("Do you agree?[Y/N] ")

if c == "Y" or c == "y":
    print("Agreed.")
elif c == "N" or c == "n":
    print("Not agreed.")