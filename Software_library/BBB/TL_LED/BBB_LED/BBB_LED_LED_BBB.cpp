#include "BBB_LED_LED_BBB.h"


BBB_LED_LED_BBB::BBB_LED_LED_BBB(int number){ 
    this->number = number; 
    ostringstream s; 
    s << INLED_PATH << number; 
    path = string(s.str()); 
}

void BBB_LED_LED_BBB::writeINLED(string filename, string value){ 
    ofstream fs; 
    fs.open((path+filename).c_str()); 
    fs << value; 
    fs.close(); 
}

void BBB_LED_LED_BBB::removeTrigger(){ 
    writeINLED("/trigger", "none"); 
}

void BBB_LED_LED_BBB::turnOn(){ 
    //cout << "Turning LED" << number << " on." << endl; 
    removeTrigger(); 
    writeINLED("/brightness", "1"); 
}

void BBB_LED_LED_BBB::turnOff(){ 
    //cout << "Turning LED" << number << " off." << endl; 
    writeINLED("/brightness", "0"); 
}

void BBB_LED_LED_BBB::toggle(){
    ifstream fs;
    fs.open((path + "/brightness").c_str()); 
    string line; 
    while(getline(fs, line)) {
        //cout << line << endl;
        if (line == "1")
            writeINLED("/brightness", "0");
        else if (line == "0")
            writeINLED("/brightness", "1");
    } 
    fs.close(); 
}


void BBB_LED_LED_BBB::flash(uint32_t ms){ 
    //cout << "Making LED" << number << " flash." << endl;
    stringstream ss;
    string delayms;
    ss << ms; ss >> delayms;
    writeINLED("/trigger", "timer"); 
    writeINLED("/delay_on", delayms); 
    writeINLED("/delay_off", delayms); 
}

void BBB_LED_LED_BBB::outputState(){ 
    ifstream fs; 
    fs.open((path + "/trigger").c_str()); 
    string line; 
    while(getline(fs, line)) cout << line << endl; 
    fs.close(); 
}

const int BBB_LED_LED_BBB::state(){
    ifstream in;
    in.open((path + "/brightness").c_str());
    string line;
    int res;
    while(getline(in, line)){
        if(line == "1"){
            res = 1;
	}else if(line == "0"){
	    res = 0;
	}
    }
    in.close();
    return res;
}

BBB_LED_LED_BBB::~BBB_LED_LED_BBB(){ 
    //cout <<"Destroying the LED object with path: " << path << endl; 
}

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_LED == BBB_LED
		BBB_LED_LED_BBB TL_LED(0);
		BBB_LED_LED_BBB TL_LED1(1);
		BBB_LED_LED_BBB TL_LED2(2);
		BBB_LED_LED_BBB TL_LED3(3);
	#endif
#endif
