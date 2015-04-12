#include <iostream>
#include "opponent.h"

using namespace std;


// Default Constructor
Opponent::Opponent(){
	mvHuman 	 	= Opponent::ROCK;
	lastHuman  	= Opponent::ROCK;
	mvComp 		 	= Opponent::ROCK;
	gameResult 	= Opponent::DRAW;
	humanWins  	= 0;
	compWins 	 	= 0;
	gamesPlayed = 0;
	maxGames 		= 10;
	playerName 	= "Rae";
}

void Opponent::getHumanInput(){
	
	char humanInput;
	
 	cout << "Enter your choice human: ";
	cin >> humanInput;
	
	switch(humanInput)
	{
		case 'r':
		case 'R':
			this->mvHuman = Opponent::ROCK;
			break;
		case 'p':
		case 'P':
			this->mvHuman = Opponent::PAPER;
			break;
		case 's':
		case 'S':
			this->mvHuman = Opponent::SCISSORS;
			break;
		default:
			this->mvHuman = Opponent::UNDECIDED;
			break;
	}
	
}

void Opponent::getMvHuman(){

	cout << "You chose: " << (char)mvHuman << endl;	

}

void Opponent::setMvComp( ){

	if(lastHuman == Opponent::SCISSORS)
	{
		switch(gameResult)
		{
			case Opponent::WIN:
				mvComp = Opponent::ROCK;
				break;
			case Opponent::LOSE:
				mvComp = Opponent::SCISSORS;
				break;
			case Opponent::DRAW:
			default:
				mvComp = Opponent::PAPER;
				break;
		}
	}
	else if(lastHuman == Opponent::PAPER)
	{
		switch(gameResult)
		{
			case Opponent::WIN:
				mvComp = Opponent::SCISSORS;
				break;
			case Opponent::LOSE:
				mvComp = Opponent::PAPER;
				break;
			case Opponent::DRAW:
			default:
				mvComp = Opponent::ROCK;
				break;
		}
	}
	else if(lastHuman == Opponent::ROCK)
	{
		switch(gameResult)
		{
			case Opponent::WIN:
				mvComp = Opponent::PAPER;
				break;
			case Opponent::LOSE:
				mvComp = Opponent::ROCK;
				break;
			case Opponent::DRAW:
			default:	
				mvComp = Opponent::SCISSORS;
				break;
		}
	}
	else
	{
		mvComp = Opponent::ROCK;
	}

}

void Opponent::getMvComp(){
	
	cout << "I chose: " << (char)mvComp << endl;
	
}

void Opponent::resolveGame(){

	// Store the human's last move
	lastHuman = mvHuman;
	
	switch(mvHuman)
	{
		case Opponent::ROCK :
			switch(mvComp)
			{
				case Opponent::SCISSORS:
					cout << "Rock beats Scissors." << endl << "You Win." << endl;
					gameResult = Opponent::WIN;
					break;
				case Opponent::PAPER:
					cout << "Paper beats Rock." << endl << "You lose." << endl;;
					gameResult = Opponent::LOSE;
					break;
				case Opponent::ROCK:
				default:
					cout << "Rock draws with Rock." << endl << "Its a Tie." << endl;;
					gameResult = Opponent::DRAW;
					break;
			}
			break;
		case Opponent::PAPER :
			switch(mvComp)
			{
				case Opponent::ROCK:
					cout << "Paper beats Rock." << endl << "You Win." << endl;
					gameResult = Opponent::WIN;
					break;
				case Opponent::SCISSORS:
					cout << "Scissors beats Paper." << endl << "You Lose." << endl;
					gameResult = Opponent::LOSE;
					break;
				case Opponent::PAPER:
				default:
					cout << "Paper draws with Paper." << endl << "Its a Tie." << endl;
					gameResult = Opponent::DRAW;
					break;
			}
			break;
		case Opponent::SCISSORS :
			switch(mvComp)
			{
				case Opponent::PAPER:
					cout << "Scissors beats Paper." << endl << "You Win." << endl;
					gameResult = Opponent::WIN;
					break;
				case Opponent::ROCK:
					cout << "Rock beats Scissors." << endl << "You Lose." << endl;
					gameResult = Opponent::LOSE;
					break;
				case Opponent::SCISSORS:
				default:
					cout << "Scissors draws with Scissors." << endl << "Its a Tie." << endl;
					gameResult = Opponent::DRAW;
					break;
			}
			break;
		default:
			gameResult = Opponent::DRAW;
	}
		
		// Update the score
		updateScore();
		outputResult();
}

// Update the scores
void Opponent::updateScore(){
	
	switch(gameResult)
	{
		case Opponent::WIN:
			humanWins++;
			gamesPlayed++;
			break;
		case Opponent::LOSE:
			compWins++;
			gamesPlayed++;
			break;
		case Opponent::DRAW:
		default:
			gamesPlayed++;
			break;
	}

}

void Opponent::outputResult(){

	
	cout << endl << "The score is " << playerName << ": " << humanWins << " MacBook: " << compWins << endl;
	cout << "We have " << maxGames - gamesPlayed << " games remaining." << endl << endl;

}
