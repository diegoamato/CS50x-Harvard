from cs50 import get_string

c = get_string("Do you agree?[Y/N] ")

if c in ["Y", "y", "YES", "yes", "YeS", "Yes"]:
    print("Agreed.")
elif c in ["N", "n", "NO", "no", "No"]:
    print("Not agreed.")