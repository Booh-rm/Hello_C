#include <algorithm>
#include <iostream>
#include <vector>


bool repetido1 (int num1, int i);
bool repetido2 (int num2, int i);
int array1[] = {};
int array2[] = {};

int main()
{
	//---------------------------------------------------------------------------------
	
	std::cout << "\n-------------------------------------------------------\n";
	
	//---------------------------------------------------------------------------------
	
	int tam1,num1,tam2,num2;
	
    std::cout<<"\nEnter the size of the first array: ";
	std::cin>>tam1;
    
	int first[tam1];
    
	for(int i=0; i<tam1; i++){
        std::cout<<"please enter value "<<i+1<<" : ";
		std::cin>>num1;
		
		while(repetido1(num1, i)){
    		std::cout<<"\nNumber repeated\n";
    		std::cout<<"\nEnter another number: ";
			std::cin>>num1;
		}
		first[i] = num1;
		array1[i] = num1;
    }
    
    std::cout<<"\nEnter the size of the second array: ";
	std::cin>>tam2;
	
    int second[tam2];
    
	for(int j=0; j<tam2; j++){
        std::cout<<"please enter value "<<j+1<<" : ";
		std::cin>>num2;
		
		while(repetido2(num2, j)){
    		std::cout<<"\nNumber repeated\n";
    		std::cout<<"\nEnter another number: ";
			std::cin>>num2;
		}
		second[j] = num2;
        array2[j] = num2;
    }
    
    //---------------------------------------------------------------------------------

    int n = sizeof(first) / sizeof(first[0]);
    int n2 = sizeof(second) / sizeof(second[0]);

    std::vector<int> v1(n);
    std::vector<int> v2(n);
    std::vector<int> v(n);
	std::vector<int>::iterator it1, ls1;
    std::vector<int>::iterator it2, ls2;
    std::vector<int>::iterator it3, st3;

    std::sort(first, first + n);
    std::sort(second, second + n2);
    

    //---------------------------------------------------------------------------------

 	std::cout << "\n-------------------------------------------------------\n";

    std::cout << "\nFirst array contains : ";
    for (int i = 0; i < n; i++)
        std::cout << " " << first[i];
    std::cout << "\n";

    std::cout << "\nSecond array contains : ";
    for (int j = 0; j < n2; j++)
        std::cout << " " << second[j];
    std::cout << "\n";

    std::cout << "\n-------------------------------------------------------\n";

    //---------------------------------------------------------------------------------

    ls1 = std::set_intersection(first, first + n, second, second + n2, v1.begin());

    std::cout << "\nThe intersection has " << (ls1 - v1.begin()) << " elements : ";
    for (it1 = v1.begin(); it1 != ls1; ++it1)
        std::cout << ' ' << *it1;
    std::cout << "\n";

    //---------------------------------------------------------------------------------

    ls2 = std::set_difference(first, first + n, second, second + n2, v2.begin());

    std::cout << "\nThe difference has " << (ls2 - v2.begin()) << " elements : ";
    for (it2 = v2.begin(); it2 < ls2; ++it2)
        std::cout << " " << *it2;
    std::cout << "\n";

    //---------------------------------------------------------------------------------

    it3 = std::set_union(first, first + n, second, second + n2, v.begin());

    std::cout << "\nThe union has " << (it3 - v.begin()) << " elements : ";
    for (st3 = v.begin(); st3 != it3; ++st3)
        std::cout << " " << *st3;
    std::cout << "\n";

    //---------------------------------------------------------------------------------

    std::cout << "\n-------------------------------------------------------\n";

 	//---------------------------------------------------------------------------------

    //system("PAUSE");
    return 0;
}

bool repetido1(int num1, int i){
   	for(int x=0; x<i; x++){
   		if(num1 == array1[x]){
   			return true;
		}
	}
	return false;
}

bool repetido2(int num2, int i){
   	for(int x=0; x<i; x++){
   		if(num2 == array2[x]){
   			return true;
		}
	}
	return false;
}
