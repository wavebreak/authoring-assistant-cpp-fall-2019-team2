#include <iostream>
#include <string>
using namespace std;

//Outputs !'s with .'s
void ReplaceExclamation(string& words) {
    string newString;
    int index;

    while(true){

        index = words.find("!");
        if (index == -1){
            break;
        }

        words.at(index) = '.';
    }
    return;
}

//FindText function to find instances in text
void FindText(string findStr, string userStr){
    int count = 0;
    int firstLetter = userStr.find(findStr.at(0));
    string compare;

    while(firstLetter != -1){
        for (int i = 0; i < findStr.length(); ++i){

            compare += userStr.at(firstLetter + i);
        }


        if (compare == findStr) {
            count ++;
        }
        compare = "";
        firstLetter = userStr.find(findStr.at(0), firstLetter + 1);
    }

    cout << "\"" << findStr << "\" instances: " << count << endl;

}

//Outputs the sting without whitespace
string OutputWithoutWhitespace(string usrStr) {

    string newString;
    int index;

    while(true) {

        index = usrStr.find(" ");
        if (index == -1) {
            break;
        }

        newString = usrStr.substr(0, index);
        usrStr.replace(0, index + 1, newString);
    }

    return usrStr;
}

//Returns the number of non-whitespace characters
int GetNumOfNonWSCharacters(string words){

    int numOfNonWSChars;

    numOfNonWSChars = OutputWithoutWhitespace(words).size();

    return numOfNonWSChars;

}
//Returns the number of words in the string
int GetNumOfWords(const string usrStr){
    string String = usrStr;
    string newString;
    int index;
    int numWords = 1;

    if (String.size() == 0){
        return 0;

    }
    while(true) {

        index = String.find(" ");
        if (index == -1) {
            break;
        }

        newString = String.substr(0, index);
        String.replace(0, index + 1, newString);

        if (String.at(index) != ' '){
            numWords++;
        }
    }

    return numWords;
}

// removes spaces if there are two or more in a row
string ShortenSpace(string userString){

    string tempString;

    // add first element of user string to empty string
    tempString.push_back(userString.at(0));

    // begin loop comparing further characters to previous character; i = 1
    for (int i = 1; i < userString.length(); i++){

        // check if current character is a space
        if (isspace(userString.at(i))){

            // if character was a space, check to see if previous character was not a space
            if (!isspace(userString.at(i - 1))){

                // if previous was not a space, add current character to end of tempString
                tempString.push_back(userString.at(i));

            }

        }
        else{
            tempString.push_back(userString.at(i));
        }

    }

    return tempString;

}

//Outputs the menu and implements the user's selection
char PrintMenu(string words){

    char answer;

    while (true){
        cout << "MENU" << endl;
        cout << "c - Number of non-whitespace characters" << endl;
        cout << "w - Number of words" << endl;
        cout << "f - Find text" << endl;
        cout << "r - Replace all !'s" << endl;
        cout << "s - Shorten spaces" << endl;
        cout << "q - Quit" << endl;
        cout << endl << "Choose an option:";
        cin >> answer;
        cout << endl;

        switch(answer){

            case 'c':
                cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(words) << endl << endl;
                return answer;
                break;

            case 'w':
                cout << "Number of words: " << GetNumOfWords(words) << endl << endl;
                return answer;
                break;

            case 'f': //Placing braces around the case's statements create a scope for variables to be declared
            {
                string findStr;
                cin.ignore();
                cout << "Enter a word or phrase to be found:";
                getline(cin, findStr);
                FindText(findStr, words);
                break;
            }

            case 'r':
                ReplaceExclamation(words);
                cout << "Edited text: " << words << endl << endl;
                return answer;
                break;

            case 's':
                //ShortenSpace(words);
                cout << "Edited text: " << ShortenSpace(words) << endl << endl;
                break;
                    //statements fall through to case q*/

            case 'q':
                return answer;
                break;
            default:
                cout << endl << "INVALID CHOICE" << endl << endl;
        }
    }

}
int main() {


    string text;
    char answer;

    cout << "Enter a sample text:\n";
    getline(cin, text);
    cout << endl << "You entered: " << text << endl << endl;

    while(true){
        answer = PrintMenu(text);
        if (answer == 'q'){
            break;
        }
    }

    return 0;
}
