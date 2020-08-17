from Crypto.Cipher import AES
from Crypto import Random
#Using pyCipher Library


key = 'abcdefabcdefcdef'
iv = Random.new().read(AES.block_size)
cipher = AES.new(key, AES.MODE_CBC, iv)
msg = iv + cipher.encrypt('Yellow Submarine')
print(msg)