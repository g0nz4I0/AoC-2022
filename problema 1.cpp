#include<iostream>
#include<vector>
#include <fstream>
#include<algorithm>
int main(){
	
	std::vector<int> elems;
	std::ifstream infile("problem1.txt");

	
	
	//getting the input
	bool new_elf_next = false;//if there is an empty line
							  //we know we need to start with a new elf
	int i_calories = 0;		  // calories as integer, therefore the "i_" prefix
	int i = 0;				  //index for inserting elements in the vector
	
	std::string calories;	//the read value (as string)
	for(std::string calories; getline(infile,calories);){

		if(calories.empty()){
			new_elf_next = true;
		}else{
			if(new_elf_next == false){		
				//if we are still on the previous elf
				//stoi casts from string TO int
				//we insert the i_calories value, 
				//we will overwrite this value some times
				//while we are on the same elf	
				i_calories += std::stoi(calories);	
				elems.insert(elems.begin() + i,i_calories);
			}else{
				//if the flag of NEW_ELF_ is TRUE
				//we reset the calories
				//and move one pos further in the vector
				i_calories = 0;
				i++;
				i_calories += std::stoi(calories);
				elems.insert(elems.begin() + i,i_calories);
				new_elf_next = false;
				//we are going to keep writing on this elf
				//the next time we go through the for loop
			}		
		}	
	}
	
	std::sort(elems.begin(), elems.end(), std::greater<int>());//we sort the vector
	//from greatest value to smallest

	int max_a = elems[0];
	int max_b = 0;
	
	std::cout<<max_a;//solution part A
	for(int j = 0; j < 3; j++)
		max_b += elems[j]; 
	std::cout<<"Max between 3 elves: "<<max_b;//solution part B
	
	return 0;
}
