def convert(number):
    result = ""
    divisibility = (number % 3 == 0, number % 5 == 0, number % 7 == 0)
    if divisibility[0]:
        result += "Pling"
    if divisibility[1]:
        result += "Plang"
    if divisibility[2]:
        result += "Plong"
    if divisibility == (False, False, False):
        result = str(number)
    return result
    