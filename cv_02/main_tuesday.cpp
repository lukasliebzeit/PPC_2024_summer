#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	/*
	vector<int> A(10);
	vector<float> B;
	vector<char> C{ 'a', 'b', 'c' };

	cout << "Parametry vectoru A:" << endl;
	std::cout << A.size() << std::endl;

	cout << "Parametry vectoru B:" << endl;
	std::cout << B.size() << std::endl;
	std::cout << B.capacity() << std::endl;
	cout << "B.reserve zavolano" << endl;
	B.reserve(100);
	std::cout << B.size() << std::endl;
	std::cout << B.capacity() << std::endl;

	cout << "Parametry vectoru C:" << endl;
	std::cout << C.max_size() << std::endl;

	for (int i = 0; i < 100; ++i)
	{
//		cout << A[i] << ", ";
		try {
			cout << A.at(i) << endl;
		}
		catch (const out_of_range& oor) {
			std::cerr << "Pristup mimo meze: " << oor.what() << '\n';
			break;
		}
	}
	cout << endl;

	for (auto it = A.begin(); it != A.end(); ++it)
	{
		*it = distance(A.begin(), it);
		cout << *it << ", ";
	}
	cout << endl;
	for (auto it = A.end(); it != A.begin(); --it)
	{
		cout << *it << ", ";
	}
	cout << endl;
*/
	vector<int> A{-2, 3, 6, 2, 0, -10, 11, 12 , 42};

	sort(A.rbegin(), A.rend());
	for (auto it = A.begin(); it != A.end(); ++it)
	{
		cout << *it << ", ";
	}
	std::map<std::string, int> D;
	D["Tokyo"] = 37833000;
	D["Dilli"] = 24953000;
	D["Sanghaj"] = 22991000;
	D["Maxico City"] = 20843000;
	D["Sao Paulo"] = 20831000;

	for (auto i : D) {
		std::cout << setw(15) << left << i.first << i.second << endl;
	}

	cout << endl << endl;

	for (auto it = D.rbegin(); it != D.rend(); ++it)
	{
		cout << "[" << it->first << "]:\t" << it->second << endl;
	}

	if (D.find("Sanghaj") != D.end())
		cout << "Sanghaj je v seznamu" << endl;
	if (D.find("Brno") != D.end())
		cout << "Brno je v seznamu" << endl;
	else
		cout << "Brno? To neznam..." << endl;
	return 0;
}
