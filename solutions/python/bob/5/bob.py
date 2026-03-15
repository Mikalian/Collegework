def response(hey_bob):
    hey_bob = hey_bob.strip()
    if not hey_bob:
        return "Fine. Be that way!"
    is_yelling = hey_bob.isupper()
    is_question = hey_bob.endswith("?")    
    tone = (is_yelling, is_question)
    match tone:
        case (False, True):
            return "Sure."
        case (True, False):
            return "Whoa, chill out!"
        case (True, True):
            return "Calm down, I know what I'm doing!"
    return "Whatever."
    