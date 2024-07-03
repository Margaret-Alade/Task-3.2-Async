//
//  main.cpp
//  Task-3.2-Async
//
//  Created by Маргарет  on 02.07.2024.
//

#include <iostream>
#include <future>
#include <functional>
int sum_el(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int sum = 0;
    for (auto i = begin; i < end; i++) {
        sum += *begin;
    }
    return sum;
}


int async_for_each(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t min_size =  125;
    auto cur_distance = std::distance(begin, end);
    
    if (cur_distance <= min_size) {
        int result = sum_el(begin, end);
        return result;
    }
    auto mid = begin;
    std::advance(mid, cur_distance/2);
    auto r_res = std::async(async_for_each, begin, mid);
                                
    auto left_res = sum_el(mid, end);
    return r_res.get() + left_res;
}

int main(int argc, const char * argv[]) {
    std::vector<int>v(1000,3);
    std::cout << "The result of function: " << async_for_each(v.begin(), v.end()) << "\n";
    
    return 0;
}
