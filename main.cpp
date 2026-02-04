#include <iostream>



//#include "op_lab_1/lab1.h"
//#include "op_lab_2/building.h"
#include "op_lab_5/lab5.h"


int main() {
    int choice;
    system("chcp 65001");
    while (true) {
        std::cout << "\n===== ======= =====" << std::endl;
        std::cout << "1. Run  #1" <<            std::endl;
        std::cout << "2. Run  #2" << std::endl;
        std::cout << "1. Run  #3" << std::endl;
        std::cout << "2. Run  #4" << std::endl;
        std::cout << "1. Run  #5" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "::: ";
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                   //run_lab1();
                   break;
            case 2:
                    //run_lab2();
                    break;
            case 3:

                break;
            case 4:

                break;

            case 5:
                run_lab5();
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}