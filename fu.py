
def fu(st):
    if st=="red":
        return "\033[0;31;40m"
    elif st=="[document]":
        return " "
    elif st=="green":
        return "\033[0;32;40m"
    elif st=="brown":
        return "\033[0;33;40m"
    elif st=="blue":
        return "\033[0;34;40m"
    elif st=="magenta":
        return "\033[0;35;40m"
    elif st=="cyan":
        return "\033[0;36;40m"
    elif st=="white":
        return "\033[0;37;40m"
    elif st=="start":
        return " "
                                            
