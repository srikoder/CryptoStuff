#   https://cryptopals.com/sets/1/challenges/3
import binascii
string = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
converted_string = binascii.unhexlify(string)
decoded = ''
act_key = 0
maxm = 0
for key in range(0, 256):
    arr = ''
    for i in converted_string:
        arr += chr(i ^ key)
    if arr.isprintable() == True:
        count = 0
        for c in arr:
            if c == ' ':
                count = count + 1
            # maxm = max(count,maxm)
        if(count > maxm):
            maxm = count
            decoded = arr
            act_key = key
print("Decoded String :", decoded, "\nKey :", chr(act_key))
# print(type(converted_string[1]),converted_string[3])