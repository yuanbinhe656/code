#include <iostream>
using namespace std;

template <typename T = int>
class TestLambda01 {
public:

	TestLambda01(int a, int b):ma(a),mb(b){}
	void operator()(int a, int b)
	{

	}
private:
	int ma;
	int mb;
};
