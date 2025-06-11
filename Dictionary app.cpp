
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Dictionary {
private:
    map<string, string> words;
    string toLowerCase(const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

public:
  
    void addWord(const string& word, const string& definition) {
        string lowerWord = toLowerCase(word);
        words[lowerWord] = definition;
        cout << "Word '" << word << "' added successfully!" << endl;
    }
 
    void searchWord(const string& word) {
        string lowerWord = toLowerCase(word);
        auto it = words.find(lowerWord);
        
        if (it != words.end()) {
            cout << "\n" << setw(15) << left << "Word:" << word << endl;
            cout << setw(15) << left << "Definition:" << it->second << endl;
        } else {
            cout << "Word '" << word << "' not found in dictionary." << endl;
        }
    }

    void displayAll() {
        if (words.empty()) {
            cout << "Dictionary is empty." << endl;
            return;
        }
        
        cout << "\n=== DICTIONARY ===" << endl;
        cout << string(50, '-') << endl;
        
        for (const auto& pair : words) {
            cout << setw(15) << left << pair.first << " : " << pair.second << endl;
        }
        cout << string(50, '-') << endl;
        cout << "Total words: " << words.size() << endl;
    }
    
    // Delete a word
    void deleteWord(const string& word) {
        string lowerWord = toLowerCase(word);
        auto it = words.find(lowerWord);
        
        if (it != words.end()) {
            words.erase(it);
            cout << "Word '" << word << "' deleted successfully!" << endl;
        } else {
            cout << "Word '" << word << "' not found in dictionary." << endl;
        }
    }
    
    
    int getSize() const {
        return words.size();
    }
};

void displayMenu() {
    cout << "\n=== DICTIONARY APP ===" << endl;
    cout << "1. Add Word" << endl;
    cout << "2. Search Word" << endl;
    cout << "3. Display All Words" << endl;
    cout << "4. Delete Word" << endl;
    cout << "5. Dictionary Stats" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
}

void initializeDictionary(Dictionary& dict) {

    dict.addWord("Algorithm", "A step-by-step procedure for solving a problem");
    dict.addWord("Computer", "An electronic device for processing data");
    dict.addWord("Programming", "The process of creating computer software");
    dict.addWord("Database", "A structured collection of data");
    dict.addWord("Network", "A group of interconnected computers");
    cout << "\nDictionary initialized with sample words!\n" << endl;
}

int main() {
    Dictionary dictionary;
    int choice;
    string word, definition;
    
    cout << "Welcome to the C++ Dictionary App!" << endl;
    initializeDictionary(dictionary);
    
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); 
        
        switch (choice) {
            case 1: {
                cout << "Enter word: ";
                getline(cin, word);
                cout << "Enter definition: ";
                getline(cin, definition);
                
                if (!word.empty() && !definition.empty()) {
                    dictionary.addWord(word, definition);
                } else {
                    cout << "Word and definition cannot be empty!" << endl;
                }
                break;
            }
            
            case 2: {
                cout << "Enter word to search: ";
                getline(cin, word);
                
                if (!word.empty()) {
                    dictionary.searchWord(word);
                } else {
                    cout << "Please enter a valid word!" << endl;
                }
                break;
            }
            
            case 3: {
                dictionary.displayAll();
                break;
            }
            
            case 4: {
                cout << "Enter word to delete: ";
                getline(cin, word);
                
                if (!word.empty()) {
                    dictionary.deleteWord(word);
                } else {
                    cout << "Please enter a valid word!" << endl;
                }
                break;
            }
            
            case 5: {
                cout << "\n=== DICTIONARY STATS ===" << endl;
                cout << "Total words in dictionary: " << dictionary.getSize() << endl;
                break;
            }
            
            case 6: {
                cout << "Thank you for using Dictionary App! Goodbye!" << endl;
                return 0;
            }
            
            default: {
                cout << "Invalid choice! Please enter a number between 1-6." << endl;
                break;
            }
        }
        
        cout << "\nPress Enter to continue...";
        cin.get();
    }
    
    return 0;
}
