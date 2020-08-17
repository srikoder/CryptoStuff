def pad(m, blength):
    numPad = (blength - len(m))
    paded = (chr(numPad)*numPad).encode()
    ans = m.encode()+paded
    return ans

def main():
    c = input()
    count = 0
    for ch in c:
        if ch=='\\':
            break
        else:
            count = count+1
    unpad = c[1:count]
    print(len(c))
    if pad(unpad, len(c)-12) == "b'" + c + "'":
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()