import csv

with open("2018m.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row["team"], row["rating"])

