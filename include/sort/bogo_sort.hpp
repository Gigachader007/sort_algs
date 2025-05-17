#pragma once

#include <cstdlib>
#include <functional>
#include <utility>


template<class It, class Compare=std::less<>>
void bogo_sort(It begin, It end, Compare cmp = Compare{}){
    auto sorted = [](It begin, It end, Compare cmp){
        for(auto it = begin + 1; it < end; ++it){
            if(!cmp(*(it - 1), *it)) return false;
        }
        return true;
    };

    while(!sorted(begin,end,cmp)){
        for(auto it = begin; it < end; ++it){
            std::swap(*it, *(begin + std::rand() % std::distance(begin, end)));
        }
    }
}