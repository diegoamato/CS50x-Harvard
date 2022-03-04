import sys

names = ["Bill", "Charlie", "Fred", "Geroge", "Ginny", "Percy", "Ron"]

if "Ron" in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)