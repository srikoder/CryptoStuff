string = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal"
encoded = ''
c = 'I'
for i in range(0, len(string)):
    if i % 3 == 0:
        c = 'I'
    elif i % 3 == 1:
        c = 'C'
    elif i % 3 == 2:
        c = 'E'

    encoded += "{:02x}".format(ord(string[i]) ^ ord(c))
print(encoded)