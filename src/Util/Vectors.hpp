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
         * Iterates through the vector and returns the largest element. Also stores the largest element index in an out parameter.
         * 
         * @attention Assumes `vec` is not empty and comparison operators are defined for T.
         * 
         * @param vec The vector to search through.
         * @param idx Out parameter for storing the index of the largest element.
        */
        template<class T>
        static T max(vector<T>& vec, int& idx){
            T* found = &vec.at(0);
            idx = 0;
            for(int i = 1; i < vec.size(); ++i){
                if(*found < vec.at(i)){
                    found = &vec.at(i);
                    idx = i;
                }
            }
            return *found;
        }
};

#endif
