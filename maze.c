task main()
{
	int tTurnTime = 1000;
	moveFwd(tTurnTime);
	rightTurn(tTurnTime);
	leftTurn(tTurnTime);
	turnAround(tTurnTime);
}


void moveFwd(int aTimeVal)
{
	setSpeeds(25, 25);
	sleep(aTimeVal);
	setSpeeds(0,0);
}

void rightTurn(int aTimeVal)
{
	setSpeeds(25, -25);
	sleep(aTimeVal)
	setSpeeds(0,0);
}

void leftTurn(int aTimeval)
{
	setSpeeds(-25,25);
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
