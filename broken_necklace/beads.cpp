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

int getLeft(string necklace, int breakpoint){
    int bead = breakpoint;
    char current = necklace[bead];
    int count = 0;
    //string beads = "";
    while(bead >= 0){
        if(necklace[bead] == current || necklace[bead] == 'w'){
            count++;
        }
        else if(current == 'w' && necklace[bead] != 'w'){
            count++;
            current = necklace[bead];
        }
        else{
            break;
        }
        //beads.insert(0,1,necklace[bead]);
        bead--;
    }
    //cout << "Left: " << beads;
    return count;
}
int getRight(string necklace, int breakpoint){
    int bead = breakpoint;
    bead += 1;
    char current = necklace[bead];
    int count = 0;
    //string beads = "";
    while(bead < necklace.length()){
        if(necklace[bead] == current || necklace[bead] == 'w'){
            count++;
        }
        else if(current == 'w' && necklace[bead] != 'w'){
            count++;
            current = necklace[bead];
        }
        else{
            break;
        }
        //beads+= necklace[bead];
        bead++;
    }
    //cout << " Right: " << beads << endl;
    return count;
}

int getBreakPoint(string necklace){
    int max = 0;
    necklace += necklace;
    //cout << necklace << endl;
    for(int i = 0; i < necklace.length() - 1; i++){
        int left = getLeft(necklace, i);
        int right = getRight(necklace, i);
        if((left + right) > max && (left + right) <= necklace.length()/2){
            max = left + right;
        }
        if(max == 0){
            return necklace.length()/2;
        }
        //cout << "Left: " << left << " Right: " << right << endl; 
    }
    return max;
}



int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int num_of_beads;
    string necklace;
    fin >> num_of_beads >> necklace;
    fout << getBreakPoint(necklace) << endl;
    
    return 0;
}