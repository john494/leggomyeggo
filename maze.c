task main()
{
	int tTurnTime = 1000;
	moveFwd(tTurnTime);
	rightTurn(tTurnTime);
	leftTurn(tTurnTime);
}


void moveFwd(int aTimeVal)
{
	setSpeeds(100, 100);
	sleep(aTimeVal);
	setSpeeds(0,0);
}

void rightTurn(int aTimeVal)
{
	setSpeeds(100, -100);
	sleep(aTimeVal)
	setSpeeds(0,0);
}

void leftTurn(int aTimeval)
{
	setSpeeds(-100,100);
	sleep(aTimeval);
	setSpeeds(0,0);
}

void turnAround(int aTimeVal)
{
	leftTurn(aTimeVal *2)
}

void setSpeeds(int aLft, int aRt)
{
	setMotorSpeed(leftMotor, aLft);
	setMotorSpeed(rightMotor, aRt);
}
