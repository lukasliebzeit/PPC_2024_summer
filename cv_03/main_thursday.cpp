#include <iostream>
#include <numeric>

using namespace std;

class Iterator
{
    int* ptr;
public:
    Iterator(int* x) : ptr(x) {}

    int& operator*() const { return *ptr; }
    Iterator& operator++() { ptr++; return *this; }
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; }
};

class Vektor
{
    int* pole;
    size_t velikost;
    size_t max_velikost;
    void resize(size_t x);
public:
    Vektor() : velikost(0), max_velikost{1} { pole = new int[max_velikost]; }
    Vektor(size_t x) : velikost(x), max_velikost{x} { pole = new int[max_velikost]; }
    size_t size() const { return velikost; }
    size_t capacity() const { return max_velikost; }
    void push_back(int x);
    int& operator[] (int x);

    Iterator begin() { return Iterator(&pole[0]); }
    Iterator end() { return Iterator(&pole[velikost]); }
};

bool operator==(Vektor& a, Vektor& b)
{
    if (a.size() != b.size())
        return false;
    for (auto i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

void Vektor::resize(size_t x)
{
    cout << "resize() z " << max_velikost << " na " << x << endl;
    max_velikost = x;
    int* tmp = new int[max_velikost];
    //for (auto i = 0; i < velikost; ++i)
    //    tmp[i] = pole[i];
    copy(pole, pole + velikost, tmp);

    delete[] pole;
    pole = tmp;
}

void Vektor::push_back(int x)
{
    cout << "push_back " << x << endl;
    if (velikost == max_velikost)
    {
        resize(max_velikost * 2);
    }
    pole[velikost++] = x;
}

int& Vektor::operator[] (int x)
{
    return pole[x];
}

inline int soucet(int a, int b)
{
    return a + b;
}

int soucet_2(int a, int b)
{
    return a + b;
}

int main()
{
    soucet(1, 2);
    soucet_2(1, 2);

    Vektor A;
    Vektor B(10);

    for (auto i = 0; i < 100; ++i)
        A.push_back(i);

    for (auto i = 0; i < 10; ++i)
        B[i] = i+1;

    for (auto it = B.begin(); it != B.end(); ++it)
        cout << *it << ", ";
    cout << endl;

    auto lambda = [&](int x, int y) {return x * y; };
    cout << "Soucin prvku v poli: " << accumulate(B.begin(), B.end(), 1, lambda) << endl;

    cout << "Soucet prvku v poli: " << accumulate(B.begin(), B.end(), 1, [&](int x, int y) {return x + y; }) << endl;


    return 0;
}