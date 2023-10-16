#include <iostream>
#include <fstream>
#include <cstring>
 
#include <cctype>
using namespace std;

int main() {

    const int len = 101; 
    char word[len], line[len];
    cout << "Enter the word to search for: ";
    cin.getline(word, len);

    ifstream fin("Shakespeare_Hamlet.txt");
    if (!fin) {
        cout << "Error opening the file!";
        return 1;
    }

    int count = 0;
    char delimiters[] = " ,.!;:?\"\n\t"; 

    while (fin.getline(line, len)) {
        char* context = nullptr;
        char* token = strtok_s(line, delimiters, &context);
        while (token != nullptr) {
            if (strcmp(token, word) == 0) {
                count++;
            }
            token = strtok_s(NULL, delimiters, &context); //  Отримуємо наступне слово
        }
    }

    cout << "Number of occurrences of the word '" << word << "': " << count << endl;
    fin.close();
    return 0;
} 
