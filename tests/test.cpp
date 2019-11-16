// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "../include/header.hpp"


TEST(Sharpet_ptr, test1_sharp_null) {//+

    SharedPtr<int> ptr;

    ASSERT_EQ(ptr.get(), nullptr);

    ASSERT_EQ(bool(ptr), false);

    ASSERT_EQ(ptr.use_count(), 0);
}

TEST(Sharpet_ptr, test1_1_sharp_null) {//+

    SharedPtr<std::string> ptr;

    ASSERT_EQ(ptr.get(), nullptr);

    ASSERT_EQ(bool(ptr), false);

    ASSERT_EQ(ptr.use_count(), 0);
}

TEST(shared_ptr, test2_Count)//+
{
    double a = rand();
    SharedPtr ptr1{new double {a}};

    ASSERT_EQ(bool(ptr1), true);

    ASSERT_EQ(ptr1.use_count(), 1);

    double b = 1945;
    SharedPtr ptr2(new double {b});

    ASSERT_EQ(ptr2.use_count(), 1);

    ASSERT_EQ(bool(ptr2), true);
}

TEST(shared_ptr, test3)//+
{
    SharedPtr ptr(new double{34.56});

    ASSERT_EQ(*(ptr.get()), 34.56);

    ASSERT_EQ(bool(ptr), true);

    ASSERT_EQ(ptr.use_count(), 1);
}




TEST(shared_ptr, test4)//+
{
    SharedPtr ptr(new int{5});

    SharedPtr ptr2(std::move(ptr));

    ASSERT_EQ(*(ptr2.get()), 5);

    ASSERT_EQ(bool(ptr2), true);

    ASSERT_EQ(ptr2.use_count(), 1);
}

TEST(shared_ptr, test5)//+
{
    SharedPtr ptr(new int{5});

    SharedPtr ptr2 = ptr;


    ASSERT_EQ(*(ptr.get()), *(ptr2.get()));

    ASSERT_EQ(*(ptr.get()), 5);



    ASSERT_EQ(bool(ptr), bool(ptr2));

    ASSERT_EQ(bool(ptr), true);



    ASSERT_EQ(ptr.use_count(), ptr2.use_count());

    ASSERT_EQ(ptr.use_count(), 2);
}

TEST(shared_ptr, test6)//+
{
    SharedPtr ptr(new int{5});

    SharedPtr ptr2 = std::move(ptr);

    ASSERT_EQ(*(ptr2.get()), 5);

    ASSERT_EQ(bool(ptr2), true);

    ASSERT_EQ(ptr2.use_count(), 1);
}



TEST(shared_ptr, test8_bool_check)//+
{
    SharedPtr<int> ptr{};

    ASSERT_EQ(bool(ptr), false);

    SharedPtr ptr2(new int{23235});

    ASSERT_EQ(bool(ptr2), true);
}

TEST(shared_ptr, test9)//+
{
    SharedPtr ptr{new int{567}};

    ptr.reset();
    ASSERT_EQ(bool(ptr), false);

    ptr.reset(new int{57});

    ASSERT_EQ(*(ptr.get()), 57);

    ASSERT_EQ(bool(ptr), true);

    ASSERT_EQ(ptr.use_count(), 1);
}

TEST(shared_ptr, test10)
{
    SharedPtr ptr1{new int{567}};
    SharedPtr ptr2{new int{123}};
    SharedPtr ptr3 = ptr1;

    ptr2.swap(ptr1);

    ASSERT_EQ(ptr2.use_count(), 2);
    ASSERT_EQ(ptr1.use_count(), 1);


}

TEST(shared_ptr, test11)//+
{
    SharedPtr ptr{new int{235}};
    SharedPtr ptr2{new int{105}};

    ptr.swap(ptr2);

    ASSERT_EQ(*(ptr2.get()), 235);

    ASSERT_EQ(bool(ptr2), true);

    ASSERT_EQ(ptr2.use_count(), 1);

    ASSERT_EQ(*(ptr.get()), 105);

    ASSERT_EQ(bool(ptr), true);

    ASSERT_EQ(ptr.use_count(), 1);
}

TEST(shared_ptr, test12)//+
{
    int d = 0;
    int* c = &d;
    SharedPtr ptr(c);

    ASSERT_EQ(*(ptr.get()), 0);

    ASSERT_EQ(bool(ptr), true);

    ASSERT_EQ(ptr.use_count(), 1);
}

TEST(shared_ptr, test13)//+
{
    SharedPtr ptr1(new int{67});

    SharedPtr ptr2(ptr1);

    ASSERT_EQ(*(ptr1.get()), *(ptr2.get()));

    ASSERT_EQ(*(ptr2.get()), 67);



    ASSERT_EQ(bool(ptr1), bool(ptr2));

    ASSERT_EQ(bool(ptr1), true);



    ASSERT_EQ(ptr1.use_count(), ptr2.use_count());

    ASSERT_EQ(ptr2.use_count(), 2);
}


TEST(shared_ptr, test14)//+
{
    SharedPtr ptr(new int{5});

    SharedPtr ptr2 = ptr;

    ASSERT_EQ(*(ptr.get()), *(ptr2.get()));

    ASSERT_EQ(*(ptr.get()), 5);



    ASSERT_EQ(bool(ptr), bool(ptr2));

    ASSERT_EQ(bool(ptr), true);



    ASSERT_EQ(ptr.use_count(), ptr2.use_count());

    ASSERT_EQ(ptr.use_count(), 2);



    ptr.~SharedPtr();



    ASSERT_EQ(*(ptr2.get()), 5);

    ASSERT_EQ(bool(ptr2), true);

    ASSERT_EQ(ptr2.use_count(), 1);
}

