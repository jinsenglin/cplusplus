 //========================DO-NOT-MODIFY-THE-FILE========================
#include <iostream>
#include <cstring>
#include "function.h"

void tryTestCase(Implement &inst)
{
    // parse each case
    std::string input;
	char op[20];
    int value;
	while(std::cin >> op)
	{
        if(strcmp("Insert", op) == 0){
            std::cin >> value;
            inst.Insert(value);
        }
        else if(strcmp("DeleteMax", op) == 0){ 
            inst.DeleteMax();
        }
		else if(strcmp("MaxPathWeight", op) == 0){ 
            std::cout << inst.MaxPathWeight(1) << std::endl;
        }
		else if(strcmp("InorderTraversal", op) == 0){ 
            std::cout << inst.InorderTraversal(1) << std::endl;
        }
		else if(strcmp("PreorderTraversal", op) == 0){ 
            std::cout << inst.PreorderTraversal(1) << std::endl;
        }
		else if(strcmp("PostorderTraversal", op) == 0){ 
            std::cout << inst.PostorderTraversal(1) << std::endl;
        }
        else if(strcmp("End", op) == 0) {
			string urResultStr = inst.toString();
            std::cout << urResultStr << endl;
            break;
        }
    }
}


int main(int argc, char* argv[])
{
	Implement inst = *(new Implement());
    tryTestCase(inst);

    return 0;
}
