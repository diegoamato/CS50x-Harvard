from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)
    #or scores.append(get_int("Score: "))

average = sum(scores) / len(scores)
print(f"Average of scores: {average:.2f}")