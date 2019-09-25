/*
  File: MASH.cpp
  Author: Gabriel Shanahan
  Date: 9/20/19
  Purpose: MASH Game.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
  //variable declaration & initialization
  int yesOrNo;
  bool runAgain(true), validAnswer(false);
  string person1, person2, person3, cityState1, cityState2, cityState3, job1, job2, job3;
  string company1, company2, company3, car1, car2, car3;
  string spouse, location, company, car, job, home;
  int salary, kids;
  int smallInt1, smallInt2, smallInt3, bigInt1, bigInt2, bigInt3, randNum;

  srand(time(0));

  //asking if the user wants to play
  cout << "\n\n\n";
  cout << "     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "      __  ______   _____ __  __" << endl;
  cout << "     /  |/  /   | / ___// / / /" << endl;
  cout << "    / /|_/ / /| | \\__ \\/ /_/ / " << endl;
  cout << "   / /  / / ___ |___/ / __  /  " << endl;
  cout << "  /_/  /_/_/  |_/____/_/ /_/   " << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "      Welcome to MASH!" << endl;
  cout << "        1) Play MASH" << endl;
  cout << "        2) Exit" << endl;
  cin >> yesOrNo;

  switch (yesOrNo)
  {
    case 1:
      runAgain = true;
      break;
    case 2:
      runAgain = false;
  }

    //start of game loop
  while(runAgain == true)
   {

    cout << "\nI am going to ask you a series of questions and then tell you your future!" << endl;
    cout << "Please answer them honestly! Let's begin." << endl;

    //user inputs
    cout << "\nEnter a person you like." << endl;
    cin.ignore();
    getline(cin, person1);
    cout << "Enter another person you like." << endl;
    getline(cin, person2);
    cout << "Enter a person you hate." << endl;
    getline(cin, person3);

    //numbers 1-100 inputs
    cout << "\nNow, tell me three whole numbers from 1-100." << endl;
    cin >> smallInt1;

    while((smallInt1 < 1) || (smallInt1 > 100))
    {
      cout << "Invalid input. Try again." << endl;
      cin >> smallInt1;
    }
    cin >> smallInt2;
    while((smallInt2 < 1) || (smallInt2 > 100))
    {
      cout << "Invalid input. Try again." << endl;
      cin >> smallInt2;
    }
    cin >> smallInt3;
    while((smallInt3 < 1) || (smallInt3 > 100))
    {
      cout << "Invalid input. Try again." << endl;
      cin >> smallInt3;
    }

   cout << "\nEnter a city, state you like." << endl;
   cin.ignore();
   getline(cin, cityState1);
   cout << "Enter another city, state you like." << endl;
   getline(cin, cityState2);
   cout << "Enter a city, state you hate." << endl;
   getline(cin, cityState3);

   cout << "\nEnter a job you like." << endl;
   getline(cin, job1);
   cout << "Enter another job you like." << endl;
   getline(cin, job2);
   cout << "Enter a job you hate." << endl;
   getline(cin, job3);

   cout << "\nEnter a company/restaurant you like." << endl;
   getline(cin, company1);
   cout << "Enter another company/restaurant you like." << endl;
   getline(cin, company2);
   cout << "Enter a company/restaurant you hate." << endl;
   getline(cin, company3);

   cout << "\nNow, tell me three whole numbers between 10000 and 500000." << endl;
   validAnswer = true;
   cin >> bigInt1;
   while((bigInt1 < 10000) || (bigInt1 > 500000))
   {
     cout << "Invalid input. Try again." << endl;
     cin >> bigInt1;
   }
   cin >> bigInt2;
   while((bigInt2 < 10000) || (bigInt2 > 500000))
   {
     cout << "Invalid input. Try again." << endl;
     cin >> bigInt2;
   }
   cin >> bigInt3;
   while((bigInt3 < 10000) || (bigInt3 > 500000))
   {
     cout << "Invalid input. Try again." << endl;
     cin >> bigInt3;
   }

   cout << "\nEnter a car you like." << endl;
   cin.ignore();
   getline(cin, car1);
   cout << "Enter another car you like." << endl;
   getline(cin, car2);
   cout << "Enter a car you hate." << endl;
   getline(cin, car3);

   //random number generation & switch statements
   randNum = rand() % 4;
   switch(randNum)
   {
     case 0:
      home = "a Mansion";
      break;
     case 1:
      home = "an Apartment";
      break;
     case 2:
      home = "a Shack";
      break;
     case 3:
      home = "a House";
      break;
   }
   cout << "\n\n";
   cout << "You will live in " << home << "." << endl;

   randNum = rand() % 3;
   switch(randNum)
   {
     case 0:
      spouse = person1;
      break;
     case 1:
      spouse = person2;
      break;
     case 2:
      spouse = person3;
      break;
   }
   cout << "You will be happily married to " << spouse << "." << endl;

   randNum = rand() % 3;
   switch(randNum)
   {
     case 0:
      kids = smallInt1;
      break;
     case 1:
      kids = smallInt2;
      break;
     case 2:
      kids = smallInt3;
      break;
   }
   cout << "You and " << spouse << " will have " << kids << " children." << endl;

   randNum = rand() % 3;
   switch(randNum)
   {
     case 0:
      location = cityState1;
      break;
     case 1:
      location = cityState2;
      break;
     case 2:
      location = cityState3;
      break;
   }
   cout << "You will live in " << location << "." << endl;

   //company selection
   randNum = rand() % 3;
   switch(randNum)
   {
     case 0:
      company = company1;
      break;
     case 1:
      company = company2;
      break;
     case 2:
      company = company3;
      break;
   }
   //job position selection
   randNum = rand() % 3;
   switch(randNum)
   {
     case 0:
      job = job1;
      break;
     case 1:
      job = job2;
      break;
     case 2:
      job = job3;
      break;
   }
   //salary selection
   randNum = rand() % 3;
   switch(randNum)
   {
     case 0:
      salary = bigInt1;
      break;
     case 1:
      salary = bigInt2;
      break;
     case 2:
      salary = bigInt3;
      break;
   }
   cout << "You will be working at " << company << " as a " << job << " making $" << salary << " a year." << endl;

   //car selection
   randNum = rand() % 3;
   switch(randNum)
   {
     case 0:
      car = car1;
      break;
     case 1:
      car = car2;
      break;
     case 2:
      car = car3;
      break;
   }
   cout << "You will drive a " << car << endl;

    //loop confirmation
    cout << "1) Play MASH Again\n2) Exit" << endl;
    cin >> yesOrNo;

    switch (yesOrNo)
    {
      case 1:
        runAgain = true;
        break;
      case 2:
        runAgain = false;
    }

  }
cout << "\nGoodbye!\n" << endl;

  return 0;
}
