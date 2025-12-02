#include "localMaximaFinder.hpp"

#include <iostream>

int main(int argc, char ** argv)
{
	const size_t NUM_ELEMS = 20000;
	const size_t NUM_ARRS = 100;

	auto input_sets = generate_input_arrs<int, NUM_ELEMS, NUM_ARRS>();

	unsigned int total_operations;
	double average_operations;

	// Solve Input Sets using brute force solution and average operations
	total_operations = 0;
	for(int i = 0; i < NUM_ARRS; i++)
	{
		unsigned int num_operations = brute_force_solver<int, NUM_ELEMS>(input_sets[i]);
		if(num_operations > 0)
		 total_operations += num_operations;
	}
	average_operations = static_cast<double>(total_operations) / NUM_ARRS;

	std::cout << "Brute Force Solution: " << average_operations << " operations" << std::endl;

	// Solve Input Sets using binary search solution and average operations
	total_operations = 0;
	for(int i = 0; i < NUM_ARRS; i++)
	{
		unsigned int num_operations = binary_search_solver<int, NUM_ELEMS>(input_sets[i]);
		if(num_operations > 0)
		 total_operations += num_operations;
	}
	average_operations = static_cast<double>(total_operations) / NUM_ARRS;

	std::cout << "Binary Search Solution: " << average_operations << " operations" << std::endl;




	return 0;
}

