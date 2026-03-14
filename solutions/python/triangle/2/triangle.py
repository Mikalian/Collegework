def equilateral(sides):
    if not is_legal_triangle(sides):
        return False
    return len(set(sides)) == 1


def isosceles(sides):
    if not is_legal_triangle(sides):
        return False
    return len(set(sides)) <= 2


def scalene(sides):
    if not is_legal_triangle(sides):
        return False
    return len(set(sides)) == 3


def is_legal_triangle(sides):
    """
    :param sides: list - the sides of the triangle.
    :return: bool - whether the sides are legal.
    """
    a, b, c = sorted(sides)
    return a + b >= c and a > 0
