#include <iostream>
#include <string>
using namespace std;

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
//Outputs !'s with .'s
void ReplaceExclamation(string& repPer) {
    unsigned int i;

    for(i = 0; i < repPer.size(); i++){
        if(repPer.at(i) == '!'){
            repPer.at(i) = '.';

        }

    }

}

//FindText function to find instances in text
void FindText(string findStr, string userStr){
    int count = 0;

    for (int i = 0; i < userStr.length(); ++i){
        char v = userStr.at(i);
        int len = findStr.length();
        if (v == findStr.at(0)) {
            string user = userStr.substr(i, len);
            if (user == findStr) {
                count++;
            }
        }
        cout << "\"" << findStr << "\" instances: " << FindText(findStr, userStr);
    }

}

//Ouputs the menu and implements the user's selection
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
                ShortenSpace(words);
                cout << "Edited text: " << words << endl << endl;
                //statements fall through to case q

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
    
   string replaceStr;
   cout<<"Enter text: ";
   getline(cin, replaceStr);

   ReplaceExclamation(replaceStr);

   cout<<replaceStr;

      
    }

    return 0;
}
