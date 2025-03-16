#include "ladder.h"
#include <cstdlib>

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int dif = 0;
    if (str1.length() == str2.length()) {
        for (int i=0; i < word1.length(); i++) {
            if (str1[i] != str2[i]) ++dif;
        }
    }
    else {
        string greater = str1.length() > str2.length() ? str1 : str2;
        string lesser = str1.length() < str2.length() ? str1 : str2;
        
        int i=0, j=0;
        while (i < greater.length() && j < lesser.length()) {
            if (greater[i] != greater[j]) {
                if (dif >= 1) return false;
                ++dif;
                ++i;
            }
            else {
                ++i;
                ++j;
            }
        }
    }
    return dif == 1;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    if (!in) {
        //Replace by caling error function
        cerr << "Error opening file: " << file_name << endl;
        return;
    }
    else {
        while (in >> word) {
            word_list.insert(word);
        }
    }
}

