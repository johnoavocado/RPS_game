class Opponent{

public: 
	
	// The possible moves
	enum Move{
		ROCK='R',
		PAPER='P',
		SCISSORS='S',
		UNDECIDED='U'
	};
	
	// The possible results (from the humans perspective)
	enum Result{
		WIN='W',
		LOSE='L',
		DRAW='D'
	};
	
	int humanWins, compWins;
	int gamesPlayed, maxGames;
	std::string playerName;
	// Default constructor
	Opponent();

	// Get the human's move
	void getHumanInput( );
	void getMvHuman( );
	void setMvComp(  );
	void getMvComp( );

	void resolveGame(  );
	
	
private:
	
	void updateScore();
	void outputResult();
	
	// Human move
	Move mvHuman;
	
	// Comp move
	Move mvComp;
	
	Move lastHuman;
	
	Result gameResult;
	
	
	
};