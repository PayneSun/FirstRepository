

if __name__ == "__main__":
    with open("zh-en.txt", "r", encoding="utf-8") as fin, open("zh.txt", "w", encoding="utf-8") as fout:
        prev_word = ""
        for words in fin:
            words = words.strip().split()
            if len(words) != 0 and prev_word != words[0]:
                fout.write(words[0] + "\n")
                prev_word = words[0]

