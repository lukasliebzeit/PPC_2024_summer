#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Iterator
{
    int* ptr;
public:
    Iterator(int* x) : ptr(x) {}

    int& operator*() const { return *ptr; }
    Iterator& operator++() { ptr++; return *this; }
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; };
};

class Vektor
{
    int* pole;
    size_t velikost;
    size_t max_velikost;
    void resize(size_t x);
public:
    Vektor() : velikost{0}, max_velikost{ 1 } { pole = new int[max_velikost]; }
    Vektor(size_t x) : velikost{ x }, max_velikost{x} { pole = new int[max_velikost]; }
    ~Vektor() { delete[] pole; }
    size_t size() const { return velikost; }
    size_t capacity() const { return max_velikost; }
    void push_back(int x);
    int& operator[] (int x);

    Iterator begin() { return Iterator(&pole[0]); }
    Iterator end() { return Iterator(&pole[velikost]); }
};


void Vektor::resize(size_t x)
{
    cout << "Resizuji pole z: max_velikost == " << max_velikost << ", na " << x << endl;
    max_velikost = x;
    int* pole_tmp = new int[max_velikost];

    std::copy(pole, pole + velikost, pole_tmp);

    delete[] pole;
    pole = pole_tmp;
}

void Vektor::push_back(int x)
{
    if (velikost == max_velikost)
    {
        resize(max_velikost * 2);
    }
    cout << "Pridavam prvek na pozici [" << velikost << "]" << endl;
    pole[velikost++] = x;
    cout << "\thodnota velikost == " << velikost << endl;
}

int& Vektor::operator[] (int x)
{
    cout << "Pristup na prvek [" << x << "]" << endl;
    return pole[x];
}

int main()
{
    Vektor A;
    for (auto i = 0; i < 10; ++i)
        A.push_back(i);

    for (auto it = A.begin(); it != A.end(); ++it)
        cout << *it << ", ";
    cout << endl;

    A[0] = 100;
    A[4] = -10;
    A[9] = -2;

    cout << "Iterator ve funkci ze std == " << accumulate(A.begin(), A.end(), 0) << endl;

    return 0;
}