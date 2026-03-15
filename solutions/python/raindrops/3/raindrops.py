def convert(number):
    result = ""
    divisibility = (number % 3 == 0, number % 5 == 0, number % 7 == 0)
    sounds = ("Pling", "Plang", "Plong")
    result = "".join(sound for is_div, sound in zip(divisibility, sounds) if is_div)
    return result or str(number)