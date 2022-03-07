from cs50 import get_string


# Implements main function
def main():

    # Get the text
    text = get_string("Text: ")

    # Implements text parsing
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Coleman-Liau index calculate
    L = (100 * letters) / words
    S = (100 * sentences) / words

    index = 0.0588 * L - 0.296 * S - 15.8

    # Print result
    if index > 15:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index:.0f}")
# ==================================


# Count the letters of the text
def count_letters(text):
    cl = 0
    for i in range(len(text)):
        if text[i].isupper() or text[i].islower():
            cl += 1
    # print(cl)
    return cl
# ==================================


# Count the words of the text
def count_words(text):
    cw = 1
    for i in range(len(text)):
        if(text[i] == " "):
            cw += 1
    # print(cw)
    return cw
# ==================================


# Count the sentences of the text
def count_sentences(text):
    cs = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            cs += 1
    # print(cs)
    return cs
# ==================================


# Call main function
main()