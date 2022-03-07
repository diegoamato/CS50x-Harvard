from cs50 import get_int

# Ask the height for the half-pyramid's
height = get_int("Height: ")

# Test if the height is correct (1 - 8)
while height < 1 or height > 8:
    print("Insert number between 1 and 8")
    height = get_int("Height: ")

# Building the half-pyramid's
for i in range(height):
    for j in range(height - 1, i, -1):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for z in range(i + 1):
        print("#", end="")
    print("")