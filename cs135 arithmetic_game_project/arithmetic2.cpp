//Name : Jorge Auquilla
//Professor : Tong Yi
//Course : CSCI 135
//Assignment : Project 1 : Task B
//This program expands upon the code written in task A and now asks 
//the user to input how many questions the user would like to generate
//for the game and the random question generator would then ask them those questions
//and depending if he got them right or not, the code will now calculate the percentage
//of questions he got correct and will display a letter grade as well as the 
//percentage grade of what he got for the questions answered
#include <iostream>
#include <cstdlib> // rand
using namespace std;

int main(){
  double numofq = 0.0;
  cout << "Enter the total number of questions to ask: ";
  cin >> numofq;
  while(numofq <= 0){
    cout << "The number of questions cannot be zero or negative. Re-enter: ";
    cin >> numofq;
  }
  double numofcorrect = 0.0;
  for(int i = 0; i < numofq; i++){
    int num = rand() % 5;
    char operators[] = {'+','-','*','/','%'};
    char op = operators[num];
    int v1 = rand() % 10;
    int v2;
    int answer;

    if(op == '/' || op == '%'){
        v2 = rand() % 9 + 1;
    }
    else{
        v2 = rand() % 10;
    }

    cout << "What is " << v1 << op << v2 << "? ";
    cin >> answer;
    if(op == '+'){
        if(answer == v1 + v2){
            numofcorrect++;
            cout << "True" << endl;
        }
      else if(answer != v1 + v2){
        cout << "False" << endl;
      }
        }
    else if(op == '-'){
        if(answer == v1 - v2){
          numofcorrect++;
            cout << "True" << endl;
        }
      else if(answer != v1 - v2){
        cout << "False" << endl;
      }
    }
    else if(op == '*'){
        if(answer == v1 * v2){
          numofcorrect++;
            cout << "True" << endl;
        }
      else if(answer != v1 * v2){
        cout << "False" << endl;
      }
    }
    else if(op == '/'){
        if(answer == v1 / v2){
          numofcorrect++;
            cout << "True" << endl;
        }
      else if(answer != v1 / v2){
        cout << "False" << endl;
      }
    }
    else if(op == '%'){
        if(answer == v1 % v2){
          numofcorrect++;
            cout << "True" << endl;
        }
      else if(answer != v1 % v2){
        cout << "False" << endl;
      }
    }
    
  }

  double percentage = (numofcorrect / numofq) * 100;
  cout << "percentage correct: " << percentage << "%" << endl;

  if(percentage >= 90){
      cout << "Letter grade: A" << endl;
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
