from cryptography.fernet import Fernet
#library with AES built in
#AES is implemented in ECB mode by default
#input "YELLOW SUBMARINE"

key = Fernet.generate_key();
f = Fernet(key)
m = input();
token = f.encrypt(m.encode())
print(token)
d = f.decrypt(token)
print(d)
