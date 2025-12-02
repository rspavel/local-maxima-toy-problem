#include <array>
#include <memory>
#include <cstdlib>
#include <ctime>

template <typename T>
bool getSlope(T left, T center, T right)
{
	if(left < center && right > center)
	{
		return 0;
	}
	else if(left < center)
	{
		return 1;
	}
	else //(center > right)
	{
		return -1;
	}
}

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

template <typename T, size_t NUM_ELEMS>
unsigned int brute_force_solver(std::array<T, NUM_ELEMS>& arr)
{
	unsigned int oper_count = 0;

	// Simply iterate through the array until we find any local maxima
	for(int i = 1; i < arr.size() - 1; i++)
	{
		// We already guaranteed we aren't an edge case so
		oper_count += 1;
		if(getSlope<T>(arr[i-1], arr[i], arr[i+1]) == 0)
		{
			// We found a maxima
			return oper_count;
		}
	}
	// No luck so return the max operation counts for this array size
	return oper_count;
}

template <typename T, size_t NUM_ELEMS>
unsigned int binary_search_solver(std::array<T, NUM_ELEMS>& arr)
{
	unsigned int oper_count = 0;

	// A variation on binary search
	//  We essentially detect the slope and search based on whether it is upward or downward
	//  This intuitively favors much larger gaps between maximas
	size_t low = 0;
	size_t high =  arr.size()-1;
	while(low <= high)
	{
		size_t center = low + (high - low) / 2;
		oper_count += 1;
		if(center != 0 && center != arr.size() - 1)
		{
			int center_slope = getSlope<T>(arr[center-1], arr[center], arr[center+1]);
			if(center_slope == 0)
			{
				return oper_count;
			}
			else if(center_slope == -1)
			{
				// Downward slope so a maxima is to the left
				high = center - 1;
			}
			else
			{
				// Upward slope so a maxima is to the right
				low = center + 1;
			}
		}
		else
		{
			// At edge of array so can't be a local maxima as per defined rules
			return oper_count;
		}
	}

	// No luck so return the max operation counts for this array size
	return oper_count;
}


