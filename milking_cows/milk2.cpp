/*
ID: cforsyt1
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int line_count, last_time_milked, longest_without_milk, longest_milking;
    int longest_start, longest_end;
    fin >> line_count;
    longest_start = 0;
    longest_end = 0;
    for(int i = 0; i < line_count; i++){
        int start, end;
        fin >> start >> end;
        if(i < 1){
            longest_milking = end - start;
            longest_without_milk = 0;
            last_time_milked = start;
        }
        if(start <= last_time_milked && i != 0 && start >= longest_start){
            longest_end = end;
        }
        else{
            longest_start = start;
            longest_end = end;
        }
        if(longest_end - longest_start > longest_milking){
            longest_milking = longest_end - longest_start;
        }
        if(start - last_time_milked > longest_without_milk){
            longest_without_milk = start - last_time_milked;
        }
        last_time_milked = end;
    }
    fout << longest_milking << " " << longest_without_milk << endl;
    return 0;
}