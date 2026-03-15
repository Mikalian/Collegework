def score(x, y):
    distance = (x ** 2 + y ** 2) ** 0.5
    points = 0
    if distance <= 1:
        points = 10
    elif 1 < distance <= 5:
        points = 5
    elif 5 < distance <= 10:
        points = 1
    return points
