#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <unordered_map>

using namespace std;






int time1() {
	static unsigned char buffer[65];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return timeinfo->tm_min;
	
}



void timer(){	
	int minetNow = time1();
	int minetAdd = minetNow + 1;
	cout << "Time1: " << minetNow << endl;
	cout << "Time2: " << minetAdd << endl;
	
	while (1) {
		int check = time1();
		if (check == minetAdd){
			cout << "BOOM!!!" << endl;
			exit(0);
		}
	}
	
}






void bomb(){
	
	usleep(1000);
	string pass;
	hash<string> hasher;

	
	while (1) {
		std::cout << "Input pass: ";
		std::cin >> pass;
		if ("10141042524399622065" == std::to_string(hasher(pass))) {
			cout << "You win!" << endl;
			exit(0);
		}else {
			cout << pass <<" :(" << endl;
		}

		
		
	}
	
}


int main() {
	
	std::thread tA(timer );
	std::thread tB(bomb);
	tA.join();
	tB.join();
	
	//return 0;

}
