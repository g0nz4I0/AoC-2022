#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
std::ifstream file{"problem4.txt"};
int sol_problem_1 = 0,sol_problem_2 = 0;
struct Task{
	int start_1,end_1,start_2,end_2;
	char hyphen_1, comma,hyphen_2;
	void problem_1(){
		if(start_1 <= start_2 && end_1 >= end_2 || start_2 <= start_1 && end_2 >= end_1)
			sol_problem_1++;
	}
	void problem_2(){
		if((start_1 < start_2 && end_1 < start_2 && end_1 != start_2 )||
		   (start_2 < start_1 && end_2 < start_1 && end_1 != start_2))
			{}	
		else
			sol_problem_2++;
	}
};

int main(){	
	std::string input;
	while(std::getline(file,input)){	
		Task task;
		std::stringstream input_data(input);
		input_data>>task.start_1>>task.hyphen_1>>task.end_1>>	task.comma>>task.start_2>>task.hyphen_2>>task.end_2;	
		task.problem_1();
		task.problem_2();
	}	
	std::cout<<"\nSoluiont problem 1: "<<sol_problem_1<<"\nSolution problem 2: "<<sol_problem_2;
}
