#include "Singleton.h"

class GameConfig : public Singleton <GameConfig>
{
	friend class Singleton<GameConfig>;

private:
	GameConfig()
	{
		minBet = 100;
		mediumBet = 250;
		largeBet = 500;
		maxBet = 1000;
	};

	int minBet;
	int mediumBet;
	int largeBet;
	int maxBet;

public:
	~GameConfig() {};

	int GetMinBet() { return minBet; }
	int GetMediumBet() { return mediumBet; }
	int GetLargeBet() { return largeBet; }
	int GetMaxBet() { return maxBet; }
};
