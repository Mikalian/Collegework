def response(hey_bob): 
    if not (hey_bob := hey_bob.strip()):
        return "Fine. Be that way!"
    is_yelling = hey_bob.isupper()
    is_question = hey_bob.endswith("?")    
    tone = (is_yelling, is_question)
    result = "Whatever."
    match tone:
        case (False, True):
            result = "Sure."
        case (True, False):
            result = "Whoa, chill out!"
        case (True, True):
            result = "Calm down, I know what I'm doing!"
    return result
    