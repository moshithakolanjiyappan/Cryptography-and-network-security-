def monoalphabetic(text, key):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    result = ""
    for ch in text.upper():
        if ch in alphabet:
            result += key[alphabet.index(ch)]
        else:
            result += ch
    return result

key = "QWERTYUIOPASDFGHJKLZXCVBNM"
print("Encrypted:", monoalphabetic("HELLO", key))
