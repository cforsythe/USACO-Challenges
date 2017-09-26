/*
ID: cforsyt1
PROG: beads
LANG: C++
*/



#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<int> addArray(string necklace){
    vector<int> letter_counts;
    char current = necklace[0];
    bool color_set = false;
    char color;
    int count = 0;
    for(int i = 0; i < necklace.length(); i++){
        if(current == necklace[i] || necklace[i] == 'w'){
            count++;
        }
        else if(current == 'w' && color_set == false){
            current = necklace[i];
            color_set = true;
            count++;
        }
        else{
            letter_counts.push_back(count);
            count = 1;
            current = necklace[i];
            color_set = false;
        }
    }
    letter_counts.push_back(count);
    for(int i = 0; i < letter_counts.size(); i++){
        cout << letter_counts[i] << " ";
    }
    return letter_counts;
}

int maxBeads(string necklace, int num_of_beads){
    vector<int> letter_counts = addArray(necklace);
    int max = letter_counts[0] + letter_counts[letter_counts.size() - 1];
    for(int i = 0; i < letter_counts.size(); i++){
        int adjacent_count = letter_counts[i] + letter_counts[i + 1];
        if(adjacent_count > max){
            max = adjacent_count;
        }
    }
    return max;
}

int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int num_of_beads;
    string necklace;
    fin >> num_of_beads >> necklace;
    
    fout << maxBeads(necklace, num_of_beads);
    
    return 0;
}