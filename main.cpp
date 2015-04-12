#include <iostream>
#include "opponent.h" 

using namespace std;

int main(){
	
	
	Opponent humanBeater;
	
	for(int i = 0; i<50; i++){cout << endl;}
	
	cout << "Welcome to the rock paper scissors game! " << endl << "Programmed by John O'Donnell" << endl << endl;
	
	while(humanBeater.gamesPlayed < humanBeater.maxGames)
	{
	// Decide the computer's move
	humanBeater.setMvComp();
	
	// Read in the human's move
	humanBeater.getHumanInput();
	
	
	cout << endl;

	// Read out the human's move
	humanBeater.getMvHuman();
	
	// Read out the computer's move	
	humanBeater.getMvComp();
	
	// Decide the result
	humanBeater.resolveGame();
	
	}
	
	if( humanBeater.humanWins > humanBeater.compWins )
	{
		cout << "You win. Back to the drawing board." << endl;
	}
	else if( humanBeater.compWins > humanBeater.humanWins )
	{
		cout << "I win! You lose! Haha" << endl;
	}
	else
	{
		cout << "Its a draw. Are you a computer?" << endl;
	}
	
	cout << "End of the game! Hope you had fun :) ";
	
	for(int i = 0; i<5;i++){cout<<endl;}
	
	return 0;

}

