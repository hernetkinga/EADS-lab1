#include <iostream>
#include "template.h"
#include <string>
#include "gtest/gtest.h"
/// I had to download googletest manually from https://github.com/google/googletest and put it in subdirectory 'lib'
/// because the compiler had problems with finding:
/// GIT_REPOSITORY https://github.com/google/googletest.git
/// GIT_TAG master
using namespace std;

int main() {
    /*
    Sequence<int, int> S1;
    cout << " Sequence 1 " << endl;
    S1.insert_back(1, 1);
    S1.insert_back(7, 2);
    S1.insert_back(3, 1);
    S1.insert_front(10, 10);
    S1.insert_back(8, 8);
    //cout << "Length of S1: " << S1.length() << endl;
    S1.print();
    cout << "--- POP FRONT ---" << endl;
    S1.pop_front();
    //S1.print();
    S1.pop_front();
    S1.pop_front();
    S1.print();

    Sequence<string, int> S2;
    cout  << " Sequence 2" << endl;
    S2.insert_back("soczek", 1);
    S2.insert_front("olowek", 17);
    S2.print();
    //S2.clear_list();
    //cout << "Removing S2" << endl;
    //S2.print();

    Sequence<int, int> S3;
    cout << " Sequence 3" << endl;
    cout << "Length of S3: " << S3.length() << endl;
    S3.pop_front();
    S3.print();

    Sequence<int,int> S4;
    S4=S1;
    cout << "Sequence 4 (copy of Sequence 1)" << endl;
    S4.print();

    Sequence<string,int> S5;
    S5=S2;
    cout << "Sequence 5 (copy of Sequence 2)" << endl;
    S5.insert_front("zeszyt",15);
    S5.print();

    Sequence<int,int> S6;
    S6.insert_front(1,1);
    S6.insert_front(2,2);
    S6.insert_front(3,3);
    S6.insert_front(4,4);
    S6.insert_front(5,5);
    S6.print();
    return 0;

*/
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
