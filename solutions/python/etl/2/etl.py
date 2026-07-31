def transform(legacy_data):
    new_data = {}
    for value in legacy_data:
        for letter in legacy_data[value]:
            lower_letter = letter.lower()
            new_data[lower_letter] = value
    return new_data
