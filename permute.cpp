#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

/*********************************************************
* Function: recursivePermute
* Parameters:
*   seenSoFar : type - string : keeps track of the char elements of string seen so far
*   remaining : type - string : the remaining portion of the string which is to be seen
*   permutations : type - vector of string : reference variable which keeps track of the permuted values of strings
* Description:
*   Recursive function which iterates through the given string and places all chars in all possible positions and
*   pushes the result to the permutations.
*********************************************************/
void recursivePermute(string seenSoFar, string remaining, vector <string>& permutations){
    if(remaining == ""){
        if(find(permutations.begin(), permutations.end(), seenSoFar) == permutations.end()){
            permutations.push_back(seenSoFar);
        }
    }
    else{
        // Iterate through the entire string and during each iteration append current char
        // to the seenSoFar string and remove current char from remaining
        for(int i=0;i < remaining.length(); i++){
            // Add the current char to the seenSoFar string
            string sofar = seenSoFar + remaining[i];
            // Exclude the current char from the remaining string
            string rest = remaining.substr(0,i) + remaining.substr(i+1);
            recursivePermute(sofar, rest, permutations);
        }
    }
}

/*********************************************************
* Function: permute
*
* Parameters:
*   str : type - string  Input string to be permuted
*   permutations : type - vector of strings contains the permuted result
*
* Description:
*   Calls recursivePermute to permute the input string and stores the result
*   in permutations.
*********************************************************/
void permute(string str, vector <string>& permutations){
    recursivePermute("", str, permutations);
}

main(){
    string str;
    vector <string> permutations;
    cout<<"\nEnter a string:\n";
    cin>>str;
    permute(str, permutations);
    cout<<"The permutations of string "<<str<<" are:\n";
    for(vector <string>::iterator itr = permutations.begin(); itr != permutations.end(); ++itr){
        cout<<*(itr)<<"\n";
    }
    cout<<"Total Count: "<<permutations.size()<<"\n";
}
