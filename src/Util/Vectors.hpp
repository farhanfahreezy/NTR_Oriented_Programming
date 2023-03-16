#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Vectors{
    public:
        template<class T>
        static void shuffle_vec(vector<T>& vec){
            random_device rd;
            mt19937 gen(rd());
            shuffle(vec.begin(), vec.end(), gen);

        }

        template<class T>
        static T max(vector<T> vec){
            /** TODO: Implement max here */
        }
};

#endif
