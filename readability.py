# TODO
from cs50 import get_string


def count_letters(text):
    letter = 0
    for i in text:
        print(i)
        if i.isalpha():
            letter += 1
    return letter


def count_words(text):
    word = 0
    for i in text:
        if i == " ":
            word += 1
    word += 1
    return word


def count_sentences(text):
    sentence = 0
    for i in text:
        if i == "." or i == "!" or i == "?":
            sentence += 1
    return sentence


sentence = get_string("Enter text: ")
letter = count_letters(sentence)
print(f"{letter} letters")
word = count_words(sentence)
print(f"{word} words")
sentences = count_sentences(sentence)
print(f"{sentences} sentences")
index = 0.0
l = 100.0 * letter / word
s = 100.0 * sentences / word
index = 0.0588 * l - 0.296 * s - 15.8
print(f"{index} is index")
print(f"L= {l}")
print(f"S= {s}")
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
