import csv

titles = []

with open("favorite.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["TITLE"].strip().upper()
        if not title in titles:
            titles.append(title)

for title in titles:
    print(title)