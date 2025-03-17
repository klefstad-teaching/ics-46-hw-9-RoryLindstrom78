#include "ladder.h"

int main() {
    set<string> all_words;
    load_words(all_words, "src/words.txt");
    vector<string> word_ladder = generate_word_ladder("car", "cheat", all_words);
    print_word_ladder(word_ladder);
} 