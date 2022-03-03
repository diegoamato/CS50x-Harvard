try:
    x = int(input("X: "))
except ValueError:
    print("That is not an int!")
    exit()
try:
    y = int(input("Y: "))
except ValueError:
    print("That is not an int!")
    exit()
print (x + y)