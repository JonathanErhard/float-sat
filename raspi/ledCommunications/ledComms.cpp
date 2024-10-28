#include <stdio.h>
#include "udp_common.h"
#include <chrono>
#include <cppgpio.hpp>
#include <iostream>
#include <thread>
#include <queue>
#include <cstring>
#include <string>
#include <bitset>

/*************************************************/

void encodeMessage(std::string explodedMessage, int length, int periodMillis);
void sendByte(char charTx, int periodMillis);
void sync(int periodMillis);


UDPInLx udpIn(5554);
UDPOutLx udpOut(5553);
std::queue<std::string> messageQueue;
int encodedMessage[100];
using namespace GPIO;
DigitalOut out(18);
DigitalOut test(23);

void udpThread(){
    char inString[64];
    while(1) {
        udpIn.get(inString, 64);
        std::cout<<inString<<std::endl;
        messageQueue.push(std::string(inString));
    }
}

bool consoleInput = false;
void consoleThread(){
std::string a;
  while(1){
      std::cin >> a;
      if(a[0] == 'o') out.on();
      else if(a[0] == 'u') out.off();
      else
      consoleInput = true;
  }   
}

#define SLEEP(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))
#define BIT_TIME 200
void newEncodeMessage(std::string msg){
	for(int charCount = 0; charCount < msg.length(); charCount++){
		char c = msg[charCount];
		for(int bitNum = 0; bitNum < 8; bitNum++){
			out.on();
			SLEEP(BIT_TIME/4);
			out.off();
			SLEEP(BIT_TIME/4);
			
			if(c & 1 << bitNum){
				out.on();
				std::cout<<"1";
			}
			else{
				out.off();
				std::cout<<"0";
			}
			SLEEP(BIT_TIME/4);
			out.off();
			SLEEP(BIT_TIME/4);
		}
		std::cout<<std::endl;
	}
	
}

int main([[gnu::unused]] int argc, [[gnu::unused]] char* argv[]) {
    
//            DigitalOut out(18);
    test.on();
    out.off();
    bool onOff; 
    std::thread udpT(udpThread);
    std::thread conT(consoleThread);
    while(1) {
        //Check periodically if we got a message, any message means that we start communications rn
        if(messageQueue.empty() && !consoleInput){
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            continue;
        }
        
        std::string message = "Ltest 123#";
        //Get message
        if(!messageQueue.empty()){
            std::string tmpmsg = messageQueue.front();
            message = tmpmsg.substr(0, tmpmsg.find("#")+1);
            if(message == "LTURNON#"){
				out.on();
				messageQueue.pop();
				continue;
			}
			else if(message == "LTURNOFF#"){
				out.off();
				messageQueue.pop();
				continue;
			}
            messageQueue.pop();
        }
        
        out.off();
        SLEEP(100);
        consoleInput = false;
        std::cout<<"doing coms, message: "<<message<<"\n";
        
        
        int frequency = 5; // Hz
        int periodMillis = (1.0/frequency) * 1000;
        
        newEncodeMessage(message);
        
        //Convert message to byte array
        /*int length = message.length();
        char* explodedMessage = new char[length + 1];
        strcpy(explodedMessage, message.c_str());
        encodeMessage(explodedMessage, length, periodMillis);*/
        
        //Send to STM that LED Communications are done
        char* msg = "F11#";
        udpOut.send(msg, 4);
    }
    return 0;
}


/*

void encodeMessage(std::string explodedMessage, int length, int periodMillis)
{
    //out.on();
    //std::this_thread::sleep_for(std::chrono::milliseconds(periodMillis)); //init symbol
    //out.off();
    for (int i = 0; i < length; i++) //last position is '\0' and you want to avoid it!
    {
        sync(periodMillis);
        sendByte(explodedMessage[i], periodMillis);
    }
}

void sendByte(char charTx, int periodMillis)
{
//    std::cout << charTx << std::endl;
    for(int i = 0; i < 8; i++){
        if (charTx & (1 << i))
        {
            std::cout << " one ";
            out.on();
            
        }
        else{
            std::cout << " zero ";
            out.off();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(periodMillis));
    }
    out.off();
    std::cout << std::endl;
}

void sync(int periodMillis){
    sendByte((char)171, periodMillis);
}*/
