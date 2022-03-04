from cs50 import get_string

people = {
    "Charlie": "+1-617-495-1000",
    "David": "+1-949-468-2750"
}

name = get_string("Name: ")

if name in people:
    print(f"Number: {people[name]}")
    #==============
    #ANOTHER WAY
    #number = people[name]
    #print(f"Number: {number}")
    #==============
else:
    print("Name not found")