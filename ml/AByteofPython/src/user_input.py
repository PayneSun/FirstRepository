# user_input.py
# 2017/09/15

import string

def reverse(text):
    return text[::-1]

def is_palindrome(text):
    text = text.lower()
    text = text.replace(' ', '')
    for char in string.punctuation:
        text = text.replace(char, '')
    return text == reverse(text)

def main():
    something = input('Enter text:')
    if (is_palindrome(something)):
        print("Yes, it is a palindrome")
    else:
        print("No, it is not a palindrome")

if __name__ == '__main__':
    main()
else:
    print("user_input.py was imported!")
