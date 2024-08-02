/***********************************************************************************************/
/******************************* merge two arrays together ********-****************************/
/***********************************************************************************************/

#include <iostream> 
#include <map>

void merge(int arr1[] , int arr2[] , int count1 , int count2) 
{ 
	std::map<int , int> new_array;

	for (int i = 0; i < count1; i++)
	{
		/* code */
		new_array[arr1[i]]++;
	}
	
	for (int i = 0; i < count2; i++)
	{
		/* code */
		new_array[arr2[i]]++;
	}

	for (auto i : new_array)
	{
		/* code */
		std::cout << i.first <<  " ";
	}
	

}
int main() 
{ 
	int arr1[] = { 11, 15, 6, 8, 9, 10 }; 
	int count1 = sizeof(arr1) / sizeof(arr1[0]); 
	
	int arr2[] = {1,2,3,4,5,6};
	int count2 = sizeof(arr2) / sizeof(arr2[0]); 


	merge(arr1 , arr2 , count1 , count2) ;


}
