words = ['happiness', 'smiles']
character_statistics = {}

for word in words:
    character_statistics[word] = {}
    for character in word:
        if character in character_statistics[word]:
            character_statistics[word][character] += 1
        else:
            character_statistics[word][character] = 1

for word, stats in character_statistics.items():
    print(f"Từ: {word}")
    for char, count in stats.items():
        print(f"  '{char}': {count}")
    print()
