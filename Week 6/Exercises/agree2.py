from cs50 import get_string

c = get_string("Do you agree?[Y/N] ")

if c.lower() in ["yes", "y"]:
    print("Agreed.")
elif c.lower() in ["no", "n"]:
    print("Not agreed.")