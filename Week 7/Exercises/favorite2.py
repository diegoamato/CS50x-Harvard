import csv

with open("favorite.csv", "r") as file:
    reader = csv.DictReader(file)
    next(reader)
    for row in reader:
        print(row)
        print(row["TITLE"])