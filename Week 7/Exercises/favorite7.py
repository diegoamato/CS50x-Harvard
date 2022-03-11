import csv

titles = {}

with open("favorite.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["TITLE"].strip().upper()
        if title in titles:
            titles[title] += 1
        else:
            titles[title] = 1

def get_value(title):
    return titles[title]

for title in sorted(titles, key=get_value, reverse=True):
    print(title, titles[title])