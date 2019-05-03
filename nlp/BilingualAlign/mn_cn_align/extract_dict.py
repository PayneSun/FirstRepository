




def decode(s):
    return ''.join([chr(i) for i in [int(b, 2) for b in s.split(' ')]])





if __name__ == "__main__":
    with open("cmdic.dat", "rb") as fin:
        for line in fin:
            print(decode(str(line)))
            # print(line.decode("unicode"))