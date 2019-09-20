/*
    File Name: program1.cpp
    Author: Gabe Shanahan
    Date: 8/30/2019
    Description: Trivia game that keeps track of the user's score and
    displays a custom message at the end depending on the user's score.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  //Variable definitions
  bool runAgain = true;
  char answer;
  int score;
  string horizontalLine(50, '-');

  do
  {
    //resets score to 0
    score = 0;

    //game introduction
    cout << horizontalLine;
    cout << "\nWelcome to Gabe's Spongebob Trivia Game!\n";
    cout << horizontalLine;
    cout << "\nMatch the following quotes with the correct characters from Spongebob Squarepants.\n\n";

    //question 1, all questions are formatted the same.
    cout << "1. \"The owner of the white sedan, you left your lights on\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'b' || answer == 'B')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 2
    cout << "2. \"This isn't normal darkness, this is advanced darkness.\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'a' || answer == 'A')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 3
    cout << "3. \"Goodbye everyone! I'll remember you all in therepy\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'e' || answer == 'E')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 4
    cout << "4. \"Ravioli, ravioli, give me the formuoli\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'e' || answer == 'E')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 5
    cout << "5. \"Remember, licking doornobs is illegal on other planets\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'a' || answer == 'A')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 6
    cout << "6. \"Do you smell it? That smell. A kind of smelly smell. The smelly smell that smells... smelly.\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'd' || answer == 'D')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 7
    cout << "7. \"The inner mechinations of my mind are an enigma\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'b' || answer == 'B')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 8
    cout << "8. \"Well, you did it. You took my one chance of happiness and crushed it. Crushed it into little tiny, bite-size pieces. \nI really had expected better of you people. I guess I'm a loser for that, too. Don't bother showing up tomorrow. \nI'll just tell them you all died in a marching accident. So, thanks. (sobbing) Thanks for nothing.\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'c' || answer == 'C')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 9
    cout << "9. \"Hmmmm... a five-letter word for happiness... money!\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'd' || answer == 'D')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //question 10
    cout << "10. \"We should take Bikini Bottom, and push it somewhere else!\"\n";
    cout << "\ta.Spongebob\n\tb.Patrick\n\tc.Squidward\n\td.Mr. Krabs\n\te.Plankton\n\n";
    cin >> answer;
    if(answer == 'b' || answer == 'B')
    {
      cout << "Correct! one point for you!\n";
      score++;
    }
    else
    {
      cout << "Sorry that's incorrect!\n";
    }

    //endgame results are displyed based on score
    cout << setw(28) << "RESULTS" << endl;
    cout << horizontalLine << endl;
    if(score == 10)
    {
        cout << "Congratulations you got a perfect score!";
    }
    else if(score >= 5 && score <= 9)
    {
      cout << "You did pretty good, but I think you can do better!";
    }
    else
    {
      cout << "Come on, you can do better... Try again!";
    }

    //outputs user's score
    cout << "\nYour score was " << score << " out of 10!\n";

    //confirmation to run again
    cout << "\nWould you like to play again? y/n: ";
    cin >> answer;
    cout << endl << endl;
    if(answer == 'n' || answer == 'N')
      runAgain = false;

  }
  while(runAgain);

  return 0;
}
