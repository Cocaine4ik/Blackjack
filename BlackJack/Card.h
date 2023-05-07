#pragma once
#include <vector>
#include <string>

/**
 * @brief Card Suits where numbers represents ASCII character set
*/
enum class Suit {
    Clubs = 5,
    Diamonds = 4,
    Hearts = 3,
    Spades = 6
};

/**
 * @brief Card Ranks where numbers represents ASCII character set
*/
enum class Rank {
    Ace = 65,
    Two = 50,
    Three = 51,
    Four = 52,
    Five = 53,
    Six = 54,
    Seven = 55,
    Eight = 56,
    Nine = 57,
    Ten = 0,
    Jack = 74,
    Queen = 81,
    King = 75
};

/**
 * @brief Card class
*/
class Card
{
private:
    /**
     * @brief Card front side icon as a strign vector
    */
    std::vector<std::string> frontIcon;

    /**
     * @brief Card back side icon as a strign vector
    */
    std::vector<std::string> backIcon;

    /**
     * @brief Card suit
    */
    Suit suit;

    /**
     * @brief Card rank
    */
    Rank rank;

    /**
     * @brief Is card faced
    */
    bool isFaced = false;

public:
    /**
     * @brief Constructor
     * @param suit Suit enum class
     * @param rank Rank enum class
    */
    Card(Suit suit, Rank rank);

    /**
     * @brief Get suit
     * @return this suit
    */
    Suit GetSuit() { return this->suit; }

    /**
     * @brief Get rank
     * @return this rank
    */
    Rank GetRank() { return this->rank; }

    /**
     * @brief If card faced or no
     * @return true if is faced, false if is not
    */
    bool IsFaced() { return isFaced; }

    /**
     * @brief Set card as faced
    */
    void FaceUp() { isFaced = true; }

    /**
     * @brief Set card front icon string vector
    */
    void SetFrontIcon();

    /**
     * @brief Set card back icon string vector
    */
    void SetBackIcon();

    /**
     * @brief Get points form the card based on card rank
     * @return int
    */
    int GetPoints();

    /**
     * @brief Get card front icon, if icon isn't set - set it
     * @return &std::vector referecne of front icon
    */
    std::vector<std::string>& GetFrontIcon() { if (frontIcon.empty()) SetFrontIcon(); return frontIcon; }

    /**
     * @brief Get card back icon, if icon isn't set - set it
     * @return &std::vector reference of back icon
    */
    std::vector<std::string>& GetBackIcon() { if (backIcon.empty()) SetBackIcon(); return backIcon; }
};