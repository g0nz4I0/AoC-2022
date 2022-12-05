#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
struct Move{
	
	std::string action,from,to;
	int quantity, origin,destination;
		
};

struct Column{
	std::vector<char> elems;
	char top_element{};
	
	int get_top_elem(){
		if(elems.empty())
		{}
		else 
			top_element = elems[elems.size()-1];		
		
		return top_element;
	}
	void remove_top_elem(){
		elems.pop_back();
	}
};

int main(){
	int counter = 0;
	std::ifstream input_file{"problem5.txt"};
	std::string data_line{};
	std::string fake_matrix;
	
	std::vector<Column> matrix;
	
	Column col1;
	Column col2;		
	Column col3;
	Column col4;
	Column col5;
	Column col6;
	Column col7;
	Column col8;
	Column col9;
	
	col1.elems = {'G','D','V','Z','J','S','B'};
	col2.elems = {'Z','S','M','G','V','P'};
	col3.elems = {'C','L','B','S','W','T','Q','F'};
	col4.elems = {'H','J','G','W','M','R','V','Q'};
	col5.elems = {'C','L','S','N','F','M','D'};
	col6.elems = {'R','G','C','D'};
	col7.elems = {'H','G','T','R','J','D','S','Q'};
	col8.elems = {'P','F','V'};
	col9.elems = {'D','R','S','T','J'};	
	
	col1.get_top_elem();
	col2.get_top_elem();
	col3.get_top_elem();
	col4.get_top_elem();
	col5.get_top_elem();
	col6.get_top_elem();
	col7.get_top_elem();
	col8.get_top_elem();
	col9.get_top_elem();	

	matrix.push_back(col1);
	matrix.push_back(col2);
	matrix.push_back(col3);
	matrix.push_back(col4);
	matrix.push_back(col5);
	matrix.push_back(col6);
	matrix.push_back(col7);
	matrix.push_back(col8);
	matrix.push_back(col9);
		
	while(getline(input_file,fake_matrix) && counter < 9)
		{counter++;}
	while(getline(input_file,data_line)){		
		std::stringstream data (data_line);
		Move next_move;
		data>>next_move.action>>next_move.quantity>>next_move.from>>next_move.origin>>next_move.to>>next_move.destination;
		char element_moving = ' ';
		int reps = 0;		
		std::cout<<"NEW MOVE!!!!!!!!!!!!!!!!!!\n";
		while(reps != next_move.quantity){
				element_moving = matrix[next_move.origin - 1 ].get_top_elem();
				matrix[next_move.origin - 1 ].remove_top_elem();
				matrix[next_move.origin - 1 ].top_element = matrix[next_move.origin - 1 ].get_top_elem();			
				matrix[next_move.destination - 1].elems.push_back(element_moving);				
				reps++;			
			}
		}	
		for(int i = 0; i< 9; i++){
			std::cout<<(char)matrix[i].get_top_elem();
		}
		//end of main
}
