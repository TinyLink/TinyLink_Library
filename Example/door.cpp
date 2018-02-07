void setup(){
	TL_Bluetooth.init("door");
}

void loop(){
	short Gx,Gy,Gz,Ax,Ay,Az;
	TL_Gyro.read();
	Gx=TL_Gyro.data_x();
	Gy=TL_Gyro.data_y();
	Gz=TL_Gyro.data_z();
	
	TL_Accelerometer.read();
	Ax=TL_Accelerometer.data_x();
	Ay=TL_Accelerometer.data_y();
	Az=TL_Accelerometer.data_z();
	
	if(Gz>100||Ax>1||Ay>1||Az>1){
		TL_LED.turnOn();
		TL_Bluetooth.send("door open");			
	}else if(Gz<-100||Ax<-1||Ay<-1||Az<-1){
		TL_LED.turnOff();
		TL_Bluetooth.send("door close");
	}
	TL_Time.delayMillis(100);
}
