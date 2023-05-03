/*
Blackjack The Game 
by github.com/Cocaine4ik/
*/

#pragma once
#include "Singleton.h"
#include "Command.h"

class Command;

/**
 * @brief Buttons enum where numbers represents ASCII character set
*/
enum class Button 
{
    Button_SPACE = 32,
    Button_1 = 49,
    Button_2 = 50,
    Button_3 = 51,
    Button_Q = 113,
    Button_W = 119,
    Button_E = 101,
    Button_R = 114,
    Button_T = 116,
    Button_Y = 89,
    Button_N = 78,
    Button_Z = 122,
    Button_X = 120,
    Button_C = 99,
    Button_V = 118
};

/**
 * @brief Input handler class
 * part of Command pattern implementation
 * based on Singleton
*/
class InputHandler : public Singleton <InputHandler>
{
    friend class Singleton<InputHandler>;

private:
    /**
     * @brief Default constructor
    */
    InputHandler();

    /**
     * @brief Default destructor
    */
    ~InputHandler();

public:
    /**
     * @brief Hadnle keyboard input
     * if button recognized execute command
     * @param button enum class Button
    */
    void HandleInput(Button button);

    /**
     * @brief 
     * @return 
    */
    bool IsBlocked() const { return isBlocked; }
    void Block(bool value) { isBlocked = value; }


private:
    /**
     * @brief Is this input handler blocked or no
    */
    bool isBlocked;

    /**
     * @brief Command pointers for every button in game
    */
    Command* button_SPACE;
    Command* button_1;
    Command* button_2;
    Command* button_3;
    Command* button_Y;
    Command* button_N;
    Command* button_Z;
    Command* button_X;
    Command* button_C;
    Command* button_V;
    Command* button_Q;
    Command* button_W;
    Command* button_E;
    Command* button_R;
    Command* button_T;
};
