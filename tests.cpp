#include <iostream>
#include <cassert>
#include <cstring>
#include "seq.h"
#include "listseq.h"
#include "arseq.h"
#include "unptr.h"
#include "shptr.h"


using std::cout;
using std::cin;
using std::endl;


//unique ptr tests
void test_creating_unique_ptr()
{
	int* ptr_1 = new int(4);
	UniquePtr<int> un_ptr_0 = UniquePtr<int>();
	assert(un_ptr_0.get() == 0);
	cout << "Unique ptr empty contructor OK\n";
	UniquePtr<int> un_ptr_1 = UniquePtr<int>(ptr_1);
	assert(un_ptr_1.get() != 0);
	cout << "Unique ptr contructor by ptr OK\n";
	UniquePtr<int> un_ptr_2 = UniquePtr<int>(new int(4));
	UniquePtr<int> un_ptr_3 = std::move(un_ptr_2);
	assert(un_ptr_3.get() != 0 && un_ptr_2.get() == 0);
	cout << "Unique ptr move contructor OK\n";
}


void test_operators_unique_ptr()
{
	UniquePtr<int> un_ptr = UniquePtr<int>(new int(1));
	int* items = new int[3];
	items[0] = 1;
	items[1] = 2;
	items[2] = 3;
	ArraySequence<int> array(items, 3);
	UniquePtr<ArraySequence<int>> un_ptr_2 = UniquePtr<ArraySequence<int>>(new ArraySequence(array));
	assert(*un_ptr == 1);
	cout << "Unique ptr operator * OK\n";
	assert(un_ptr_2->get_length() == 3);
	cout << "Unique ptr operator -> OK\n";
}


void test_get_unique_ptr()
{
	int* ptr = new int(2);
	UniquePtr<int> un_ptr = UniquePtr<int>(ptr);
	assert(un_ptr.get() == ptr);
	cout << "Unique ptr get OK\n";
}


void test_reset_unique_ptr()
{
	int* ptr = new int(2);
	UniquePtr<int> un_ptr = UniquePtr<int>(ptr);
	un_ptr.reset(new int(3));
	assert(*un_ptr == 3);
	cout << "Unique ptr reset OK\n";
}


void test_release_unique_ptr()
{
	int* ptr_1 = new int(2);
	UniquePtr<int> un_ptr = UniquePtr<int>(ptr_1);
	int* ptr_2 = un_ptr.release();
	assert(un_ptr.get() == 0 && ptr_1 == ptr_2);
	cout << "Unique ptr release OK\n";
}


void test_swap_unique_ptr()
{
	UniquePtr<int> un_ptr_1 = UniquePtr<int>(new int(1));
	UniquePtr<int> un_ptr_2 = UniquePtr<int>(new int(2));
	un_ptr_1.swap(un_ptr_2);
	assert(*un_ptr_1 == 2 && *un_ptr_2 == 1);
	cout << "Unique ptr swap OK\n";
}


//shared ptr tests
void test_creating_shared_ptr()
{
	int* ptr_1 = new int(4);
	SharedPtr<int> sh_ptr_0 = SharedPtr<int>();
	assert(sh_ptr_0.get() == 0);
	cout << "Shared ptr empty contructor OK\n";
	SharedPtr<int> sh_ptr_1 = SharedPtr<int>(ptr_1);
	assert(sh_ptr_1.get() != 0);
	cout << "Shared ptr contructor by ptr OK\n";
	SharedPtr<int> sh_ptr_2 = sh_ptr_1;
	assert(sh_ptr_1.get() == sh_ptr_2.get());
	cout << "Shared ptr copy contructor OK\n";


}


void test_operators_shared_ptr()
{
	SharedPtr<int> sh_ptr_1 = SharedPtr<int>(new int(1));
	SharedPtr<int> sh_ptr_2 = SharedPtr<int>(new int(2));
	sh_ptr_2 = sh_ptr_1;
	int* items = new int[3];
	items[0] = 1;
	items[1] = 2;
	items[2] = 3;
	ArraySequence<int> array(items, 3);
	SharedPtr<ArraySequence<int>> sh_ptr_3 = SharedPtr<ArraySequence<int>>(new ArraySequence(array));
	assert(*sh_ptr_1 == 1);
	cout << "Shared ptr ptr operator * OK\n";
	assert(sh_ptr_3->get_length() == 3);
	cout << "Shared ptr operator -> OK\n";
	assert(*sh_ptr_2 == 1 && sh_ptr_2.use_count() == 2);
	cout << "Shared ptr assignment OK\n";
}


void test_get_shared_ptr()
{
	int* ptr = new int(2);
	SharedPtr<int> sh_ptr = SharedPtr<int>(ptr);
	assert(sh_ptr.get() == ptr);
	cout << "Shared ptr get OK\n";
}


void test_reset_shared_ptr()
{
	int* ptr = new int(2);
	SharedPtr<int> sh_ptr = SharedPtr<int>(ptr);
	sh_ptr.reset(new int(3));
	assert(*sh_ptr == 3);
	cout << "Shared ptr reset OK\n";
}


void test_swap_shared_ptr()
{
	SharedPtr<int> sh_ptr_1 = SharedPtr<int>(new int(1));
	SharedPtr<int> sh_ptr_2 = SharedPtr<int>(new int(2));
	SharedPtr<int> sh_ptr_3 = sh_ptr_2;
	sh_ptr_1.swap(sh_ptr_2);
	assert(*sh_ptr_1 == 2 && *sh_ptr_2 == 1 && sh_ptr_1.use_count() == 2 && sh_ptr_2.use_count() == 1);
	cout << "Shared ptr swap OK\n";
}


void test_unique_shared_ptr()
{
	SharedPtr<int> sh_ptr_1 = SharedPtr<int>(new int(1));
	SharedPtr<int> sh_ptr_2 = SharedPtr<int>(new int(2));
	SharedPtr<int> sh_ptr_3 = sh_ptr_2;
	assert(sh_ptr_1.unique() && !sh_ptr_2.unique());
	cout << "Shared ptr unique OK\n";
}

void test_use_count_shared_ptr()
{
	SharedPtr<int> sh_ptr_1 = SharedPtr<int>(new int(1));
	SharedPtr<int> sh_ptr_2 = SharedPtr<int>(new int(2));
	SharedPtr<int> sh_ptr_3 = sh_ptr_2;
	assert(sh_ptr_1.use_count() == 1 && sh_ptr_2.use_count() == 2);
	cout << "Shared ptr use_count OK\n";
}


int main()
{
	//running unique ptr tests
	test_creating_unique_ptr();
	test_operators_unique_ptr();
	test_get_unique_ptr();
	test_reset_unique_ptr();
	test_release_unique_ptr();
	test_swap_unique_ptr();

	//running shared ptr tests
	test_creating_shared_ptr();
	test_operators_shared_ptr();
	test_get_shared_ptr();
	test_reset_shared_ptr();
	test_swap_shared_ptr();
	test_unique_shared_ptr();
	test_use_count_shared_ptr();
	return 1;
}