#include<iostream>
using namespace std;


//Global Variables
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------

//Initializing The block array by size of 10
int block_size[10];

//Initializing The process array by size of 10
int process_size[10];

//user specifing the number of blocks
int number_of_blocks;

//user specifing number of processes
int number_of_processes;

//Array of flags to iterate around all the elements in the array, the flag is either (false = 0) or (true = 1) 
int flags[10];

//The new array that will contain the elements that their sizes are less than or equal to the size of each index in the block array
int allocation[10];



int block[10];
int processes[10];
int temp;
int lowest = 9999;



//----------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------






//The Main Algorithm
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------


void first_fit_algorithm() {

	//Loops iterators
	int x;
	int y;


	//Nested for loop used to iterate on the whole array of blockes and compare its size with the size of each process
	for (x = 0; x < number_of_processes; x++)
		for (y = 0; y < number_of_blocks; y++)

			//The Block size must be bigger than or equal the process size not only that, the block must be at first empty which is why we said that ( "flags[j] == 0 && block_size[j] >= process_size[i]" )
			if (flags[y] == 0 && block_size[y] >= process_size[x])
			{
				//If the condition is true, we will place the process in the allocation array
				allocation[y] = x;

				//Then change the flag to 1, which means that this element is checked and allocated 
				flags[y] = 1;

				//Break out of the if condition to execute the rest of the algorithm
				break;
			}

	//Loop used to print out the processes and their sizes that have been assigned to the suitable blocks

	cout << "T          A         B           L         E" << endl;
	cout << endl;
	cout << endl;

	cout << "#----------------------------------------------------------------------#" << endl;


	cout << " " << "Block number:\t size: \t\t process number:\t\t size:" << endl;
	for (x = 0; x < number_of_blocks; x++)
	{

		//we said (i+1) so  the indices can be printed starting by 1
		cout << " " << "\n" << x + 1 << "\t\t" << block_size[x] << "\t\t";
		//This means if process meet the conditions of being less than or equal the block size and that the block was at the first place empty, print the process along with its size
		if (flags[x] == 1) {
			cout << " " << allocation[x] + 1 << "\t\t\t\t" << process_size[allocation[x]];
		}

		//Else, this means that the process did not fit any of the blocks, so it was not located
		else {
			cout << "Not allocated" << endl;
		}

	}
	cout << endl;
	cout << "#----------------------------------------------------------------------#" << endl;


}
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
void best_fit_algorithm() {



	int x;
	int y;

	for (x = 1; x <= number_of_processes; x++)
	{
		for (y = 1; y <= number_of_blocks; y++)
		{
			if (block_size[y] == NULL)
			{

				temp = block[y] - processes[x];
				if (temp >= 0)
					if (lowest > temp)
					{
						process_size[x] = y;
						lowest = temp;
					}
			}
		}

	}

	cout << "T          A         B           L         E" << endl;
	cout << endl;
	cout << endl;

	cout << "#----------------------------------------------------------------------#" << endl;

	cout << "\nProcess_number\tsize\tBlock_number\t\tsize";
	for (x = 1; x <= number_of_processes && process_size[x] != NULL; x++) {

		cout << "\n" << x << "\t\t" << processes[x] << "\t\t" << process_size[x] << "\t\t" << block[process_size[x]] << endl;
	}

	cout << endl;
	cout << "#----------------------------------------------------------------------#" << endl;


}


void insert_best_fit() {
	int x;
	int y;
	cout << "\n\t\t\tMemory Management Scheme - Best Fit" << endl;
	cout << "\t\t\t_____" << endl;
	cout << "\nEnter the number of blocks:";
	cin >> number_of_blocks;


	cout << "\nEnter the size of the blocks:-\n";
	for (x = 1; x <= number_of_blocks; x++)
	{
		cout << "Block no." << x << ":";
		cin >> block[x];
	}



	cout << "Enter the number of processes:";
	cin >> number_of_processes;


	cout << "\nEnter the size of the processes :-\n";
	for (x = 1; x <= number_of_processes; x++)
	{
		cout << "Process no. " << x << ":";
		cin >> processes[x];
	}

	best_fit_algorithm();
}



void insert_first_fit() {

	//Loops iterators
	int x;
	int y;
	//Creating a for loop to initilize the flag array and the allocation array
	for (x = 0; x < 10; x++)
	{
		//Here the flag array will be equal to zero , and that means that all elements are not checked yet
		flags[x] = 0;

		//This means all the array elements are initialized by 0 , so later on i can be filled with processes
		allocation[x] = 0;
	}
	cout << "\n\t\t\tMemory Management Scheme - First Fit" << endl;
	cout << "\t\t\t_____" << endl;
	//Specifing number of blocks
	cout << "Enter no. of blocks: " << endl;
	cin >> number_of_blocks;

	//Specifing the size of each block
	cout << "Enter size of each block: " << endl;
	for (x = 0; x < number_of_blocks; x++) {
		cout << "Block no." << x << ":";
		cin >> block_size[x];
	}

	//Specifing number of processes
	cout << "Enter no. of processes: " << endl;
	cin >> number_of_processes;

	//Specifing the size of each process
	cout << "Enter size of each process: " << endl;
	for (x = 0; x < number_of_processes; x++) {
		cout << "Process no. " << x << ":";
		cin >> process_size[x];
	}
	cout << endl;
	first_fit_algorithm();


}

void worst_fit_algorithm()
{
	for (int g = 0; g < number_of_processes; g++)
	{
		int maximium = block_size[0];
		int position = 0;

		for (int z = 0; z < number_of_blocks; z++)


			if (maximium < block_size[z])
			{
				maximium = block_size[z];
				position = z;
			}


		if (maximium >= process_size[g])
		{
			cout << endl;
			cout << "processe -> " << g + 1 << " is allocated to block " << position + 1;
			block_size[position] = block_size[position] - process_size[g];
		}


		else
		{
			cout << endl;
			cout << "processe -> " << g + 1 << " can't be allocated";

		}
	}
}



void insert_worst_fit() {


	int x;
	int y;

	cout << " Enter the number of blocks : ";
	cin >> number_of_blocks;

	for (x = 0; x < number_of_blocks; x++) {
		cout << "Block No: " << (x + 1) << endl;
		cin >> block_size[x];
	}

	cout << " Enter the number of processes : ";
	cin >> number_of_processes;


	for (x = 0; x < number_of_processes; x++) {
		cout << "Process no: " << (x + 1) << endl;
		cin >> process_size[x];
	}
	worst_fit_algorithm();
}
int main()
{
	cout << "Choose between :" << endl;
	cout << "___" << endl;
	cout << endl;
	cout << "1-" << "First fit algorithm" << endl;
	cout << "2-" << "Best fit algorithm" << endl;
	cout << "3-" << "Worst fit algorithm" << endl;
	cout << "4-" << "Exit the program" << endl;
	cout << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		//Calling the function that will execute the algorithm based on your choice(first fit)
		insert_first_fit();
	}
	else if (choice == 2) {
		//Calling the function that will execute the algorithm based on your choice(best fit)
		insert_best_fit();
	}

	else if (choice == 3) {
		//Calling the function that will execute the algorithm based on your choice(worst fit)
		insert_worst_fit();

	}
	else if (choice == 4) {
		exit(0);
	}
}