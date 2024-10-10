/*
Author: Jorge Auquilla
Course: CS135
Instructor: Tong Yi
Assignment: Project 1, Task D

This program allows for the user to be able to open the problems.csv files and then check to see if it would
open or not, then they would create 2 arrays to be able to go through the questions and answers of that file, once it
goes through, then it would use a while loop to randomly select any of those questions and be able to display the 
question to the user, if the user is correct, then it would be able to add it to the correct counter and if the user
gets over 60% or more as their score, then the program would stop, but if not it keeps going and then would display their
percentage for both conditions
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    string fileName = "problems.csv";
    ifstream fin(fileName);
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    const int size = 20;
    string questions[size];
    double answers[size];
    string txt, ans;
    int numCorrect = 0;
    double numQuestions = 1;
    int index = 0;

    while (getline(fin, txt, ',') && getline(fin, ans)) {
        questions[index] = txt;
        answers[index] = stod(ans);
        index++;
    }

    while (index > 0) {
      srand(time(NULL));
      int random = rand() % index;
      cout << "(" << numQuestions << ") What is: " << questions[random] << "?" ;
      double reply;
      cin >> reply;

      int lastIndex = index - 1;

      if (reply == answers[random]){
        cout << "True!" << endl;
        numCorrect++;
        } else{
            cout << "False!" << endl;
        }

        swap(questions[random], questions[lastIndex]);
        swap(answers[random], answers[lastIndex]);
        numQuestions++;
        index--;

        double correctRate = (static_cast<double>(numCorrect) / static_cast<double>(numQuestions) * 100);

        if (correctRate >= 60) {
            cout << "At least 60%" <<" is correct. Stop." << endl;
            cout << "Percent: " << correctRate << "%" << endl;
            break;
        }
    }

    double finalCorrectRate = (static_cast<double>(numCorrect) / static_cast<double>(numQuestions) * 100);
    if (finalCorrectRate < 60) {
        cout << "Percent: " << finalCorrectRate << "%" << endl;
    }

    fin.close();
    return 0;
}
