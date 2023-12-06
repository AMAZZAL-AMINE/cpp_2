#include <iostream>
#include <vector>


void split_vector_into_pairs(std::vector<int>& d, size_t size)
{
    if (d.size() < size * 2)
        return;
    std::vector<std::pair<std::vector<int>, std::vector<int> > > pairs;
    std::vector<int> tmp;
    if (d.size() % (size * 2) != 0)
    {
        for (size_t i = d.size() - (d.size() % (size * 2)); i < d.size(); i++)
                tmp.push_back(d[i]);
        d.erase(d.end() - (d.size() % (size * 2)), d.end());
    }
    for (size_t i = 0; i < d.size(); i += size * 2)
    {
        std::vector<int> first_vector;
        std::vector<int> second_vector;
        for (size_t j = i; j < i + size ; j++)
                first_vector.push_back(d[j]);
        for (size_t j = i + size; j < i + size * 2; j++)
                second_vector.push_back(d[j]);
        if (first_vector.back() > second_vector.back())
            std::swap(first_vector, second_vector);
        pairs.push_back(std::make_pair(first_vector, second_vector));
    }
    d.clear();
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::vector<int>& first_subvector = pairs[i].first;
        std::vector<int>& second_subvector = pairs[i].second;
        for (size_t j = 0; j < size; j++)
            d.push_back(first_subvector[j]);
        for (size_t j = 0; j < size; j++)
            d.push_back(second_subvector[j]);
    }
    split_vector_into_pairs(d, size * 2);
}
