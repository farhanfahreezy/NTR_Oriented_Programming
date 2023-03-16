#include <Util/Vectors.hpp>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i != 11; i = (i + 7) % 13)
        v.push_back(i);
    for(auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;

    int i;
    int max = Vectors::max<int>(v, i);
    cout << "max: " << i << " -> " << max << endl;
    return 0;
}
