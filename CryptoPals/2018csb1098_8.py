def calcRepetitions(ci):
    blength = 16
    blocks = []
    for j in range(0, len(ci), blength):
        blocks.append(ci[j: j + blength])
    repetitions = len(blocks) - len(set(blocks))  # set returns the same list after removing all the repetitions
    ans = {
        'ci' : ci,
        'repetitions' : repetitions
    }
    return ans


def main():
    c = []
    for line in open('input8.txt'):
        c.append(bytes.fromhex(line.strip()))
    numRepetitions = []
    for ci in c:
        numRepetitions.append(calcRepetitions(ci))
    maxRepetitions = sorted(numRepetitions, key=lambda x: x['repetitions'], reverse=True)[0]
    print(maxRepetitions['ci'])

if __name__ == '__main__':
    main()