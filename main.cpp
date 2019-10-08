#include <iostream>
#include <string>
using namespace std;

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
