#include "ladder.h"
#include <cstdlib>

void error(string word1, string word2, string msg) {
    cout << msg << " " << word1 << " " << word2 << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int dif = 0;
    if (str1.length() == str2.length()) {
        for (int i=0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) ++dif;
        }
    }
    else {
        string greater = str1.length() > str2.length() ? str1 : str2;
        string lesser = str1.length() < str2.length() ? str1 : str2;
        
        int i=0, j=0;
        while (i < greater.length() && j < lesser.length()) {
            if (greater[i] != lesser[j]) {
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
    return dif <= 1;
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
        string word;
        while (in >> word) {
            word_list.insert(word);
        }
    }
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();

        for (const string & word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);

                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if (word == end_word) return new_ladder;

                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {};
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size() > 0) {
        cout << "Word ladder found: ";
        for (auto word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
    else {
        cout << "No word ladder found." << endl;
    }
}

#define my_assert(e) {cout << #e << ((e) ? " passed" : " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}