def pad(m, blength):
    numPad = (blength - len(m))
    paded = (chr(numPad)*numPad).encode()
    ans = m+paded
    return ans

def main():
    blength = 20
    m = b'YELLOW SUBMARINE'
    print(pad(m, blength))

if __name__ == '__main__':
    main()