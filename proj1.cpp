/**

*File Name: proj1.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

*Assisted by and Assisted line numbers:


*Your Name: Cory Drangel

*Your PSU user ID:  cjd209

*Course title: CMPSC465 Summer 2022

*Due Time: 11:59 pm, Sunday, May 29, 2022

*Time of Last Modification: 8:42 am, Sunday, May 29, 2022

*Description: For trains coming in on Track A in numerical order, the program determines if
              the order set in the input file can be accomplished so that the trains are in
              that order on track B. If that can be accomplished, it outputs "Yes" to an 
              output file. If it cannot be accomplished, it outputs "No" to the file.

*/

#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int main() {
    const int SIZE = 1000;          //constant for the size of the arrays for tracks A and B
    int n;                          //int to set the size of the arrays and stack to be used
    ifstream inFile;
    ofstream outFile;
    string inStr,                 //string that is used as the input line
          nStr;                   //string that is used for getting the n value
    bool endOfBlock = false,     //boolean value used to determine the end of a n block
          endOfFile = false;     //boolean value used to determine the file is done

    inFile.open("lab1in.txt");
    outFile.open("lab1out.txt");

    //if statement to determine the input file works correctly
    if (inFile) {
        //while statement that exits when the end of file is reached
        while (!endOfFile) {
            //first value put into the string
            inFile >> nStr;            

            //if statement to determine if the string is a 0, indicating the end of the file
            if (nStr != "0") {
                //if string is not a zero, converting it to the n value
                n = stoi(nStr);
                //getline will just get the \n char so it is thrown out
                getline(inFile, inStr, '\n');
                endOfBlock = false;

                //while statement to determine if the n block is done running
                while (!endOfBlock) {
                    //getline to retrieve the line to be evaluated and put into a string
                    getline(inFile, inStr, '\n');
                    //if statement to determine if the string is a 0, indicating the block is done
                    if (inStr != "0") {
                        int trackA[SIZE];      //array to be used as track A
                        int trackB[SIZE];      //array to be used as track B
                        int bIndex = 0;        //index value for B
                        int currentNum;        //value that is the next one to be put on track B
                        stack<int> station;    //stack that is used as the station
                        bool done = false;    //boolean value indicating the evalutation is done

                        //for loop to put the values on track A in numerical order
                        for (int i = 0; i < n; i++) {
                            trackA[i] = i + 1;
                        }

                        //getting the next value from the string that we are looking for
                        string str1 = inStr.substr(0, inStr.find(" "));
                        //erasing the value from the string so the next value is at the front
                        inStr.erase(0, inStr.find(" ") + 1);
                        //converting the string value to an int
                        currentNum = stoi(str1);

                        //index value for track A
                        int j = 0;
                        //while loop to determine if the evaluation is done for the line
                        while (!done) {
                            //taking the value from track A and putting it onto the stack
                            station.push(trackA[j]);

                            //while loop for if the stack is not empty and the value 
                            //we are looking for is the one on the top of the stack
                            while (!station.empty() && currentNum == station.top()) {
                              //takes the value from the stack and puts it on track B  
                              trackB[bIndex] = station.top();
                              //pops the value off the stack
                              station.pop();
                              //increases the index for track B 
                              bIndex++;

                              //gets the next value from the string, erases it from
                              //string, and converts it to a number
                              str1 = inStr.substr(0, inStr.find(" "));
                              inStr.erase(0, inStr.find(" ") + 1);
                              currentNum = stoi(str1);
                            }
                            //increases the index for track A
                            j++;
                            //if the index for track A = the n value, indicating the 
                            //evaluation is done working
                            if (j == n) {
                                //putting the boolean value indicating the evaluation is
                                //done to true
                                done = true;
                              
                                //if statement comparing the track A and B indexes to see
                                //if the evaluation would work
                                if (bIndex == j) {
                                    outFile << "Yes" << endl;
                                }
                                else {
                                    outFile << "No" << endl;
                                }
                            }
                        }
                    }
                    else {
                        //changing the boolean value for when the end of the block is reached
                        //to true
                        endOfBlock = true;
                        outFile << endl;
                    }
                }
            }
            else {
                //changing the boolean value for when the end of the file is reached to true
                endOfFile = true;
            }

        }
    }
    else
        cout << "error reading input";

    outFile.close();
    inFile.close();
}