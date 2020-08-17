f = open("4.txt", "r")
data = f.readlines()
for line in data:
    if len(line) % 2 == 0:
        print("String which is encrypted using single-character XOR :",line)
f.close()
