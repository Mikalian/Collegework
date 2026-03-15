def is_armstrong_number(number):
    length = len(str(number))
    return sum(digit ** length for digit in list(map(int, str(number)))) == number
