#!/usr/bin/python
import base64
from Cryptodome.Cipher import AES
from Cryptodome.Protocol.KDF import PBKDF2
from Cryptodome.Random import get_random_bytes
from Cryptodome.Hash import SHA512

def sub_cipher_encrypt(sc_clear_text,sc_shift_count):
        b64_sc_clear_text = ((str(base64.b64encode(sc_clear_text.encode('utf-8')))).split('b\'')[1]).split('\'')[0]
        clear_text_list = list(b64_sc_clear_text)
        print("DEBUG: Base64: " + b64_sc_clear_text)
        cipher_text = ""
        for i in clear_text_list:
                if i == '=':
                        continue
                else:
                        sc_shift_count = ((int(sc_shift_count) + 1)%26)
                        clear_text_ord = ord(i)
                        cipher_text_ord = clear_text_ord + int(sc_shift_count)
                        if ((clear_text_ord in range(65,91)) and (cipher_text_ord > 90)):
                                cipher_text_ord = ((cipher_text_ord - 91) + 65)
                                cipher_text = cipher_text + chr(cipher_text_ord)
                        elif ((clear_text_ord in range(97,123)) and (cipher_text_ord > 122)):
                                cipher_text_ord = ((cipher_text_ord - 123) + 97)
                                cipher_text = cipher_text + chr(cipher_text_ord)
                        elif ((clear_text_ord == 43) or (clear_text_ord == 47)):
                                if clear_text_ord == 43:
                                        cipher_text_ord = 94
                                else:
                                        cipher_text_ord = 60
                                cipher_text = cipher_text + chr(cipher_text_ord)
                        elif ((clear_text_ord in range(48,58))):
                                cipher_text_ord = (((int(sc_shift_count))%10) + clear_text_ord)
                                if cipher_text_ord > 57:
                                        cipher_text_ord = ((cipher_text_ord - 58) + 48)
                                else:
                                        cipher_text_ord = cipher_text_ord
                                cipher_text = cipher_text + chr(cipher_text_ord)
                        elif (((clear_text_ord in range(48,58)) and (cipher_text_ord <= 57)) or ((clear_text_ord in range(65,91)) and (cipher_text_ord <= 90)) or ((clear_text_ord in range(97,123)) and (cipher_text_ord <= 122))):
                                cipher_text = cipher_text + chr(cipher_text_ord)
                        else:
                                print("]["*20)                                
                                print("Why this Error, STILL?")
                                print("DEBUG: Error For: "+i)
                                print("DEBUG: Base64: " + b64_sc_clear_text)
        print("DEBUG: cipher_text: "+cipher_text)
        return cipher_text

def sub_cipher_decrypt(sc_cipher_text,sc_shift_count):
        cipher_text_list = list(sc_cipher_text)
        clear_text = ""
        for i in cipher_text_list:
                #Experimental may remove
                sc_shift_count = ((int(sc_shift_count) + 1)%26)
                #For Above Line
                cipher_text_ord = ord(i)
                clear_text_ord = cipher_text_ord - int(sc_shift_count)
                if i == '^':
                        clear_text = clear_text + '+'
                elif i == '<':
                        clear_text = clear_text + '/'
                elif ((cipher_text_ord in range(65,91)) and (clear_text_ord < 65)):
                        clear_text_ord = (91 - (65 - clear_text_ord))
                        clear_text = clear_text + chr(clear_text_ord)
                elif ((cipher_text_ord in range(97,123)) and (clear_text_ord < 97)):
                        clear_text_ord = (123 - (97 - clear_text_ord))
                        clear_text = clear_text + chr(clear_text_ord)
                elif ((cipher_text_ord in range(48,58))):
                        clear_text_ord = (cipher_text_ord - (int(sc_shift_count)%10))
                        if clear_text_ord < 48:
                                clear_text_ord = (58 - (48 - clear_text_ord))
                        else:
                                clear_text_ord = clear_text_ord
                        clear_text = clear_text + chr(clear_text_ord)
                elif (((cipher_text_ord in range(48,58)) and (clear_text_ord >= 48)) or ((cipher_text_ord in range(65,91)) and (clear_text_ord >= 65)) or ((cipher_text_ord in range(97,123)) and (clear_text_ord >= 97))):
                        clear_text = clear_text + chr(clear_text_ord)
                else:
                        print("]["*20)                                
                        print("Why this Error, STILL?")
                        print("DEBUG: Error For: "+i)
        b64_clear_text = clear_text + "===="
        print("DEBUG: clear_text :" + b64_clear_text)
        final_clear_text = ((str(base64.b64decode(b64_clear_text.encode('utf-8')))).split('b\'')[1]).split('\'')[0]
        print("DEBUG: final_clear_text: " + final_clear_text)
        return final_clear_text

