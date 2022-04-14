#include <iostream>;
using namespace std;
#include <string>;

int row, number;//my values that i will get with cin 

bool first = true;//to start with the first player we give it true
bool second = false;


string arr[4][7] = {//my 2-D string array
		{" "," ", " ","I"," "," ", " "},
		{" "," ", "I","I","I"," ", " "},
		{" ","I","I","I","I","I", " "},
		{"I","I","I","I","I","I", "I"}
};

void printTable() {//my method for printing the array
	int a = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			cout << arr[i][j] << " ";
		}
		cout <<"row:"<<a++ << endl;//it also prints the row numbers besides the rows
	}

}

void playTwo() {//my method for playing 2 players
	while (first ||second) {//if one of them is true, it enters a while loop
		if(first==true)cout << "First player: ";
		if (second == true)cout << "Second player: ";
		cout << "Which row do you want to remove sticks from?";
		cin >> row;
		cout << "How many sticks do you want to remove?";
		cin >> number;
		cout << endl;

		if (0 < row && row < 5) {//works for these row numbers
			for (int j = 0; j < 7; j++) {
				while (number > 0 && arr[row - 1][j] == "I") {
					/*checks the indexes and changes the I
					indexes with " " acoording togiven rows and numbers*/
					arr[row - 1][j] = " ";
					number--;
				}
		
			}

			printTable();//prints the new changed array
			cout << endl;
		}

		//to check if the game ends, it checks the array values which are " " and increments the sum
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 7; j++) {
				if (arr[i][j] == " ") {
					sum++;
				}
			}
			
		}
		//if the sum of the spaces " " is 27, there is one "I" lefti so the game should end
		if (sum==27 ) {
			
			if (first == true) {
				cout << "FIRST PLAYER HAS WON"<<endl;
				first = false;
				second = false;
			}

				if (second == true) {
					cout << "SECOND PLAYER HAS WON" << endl;
					first = false;
					second = false;
				}

			}
	
		//to switch between the first player and the second player
		if (first == true && second== false) {
			first = false;
			second = true;
		}
		else if (first == false && second==true) {
			first = true;
			second = false;
		}
	}//end of the while loop
}//end of the method

//my main method
int main() {

	//creating the menu
	string input;
	cout <<"        "<<"THE GAME OF NIM" << endl;
	cout << "It's waiting for you to start the game..." << endl;
	cout << "MENU:"<<endl;
	cout << "Press 'a' to play as two player" << endl;
	cout << "Press 'b' to play against computer" << endl<<endl;
	//printing the table 
	printTable();
	//getting the input
	cin >> input;
	
	//if the player presses the key a, the game starts to play between two players
	if (input == "a") {
		playTwo();
	}
	



}