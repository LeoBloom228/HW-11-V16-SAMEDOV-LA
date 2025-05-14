//Task 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

int main() 
{
    std::vector<int> numbers;
    int x;

    std::cout << "Please, enter a seqeunce of integers (enter a non-digit to complete):\n";
    while (std::cin >> x) 
    {
        numbers.push_back(x);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (numbers.size() < 2) 
    {
        std::cerr << "Error! Not enough elements.\n";
        return 1;
    }

    auto min_it = std::min_element(numbers.begin(), numbers.end());
    auto max_it = std::max_element(numbers.begin(), numbers.end());

    // Defining the range boundaries between min and max, excluding the elements themselves
    auto begin = std::min(min_it, max_it) + 1;
    auto end = std::max(min_it, max_it);

    int sum = std::accumulate(begin, end, 0);

    if (max_it > min_it) 
    {
        std::cout << "The max element is located after the min one.\n";
    }

    std::cout << "The sum between the max element amd the min one is: " << sum << "\n";

    return 0;
}

