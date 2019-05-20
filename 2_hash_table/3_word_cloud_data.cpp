/**
 *  Determine if a any permutation of the given string is a palindrome
 *  (permutation = ordering set, 
 *   palindrome = same read forward or backwards)
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    1) how to split words from string
 *       - CHECKPOINTS: handle the end of the input string, 
 *                      hyphenated words, 
 *                      punctuation ( . , ! ? ' () ... ), 
 *                      and edge cases
 *      -> use isalpha() and check LENGTH for each word
 *
 *      cf) if thought of building the word character by character (using +=),
 *          parsing into words costs O(n^2) time 
 *          (bcuz each time new char is appended -> creates whole new string)
 * 
 *      => instead, keep track of START INDEX and LENGTH of word: O(n) time
 *         or could use stringstream
 * 
 *    2) handle duplicate words w/ different cases: (ex. how to handle "Blue", "blue", "BLue", etc.)
 *       -> various options (none are perfect; each has pros and cons)
 * 
 *          - ex. only store a word uppercase if it is always uppercase in the original string, 
 *                store a word uppercase, if it is ever uppercase in the original string
 *                use an API or other tool that identifies proper nouns, 
 *                ignore case entirely and make every word lowercase,
 *                etc.
 *       => come up with several heuristics, weigh them carefully, and choose the best solution for the given context
 * 
 *    3) take advantage of built-in functions:
 *       - chars: isalpha(), islower(), isupper(), isdigit(), tolower(), toupper()
 *       - strings: transform(s.begin(), s.end(), s.begin(), ::tolower),
 * 
 *    4) use a CLASS: 
 *       (allows us to tie our methods together, 
 *        calling them on instances of our class INSTEAD OF PASSING REFERENCES)
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  Define class WordCloudData
 *  which contains wordsToCounts_ data = map of frequency of words
 *  and methods to populate the wordsToCounds data
 *  
*/
class WordCloudData {

private:
    unordered_map<string, size_t> wordsToCounts_;

    /**
    *  helper function to count frequencies of each word
    *  (handles specifics on how to deal w/ uppercase /lowercase words)
    */
    void addWordToHashMap(string word) {

        // if word already exists in hash map,
        if (wordsToCounts_.count(word) > 0) {

            // increment its count
            wordsToCounts_[word] += 1;
        }
        // if word does not exist,
        else {

            string lowercaseWord = word;
            lowercaseWord[0] = tolower(lowercaseWord[0]);
            string capitalizedWord = word;
            capitalizedWord[0] = toupper(capitalizedWord[0]);

            // if word is capitalized and lowercase version exists in hash map,
            if (isupper(word[0]) && wordsToCounts_.count(lowercaseWord) > 0) {

                // include as lowercase version
                wordsToCounts_[lowercaseWord] += 1;
            } 
            // else, if word is lowercase and capitalized version exists in hash map
            else if (islower(word[0]) && wordsToCounts_.count(capitalizedWord) > 0) {

                // include merge two versions into lowercase version
                wordsToCounts_[word] = wordsToCounts_[capitalizedWord] + 1;
                wordsToCounts_.erase(capitalizedWord);
            } 
            else {
                // add to hash map as is
                wordsToCounts_[word] = 1;
            }
        }
    }

    /**
    *   count the frequency of each word in string
    *   (split the string into words and then, 
    *    pass each word to helper function addWordToHashMap)
    * 
    *   -> CAREFUL w/ hyphenated words, punctuation, etc.
    */
    void populateWordsToCounts(const string &inputString) {

        // split string into words (careful of punctuations!)
        vector<string> words;
        int startIndex = 0;

        for (int i = 0, n = inputString.length(); i <= n; i++) {

            // if letter is not alphabet or end of string
            if (!isalpha(inputString[i]) || i == n) {

                // if end of word (length of word > 0)
                if (i > startIndex) {

                    // include apostrophe (') and hyphen (-) between words
                    if (inputString[i] == '\'' || inputString[i] == '-') {
                        continue;
                    }

                    // parse word
                    int length = i - startIndex;
                    string word = inputString.substr(startIndex, length);
                }

                // update start to new word
                startIndex = i + 1;
            }
        }
    }

public:

    /** constructor for WordCloudData object
     *  (counts frequency of each word in given string using an unordered map)
    */
    WordCloudData(const string &inputString) {
        populateWordsToCounts(inputString);
    }

    // returns unordered map (frequency count of each word)
    const unordered_map<string, size_t> getWordsToCounts() const {
        return wordsToCounts_;
    }
};