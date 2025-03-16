#include "ladder.h"
#include <cstdlib>

bool is_adjacent(const string& word1, const string& word2) {
    //If word lengths differ by anything greater than one character
    if (abs(word1.length() - word2.length()) > 1) return false;

    //This is pretty simple, if the strings are the same length, we 
    //simply iterate through the string keeping track of different
    //characters and if the number of different characters exceeds
    //one then we can return false, otherwise return true.
    if (word1.length() == word2.length()) {
        int dif = 0;
        for (int i=0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) ++dif;
            if (dif > 1) return false;
        }
        return dif == 1;
    }
    //Iterate through both strings. When we get to the characters that don't mach
    //up we check if this is the first occurence. If it is we set foundDifference to
    //true and we iterate i for the greater string. Then we continue checking. If there
    //is more than once occurence of differing chars we return false. 
    else {
        string greater = word1.length() > word2.length() ? word1 : word2;
        string lesser = word1.length() < word2.length() ? word1 : word2;

        int i = 0, j = 0;
        bool foundDifference = false;
        
        while (i < greater.length() && j < lesser.length()) {
            if (greater[i] != lesser[j]) {
                if (foundDifference) return false;
                foundDifference = true;
                ++i;
            }
            else {
                ++i;
                ++j;
            }
        }
        return true;
    }
}

