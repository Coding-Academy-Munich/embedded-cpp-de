#include <iostream>
using namespace std;

#include <vector>
#include <tuple>

using namespace std;

class BadNames {
private:
    vector<tuple<int, int>> theList;

public:
    BadNames(vector<tuple<int, int>> list) : theList(list) {}

    vector<tuple<int, int>> getThem() {
        vector<tuple<int, int>> list1;
        for (auto& x : theList) {
            if (get<1>(x) == 1) {
                list1.push_back(x);
            }
        }
        return list1;
    }
};

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class BadNames {
private:
    vector<tuple<int, int, int>> theList;
public:
    BadNames(vector<tuple<int, int, int>> initList) : theList(initList) {}

    vector<tuple<int, int, int>> getThem() {
        vector<tuple<int, int, int>> result;
        for (auto &item : theList) {
            if (get<1>(item) > 0) {
                result.push_back(item);
            }
        }
        return result;
    }

    void setTheList(int index, tuple<int, int, int> value) {
        if (index >= 0 && index < theList.size()) {
            theList[index] = value;
        }
    }

    vector<tuple<int, int, int>> getTheList() {
        return theList;
    }
};

int main() {
    vector<tuple<int, int, int>> initList;
    for (int i = 0; i < 64; ++i) {
        initList.push_back(make_tuple(i, 0, 0));
    }
    BadNames thing(initList);
    thing.setTheList(2, make_tuple(2, 1, 0));

    assert(thing.getThem() == vector<tuple<int, int, int>>{make_tuple(2, 1, 0)});

    for (auto &item : thing.getThem()) {
        cout << "(" << get<0>(item) << ", " << get<1>(item) << ", " << get<2>(item) << ")" << endl;
    }

    return 0;
}