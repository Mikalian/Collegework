def classify(number):
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """
    if (number <= 0):
        raise ValueError("Classification is only possible for positive integers.")
    aliquot_sum = sum(value for value in range(1,number) if number % value == 0) 
    if aliquot_sum == number:
        return "perfect"
    if aliquot_sum >= number:
        return "abundant"
    return "deficient"