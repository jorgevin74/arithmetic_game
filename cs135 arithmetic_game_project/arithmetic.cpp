//Author : Jorge Auquilla
//Course : CSCI 135
//Instructor : Tong Yi
//Assignment : Project 1 : Task A
//This piece of the program go through the array of operators that are available and
//what happens is that we have a num which goes through random numbers between 0 and 4 and chooses
//which number it will be and that number chosen is the operator that will be used we then find a number for v1 and it
//can be chosen in between from 0 to 9. if the array outputs a random operator such as / or a % then the 2nd number
//will be chosen from 1 to 9 but anything else will be the same 0 to 9 like the first number,the program will ask you for the 
//answer and if the answer put down by the user is correct, then the program will output True, if not it will output false
//and will tell you it's incorrect




#include <iostream>
#include <cstdlib> // rand
using namespace std;

int main(){

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

    cout << "what is: " << v1 << op << v2 << " ?";
    cin >> answer;

    if(answer == v1 + v2){
        cout << "True";
    }
    else if(answer == v1 - v2){
        cout << "True";
    }
    else if(answer == v1 * v2){
        cout << "True";
    }
    else if(answer == v1 / v2){
        cout << "True";
    }
    else if(answer == v1 % v2){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;


}