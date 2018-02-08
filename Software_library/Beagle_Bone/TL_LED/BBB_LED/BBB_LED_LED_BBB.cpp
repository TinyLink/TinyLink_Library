#include "BBB_LED_LED_BBB.h"


INLED::INLED(int number){ 
    this->number = number; 
    ostringstream s; 
    s << INLED_PATH << number; 
    path = string(s.str()); 
}

void INLED::writeINLED(string filename, string value){ 
    ofstream fs; 
    fs.open((path+filename).c_str()); 
    fs << value; 
    fs.close(); 
}

void INLED::removeTrigger(){ 
    writeINLED("/trigger", "none"); 
}

void INLED::turnOn(){ 
    //cout << "Turning LED" << number << " on." << endl; 
    removeTrigger(); 
    writeINLED("/brightness", "1"); 
}

void INLED::turnOff(){ 
    //cout << "Turning LED" << number << " off." << endl; 
    writeINLED("/brightness", "0"); 
}

void INLED::toggle(){
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


void INLED::flash(uint32_t ms){ 
    //cout << "Making LED" << number << " flash." << endl;
    stringstream ss;
    string delayms;
    ss << ms; ss >> delayms;
    writeINLED("/trigger", "timer"); 
    writeINLED("/delay_on", delayms); 
    writeINLED("/delay_off", delayms); 
}

void INLED::outputState(){ 
    ifstream fs; 
    fs.open((path + "/trigger").c_str()); 
    string line; 
    while(getline(fs, line)) cout << line << endl; 
    fs.close(); 
}

INLED::~INLED(){ 
    //cout <<"Destroying the LED object with path: " << path << endl; 
}

#if PLATFORM == 3 && BOARD == 1005
# if LED == BBB_LED
INLED TL_LED(0);
INLED TL_LED1(1);
INLED TL_LED2(2);
INLED TL_LED3(3);
#endif
#endif