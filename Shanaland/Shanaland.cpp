/*
  File Name: Shanaland.cpp
  Author: Gabriel Shanahan
  Date: 10/18/19
  Purpose: a game where your players navigate through an imaginary world (board) using an imaginary dice.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

//streams
ifstream inputStream;
string fileLine;
//integers
int numPlayers, dieRoll, goodBad;

//Allows the users to input the players names
void GetPlayersNames(string names[], int numPlayers)
{
  for(int i = 0; i < numPlayers; ++i)
  {
    cout << "PLAYER " << i + 1 << ", WHAT IS YOUR NAME?" << endl;
    cout << "NAME: ";
    getline(cin, names[i]);
    cout << endl;
  }
  cout << "____________________\n";
}

//random number generation for dice output
int RollDice(string currentPlayer)
{
  cout << "____________________" << endl;
  cout << "\n" << currentPlayer << ", PRESS ENTER TO ROLL THE DICE!" << endl;
  cin.ignore();
  srand(time(NULL));
  dieRoll = (rand() % 6) + 1;
  switch(dieRoll)
  {
  	case 1:
  		cout << " _________\n";
  		cout << "|         |\n";
  		cout << "|    o    |\n";
  		cout << "|         |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 2:
  		cout << " _________\n";
  		cout << "|         |\n";
  		cout << "|  o      |\n";
  		cout << "|      o  |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 3:
  		cout << " _________\n";
  		cout << "| o       |\n";
  		cout << "|    o    |\n";
  		cout << "|       o |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 4:
  		cout << " _________\n";
  		cout << "| o     o |\n";
  		cout << "|         |\n";
  		cout << "| o     o |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 5:
  		cout << " _________\n";
  		cout << "| o     o |\n";
  		cout << "|    o    |\n";
  		cout << "| o     o |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 6:
  		cout << " _________\n";
  		cout << "| o     o |\n";
  		cout << "| o     o |\n";
  		cout << "| o     o |\n";
  		cout << "|_________|\n\n";
  		break;
  }

  cout << "YOU ROLLED A ";
  return dieRoll;
}

//endgame function
void PlayerFinishedBoard(string names[], int boardSpace[], float score[], int numPlayers)
{
  int highestBoardSpace(0);
  string highestPlayer;
  int highestScore = score[0];
  string highestScorePlayer = names[0];
  //finds the player that reached the end of the board first
  for(int i = 0; i < numPlayers; ++i)
  {
    if(boardSpace[i] > highestBoardSpace)
    {
      highestPlayer = names[i];
      highestBoardSpace = boardSpace[i];
    }
  }
  cout << "\n___________________________________________" << endl;
  cout << "~ ~ ~YOU FINISHED SHANALAND! CONGRATULATIONS!~ ~ ~" << endl;
  cout << highestPlayer << " MADE IT TO THE END OF THE BOARD FIRST!" << endl;

  //finds the player with the highest score
  for(int i = 0; i < numPlayers; ++i)
  {
    if(score[i] > highestScore)
    {
      highestScorePlayer = names[i];
      highestScore = score[i];
    }
  }
  cout << highestScorePlayer << " HAD THE HIGHEST SCORE: " << highestScore << endl;
  cout << "___________________________________________" << endl;
}

void ActivateActionOnSpace(string names[], int boardSpace[], float score[], int numPlayers, int currentPlayerIndex)
{
  goodBad = (rand() % 2) + 1;
  string fileLine;
  int pointsGotten = ((rand() % 100000) + 1);
  srand(time(NULL));
  cout << names[currentPlayerIndex] << " IS NOW ON SPACE " << boardSpace[currentPlayerIndex] << endl;
  switch (goodBad)
  {
    case 1:
      inputStream.open("GOOD.txt");
      for(int i = 0; i < (rand() % 20) + 1; ++i)
      {
        getline(inputStream, fileLine);
      }
      inputStream.close();
      cout << "         /-\\        /-\\         " << endl;
      cout << "          O          O          " << endl;
      cout << "               oo               " << endl;
      cout << "         \\            /         " << endl;
      cout << "           \\________/           " << endl;
      cout << "GREAT! ";
      cout << fileLine << endl;
      score[currentPlayerIndex] = score[currentPlayerIndex] + pointsGotten;
      cout << "+" << pointsGotten << " POINTS! YOUR SCORE IS NOW " << score[currentPlayerIndex] << endl;
      cout << "____________________" << endl;
      break;
    case 2:
      inputStream.open("BAD.txt");
      for(int i = 0; i < (rand() % 20) + 1; ++i)
      {
        getline(inputStream, fileLine);
      }
      inputStream.close();
      cout << "         /-\\        /-\\         " << endl;
      cout << "          O          O          " << endl;
      cout << "               oo     '         " << endl;
      cout << "            ________   '        " << endl;
      cout << "          /          \\          " << endl;
      cout << "OH NO! ";
      cout << fileLine << endl;
      score[currentPlayerIndex] = score[currentPlayerIndex] - pointsGotten;
      cout << "-" << pointsGotten << " POINTS! YOUR SCORE IS NOW " << score[currentPlayerIndex] << endl;
      cout << "____________________" << endl;
      break;
  }

}

int main()
{
  char playAgain('y');
  while(playAgain == 'y' || playAgain =='Y') //game loop
  {
    bool stillPlaying(true);
    cout << "WELCOME TO" << endl;
    cout << " ____  _  _   __   __ _   __   __     __   __ _  ____ " << endl;
    cout << "/ ___)/ )( \\ / _\\ (  ( \\ / _\\ (  )   / _\\ (  ( \\(    \\" << endl;
    cout << "\\___ \\) __ (/    \\/    //    \\/ (_/\\/    \\/    / ) D (" << endl;
    cout << "(____/\\_)(_/\\_/\\_/\\_)__)\\_/\\_/\\____/\\_/\\_/\\_)__)(____/" << endl;
    cout << endl;
    cout << "How many players will there be this time? (1-20)" << endl;
    cin >> numPlayers;
    cin.ignore();
    while(numPlayers > 20 || numPlayers < 1)
    {
      cout << "Sorry that number is invalid. Enter again." << endl;
      cin >> numPlayers;
      cin.ignore();
    }

    string names [numPlayers];
    for(int i = 0; i < numPlayers; ++i)
    {
      names[i] = "";
    }

    int boardSpace [numPlayers];
    for(int i = 0; i < numPlayers; ++i)
    {
      boardSpace[i] = 0;
    }

    float score [numPlayers];
    for(int i = 0; i < numPlayers; ++i)
    {
      score[i] = 0.0;
    }

    GetPlayersNames(names, numPlayers);

    //loop that iterates until a player gets to the end of the board
    while(stillPlaying == true)
    {
      //cycles through each players turn
      for(int i = 0; i < numPlayers; ++i)
      {
        dieRoll = RollDice(names[i]);
        cout << dieRoll << endl;
        boardSpace[i] = boardSpace[i] + dieRoll;
        if(boardSpace[i] >= 25)
        {
          stillPlaying = false;
          PlayerFinishedBoard(names, boardSpace, score, numPlayers);
          break;
        }
        else
        {
          stillPlaying = true;
          ActivateActionOnSpace(names, boardSpace, score, numPlayers, i);
        }
      }
    }

    cout << "\nWould you like to play SHANALAND again? y/n" << endl; //game loop confirmation
    cin >> playAgain;
  }

  return 0;
}
