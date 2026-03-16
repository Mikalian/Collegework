def classify(number):
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """
    if number <= 0:
        raise ValueError("Classification is only possible for positive integers.")
    aliquot_sum = 0
    for value in range(1, int(number ** 0.5) + 1):
        if number % value == 0:
            k = number // value
            aliquot_sum += value
            if value != k:
                aliquot_sum += k
    aliquot_sum = aliquot_sum - number
    if aliquot_sum == number:
        return "perfect"
    if aliquot_sum > number:
        return "abundant"
    return "deficient"
