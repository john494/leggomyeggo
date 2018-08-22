#pragma config(StandardModel, "VEX IQ Clawbot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Check platform
#ifndef VexIQ
#error "This program is designed for the VexIQ platform"
#else

// Check if Smart Radio features are enabled
#ifndef VexIQ_SR
#error "This sample needs to have the smart radio features enabled"
#else

char usrMsg[41]; //extra byte for null char
task main()
{
	unsigned int nBtnNumber = 0;
	while(true){
		if (userMessageAvailable())
		{
			readUserMessage(usrMsg);//save Incoming message

			if (sscanf(usrMsg, "AppBtn%1u", &nBtnNumber)){//check message format and store button to a variable
				switch(nBtnNumber){//make decision of which code to run based off of 4 cases
					case 1:
						forward(0.5, rotations, 50);
						break;

					case 2:
						backward(0.5, rotations, 50);
						break;

					case 3:
						turnLeft(0.5, rotations, 50);
						break;

					case 4:
						turnRight(0.5, rotations, 50);
						break;
					default:
						//Button number received is not a valid case
						stopAllMotors();
						break;
					}
				}else{
				//message was in incorrect format
				}
			}else{
			//No message sent

		}
	}
}

#endif // End Smart Radio features enabled check
#endif // End platform check
