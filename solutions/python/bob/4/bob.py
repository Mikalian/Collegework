def response(hey_bob):
    hey_bob = hey_bob.strip()
    is_yelling = hey_bob.isupper()
    is_question = hey_bob.endswith("?")
    is_silence = not hey_bob
    tone = (is_yelling, is_question, is_silence)
    match tone:
        case (False, True, False):
            return "Sure."
        case (True, False, False):
            return "Whoa, chill out!"
        case (True, True, False):
            return "Calm down, I know what I'm doing!"
        case (_, _, True):
            return "Fine. Be that way!"
        case _:
            return "Whatever."
    
    