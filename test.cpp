#include "gtest/gtest.h"
#include "template.h"
#include <string>

TEST(Sequence, length){
    //empty sequence
    Sequence<int,int> t1;
    //empty sequence has length 0
    ASSERT_EQ(t1.length(),0);

    t1.insert_back(1,1);
    t1.insert_front(2,2);
    //expected value is 2
    ASSERT_EQ(t1.length(),2);

    t1.pop_front();
    t1.pop_front();
    t1.pop_front();
    //expected value is 0 not -1
    ASSERT_EQ(t1.length(),0);

    //length test with strings
    Sequence<string,int> t2;
    t2.insert_back("ziaja",1315);
    t2.insert_back("lays",876);
    t2.insert_back("buff",2137);
    ASSERT_EQ(t2.length(),3);
}

TEST(Sequence,pop_test){
    //pop_front is a bool function meaning returns true when removing, false when empty sequence
    Sequence<int,int> t3;
    ASSERT_EQ(t3.pop_front(),false);
    t3.insert_back(1,1);
    //removing 1 out of 1 objects - expected true
    ASSERT_EQ(t3.pop_front(),true);
    //removing 1 out of 0 objects - expected false
    ASSERT_EQ(t3.pop_front(),false);
}
TEST(Sequence,clear){
    Sequence<string,string> test;
    test.insert_back("abc","cde");
    test.insert_back("cde","abc");
    test.clear_list();
    //all elements should be removed - expected 0
    ASSERT_EQ(test.length(),0);
}
TEST(Sequence,assignment){
 Sequence<int,int> *t4 = new Sequence<int,int>;
 t4->insert_front(1,1);
 t4->insert_front(2,2);
 t4->insert_front(3,3);
 t4->insert_back(5,5);
 Sequence<int,int> t5;
 t5 = *t4;
 delete t4;
    ASSERT_EQ(t5.length(),4);
    ASSERT_EQ(t5.pop_front(),true);
    ASSERT_EQ(t5.pop_front(),true);
    ASSERT_EQ(t5.pop_front(),true);
    ASSERT_EQ(t5.pop_front(),true);
    ASSERT_EQ(t5.length(),0);
    ASSERT_EQ(t5.pop_front(),false);
}
TEST(Sequence, splitkey){
    /*
    Sequence<int,int> s1;
    s1.insert_back(1,1);
    s1.insert_back(2,2);
    s1.insert_back(3,3);
    s1.insert_back(4,4);
    s1.insert_back(5,5);
    s1.insert_back(6,6);
    Sequence<int,int> s2;
    Sequence<int,int> s3;
    split_key(s1,3,1,2,1,2,s2,s3);
    cout<<"S2:"<<endl;
    s2.print();
    cout<<"S3:"<<endl;
    s3.print();
*/
    Sequence<int,int> seq;
    seq.insert_back(1,2);
    seq.insert_back(1,3);
    seq.insert_back(1,5);
    seq.insert_back(2,11);
    seq.insert_back(3,17);
    seq.insert_back(4,3);
    seq.insert_back(5,2);
    seq.insert_back(6,6);
    seq.insert_back(10,14);
    seq.insert_back(10,13);
    seq.insert_back(1,1);
    cout<<"seq:"<< endl;
    seq.print();
    Sequence<int,int>seq1;
    Sequence<int,int>seq2;
    split_key(seq,1,3,2,3,3,seq1,seq2);
    cout<<"seq1:" << endl;
    seq1.print();
    ASSERT_EQ(seq1.length(),4);
    cout<<"seq2:" << endl;
    seq2.print();
    ASSERT_EQ(seq2.length(),5);
}
/*
TEST(Sequence,copy){
    Sequence<int,int> t6;
    t6.insert_front(1,1);
    t6.insert_front(2,2);
    t6.insert_front(3,3);
    t6.clear_list();
    t6.print();

    Sequence<int,int> t7 = t6;

    t7.print();
    ASSERT_EQ(t7.length(),0);
}
 */
/*
//this test is supposed to fail
TEST(Sequence, length_FAIL_test){
    Sequence<int,int> t2;
    ASSERT_EQ (t2.length(),1);
}
TEST(Sequence,test){
    ASSERT_EQ("","");
}
 */