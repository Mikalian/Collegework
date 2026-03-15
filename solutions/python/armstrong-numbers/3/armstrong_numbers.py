def is_armstrong_number(number):
    digits_list = str(abs(number))
    length = len(digits_list)
    return sum(int(digit) ** length for digit in digits_list) == number
