import csv

titles = set()

with open("favorite.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["TITLE"].strip().upper()
        titles.add(title)

for title in titles:
    print(title)