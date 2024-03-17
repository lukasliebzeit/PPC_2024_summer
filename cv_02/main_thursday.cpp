#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	/*
	std::vector<int> A(10);
	std::vector<float> B;
	std::vector<char> C{ 'a', 'b', 'c' };

	cout << "Vlastnosti kontejneru A:" << endl;
	cout << "A.size() == " << A.size() << endl;
	cout << "A.capacity() == " << A.capacity() << endl;
	cout << "A.max_capacity() == " << A.max_size() << endl << endl;

	cout << "Vlastnosti kontejneru B:" << endl;
	cout << "B.size() == " << B.size() << endl;
	cout << "B.capacity() == " << B.capacity() << endl;
	cout << "B.max_capacity() == " << B.max_size() << endl << endl;

	cout << "Vlastnosti kontejneru C:" << endl;
	cout << "C.size() == " << C.size() << endl;
	cout << "C.capacity() == " << C.capacity() << endl;
	cout << "C.max_capacity() == " << C.max_size() << endl << endl;

	B.reserve(100);
	cout << "Vlastnosti kontejneru B:" << endl;
	cout << "B.size() == " << B.size() << endl;
	cout << "B.capacity() == " << B.capacity() << endl;
	cout << "B.max_capacity() == " << B.max_size() << endl << endl;
	*/
	/*
		for (int i = 0; i < 12; ++i)
		{
	//		cout << A[i] << ", ";
			try
			{
				cout << A.at(i) << ", ";
			}
			catch (const out_of_range& e)
			{
				cout << e.what() << endl;
			}
		}
		cout << endl;
	*/
	/*
	auto T1 = 1;
	auto T2 = 1.0;
	auto T3 = "123";
	cout << typeid(T1).name() << ", " << typeid(T2).name() << ", " << typeid(T3).name() << ", " << endl;
		
	for (int i = 0; i < A.size(); ++i)
		A[i] = i;

	for (auto it = A.begin(); it != A.end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;
	*/

	/*
	A.push_back(1);
	B.push_back(1.0);
	C.push_back('l');
	cout << "A.capacity() == " << A.capacity() << endl;
	cout << "B.capacity() == " << B.capacity() << endl;
	cout << "C.capacity() == " << C.capacity() << endl;

	for (int i = 0; i < 20; ++i)
	{
		B.push_back(static_cast<float>(i));
		cout << "B.capacity() == " << B.capacity() << endl;
	}

	vector<uint8_t> S1;
	cout << "S1: " << S1.max_size() << ", " << sizeof(uint8_t) << endl;
	vector<uint16_t> S2;
	cout << "S2: " << S2.max_size() << ", " << sizeof(uint16_t) << endl;
	vector<uint32_t> S3;
	cout << "S3: " << S3.max_size() << ", " << sizeof(uint32_t) << endl;
	vector<uint64_t> S4;
	cout << "S4: " << S4.max_size() << ", " << sizeof(uint64_t) << endl;
	*/

	std::map<std::string, int> D;
	D["Tokyo"] = 37833000;
	D["Dilli"] = 24953000;
	D["Sanghaj"] = 22991000;
	D["Maxico City"] = 20843000;
	D["Sao Paulo"] = 20831000;
	D["Praha"] = 1000000;

	for (auto it = D.begin(); it != D.end(); ++it)
	{
		cout << it->first << ": " << it->second << endl;
	}

	auto it = D.find("Praha");
	if (it == D.end())
	{
		cout << "Praha tam neni" << endl;
	}
	else
	{
		cout << "Praha tam je a ma " << it->second << " pocet obyvatel" << endl;
	}

	return 0;
}
