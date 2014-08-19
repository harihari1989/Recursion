#include<iostream>
#include<vector>
using namespace std;

/*********************************************************
* Function: printElements
* Parameters:
*   elements : type - vector of ints : the elements which are to be printed.
* Description:
*   Iterates through the elements and prints them.
*********************************************************/
void printElements(vector <int> &elements){
	for(int i=0;i<elements.size();i++){
		cout<<elements[i]<<"\t";
	}
	cout<<endl;
}

/*********************************************************
* Function: printSubsets
* Parameters:
*   subsets : type - vector of vector of ints : the subset elements which are to be printed.
* Description:
*   Iterates through the subset of elements and prints them.
*********************************************************/
void printSubsets(vector < vector<int> > &subsets){
	cout<<"size="<<subsets.size()<<endl;
	for(int i=0;i<subsets.size();i++){
		printElements(subsets[i]);
	}
}

/*********************************************************
* Function: generateSubsets
* Parameters:
*   sofar : type - vector of ints : keeps track of the elements added so far.
*	remaining : type - vector of ints : keeps track of the remaining elements.
*	subsets : type - vector of vector of ints : the subset elements which are to be printed.
* Description:
*   Recursively generates subsets by making two recursive calls one by adding the current element to sofar
*	and other by not adding the element.
*********************************************************/
void generateSubsets(vector<int> sofar, vector<int> remaining, vector<vector <int> > &subsets){
	if(remaining.size() == 0){
		subsets.push_back(sofar);
	}
	else{
		vector<int> sofar_adding_element = sofar;
		sofar_adding_element.push_back(remaining[0]);
		remaining.erase(remaining.begin());
		// Recursively call generateSubsets by adding an element from remaining to sofar and by not adding
		generateSubsets(sofar, remaining, subsets);
		generateSubsets(sofar_adding_element, remaining, subsets);
	}
}

int main(){
	vector<int> elements;
	int n,element;
	cout<<"Enter the number of elements:"<<endl;
	cin>>n;
	cout<<endl<<"Enter the elements:"<<endl;
	for(int i=0;i<n;i++){
		cin>>element;
		elements.push_back(element);
	}
	vector<vector <int> > subsets;
	vector<int> sofar;
	generateSubsets(sofar, elements, subsets);
	printSubsets(subsets);
	return 0;
}
