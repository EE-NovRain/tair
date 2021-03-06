#include "interface_test_base.h"
#include <string>
using testing::Types;
using namespace boost;
using namespace std;

namespace tair {
	
typedef ::testing::Types<int32_t,int64_t,double,std::string> ItemTypes;

TYPED_TEST_CASE(CTestInterfaceItemBase,ItemTypes);

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_01_dataNotExist)
{
	data_entry key1("Item10TestCase_01_key_01");
	data_entry key2("Item10TestCase_01_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(ret,TAIR_RETURN_SUCCESS);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(ret,TAIR_RETURN_SUCCESS);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,0,1);
	ASSERT_EQ(TAIR_RETURN_DATA_NOT_EXIST, ret);

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_01_1_dataNotExist)
{
	data_entry key1("Item10TestCase_01_1_key_01");
	data_entry key2("Item10TestCase_01_1_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(ret,TAIR_RETURN_SUCCESS);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(ret,TAIR_RETURN_SUCCESS);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(-1,key2,0,1);
	ASSERT_EQ(TAIR_RETURN_INVALID_ARGUMENT, ret);

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_01_2_dataNotExist)
{
	data_entry key("");
	int ret = CTestInterfaceBase::client_handle.remove_items(1,key,0,1);
	ASSERT_EQ(TAIR_RETURN_ITEMSIZE_ERROR, ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_02_dataExist)
{
	data_entry key1("Item10TestCase_03_key_01");
	data_entry key2("Item10TestCase_03_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,0,1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_TRUE(result_3.size() == value_3.size() - 1);
	for(uint32_t i=0;i<result_3.size();++i){
		ASSERT_TRUE(result_3[i] == value_3[i+1]);
	}

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_03_dataExist)
{
	data_entry key1("Item10TestCase_03_key_01");
	data_entry key2("Item10TestCase_03_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,1,2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_TRUE(result_3.size() == value_3.size() - 2);
	ASSERT_TRUE(result_3[0] == value_3[0]);
	for(uint32_t i=1;i<result_3.size();++i){
		ASSERT_TRUE(result_3[i] == value_3[i+2]);
	}

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}


TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_04_dataExist)
{
	data_entry key1("Item10TestCase_04_key_01");
	data_entry key2("Item10TestCase_04_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,-1,2,result_3);
	ASSERT_EQ(TAIR_RETURN_SUCCESS, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_TRUE(result_3.size() == value_3.size() - 1);
	for(uint32_t i=0;i<result_3.size();++i){
		ASSERT_TRUE(result_3[i] == value_3[i]);
	}

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_05_dataExist)
{
	data_entry key1("Item10TestCase_05_key_01");
	data_entry key2("Item10TestCase_05_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,value_3.size() + 10,2);
	ASSERT_EQ(TAIR_RETURN_OUT_OF_RANGE, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_TRUE(result_3 == value_3);

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}


TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_06_dataExist)
{
	data_entry key1("Item10TestCase_06_key_01");
	data_entry key2("Item10TestCase_06_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,1,value_3.size() + 1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_TRUE(result_3.size() == 1);
	ASSERT_TRUE(result_3[0] == value_3[0]);

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_09_dataExist)
{
	data_entry key1("Item10TestCase_09_key_01");
	data_entry key2("Item10TestCase_09_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	//count == 0
	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,1,0);
	ASSERT_EQ(TAIR_RETURN_INVALID_ARGUMENT, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_TRUE(result_3 == value_3);

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_10_dataExist)
{
	data_entry key1("Item10TestCase_10_key_01");
	data_entry key2("Item10TestCase_10_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	//count == 0
	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,0,tair_client_api::ALL_ITEMS);
	ASSERT_EQ(TAIR_RETURN_SUCCESS, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_EQ(TAIR_RETURN_DATA_NOT_EXIST,ret);

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_DATA_NOT_EXIST,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_11_dataExist)
{
	data_entry key1("Item10TestCase_11_key_01");
	data_entry key2("Item10TestCase_11_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	//count == 0
	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,2,tair_client_api::ALL_ITEMS);
	ASSERT_EQ(TAIR_RETURN_SUCCESS, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ASSERT_TRUE(result_3.size() == 2);
	ASSERT_TRUE(result_3[0] == value_3[0]);
	ASSERT_TRUE(result_3[1] == value_3[1]);

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_12_dataExist)
{
	data_entry key1("Item10TestCase_12_key_01");
	data_entry key2("Item10TestCase_12_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,-3,tair_client_api::ALL_ITEMS);
	ASSERT_EQ(TAIR_RETURN_SUCCESS, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ASSERT_TRUE(result_3.size() == value_3.size() - 3);
	for(uint32_t i=0;i<result_3.size();++i){
		ASSERT_EQ(result_3[i],value_3[i]);
	}

	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_13_dataExist)
{
	data_entry key1("Item10TestCase_13_key_01");
	data_entry key2("Item10TestCase_13_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;

	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	
	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	//count == -1
	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,1,-1);
	ASSERT_EQ(TAIR_RETURN_INVALID_ARGUMENT, ret);
	
	ret = CTestInterfaceBase::client_handle.get_items(1,key2,0,tair_client_api::ALL_ITEMS,result_3);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ASSERT_TRUE(result_3 == value_3);
	
	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
}

TYPED_TEST(CTestInterfaceItemBase,Item10_x_removeItems_14_dataExist)
{
	data_entry key1("Item10TestCase_14_key_01");
	data_entry key2("Item10TestCase_14_key_02");

	typename TestFixture::List value_1;
	typename TestFixture::List value_2;
	typename TestFixture::List value_3;
	
	CTestInterfaceBase::client_handle.remove(1,key2);
	try {
		for(uint32_t i=0;i < this->_data.size();++i){
			value_1.push_back(any_cast<TypeParam> (this->_data[i]));
		}

		for(uint32_t i=0;i < this->_data2.size();++i){
			value_2.push_back(any_cast<TypeParam> (this->_data2[i]));
		}
		for(uint32_t i=0;i < this->_data3.size();++i){
			value_3.push_back(any_cast<TypeParam> (this->_data3[i]));
		}
	}catch(bad_any_cast& e){
		cout << e.what() << endl;
		exit(-1);
	}


	int ret = CTestInterfaceBase::client_handle.add_items(1,key1,value_1,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(2,key2,value_2,0,0);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	ret = CTestInterfaceBase::client_handle.add_items(1,key2,value_3,0,3);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);

	sleep(4);

	typename TestFixture::List result_1;
	typename TestFixture::List result_2;
	typename TestFixture::List result_3;

	ret = CTestInterfaceBase::client_handle.get_items(1,key1,0,tair_client_api::ALL_ITEMS,result_1);
	ASSERT_TRUE(value_1 == result_1);

	ret = CTestInterfaceBase::client_handle.get_items(2,key2,0,tair_client_api::ALL_ITEMS,result_2);
	ASSERT_TRUE(value_2 == result_2);

	ret = CTestInterfaceBase::client_handle.remove_items(1,key2,1,1);
	ASSERT_EQ(TAIR_RETURN_DATA_EXPIRED, ret);
	
	//clean
	ret = CTestInterfaceBase::client_handle.remove(1,key1);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(2,key2);
	ASSERT_EQ(TAIR_RETURN_SUCCESS,ret);
	ret = CTestInterfaceBase::client_handle.remove(1,key2);
	ASSERT_EQ(TAIR_RETURN_DATA_NOT_EXIST,ret);
}


} /* tair */

