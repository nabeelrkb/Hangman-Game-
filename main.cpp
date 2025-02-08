#include <iostream>
using namespace std;

void displayHangman(int livesLeft);
int stringLengthFinder(const char* str);
void displayWord(const char guessedWord[], int length);
int isWordGuessed(const char guessedWord[], const char orignalWord[], int length);
void displayAsciiArt();

int main(){
	int maxAttempt = 6;
	const char* wordList[] = {"PROGRAM"};
	const int wordCount = 1;
	int selectedWordIndex = 0;
	const char* orignalWord = wordList[selectedWordIndex];
	int wordLength = stringLengthFinder(orignalWord);
	char guessedWord[wordLength];
	for (int i=0; i < wordLength; i++){
		guessedWord[i] = '_';
	}
	int livesLeft = maxAttempt;
	char guessedLetter;
	bool isTheGuessCorrect;
	
	while(livesLeft>0){
		system("cls");
		displayAsciiArt();
		cout<<"Lives Left: "<<livesLeft<<endl;
		displayHangman(livesLeft);
		displayWord(guessedWord, wordLength);
		
		cout<<"Guessed a Letter: ";
		cin>>guessedLetter;
		cin.ignore(1000, '\n');
		if (guessedLetter>='a' && guessedLetter<='z'){
			guessedLetter = guessedLetter - (32);
		}
		isTheGuessCorrect = false;
		for (int i = 0; i<wordLength; i++){
			if (orignalWord[i] == guessedLetter){	
			guessedWord[i] = guessedLetter;
			isTheGuessCorrect = true;
			}	
		}
		if (isTheGuessCorrect == false){
			livesLeft--;
		}	
		if (isWordGuessed(guessedWord,orignalWord,wordLength)){
			system ("cls");
			cout<<"Congratuations you have won the game! ";
			displayWord(guessedWord, wordLength);
			return 0;
		}
	}
	system ("cls");
	cout<<"Game Over! The orignal word was: "<<orignalWord<<endl;
	displayHangman (0);
	return 0;
}
void displayAsciiArt(){
	cout << "HH   HH     AA     NN   NN  GGGGGG   MM    MM     AA     NN   NN" << endl;
    cout << "HH   HH    AAAA    NNN  NN  GG       MMM  MMM    AAAA    NNN  NN" << endl;
    cout << "HHHHHHH   AA  AA   NN N NN  GG  GGG  MM MM MM   AA  AA   NN N NN" << endl;
    cout << "HH   HH  AAAAAAAA  NN  NNN  GG   GG  MM    MM  AAAAAAAA  NN  NNN" << endl;
    cout << "HH   HH  AA    AA  NN   NN  GGGGGG   MM    MM  AA    AA  NN   NN" << endl;
}

void displayHangman(int livesLeft){
    switch (livesLeft){
		case 6:	
		cout << "  _______\n"
                " |       |\n"
                " |\n"
                " |\n"
                " |\n"
                " |\n"
                " |\n\n";
		break;
		case 5:
		cout << "  _______\n"
                " |       |\n"
                " |       O\n"
                " |\n"
                " |\n"
                " |\n"
                " |\n\n";
        break;
		case 4:
		cout << "  _______\n"
                " |       |\n"
                " |       O\n"
                " |       |\n"
                " |\n"
                " |\n"
                " |\n\n";
		break;
		case 3:
		cout << "  _______\n"
                " |       |\n"
                " |       O\n"
                " |      /|\n"
                " |\n"
                " |\n"
                " |\n\n";
		break;
		case 2:
		cout << "  _______\n"
                " |       |\n"
                " |       O\n"
                " |      /|\\\n"
                " |\n"
                " |\n"
                " |\n\n";
		break;
		case 1:
		cout << "  _______\n"
                " |       |\n"
                " |       O\n"
                " |      /|\\\n"
                " |      /\n"
                " |\n"
                " |\n\n";
        break;
		default:
		cout << "  _______\n"
                " |       |\n"
                " |       O\n"
                " |      /|\\\n"
                " |      / \\\n"
                " |\n"
                " |\n\n";
        break;
	}
}

int stringLengthFinder(const char* str){
	int length = 0;
	while(str[length] != '\0'){
		length++;
	}
	return length;
}

void displayWord(const char guessedWord[], int length){
	for (int i=0; i<length; i++){
		cout<<guessedWord[i]<<" ";
	}
	cout<<endl;
}

int isWordGuessed(const char guessedWord[], const char orignalWord[], int length){
{
	for (int i = 0; i< length; i++){
		if (orignalWord[i] != guessedWord[i]){
			return false;
		}
	}
	return true;
}
}