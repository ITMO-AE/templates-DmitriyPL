#include <iostream>
#include <vector>
#include <map>

using namespace std;

template < typename T>
T Sqr( T v )
{
    T res;
    for (auto i: v) {
        res.push_back(i*i);
    };
    return res;
}

template <typename K, typename V1, typename V2>
map< K, pair <V1, V2> > Sqr( map < K, pair <V1, V2> > m )
{
    map< K, pair <V1, V2> > res;

    for (auto i: m) {
        i.second.first *= i.second.first;
        i.second.second *= i.second.second;
        res.insert( i );
    }

    return res;
}

int main()
{
    // Пример вызова функции
    vector<int> v = {1, 2, 3};

    cout << "vector:";

    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
