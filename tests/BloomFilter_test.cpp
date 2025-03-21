//
// Created by mr on 1/19/24.
//

#include <gtest/gtest.h>
#include "../src/URLArray.h"
#include "../src/AddUrl.h"
#include "../src/SearchUrl.h"
#include "../src/URLVector.h"
#include "../src/Hash1.h"
#include "../src/Hash2.h"
#include <string>
#include "../src/Menu.h"
#include "../src/BloomFilter.h"

TEST(URLVectTrue, BasicTest) {
    URLVector* vect = new URLVector();
    vect->addURL("hi");
    EXPECT_TRUE(vect->searchURL("hi"));
    delete vect;
}

TEST(URLVectFalse, BasicTest) {
    URLVector* vect = new URLVector();
    vect->addURL("hi");
    EXPECT_FALSE(vect->searchURL("bye"));
    delete vect;
}

TEST(Hash1True, BasicTest){
    std::hash<std::string> hasher;
    Hash1* hash1 = new Hash1(10, "hi");
    EXPECT_EQ(hash1->doHash(), hasher("hi") % 10);
    delete hash1;
}

TEST(Hash1False, BasicTest){
    std::hash<std::string> hasher;
    Hash1* hash1 = new Hash1(10, "hi");
    EXPECT_NE(hash1->doHash(), hasher("bye") % 10);
    delete hash1;
}

TEST(Hash2True, BasicTest){
    std::hash<std::string> hasher;
    Hash2* hash2 = new Hash2(10, "hi");
    std::string check1 =std::to_string(hasher("hi"));
    EXPECT_EQ(hash2->doHash(), hasher(check1) % 10);
    delete hash2;
}

TEST(Hash2False, BasicTest){
    std::hash<std::string> hasher;
    Hash2* hash2 = new Hash2(10, "hi");
    std::string check2 =std::to_string(hasher("bi"));
    EXPECT_NE(hash2->doHash(), hasher(check2) % 10);
    delete hash2;
}

TEST(SearchURLTrue, BasicTest){
    //add url
    bool* arr = new bool[8];
    for (int i = 0; i <8 ; i++){
        arr[i] = false;
    }
    URLVector* urlVector = new URLVector();
    AddUrl* addurl = new AddUrl(8, arr, 1, 2, urlVector);
    addurl->execute("hi");

    //search url
    testing::internal::CaptureStdout();
    SearchUrl* searchUrl = new SearchUrl(8, arr, 1, 2, urlVector);
    bool result = searchUrl->execute("hi");
    EXPECT_TRUE(result);

    delete[] arr;
    delete urlVector;
    delete addurl;
}

TEST(SearchURLFalse, BasicTest){
    //add url
    bool* arr = new bool[8];
    for (int i = 0; i <8 ; i++){
        arr[i] = false;
    }
    URLVector* urlVector = new URLVector();
    AddUrl* addurl = new AddUrl(8, arr, 1, 2, urlVector);
    addurl->execute("hi");

    //search url
    testing::internal::CaptureStdout();
    SearchUrl* searchUrl = new SearchUrl(8, arr, 1, 2, urlVector);
    bool result = searchUrl->execute("bi");
    EXPECT_FALSE(result);

    delete[] arr;
    delete urlVector;
    delete addurl;
}









