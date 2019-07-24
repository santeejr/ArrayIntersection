#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> ArrayInt(std::vector<int> list1, std::vector<int> list2)
{
    std::vector<int> result;
    std::sort(list1.begin(), list1.end()); // log n
    std::sort(list2.begin(), list2.end()); // log n

    size_t size_l1 = list1.size();
    size_t size_l2 = list2.size();

    size_t p_list1 = 0;
    size_t p_list2 = 0;

    while (p_list1 < size_l1 && p_list2 < size_l2) // n + m // worst case 2n // (n)
    {
        if (list1[p_list1] == list2[p_list2])
        {
           result.push_back(list1[p_list1]);
           ++p_list1;
           ++p_list2;
        }
        else if (list1[p_list1] < list2[p_list2])
        {
            ++p_list1;
        }
        else {
            ++p_list2;
        }
    }

    return result;
}

int main()
{
    std::vector<int> l1 = {1,6,7};
    std::vector<int> l2 = {5,2,4545,54,5,65,4,54,654,65,4,654,654};

    std::vector<int> r = ArrayInt(l1, l2);
    for (auto i : r) {
        std::cout << i << std::endl;
    }
}
