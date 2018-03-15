#include "Grove_GSR_Skin_Current_LinkIt_One.h"

Grove_GSR_Skin_Current_LinkIt_One::Grove_GSR_Skin_Current_LinkIt_One(): Sensor(0) {	
}

int Grove_GSR_Skin_Current_LinkIt_One::_read(){
	 _data = analogRead(SKIN_CURRENT_ANALOG);
	 return 0;
}

Grove_GSR_Skin_Current_LinkIt_One TL_Skin_Current;
