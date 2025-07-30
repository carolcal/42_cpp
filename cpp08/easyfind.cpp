#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return std::distance(container.begin(), it);
}

int main()
{
    try {
        int arr1[] = {1, 2, 3};
        std::vector<int> v(arr1, arr1 + 3);
        std::cout << "vector: " << easyfind(v, 2) << std::endl;

        int arr2[] = {4, 5, 6};
        std::list<int> l(arr2, arr2 + 3);
        std::cout << "list: " << easyfind(l, 6) << std::endl;

        int arr3[] = {7, 8, 9};
        std::deque<int> d(arr3, arr3 + 3);
        std::cout << "deque: " << easyfind(d, 7) << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}