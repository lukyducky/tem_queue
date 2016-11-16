#include "t_queue.h"
#include <ctime>

using namespace std;

int main(){

	srand(time(NULL));
	Queue <int> Q;
	Queue <int>Q1;

	for (int i = 0; i < 10; i++){
		int r = rand() %50;
		int q = rand() % 51;
		Q.pushBack(r);
		Q1.pushBack(q);
	}

	cout << Q << endl << Q1;
	

	system("pause");

}