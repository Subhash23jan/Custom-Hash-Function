#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    MyMap<int, string> mp;

    mp.put(10, "Subhash");
    mp.put(20, "Darshan");
    cout << "Get key 10: " << mp.get(10) << endl;
    cout << "Get key 20: " << mp.get(20) << endl;

    mp.put(10, "Updated Name");
    cout << "Updated key 10: " << mp.get(10) << endl;

    cout << "Contains key 20: " << mp.contains(20) << endl;
    cout << "Contains key 30: " << mp.contains(30) << endl;

    mp.clear();
    cout << "Get key 10 after clear: " << mp.get(10) << endl;

    return 0;
}
