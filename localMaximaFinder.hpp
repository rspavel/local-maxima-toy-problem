#include <array>
#include <memory>
#include <cstdlib>
#include <ctime>

template <typename T, size_t NUM_ELEMS, size_t NUM_ARRS>
std::unique_ptr<std::array<T, NUM_ELEMS>[]> generate_input_arrs()
{
	// Create an array of std::arrays
	auto ret = std::make_unique<std::array<T, NUM_ELEMS>[]>(NUM_ARRS);
	// Seed the random number generator
	std::srand(std::time({}));
	// And initialize the arrays
	for(int i = 0; i < NUM_ARRS; i++)
	{
		for(int j = 0; j < NUM_ELEMS; j++)
		{
			ret.get()[i][j] = rand();
		}
	}
	return ret;
}

