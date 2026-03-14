def equilateral(sides):
    if not is_legal_triangle(sides):
        return False
    a, b, c = sides
    return a == b == c


def isosceles(sides):
    if not is_legal_triangle(sides):
        return False
    a, b, c = sides
    return a == b or b == c or c == a


def scalene(sides):
    if not is_legal_triangle(sides):
        return False
    a, b, c = sides
    return a != b and b != c and c != a


def is_legal_triangle(sides):
    """
    :param sides: list - the sides of the triangle.
    :return: bool - whether the sides are legal.
    """
    a, b, c = sides
    return (a + b >= c) and (b + c >= a) and (a + c >= b) and (a > 0) and (b > 0) and (c > 0)
