/*
ID: cforsyt1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

bool isCentury(int year){
    if((year % 100) == 0){
        return true;
    }
return false;
}

bool isLeap(int year){
    if(isCentury(year) && (year % 400) == 0){
        return true;
    }
    else{
        if(!isCentury(year) && (year % 4) == 0){
            return true;
        }
        return false;
    }
}

int main(){
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int numOfYears;
    map<string, int> occurances;
    fin >> numOfYears;
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int amountDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfWeek = 0; //Start at Monday
    int dayOfMonth = 0;
    int month = 0;
    int year = 1900;
    bool leap = false;
    
    
    while(year < 1900 + numOfYears){
        if(dayOfMonth == 12){
            occurances[days[dayOfWeek]]++;
        }
        dayOfWeek = (dayOfWeek  + 1) % 7;
        dayOfMonth++;
            
        if((dayOfMonth % amountDays[month]) == 0){
            month = (month + 1) % 12;
            dayOfMonth = 0;
        }
        if(dayOfMonth == 0 && month == 0){
            year++;
            leap = isLeap(year);
            if(leap){
                amountDays[1] = 29;
            }
            else{
                amountDays[1] = 28;
            }
        }
    }
    fout << occurances["Saturday"] << " " <<occurances["Sunday"] << " " << occurances["Monday"] << " " << occurances["Tuesday"] << " " << occurances["Wednesday"] << " " << occurances["Thursday"] << " " << occurances["Friday"] << "\n";
    return 0;
}
  