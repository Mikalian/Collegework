def response(hey_bob):
    hey_bob = hey_bob.strip()
    is_silence = not hey_bob
    is_yelling = hey_bob.isupper()
    is_question = hey_bob.endswith('?')
    if [is_yelling, is_question, is_silence] == [False, True, False]:
        return "Sure."
    if [is_yelling, is_question, is_silence] == [True, False, False]:
        return "Whoa, chill out!"
    if [is_yelling, is_question, is_silence] == [True, True, False]:
        return "Calm down, I know what I'm doing!"
    if [is_yelling, is_question, is_silence] == [False, False, True]:
        return "Fine. Be that way!"
    return "Whatever."