/*
Author: Jorge Auquilla
Course: CSCI 135
Instructor: Tong Yi
Assignment: Project 1 Task C

This program allows for the user to take in a csv file and be able
to read all of the lines inside the file and be able to ask the user to answer
the questions inside the file and it would post the results and would let the user 
know how many questions he got correct and the percentage total he got
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <climits>
using namespace std;

int main(){
    string fileName = "problems.csv";
    ifstream fin(fileName);
    if(fin.fail()){
        cerr << "This file cannot be read";
        exit(1);
    }
    string txt;
    string ans;
    int numQuestions = 0;
    double numCorrect = 0.0;
    double reply;
    while(getline(fin, txt, ',') && getline(fin, ans)){
        cout << "(" << numQuestions << ")" << "what is: " << txt << "?";
        cin >> reply;

        if(reply == stof(ans)){
            cout << endl << "True" << endl;
            numCorrect++;
        }
        else{
            cout << endl << "False" << endl;
        }
        numQuestions++;
    }
        double percentage = (numCorrect / double(numQuestions)) * 100;
        cout << endl <<  "percent: " << percentage << "%" <<endl ;
        if(percentage >= 90){
            cout << "Letter grade: A";
            }
            else if(percentage >= 80 && percentage <90){
                cout << "Letter grade: B" << endl;
                 }
                  else if(percentage >= 70 && percentage <80){
                    cout << "Letter grade: C" << endl;
                    }
                    else if(percentage < 70 && percentage >= 60 ){
                        cout << "Letter grade: D" << endl;
                        }
                        else{
                            cout << "Letter grade: F" << endl;
                        }
                        return 0;
    








}