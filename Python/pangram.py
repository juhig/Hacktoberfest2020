# This function checks whether a string is a pangram or not. A pangram is a word or sentence that contains every letter of the alphabet at least once.
# Examples of pangrams: "The quick brown fox jumps over the lazy dog", "The five boxing wizards jump quickly", "Jim quickly realized that the beautiful gowns are expensive"

import string

def ispangram(str1, alphabet=string.ascii_lowercase):
    new_s = set(str1.replace(" ", "").lower()) # remove white spaces, get unique letters by putting into set, make everything lowercase
    alphabet =s et(string.ascii_lowercase) # make alphabet a set
    if len(alphabet.difference(new_s))==0:
        return "This is a pangram!"
    else:
        return "This is not pangram!"
