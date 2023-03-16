#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Vectors{
    public:
        /**
         * Shuffles a vector's elements.
         * 
         * @param vec The vector to be shuffled.
        */
        template<class T>
        static void shuffle_vec(vector<T>& vec){
            random_device rd;
            mt19937 gen(rd());
            shuffle(vec.begin(), vec.end(), gen);

        }

        /**
         * Iterates through the vector and returns the largest element.
         * 
         * @attention Assumes `vec` is not empty and comparison operators are defined for T.
         * 
         * @param vec The vector to search through.
        */
        template<class T>
        static T max(const vector<T>& vec){
            auto i = vec.cbegin(), found = i;
            while(++i != vec.cend())
                if(*found < *i)found = i;
            return *found;
        }
};

#endif
