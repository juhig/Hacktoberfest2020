import math


# Encryption
def encryptMessage(msg):
    cipher = ""

    msg_len = float(len(msg))
    msg_lst = list(msg)
    # calculate maximum row of the matrix
    row = int(math.ceil(msg_len / col))

    # add the padding character '_' in the empty cell of the matix
    fill_null = int((row * col) - msg_len)
    msg_lst.extend('_' * fill_null)

    # create Matrix and insert message and
    # padding characters row-wise
    matrix = [msg_lst[i: i + col]
              for i in range(0, len(msg_lst), col)]

    for i in range(col):
        cipher += ''.join([row[i]
                           for row in matrix])

    return cipher


# Decryption
def decryptMessage(cipher):

    msg_indx = 0
    msg_len = float(len(cipher))
    msg_lst = list(cipher)

    row = int(math.ceil(msg_len / col))
    # create an empty matrix
    dec_cipher = []
    for _ in range(row):
        dec_cipher += [[None] * col]

    # Arrange the matrix column wise
    for i in range(col):
        for j in range(row):
            dec_cipher[j][i] = msg_lst[msg_indx]
            msg_indx += 1

    msg = ''.join(sum(dec_cipher, []))
    null_count = msg.count('_')

    if null_count > 0:
        return msg[: -null_count]

    return msg


msg = input("Enter plain text: ")
col = 4
cipher = encryptMessage(msg)
print("Encrypted Message:", cipher)
print("Decryped Message:", decryptMessage(cipher))