def aes_gcm_encrypt(aes_plaintext, aes_password):
        bytes_aes_plaintext = aes_plaintext.encode('utf-8')
        salt = get_random_bytes(32)
        key = PBKDF2(aes_password, salt, dkLen=32, count=1000000, hmac_hash_module=SHA512)
        encrypter = AES.new(key, AES.MODE_GCM)
        aes_ciphertext, tag = encrypter.encrypt_and_digest(bytes_aes_plaintext)
        nonce = encrypter.nonce
        b64_salt = (base64.b64encode(salt).decode('utf-8')).split('=')[0]
        b64_aes_ciphertext = (base64.b64encode(aes_ciphertext).decode('utf-8')).split('=')[0]
        b64_tag = (base64.b64encode(tag).decode('utf-8')).split('=')[0]
        b64_nonce = (base64.b64encode(nonce).decode('utf-8')).split('=')[0]
        aes_delimiter = "::"
        ciphertext_compound = b64_salt + aes_delimiter + b64_aes_ciphertext + aes_delimiter + b64_tag + aes_delimiter + b64_nonce
        print("DEBUG: b64_salt: " + b64_salt)
        print("DEBUG: b64_aes_ciphertext: " + b64_aes_ciphertext)
        print("DEBUG: b64_tag: " + b64_tag)
        print("DEBUG: b64_nonce: " + b64_nonce)
        print("DEBUG: ciphertext_compound: " + ciphertext_compound)
        return ciphertext_compound

def aes_gcm_decrypt(aes_ciphertext, aes_password):
        salt = base64.b64decode((aes_ciphertext.split("::")[0])+"====")#.encode('utf-8')
        dec_ciphertext = base64.b64decode((aes_ciphertext.split("::")[1])+"====")#.encode('utf-8')
        tag = base64.b64decode((aes_ciphertext.split("::")[2])+"====")#.encode('utf-8')
        nonce = base64.b64decode((aes_ciphertext.split("::")[3])+"====")#.encode('utf-8')
        key = PBKDF2(aes_password, salt, dkLen=32, count=1000000, hmac_hash_module=SHA512)
        decrypter = AES.new(key, AES.MODE_GCM, nonce)
        #Need to put this in try for scenarios when message text does not appear authenticated
        try:
                aes_cleartext = decrypter.decrypt_and_verify(dec_ciphertext,tag)
                aes_cleartext = aes_cleartext.decode('utf-8')
                print("DEBUG: aes_cleartext: " + aes_cleartext)
                return aes_cleartext
        except ValueError as mac_mismatch:
                print("MAC Validation failed, INTEGRITY LOST!")

def sub_aes_encrypt(sub_aes_cleartext,sub_shift):
        component_list = (sub_aes_cleartext.split("::"))
        enc_component = ""
        for i in component_list:
                enc_component = enc_component + sub_cipher_encrypt(i,sub_shift) + "::"
        print("DEBUG: enc_component: " + enc_component)
        return enc_component

def sub_aes_decrypt(sub_aes_ciphertext, sub_shift):
        enc_component_list = sub_aes_ciphertext.split("::")
        clear_component = ""
        for i in enc_component_list:
                clear_component = clear_component + sub_cipher_decrypt(i,sub_shift) + "::"
        print("DEBUG: clear_component: " + clear_component)
        return clear_component
        
sub_aes_shift = input("Enter Word Number!\n")
scctext = input("Enter Text to encrypt!\n")
scshift = input("Enter the book page number\n")
aespass = input("Enter the Chosen Word!\n")
#sub_cipher_decrypt(sub_cipher_encrypt(scctext,scshift),scshift)
print("%"*20)
print("\n\n")
print("%"*20)
sub_cipher_decrypt((aes_gcm_decrypt(sub_aes_decrypt(sub_aes_encrypt(aes_gcm_encrypt(sub_cipher_encrypt(scctext,scshift),aespass),sub_aes_shift),sub_aes_shift),aespass)),scshift)
