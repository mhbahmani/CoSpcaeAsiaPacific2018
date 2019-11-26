	//IR_Force

#define CsBot_AI_H//DO NOT delete this line
#ifndef CSBOT_REAL
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define DLL_EXPORT extern __declspec(dllexport)
#define PI 3.14159265359
#define ON 1
#define OFF 2
#endif//The robot ID : It must be two char, such as '00','kl' or 'Cr'.
char AI_MyID[2] = { '0','2' };


typedef int bool;
#define true 1
#define false 0



int Duration = 0;
int SuperDuration = 0;
int bGameEnd = false;
int CurAction = -1;
int CurGame = 0;
int SuperObj_Num = 0;
int SuperObj_X = 0;
int SuperObj_Y = 0;
int Teleport = 0;
int LoadedObjects = 0;
int US_Front = 0;
int US_Left = 0;
int US_Right = 0;
int CSLeft_R = 0;
int CSLeft_G = 0;
int CSLeft_B = 0;
int CSRight_R = 0;
int CSRight_G = 0;
int CSRight_B = 0;
int PositionX = 0;
int PositionY = 0;
int TM_State = 0;
int Compass = 0;
int Time = 0;
int WheelLeft = 0;
int WheelRight = 0;
int LED_1 = 0;
int MyState = 0;
int AI_SensorNum = 13;
/*=================================*/

int lastMode;
int robotState = 0;
int modeTime = 0;
int timer = 0;
int counter_move = 0;
int counterAvoiding = 0;
char flagTrapDirection;

int flagYellow = 0;
int timerTrap = 0;
	//////////////////////////
int wallArrs[] = { 50,40,30 };//Distance
int wallArrsSpeeds[] = { 3,3,3 };//Speed

	/////////////////////////colors
int BLUE[] = { 45, 45, 225 };
int RED[] = { 239, 32, 32 };
int GREEN[] = { 29, 249, 29 };
int GREEN2[] = { 29, 249, 249 };
int YELLOW[] = { 230, 230, 25 };
int YELLOW2[] = { 0, 0,  0};
int BLACK[] = { 29, 29, 29 };
int ORANGE[] = { 204, 130, 0};
int ORANGE2[] = { 235,148,0 };
int SILVER[] = { 143,151,247 };
int PINK[] = { 243,35,255 };
int BLUESPECIAL[] = {78,140,248};
int SWAMPLAND[] = {153,162,215};
int SWAMPLAND2[] = {176,185,238};
int SUPEROBJECT[] = {235,44,255};

int tolerance = 25;
#define none 0
#define yellow 1
#define orange 2
#define blueSpecial 3
#define purple 4





	/////////////////////////////////////////////////////////////////////////////////lahazat akhar

	/////////////////////////////////////////////////////////////////////////////////lahazat akhar

int colorL = none;
int colorR = none;

int counterStopObj = 0;
char flagStayInColor = 'n';

int flagYellowR = 0;
int flagYellowL = 0;
int counterYellowR = 0;
int counterYellowL = 0;
int flagOutSide = 0;
int counterOutSide = 0;
int flagWallR = 0;
int flagWallL = 0;
int flagWallF = 0;
int counterWallR = 0;
int counterWallleft = 0;
int counterWallF = 0;
int flaghandle = 0;
	/////////////////////////avoidWall
char flagWallDistance = 'n';
int currentPoint = 0;
#define pointCountB 89
int locXB[89] = { 58, 35, 77, 95,111,130,161,172,206,213,237,264,228,297,320,303,315,306,231,264,210,224,175,188,164,156,134,116,111, 93, 61, 42, 19, 30, 18, 31, 16, 62, 75,108,110,135,125,148, 63, 50, 76, 77, 99,114,137,149,174,194,212,231,236,220,258,228,222,263,231,278,295,310,324,337,310,294,274,250,199,203,172,170,149,133,121,107, 98, 72, 33, 30, 18, 28, 18, 28, 23};
int locYB[89] = {125,160,153,186,158,191,170,206,181,217,178,191,161,161,152,130,116, 89,113, 75,100, 66, 97, 58, 94, 14, 39,  7, 44, 14, 10, 18, 19, 32, 52, 62, 86, 89,105, 92,115,112,143,147,211,253,217,254,229,255,230,252,221,260,222,245,206,178,170,140,108, 92, 74, 30, 62, 33, 68, 46, 60, 35, 59, 28, 69, 94, 94, 64, 37, 20, 34, 20, 39, 20, 10, 22, 31, 48, 65, 76, 95};
#define pointCountR 89
int locXR[89] = { 58, 35, 77, 95,111,130,161,172,206,213,237,264,228,297,320,303,315,306,231,264,210,224,175,188,164,156,134,116,111, 93, 61, 42, 19, 30, 18, 31, 16, 62, 75,108,110,135,125,148, 63, 50, 76, 77, 99,114,137,149,174,194,212,231,236,220,258,228,222,263,231,278,295,310,324,337,310,294,274,250,199,203,172,170,149,133,121,107, 98, 72, 33, 30, 18, 28, 18, 28, 23};
int locYR[89] = {125,160,153,186,158,191,170,206,181,217,178,191,161,161,152,130,116, 89,113, 75,100, 66, 97, 58, 94, 14, 39,  7, 44, 14, 10, 18, 19, 32, 52, 62, 86, 89,105, 92,115,112,143,147,211,253,217,254,229,255,230,252,221,260,222,245,206,178,170,140,108, 92, 74, 30, 62, 33, 68, 46, 60, 35, 59, 28, 69, 94, 94, 64, 37, 20, 34, 20, 39, 20, 10, 22, 31, 48, 65, 76, 95};



int TimeLastMoment = 450;//change



int anglehandle;
//////////////////////////////////
#define vertex_num 24
int dist[vertex_num];
int prev[vertex_num];
int q[vertex_num];
int x;
int pointPosition[vertex_num][2] = {
{14,254},//0
{343,14},//1
{298,51},//2
{61,231},//3
{123,183},//4
{175,247},//5
{179,188},//6
{233,242},//7
{247,181},//8
{335,144},//9
{313,111},//10
{220,83},//11
{227,134},//12
{212,35},//13
{178,75},//14
{126,21},//15
{60,14},//16
{19,19},//17
{20,90},//18
{78,90},//19
{36,143},//20
{75,179},//21
{135,119},//22
{133,153},//23
};
int graph[vertex_num][vertex_num] = {
{-1,-1,-1,137,-1,423,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,153,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,347,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,153,-1,-1,-1,-1,-1,-1,-1,-1,162,220,-1,230,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{137,-1,-1,-1,205,301,328,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,142,-1,-1},
{-1,-1,-1,205,-1,216,147,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,126,-1,84},
{423,-1,-1,301,216,-1,155,151,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,318,-1,-1},
{-1,-1,-1,328,147,155,-1,202,179,-1,-1,-1,189,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,151},
{-1,-1,-1,-1,-1,151,202,-1,166,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,255,179,166,-1,250,-1,-1,134,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,250,-1,103,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,162,-1,-1,-1,-1,-1,-1,103,-1,254,-1,333,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,220,-1,-1,-1,-1,-1,-1,-1,254,-1,133,128,112,296,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,189,-1,134,-1,-1,133,-1,-1,199,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,347,230,-1,-1,-1,-1,-1,-1,-1,333,128,-1,-1,138,228,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,112,199,138,-1,197,-1,-1,-1,-1,-1,-1,161,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,296,-1,228,197,-1,174,-1,-1,221,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,174,-1,108,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,108,-1,186,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,186,-1,151,144,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,221,-1,-1,151,-1,175,-1,166,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,144,175,-1,138,-1,-1},
{-1,-1,-1,142,126,318,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,138,-1,-1,167},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,161,-1,-1,-1,-1,166,-1,-1,-1,89},
{-1,-1,-1,-1,84,-1,151,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,167,89,-1},
};
#define boxCount 2//change
int orangeBox[boxCount] = {0,1};
#define redZone 5
#define greenZone 5
#define blackZone 5



////////////////////////////////////////
#define trapCount 2
int yellows[2][7]={
{1,41,35,75,69,58,55},
{1,292,201,329,238,310,265},
};
////////////////////////////////////////
	//sits
#define superObjOrRGB -1
#define null -2


///////////////////////////////////////////////////////////////////////////////////////Prototype/////////////////////////////////////////////////////////////////////////////////
int compassFinder(limit);
void mode(int state);
void move(int l, int r);
void avoidWall();
void avoidTrap();
int findDistanceFromNode(int x1,int y1,int x2,int y2);
int findDistance(int x, int y);
char* getColor();
bool colorString(char* colorStringValue);
void changeModIfStuck(int stuckTime);
void stopBox(int t,int nextMode);
void stopObj(int t,int nextMode);
void findObj(int redNum,int blackNum,int greenNum);
void avoidTrapXY();
void findNearestPathToBot();
///////////////////////////////////////////////////////////////////////////////////////Prototype/////////////////////////////////////////////////////////////////////////////////
int nearestPointToBot = -1;
int nearestBoxToBot = -1;
int nearestPointToPath = -1;
int nearestPointToSuperObj = -1;
int pointcounterDijkstra = 0;
int nearestPathToBot = -1;

int lastlastmode,lastlastlastMode;

	/////////////////////////////////////////////////////////positioning////////
int robotX = 0;
int robotY = 0;

	///////////////////////////////obsticleBox
int CounterDeposite = 0;

	/////////////////////////moving varible
int counterAccelerate = 0;
int moveAccelerate = 1;
int counterStop = 0;
int counterFollowAngle = 0;
int counterNextPoint = 0;
int onOrOffWaiting = 0;///////////////////////////////////////////////change
	//////////////////////////compassFinder
#define NL 1
#define NW 2
#define WU 3
#define WD 4
#define SW 5
#define SL 6
#define SR 7
#define SE 8
#define ED 9
#define EU 10
#define NE 11
#define NR 12
	////////////////////////modes
/*#define search 1
 #define collect 2
 #define goToBox 3
 #define deposite 4*/
enum state {
	START = 0,
	SEARCH = 1,
	COLLECT = 2,
	GOTOBOX = 3,
	DEPOSITE = 4,
	GOTOSUPEROBJ = 5,
	GOINGOUT = 6,
	STOPSUPEROBJ = 7,
	BACKTOPATH = 8,
	TURNFORDANGER = 9,
	LASTMOMENT = 10,
	SPECIALSEARCH = 11 ,
};
int world = 1;
	//////////////////////Obj
int redObj = 0;
int greenObj = 0;
int blackObj = 0;
int superObjX = -1;
int superObjY = -1;

	////////////////////robotcolor
char ourRobot = 'n';
int flagCheckRobot = 0;

int lastpoint = 0;
	/////////////////////////////////Prototype
void waitForFollowAngle(int waitTime);
void clearObj();

int modeAfterDeposite = 0;
	////////////////teleport
int maxTime = 200;
int minTime = 180;
#define CsBot_AI_C//DO NOT delete this line

DLL_EXPORT void SetGameID(int GameID)
{
	CurGame = GameID;
	bGameEnd = 0;
}

DLL_EXPORT int GetGameID()
{
	return CurGame;
}

	//Only Used by CsBot Dance Platform
DLL_EXPORT int IsGameEnd()
{
	return bGameEnd;
}

#ifndef CSBOT_REAL

DLL_EXPORT char* GetDebugInfo()
{
	char info[1024];
	sprintf(info, "robotSatete=%d;lastMode=%d;lastlastMode=%d;redObj=%d;greenObj=%d;blackObj=%d;LoadedObjects=%d;", robotState, lastMode,lastlastmode,redObj, greenObj, blackObj, LoadedObjects);
	return info;
}

DLL_EXPORT char* GetTeamName()
{
     return "CoSpace Team";
}

DLL_EXPORT int GetCurAction()
{
	return CurAction;
}

	//Only Used by CsBot Rescue Platform
DLL_EXPORT int GetTeleport()
{
	return Teleport;
}

	//Only Used by CsBot Rescue Platform
DLL_EXPORT void SetSuperObj(int X, int Y, int num)
{
	SuperObj_X = X;
	SuperObj_Y = Y;
	SuperObj_Num = num;
}
	//Only Used by CsBot Rescue Platform
DLL_EXPORT void GetSuperObj(int *X, int *Y, int *num)
{
	*X = SuperObj_X;
	*Y = SuperObj_Y;
	*num = SuperObj_Num;
}

#endif CSBOT_REAL

DLL_EXPORT void SetDataAI(volatile int* packet, volatile int *AI_IN)
{

	int sum = 0;

	US_Front = AI_IN[0]; packet[0] = US_Front; sum += US_Front;
	US_Left = AI_IN[1]; packet[1] = US_Left; sum += US_Left;
	US_Right = AI_IN[2]; packet[2] = US_Right; sum += US_Right;
	CSLeft_R = AI_IN[3]; packet[3] = CSLeft_R; sum += CSLeft_R;
	CSLeft_G = AI_IN[4]; packet[4] = CSLeft_G; sum += CSLeft_G;
	CSLeft_B = AI_IN[5]; packet[5] = CSLeft_B; sum += CSLeft_B;
	CSRight_R = AI_IN[6]; packet[6] = CSRight_R; sum += CSRight_R;
	CSRight_G = AI_IN[7]; packet[7] = CSRight_G; sum += CSRight_G;
	CSRight_B = AI_IN[8]; packet[8] = CSRight_B; sum += CSRight_B;
	PositionX = AI_IN[9]; packet[9] = PositionX; sum += PositionX;
	PositionY = AI_IN[10]; packet[10] = PositionY; sum += PositionY;
	TM_State = AI_IN[11]; packet[11] = TM_State; sum += TM_State;
	Compass = AI_IN[12]; packet[12] = Compass; sum += Compass;
	Time = AI_IN[13]; packet[13] = Time; sum += Time;
	packet[14] = sum;

}
DLL_EXPORT void GetCommand(int *AI_OUT)
{
	AI_OUT[0] = WheelLeft;
	AI_OUT[1] = WheelRight;
	AI_OUT[2] = LED_1;
	AI_OUT[3] = MyState;
}
int compassFinder(limit){
	if(Compass <= limit){
		return NL;
	}
	else if(Compass <= 90 - limit){
		return NW;
	}
	else if(Compass <= 90){
		return WU;
	}
	else if(Compass <= 90 + limit){
		return WD;
	}
	else if(Compass <= 180 - limit){
		return SW;
	}
	else if(Compass <= 180){
		return SL;
	}
	else if(Compass <= 180 + limit){
		return SR;
	}
	else if(Compass <= 270 - limit){
		return SE;
	}
	else if(Compass <= 270){
		return ED;
	}
	else if(Compass <= 270 + limit){
		return EU;
	}
	else if(Compass <= 360 - limit){
		return NE;
	}
	else if(Compass <= 360){
		return NR;
	}
}
void mode(int state) {
	lastlastlastMode = lastlastmode;
	lastlastmode = lastMode;
	lastMode = robotState;
	robotState = state;
	modeTime = Time;
}
void move(int l, int r) {
	WheelLeft = l;
	WheelRight = r;
}
void avoidWall()
{
	if(world == 2 || (world == 1 && robotState == GOTOBOX)){
		////////////////////////////////////////////////////////////////////////handleWallAndTrap
		if((counterWallF >= 5 && flagWallF == 1) || counterWallF >= 70){
			flagWallF = 0;
			counterWallF = 0;
		}
		if((counterWallleft >= 5 && flagWallL == 1) || counterWallleft >= 70){
			flagWallL = 0;
			counterWallleft = 0;
		}
		if((counterWallR >= 5 && flagWallR == 1) || counterWallR >= 70){
			flagWallR = 0;
			counterWallR = 0;
		}
		if(US_Front <= 6){
			flagWallF = 1;
			counterWallF = 0;
		}
		if(US_Left <= 6){
			flagWallL = 1;
			counterWallleft = 0;
		}
		if(US_Right <= 6){
			flagWallR = 1;
			counterWallR = 0;
		}
		counterWallR++;
		counterWallleft++;
		counterWallF++;
		////////////////////////////////////////////////////////////////////////handleWallAndTrap
		if(US_Right <= 25){
			flagWallDistance = 'r';
		}
		if(US_Left <= 25){
			flagWallDistance = 'l';
		}
		else{
			flagWallDistance = 'n';
		}
		if (US_Front >= 7 && US_Right <= 9)
			{
			if(world == 1)
				Duration = 4;
			CurAction = 1;
			}
		else if (US_Front >= 7 && US_Left <= 9)
			{
			if(world == 1)
				Duration = 4;
			CurAction = 2;
			}
		else if (US_Front <= 12 && US_Left <= 12 && US_Right >= 17)
			{
			CurAction = 3;
			if(world == 1)
				Duration = 4;
			}
		else if (US_Front <= 12 && US_Left >= 10 && US_Right <= 12)
			{
			CurAction = 4;
			if(world == 1)
				Duration = 4;
			}
		else if (US_Front <= 12 && US_Left <= 10 && US_Right <= 12)
			{
			CurAction = 5;
			if(world == 1)
				Duration = 4;
			}
		else if (US_Front <= 13)
			{
			if (flagWallDistance == 'r')
				{
				CurAction = 6;
				if(world == 1)
					Duration = 4;
				}
			else
				{
				CurAction = 7;
				if(world == 1)
					Duration = 4;
				}
			}
		else
			{
			CurAction = 0;
			Duration = 4;
			}

		switch (CurAction)
		{
			case 1:
			WheelLeft = 1;
			WheelRight = 5;
			break;
			case 2:
			WheelLeft = 5;
			WheelRight = 1;
			break;
			case 3:
			WheelLeft = 4;
			WheelRight = -3;
			break;
			case 4:
			WheelLeft = -3;
			WheelRight = 4;
			break;
			case 5:
			WheelLeft = -3;
			WheelRight = -5;
			break;
			case 6:
			WheelLeft = -4;
			WheelRight = 2;
			break;
			case 7:
			WheelLeft = 2;
			WheelRight = -4;
			break;
			default:
			break;
		}
	}
	else if(world == 1){
			////////////////////////////////////////////////////////////////////////handleWallAndTrap
			if((counterWallF > 5 && flagWallF == 1) || counterWallF >= 70){
				flagWallF = 0;
				counterWallF = 0;
			}
			if((counterWallleft > 5 && flagWallL == 1) || counterWallleft >= 70){
				flagWallL = 0;
				counterWallleft = 0;
			}
			if((counterWallR > 5 && flagWallR == 1) || counterWallR >= 70){
				flagWallR = 0;
				counterWallR = 0;
			}
			if(US_Front <= 6){
				flagWallF = 1;
				counterWallF = 0;
			}
			if(US_Left <= 6){
				flagWallL = 1;
				counterWallleft = 0;
			}
			if(US_Right <= 6){
				flagWallR = 1;
				counterWallR = 0;
			}
			counterWallR++;
			counterWallleft++;
			counterWallF++;
			////////////////////////////////////////////////////////////////////////handleWallAndTrap
			//////////////SpeedConfig
		for (int i = 0;i < 3; i++)
			{
			if (US_Front <= wallArrs[i])
				{
				move(wallArrsSpeeds[i], wallArrsSpeeds[i]);
				}
			}
		if(US_Right <= 25){
			flagWallDistance = 'r';
		}
		if(US_Left <= 25){
			flagWallDistance = 'l';
		}
		else{
			flagWallDistance = 'n';
		}
		if (US_Front >= 10 && US_Right <= 12)
			{
			if(world == 1)
				Duration = 4;
			CurAction = 1;
			}
		else if (US_Front >= 10 && US_Left <= 12)
			{
			if(world == 1)
				Duration = 4;
			CurAction = 2;
			}
		else if (US_Front <= 15 && US_Left <= 15 && US_Right >= 10)
			{
			CurAction = 3;
			if(world == 1)
				Duration = 4;
			}
		else if (US_Front <= 15 && US_Left >= 10 && US_Right <= 15)
			{
			CurAction = 4;
			if(world == 1)
				Duration = 4;
			}
		else if (US_Front <= 15 && US_Left <= 10 && US_Right <= 15)
			{
			CurAction = 5;
			if(world == 1)
				Duration = 4;
			}
		else if (US_Front <= 10)
			{
			if (flagWallDistance == 'r')
				{
				CurAction = 6;
				if(world == 1)
					Duration = 4;
				}
			else
				{
				CurAction = 7;
				if(world == 1)
					Duration = 4;
				}
			}
		else
			{
			CurAction = 0;
			Duration = 4;
			}

		switch (CurAction)
		{
			case 1:
			WheelLeft = -1;
			WheelRight = 5;
			break;
			case 2:
			WheelLeft = 5;
			WheelRight = -1;
			break;
			case 3:
			WheelLeft = 5;
			WheelRight = -3;
			break;
			case 4:
			WheelLeft = -3;
			WheelRight = 5;
			break;
			case 5:
			WheelLeft = -3;
			WheelRight = -5;
			break;
			case 6:
			WheelLeft = -5;
			WheelRight = -2;
			break;
			case 7:
			WheelLeft = -2;
			WheelRight = -5;
			break;
			default:
			break;
		}
	}
}
void avoidTrap()
{
	if(world == 1){
			//    if(colorString("yellow_b") || colorString("yellow_r") || colorString("yellow_l"))
			//        waitForFollowAngle(15);//change
			/////////////////////////////////////////////////////hanldeWallAndTrap
			//  if(findDistance(superObjX,superObjY) > 20 || world == 1){
		if((counterYellowR >= 5 && flagYellowR == 1) || counterYellowR >= 70){
			flagYellowR = 0;
			counterYellowR = 0;
		}
		if((counterYellowL >= 5 && flagYellowL == 1) || counterYellowL >= 70){
			flagYellowL = 0;
			counterYellowL = 0;
		}
		if(colorString("yellow_l")){
			flagYellowL = 1;
			counterYellowL = 0;
		}
		if(colorString("yellow_r")){
			flagYellowR = 1;
			counterYellowR = 0;
		}
		counterYellowR++;
		counterYellowL++;
			/////////////////////////////////////////////////////hanldeWallAndTrap
		int counter = 0;
		if (timerTrap > 2 && flagYellow == 1)
			{
			timerTrap = 0;
			counterAvoiding = 0;
			flagYellow = 0;
			}
		if (colorString("yellow_l") || colorString("yellow_r") || colorString("yellow_b")) {
			counterAvoiding++;
			timerTrap = 0;
			counter++;
			flagYellow = 1;
			if (colorString("yellow_r"))
				{
				flagTrapDirection = 'r';
				move(-2, 3);
				}
			if (colorString("yellow_l"))
				{
				flagTrapDirection = 'l';
				move(3, -2);

				}
			if (colorString("yellow_b"))
				{
				if (flagTrapDirection == 'l')
					move(-2, -5);
				else if (flagTrapDirection == 'r')
					move(-5, -2);
				else
					move(-5, -1);
				}
		}
		else
			{
			flagTrapDirection = 'n';
			timerTrap++;
			}
		if (Time - timer > 1 && (colorString("yellow_l") || colorString("yellow_r")))
			{
			counter++;
			}
		if (counter > 60 && counter < 100 && (colorString("yellow_l") || colorString("yellow_r")))
			{
			LoadedObjects = 0;
			counter = 0;
			}
		if(colorString("blue")){
			clearObj();
		}
	}
	else{
		if(world == 2 && (!colorString("yellow_l") && !colorString("yellow_r") && !colorString("yellow_b"))){
			avoidTrapXY();
		}
			/////////////////////////////////////////////////////hanldeWallAndTrap
		if((counterYellowR > 20 && flagYellowR == 1) || counterYellowR >= 70){
			flagYellowR = 0;
			counterYellowR = 0;
		}
		if((counterYellowL > 20 && flagYellowL == 1) || counterYellowL >= 70){
			flagYellowL = 0;
			counterYellowL = 0;
		}
		if(colorString("yellow_l")){
			flagYellowL = 1;
		}
		if(colorString("yellow_r")){
			flagYellowR = 1;
		}
		if(colorString("yellow_b")){
			flagYellowR = 1;
			flagYellowL = 1;
		}
		counterYellowR++;
		counterYellowL++;
			/////////////////////////////////////////////////////hanldeWallAndTrap
		int counter = 0;
		if (timerTrap > 2 && flagYellow == 1)
			{
			timerTrap = 0;
			counterAvoiding = 0;
			flagYellow = 0;
			}
		if (colorString("yellow_l") || colorString("yellow_r") || colorString("yellow_b")) {
			counterAvoiding++;
			timerTrap = 0;
			counter++;
			flagYellow = 1;
			if (colorString("yellow_b"))
				{
				////printf("Yellow_b \n");
				if (flagTrapDirection == 'l')
					move(2, -4);
				else if (flagTrapDirection == 'r')
					move(-4, 2);
				else
					move(-4, 1);
				}
			else if (colorString("yellow_r"))
				{
				////printf("Yellow_r \n");
				flagTrapDirection = 'r';
				move(-2, 3);
				}
			else if (colorString("yellow_l"))
				{
				////printf("Yellow_l \n");
				flagTrapDirection = 'l';
				move(3, -2);

				}
		}
		else
			{
			flagTrapDirection = 'n';
			timerTrap++;
			}
		if (Time - timer > 1 && (colorString("yellow_l") || colorString("yellow_r")))
			{
			counter++;
			}
		if (counter > 60 && counter < 100 && (colorString("yellow_l") || colorString("yellow_r")))
			{
			LoadedObjects = 0;
			counter = 0;
			}
		if(colorString("blue")){
			clearObj();
		}
			//    if(colorString("yellow_b") || colorString("yellow_r") || colorString("yellow_l")){
			//        waitForFollowAngle(15);//change
			//        if(colorString("yellow_b")){
			//            move(-2, -4);
			//        }
			//        else if(colorString("yellow_r")){
			//            move(-1, 4);
			//        }
			//        else if(colorString("yellow_l")){
			//            move(4, -1);
			//        }
			//    }
	}
		//}
}
int findDistanceFromNode(int x1,int y1,int x2,int y2){
	int distPow = pow((x1 - x2), 2) + pow((y1 - y2), 2);
	return sqrt(distPow);
}
int findDistance(int x, int y) {
	int distPow = pow((robotX - x), 2) + pow((robotY - y), 2);

	return sqrt(distPow);
}
char* getColor() {
	if ((YELLOW[0] - (tolerance + 10) < CSRight_R && CSRight_R < YELLOW[0] + (tolerance + 10) && YELLOW[1] - (tolerance + 10) < CSRight_G && CSRight_G < YELLOW[1] + (tolerance + 10) && YELLOW[2] - (tolerance + 10) < CSRight_B && CSRight_B < YELLOW[2] + (tolerance + 10)) &&
		(YELLOW[0] - (tolerance + 10) < CSLeft_R  && CSLeft_R < YELLOW[0] + (tolerance + 10) && YELLOW[1] - (tolerance + 10) < CSLeft_G  && CSLeft_G < YELLOW[1] + (tolerance + 10) && YELLOW[2] - (tolerance + 10) < CSLeft_B  && CSLeft_B < YELLOW[2] + (tolerance + 10))){
		colorL = yellow;
		colorR = yellow;
		return "yellow_b";
	}
	else if ((YELLOW[0] - (tolerance + 10) < CSLeft_R  && CSLeft_R < YELLOW[0] + (tolerance + 10) && YELLOW[1] - (tolerance + 10) < CSLeft_G  && CSLeft_G < YELLOW[1] + (tolerance + 10) && YELLOW[2] - (tolerance + 10) < CSLeft_B  && CSLeft_B < YELLOW[2] + (tolerance + 10))){
		colorL = yellow;
		return "yellow_l";
	}
	else if ((YELLOW[0] - (tolerance + 10) < CSRight_R && CSRight_R < YELLOW[0] + (tolerance + 10) && YELLOW[1] - (tolerance + 10) < CSRight_G && CSRight_G < YELLOW[1] + (tolerance + 10) && YELLOW[2] - (tolerance + 10) < CSRight_B && CSRight_B < YELLOW[2] + (tolerance + 10))){
		colorR = yellow;
		return "yellow_r";
	}
		/////////////////////////////
	if ((SWAMPLAND[0] - tolerance < CSRight_R && CSRight_R < SWAMPLAND[0] + tolerance && SWAMPLAND[1] - tolerance < CSRight_G && CSRight_G < SWAMPLAND[1] + tolerance && SWAMPLAND[2] - tolerance < CSRight_B && CSRight_B < SWAMPLAND[2] + tolerance) &&
		(SWAMPLAND[0] - tolerance < CSLeft_R  && CSLeft_R < SWAMPLAND[0] + tolerance && SWAMPLAND[1] - tolerance < CSLeft_G  && CSLeft_G < SWAMPLAND[1] + tolerance && SWAMPLAND[2] - tolerance < CSLeft_B  && CSLeft_B < SWAMPLAND[2] + tolerance)){
		return "swampland_b";
	}
	else if ((SWAMPLAND[0] - tolerance < CSLeft_R  && CSLeft_R < SWAMPLAND[0] + tolerance && SWAMPLAND[1] - tolerance < CSLeft_G  && CSLeft_G < SWAMPLAND[1] + tolerance && SWAMPLAND[2] - tolerance < CSLeft_B  && CSLeft_B < SWAMPLAND[2] + tolerance)){
		return "swampland_l";
	}
	else if ((SWAMPLAND[0] - tolerance < CSRight_R && CSRight_R < SWAMPLAND[0] + tolerance && SWAMPLAND[1] - tolerance < CSRight_G && CSRight_G < SWAMPLAND[1] + tolerance && SWAMPLAND[2] - tolerance < CSRight_B && CSRight_B < SWAMPLAND[2] + tolerance)){
		return "swampland_r";
	}
		/////////////////////////////
	else if ((GREEN[0] - tolerance < CSRight_R && CSRight_R < GREEN[0] + tolerance && GREEN[1] - tolerance < CSRight_G && CSRight_G < GREEN[1] + tolerance && GREEN[2] - tolerance < CSRight_B && CSRight_B < GREEN[2] + tolerance) ||
			 (GREEN[0] - tolerance < CSLeft_R  && CSLeft_R < GREEN[0] + tolerance && GREEN[1] - tolerance < CSLeft_G  && CSLeft_G < GREEN[1] + tolerance && GREEN[2] - tolerance < CSLeft_B  && CSLeft_B < GREEN[2] + tolerance))
		return "green";
		////////////////////////////
	else if ((GREEN2[0] - tolerance < CSRight_R && CSRight_R < GREEN2[0] + tolerance && GREEN2[1] - tolerance < CSRight_G && CSRight_G < GREEN2[1] + tolerance && GREEN2[2] - tolerance < CSRight_B && CSRight_B < GREEN2[2] + tolerance) ||
			 (GREEN2[0] - tolerance < CSLeft_R  && CSLeft_R < GREEN2[0] + tolerance && GREEN2[1] - tolerance < CSLeft_G  && CSLeft_G < GREEN2[1] + tolerance && GREEN2[2] - tolerance < CSLeft_B  && CSLeft_B < GREEN2[2] + tolerance))
		return "green";
		////////////////////////////
	else if ((BLACK[0] - tolerance < CSRight_R && CSRight_R < BLACK[0] + tolerance && BLACK[1] - tolerance < CSRight_G && CSRight_G < BLACK[1] + tolerance && BLACK[2] - tolerance < CSRight_B && CSRight_B < BLACK[2] + tolerance) ||
			 (BLACK[0] - tolerance < CSLeft_R  && CSLeft_R < BLACK[0] + tolerance && BLACK[1] - tolerance < CSLeft_G  && CSLeft_G < BLACK[1] + tolerance && BLACK[2] - tolerance < CSLeft_B  && CSLeft_B < BLACK[2] + tolerance))
		return "black";
		//////////////////////////////
	else if ((RED[0] - tolerance < CSRight_R && CSRight_R < RED[0] + tolerance && RED[1] - tolerance < CSRight_G && CSRight_G < RED[1] + tolerance && RED[2] - tolerance < CSRight_B && CSRight_B < RED[2] + tolerance) ||
			 (RED[0] - tolerance < CSLeft_R  && CSLeft_R < RED[0] + tolerance && RED[1] - tolerance < CSLeft_G  && CSLeft_G < RED[1] + tolerance && RED[2] - tolerance < CSLeft_B  && CSLeft_B < RED[2] + tolerance))
		return "red";
		//////////////////////////////
	else if ((SUPEROBJECT[0] - tolerance < CSRight_R && CSRight_R < SUPEROBJECT[0] + tolerance && SUPEROBJECT[1] - tolerance < CSRight_G && CSRight_G < SUPEROBJECT[1] + tolerance && SUPEROBJECT[2] - tolerance < CSRight_B && CSRight_B < SUPEROBJECT[2] + tolerance) ||
			 (SUPEROBJECT[0] - tolerance < CSLeft_R  && CSLeft_R < SUPEROBJECT[0] + tolerance && SUPEROBJECT[1] - tolerance < CSLeft_G  && CSLeft_G < SUPEROBJECT[1] + tolerance && SUPEROBJECT[2] - tolerance < CSLeft_B  && CSLeft_B < SUPEROBJECT[2] + tolerance))
		return "superobj";
		////////////////////////////
	else if ((BLUESPECIAL[0] - tolerance < CSRight_R && CSRight_R < BLUESPECIAL[0] + tolerance && BLUESPECIAL[1] - tolerance < CSRight_G && CSRight_G < BLUESPECIAL[1] + tolerance && BLUESPECIAL[2] - tolerance < CSRight_B && CSRight_B < BLUESPECIAL[2] + tolerance) &&
			 (BLUESPECIAL[0] - tolerance < CSLeft_R  && CSLeft_R < BLUESPECIAL[0] + tolerance && BLUESPECIAL[1] - tolerance < CSLeft_G  && CSLeft_G < BLUESPECIAL[1] + tolerance && BLUESPECIAL[2] - tolerance < CSLeft_B  && CSLeft_B < BLUESPECIAL[2] + tolerance)){
		colorL = blueSpecial;
		colorR = blueSpecial;
		return "blueSpecial_b";
	}
	else if ((BLUESPECIAL[0] - tolerance < CSLeft_R  && CSLeft_R < BLUESPECIAL[0] + tolerance && BLUESPECIAL[1] - tolerance < CSLeft_G  && CSLeft_G < BLUESPECIAL[1] + tolerance && BLUESPECIAL[2] - tolerance < CSLeft_B  && CSLeft_B < BLUESPECIAL[2] + tolerance)){
		colorL = blueSpecial;
		return "blueSpecial_l";
	}
	else if ((BLUESPECIAL[0] - tolerance < CSRight_R && CSRight_R < BLUESPECIAL[0] + tolerance && BLUESPECIAL[1] - tolerance < CSRight_G && CSRight_G < BLUESPECIAL[1] + tolerance && BLUESPECIAL[2] - tolerance < CSRight_B && CSRight_B < BLUESPECIAL[2] + tolerance)){
		colorR = blueSpecial;
		return "blueSpecial_r";
	}
		///////////////////////////
	else if ((BLUE[0] - tolerance < CSRight_R && CSRight_R < BLUE[0] + tolerance && BLUE[1] - tolerance < CSRight_G && CSRight_G < BLUE[1] + tolerance && BLUE[2] - tolerance < CSRight_B && CSRight_B < BLUE[2] + tolerance) ||
			 (BLUE[0] - tolerance < CSLeft_R  && CSLeft_R < BLUE[0] + tolerance && BLUE[1] - tolerance < CSLeft_G  && CSLeft_G < BLUE[1] + tolerance && BLUE[2] - tolerance < CSLeft_B  && CSLeft_B < BLUE[2] + tolerance))
		return "blue";
		////////////////////////////
	else if ((ORANGE[0] - (tolerance + 10) < CSRight_R && CSRight_R < ORANGE[0] + (tolerance + 10) && ORANGE[1] - (tolerance + 10) < CSRight_G && CSRight_G < ORANGE[1] + (tolerance + 10) && ORANGE[2] - (tolerance + 10) < CSRight_B && CSRight_B < ORANGE[2] + (tolerance + 10))&&(ORANGE[0] - (tolerance + 10) < CSLeft_R  && CSLeft_R < ORANGE[0] + (tolerance + 10) && ORANGE[1] - (tolerance + 10) < CSLeft_G  && CSLeft_G < ORANGE[1] + (tolerance + 10) && ORANGE[2] - (tolerance + 10) < CSLeft_B  && CSLeft_B < ORANGE[2] + (tolerance + 10))){
		colorL = orange;
		colorR = orange;
		return "orange_b";
	}
	else if ((ORANGE[0] - (tolerance + 10) < CSLeft_R  && CSLeft_R < ORANGE[0] + (tolerance + 10) && ORANGE[1] - (tolerance + 10) < CSLeft_G  && CSLeft_G < ORANGE[1] + (tolerance + 10) && ORANGE[2] - (tolerance + 10) < CSLeft_B  && CSLeft_B < ORANGE[2] + (tolerance + 10))){
		return "orange_l";
	}
	else if ((ORANGE[0] - (tolerance + 10) < CSRight_R && CSRight_R < ORANGE[0] + (tolerance + 10) && ORANGE[1] - (tolerance + 10) < CSRight_G && CSRight_G < ORANGE[1] + (tolerance + 10) && ORANGE[2] - (tolerance + 10) < CSRight_B && CSRight_B < ORANGE[2] + (tolerance + 10))){
		return "orange_r";
	}
		///////////////////////////////////
	else if ((ORANGE2[0] - (tolerance + 10) < CSRight_R && CSRight_R < ORANGE2[0] + (tolerance + 10) && ORANGE2[1] - (tolerance + 10) < CSRight_G && CSRight_G < ORANGE2[1] + (tolerance + 10) && ORANGE2[2] - (tolerance + 10) < CSRight_B && CSRight_B < ORANGE2[2] + (tolerance + 10))&&(ORANGE2[0] - (tolerance + 10) < CSLeft_R  && CSLeft_R < ORANGE2[0] + (tolerance + 10) && ORANGE2[1] - (tolerance + 10) < CSLeft_G  && CSLeft_G < ORANGE2[1] + (tolerance + 10) && ORANGE2[2] - (tolerance + 10) < CSLeft_B  && CSLeft_B < ORANGE2[2] + (tolerance + 10))){
		colorL = orange;
		colorR = orange;
		return "orange_b";
	}
	else if ((ORANGE2[0] - (tolerance + 10) < CSLeft_R  && CSLeft_R < ORANGE2[0] + (tolerance + 10) && ORANGE2[1] - (tolerance + 10) < CSLeft_G  && CSLeft_G < ORANGE2[1] + (tolerance + 10) && ORANGE2[2] - (tolerance + 10) < CSLeft_B  && CSLeft_B < ORANGE2[2] + (tolerance + 10))){
		return "orange_l";
	}
	else if ((ORANGE2[0] - (tolerance + 10) < CSRight_R && CSRight_R < ORANGE2[0] + (tolerance + 10) && ORANGE2[1] - (tolerance + 10) < CSRight_G && CSRight_G < ORANGE2[1] + (tolerance + 10) && ORANGE2[2] - (tolerance + 10) < CSRight_B && CSRight_B < ORANGE2[2] + (tolerance + 10))){
		return "orange_r";
	}
		///////////////////////////////////
	else {
		colorL = none;
		colorR = none;
		return "NONE";
	}
	
}
bool colorString(char* colorStringValue) {

	if (strcmp(getColor(), colorStringValue) == 0)
		return true;

	return false;
}
void changeModIfStuck(int stuckTime) {
	if (modeTime + stuckTime < Time && lastMode == GOTOBOX && robotState == DEPOSITE && robotX != 0)//rbotX != 0 ----> world 2
		mode(GOINGOUT);
	if (modeTime + stuckTime<Time && robotState != SEARCH){
		mode(SEARCH);
	}
	if (modeTime + stuckTime < Time && robotState == SEARCH){
		if(lastMode == GOTOBOX){
			if(modeTime + stuckTime + 5 < Time)
				mode(GOTOBOX);
		}
		else
			mode(GOTOBOX);
	}
}
void stopBox(int t,int nextMode){
	if(counterStopObj < t){
		counterStopObj++;
		LED_1 = 2;
		move(0, 0);
	}
	else{
		greenObj = blackObj = redObj = LoadedObjects = 0;
		counterStopObj = 0;
		if(Time > TimeLastMoment)
			mode(LASTMOMENT);
		mode(nextMode);
	}
}
void stopObj(int t,int nextMode){
	if(counterStopObj < t){
		counterStopObj++;
		move(0, 0);
	}
	else{
		if(robotState == STOPSUPEROBJ){
			LoadedObjects++;
		}
		counterStopObj = 0;
		mode(nextMode);
	}
}
int flagArrive = 0;
int timerGoToBox;
void findObj(int redNum,int blackNum,int greenNum) {
	if((redObj == redNum && greenObj == greenNum && blackObj == blackNum && robotState == LASTMOMENT) || (LoadedObjects >= 6 && robotState != GOTOBOX && robotState != DEPOSITE)){
		mode(GOTOBOX);
		timerGoToBox = Time;
	}
	if (colorString("red") && redObj < redNum) {
		redObj++;
		LoadedObjects++;
		mode(COLLECT);
		if(lastMode == LASTMOMENT && redObj == redNum && checkObjs() == redZone)
			flagArrive = 0;
	}
	if (colorString("superobj") && world == 2 && robotState != GOTOSUPEROBJ) {
		LoadedObjects++;
		mode(COLLECT);
	}
	if (colorString("green") && greenObj < greenNum) {
		greenObj++;
		LoadedObjects++;
		mode(COLLECT);
		if(lastMode == LASTMOMENT && greenObj == greenNum && checkObjs() == greenZone)
			flagArrive = 0;
	}
	if (colorString("black") && blackObj < blackNum) {
		blackObj++;
		LoadedObjects++;
		mode(COLLECT);
		if(lastMode == LASTMOMENT && blackObj == blackNum && checkObjs() == redZone)
			flagArrive = 0;
	}
}
void magicMove(int first_spead, int second_spead, int t){
	counter_move++;
	if (counter_move <= t)
		move(first_spead, first_spead);
	else if (counter_move <= 2 * t)
		move(second_spead, second_spead);
	else
		counter_move = 0;
}
int findAngleDif(int angle1, int angle2){
	int delta = abs(angle1 - angle2);
	return min(delta, 360 - delta);
}
void handle_position_lost(){
	double avrage_move = ((double)WheelLeft + WheelRight) / 2;
	double delta_move = 9.5588 * 6 / 100 * avrage_move;
	double delta_x = cos(((Compass + 90) % 360) * PI / 180) * delta_move;
	double delta_y = sin(((Compass + 90) % 360) * PI / 180) * delta_move;
	robotX += delta_x;
	robotY += delta_y;
}
void update_robot_position() {
	if (PositionX != 0 && PositionY != 0){
		robotX = PositionX;
		robotY = PositionY;
	}
	else
		handle_position_lost();
}
int findAngle(int end_position_x, int end_position_y){
	int delta_x = end_position_x - robotX;
	int delta_y = end_position_y - robotY;
	int angle;
	double tanjant;
	if (delta_x == 0)
		{
		if (robotY < end_position_y)
			angle = 0;
		else if (robotY > end_position_y)
			angle = 180;
		}
	else
		{
		tanjant = (double)delta_y / delta_x;
		if (delta_x > 0)
			{
			angle = (atan(tanjant) * 360 / (2 * PI)) + 270;
			}
		else if (delta_x < 0)
			{
			angle = (atan(tanjant) * 360 / (2 * PI)) + 90;
			}
		}
	return angle;
}
int flagObsticle = 0;
void goto_position_sharp(int x, int y){
	int angle = findAngle(x, y);
	int dif = abs(Compass - angle);
	if (Compass >= angle)
		{
		if (dif <= 180)
			{
			WheelLeft = 4;
			WheelRight = (int)(2 - (sqrt((double)dif) *5/13.41));
			}
		else
			{
			WheelLeft = (int)(2 - (sqrt((double)(dif - 180)) * 5 / 13.41));
			WheelRight = 4;
			}
		}
	else
		{
		if (dif <= 180)
			{
			WheelLeft = (int)(2 - (sqrt((double)dif) * 5 / 13.41));
			WheelRight = 4;
			}
		else
			{
			WheelLeft = 4;
			WheelRight = (int)(2 - (sqrt((double)(dif - 180)) * 5 / 13.41));
			}
		}
	if (findAngleDif(Compass, angle) < 10)
	{
		magicMove(5,5,1);
	}
	if((findDistance(superObjX,superObjY) < 20 && superObjX > -1) || flagObsticle == 1 ) {
		WheelLeft -= 3;
		WheelRight -= 3;
		if(WheelLeft <= 0)
			WheelLeft += 2;
		if(WheelRight <= 0)
			WheelRight += 2;
	}
}
void goto_position_mellow(int x, int y){
	int angle = findAngle(x, y);
	int dif = abs(Compass - angle);
	if (Compass >= angle)
		{
		if (dif <= 180)
			{
			WheelLeft = 5;
			WheelRight = 2- (dif*4 / 180);
			}
		else
			{
			WheelLeft = 2 - (dif - 180)*4 / 180;
			WheelRight = 5;
			}
		}
	else
		{
		if (dif <= 180)
			{
			WheelLeft = 2 - (dif*4 / 180);
			WheelRight = 5;
			}
		else
			{
			WheelLeft = 5;
			WheelRight = 2 - (dif - 180)*4 / 180;
			}
		}
	if (findAngleDif(Compass, angle) < 10)
	{
		//magicMove(4, 5, 1);
		move(5,5);
	}
}
void followAngle(int angle){
	int dif = abs(Compass - angle);
	if (Compass >= angle)
		{
		if (dif <= 180)
			{
			WheelLeft = 3;
			WheelRight = (int)(2 - (sqrt((double)dif) * 2 / 13.41));
			}
		else
			{
			WheelLeft = (int)(2 - (sqrt((double)(dif - 180)) * 2 / 13.41));
			WheelRight = 3;
			}
		}
	else
		{
		if (dif <= 180)
			{
			WheelLeft = (int)(2 - (sqrt((double)dif) * 2 / 13.41));
			WheelRight = 3;
			}
		else
			{
			WheelLeft = 3;
			WheelRight = (int)(2 - (sqrt((double)(dif - 180)) * 2 / 13.41));
			}
		}
	if (findAngleDif(Compass, angle) < 10)
		{
		if(robotX > 0)
			magicMove(3, 4, 1);
		else
			move(3, 3);
		}
}
int distanceAngle = -1;
void goToAngle(int angle,int nextMode){
	if(Compass >= angle){
		if(distanceAngle == -1)
			distanceAngle = Compass - angle;
		if(Compass - angle <= 180){
			if(distanceAngle / 5 >= Compass - angle){
				move(1, -1);
			}
			else if(distanceAngle / 4 >= Compass - angle){
				move(2, -2);
			}
			else if(distanceAngle / 3 >= Compass - angle){
				move(3, -3);
			}
			else{
				move(4, -4);
			}
		}
		else{
			if(distanceAngle / 5 >= Compass - angle){
				move(-1, 1);
			}
			else if(distanceAngle / 4 >= Compass - angle){
				move(-2, 2);
			}
			else if(distanceAngle / 3 >= Compass - angle){
				move(-3, 3);
			}
			else{
				move(-4, 4);
			}
		}
	}
	else{
		if(distanceAngle == -1)
			distanceAngle = angle - Compass;
		if(angle - Compass >= 180){
			if(distanceAngle / 5 >= angle - Compass){
				move(1, -1);
			}
			else if(distanceAngle / 4 >= angle - Compass){
				move(2, -2);
			}
			else if(distanceAngle / 3 >= angle - Compass){
				move(3, -3);
			}
			else{
				move(4, -4);
			}
		}
		else{
			if(distanceAngle / 5 >= angle - Compass){
				move(-1, 1);
			}
			else if(distanceAngle / 4 >= angle - Compass){
				move(-2, 2);
			}
			else if(distanceAngle / 3 >= angle - Compass){
				move(-3, 3);
			}
			else{
				move(-4, 4);
			}
		}
	}
	if(Compass > angle - 5 && Compass < angle + 5){
		mode(nextMode);
	}
}
void moveTime(int nextMode,int t,int L,int R){
	counterStop++;
	if (counterStop < t)
		{
		LED_1 = 1;
		move(L, R);
		}
	else
		{
		flagWallL = flagWallR = flagWallF = flagYellowL = flagYellowR = flagOutSide = flaghandle = 0;
		CounterDeposite = 0;
		counterStop = 0;
		mode(nextMode);
		}
}
int timerTeleport = 120;
void teleport(int teleportNum){
	//printf("timerTeleport = %d\n",timerTeleport);
	if(Time >= maxTime && !colorString("orange_r") && !colorString("orange_l") ){
		LoadedObjects = blackObj = redObj = greenObj = 0;
		Teleport = teleportNum;
		mode(START);
	}
	else if(Time >= minTime){
		if(!colorString("orange_r") && !colorString("orange_l") && timerTeleport > 0 && lastMode == DEPOSITE)
			timerTeleport--;
		else if(!colorString("orange_r") && !colorString("orange_l") && LoadedObjects <= 2 && lastMode == DEPOSITE){
			LoadedObjects = blackObj = redObj = greenObj = 0;
			Teleport = teleportNum;
			mode(START);
			//printf("GOT IN!");
		}
		else if(LoadedObjects >= 3 && (robotState != DEPOSITE)){
			mode(GOTOBOX);
		}
	}
}
void fitInBox() {
	if (colorString("orange_b"))
		mode(DEPOSITE);
	else if (colorString("orange_r"))
		move(2, 0);
	else if (colorString("orange_l"))
		move(0, 2);
}
void clearObj() {
	greenObj = 0;
	blackObj = 0;
	redObj = 0;
	LoadedObjects = 0;
}
void accelerateMove(int maxSpeed,int cycle){
	move(moveAccelerate, moveAccelerate);
	counterAccelerate++;
	if(counterAccelerate >= cycle && moveAccelerate < maxSpeed){
		moveAccelerate++;
		counterAccelerate = 0;
	}
}
void waitForFollowAngle(int waitTime){
	if(onOrOffWaiting == 1){
		if(robotState != SEARCH){
			//mode(SEARCH);
		}
		if(robotState == SEARCH && lastMode == GOTOBOX){
			counterFollowAngle++;
			if(counterFollowAngle >= waitTime){
				//mode(lastMode);
				counterFollowAngle = 0;
			}
		}
	}
}
void followWall(char sensor,int tolerance,int r,int l){
	if(sensor == 'r'){
		if(US_Front < 15){
			move(-3, 3);
		}
		else if(US_Right <= tolerance - 7){
			move(l, r);
		}
		else if(US_Right >= tolerance + 7){
			move(r, l);
		}
		else{
			move(3, 3);
		}
	}
	else if(sensor == 'l'){
		if(US_Front < 15){
			move(3, -3);
		}
		else if(US_Left <= tolerance - 7){
			move(r, l);
		}
		else if(US_Left >= tolerance + 7){
			move(l, r);
		}
		else{
			move(3, 3);
		}
	}
}
void stayInColor(int color){
	if(colorL != color || colorR != color){
		if(flagStayInColor == 'l'){
			move(4,-2);
		}
		else if(flagStayInColor == 'r'){
			move(-2,4);
		}
		else{
			move(4,-3);
		}
	}
	else if(colorL != color){
		flagStayInColor = 'l';
		move(3, 1);
	}
	else if(colorR != color){
		flagStayInColor = 'r';
		move(1, 3);
	}
	else{
		flagStayInColor = 'n';
	}
}
int find_distance(int x, int y){
	double delta_x = (x - robotX);
	double delta_y = (y - robotY);
	return (int)sqrt((delta_x*delta_x) + (delta_y*delta_y));
}
int counterchangePoint = 0;
void changePointIfStuck(){
	if(counterchangePoint >= 75){
		currentPoint--;
		counterchangePoint = 0;
	}
}
void followPath(int distanceForNextPoint){
	if(ourRobot == 'b'){
		goto_position_mellow(locXB[currentPoint], locYB[currentPoint]);
		if(counterchangePoint <= 150){
			counterchangePoint++;
		}
		if(findDistance(locXB[currentPoint], locYB[currentPoint]) < 25){
			goto_position_sharp(locXB[currentPoint], locYB[currentPoint]);
		}
		if(findDistance(locXB[currentPoint], locYB[currentPoint]) < distanceForNextPoint){
			currentPoint++;
			counterchangePoint = 0;
		}
		if(currentPoint >= pointCountB){
			currentPoint = 2;
			counterchangePoint = 0;
		}
		if(counterchangePoint >= 200){
			mode(BACKTOPATH);
		}
	}
	else{
		goto_position_mellow(locXR[currentPoint], locYR[currentPoint]);
		if(counterchangePoint <= 100){
			counterchangePoint++;
		}
		if(findDistance(locXR[currentPoint], locYR[currentPoint]) < 25){
			goto_position_sharp(locXR[currentPoint], locYR[currentPoint]);
		}
		if(findDistance(locXR[currentPoint], locYR[currentPoint]) < distanceForNextPoint){
			currentPoint++;
			counterchangePoint = 0;
		}
		if(currentPoint >= pointCountR){
			currentPoint = 2;
			counterchangePoint = 0;
		}
		if(counterchangePoint >= 100){
			mode(BACKTOPATH);
		}
	}
		//changePointIfStuck();
}
int minVertex(){
	int i,myVertex;
	int x = 10000;
	for(i = 0;i < vertex_num;i++){
		if (q[i] != -1){
			if(dist[i] < x){
				myVertex = i;
				x = dist[i];
			}
		}
	}
	return myVertex;
}
void performDijkstra(int source){
	int i , j;
	int alt ;
	for(i = 0;i < vertex_num;i++){
		dist[i] = 1000;
		prev[i] = -1;
		q[i] = i;
	}
	dist[source] = 0;
	int u ;
	int mamad;
	for (mamad = 0;mamad < vertex_num ; mamad++){
		u = minVertex();
		q[u] = -1;
		for(j = 0; j<vertex_num; j++){
			if (graph[u][j] != -1){
				alt = dist[u] + graph[u][j];
				if(alt <= dist[j]){
					dist[j] = alt;
					prev[j] = u;
				}
			}
		}
	}
}
int nonReverseRoute[vertex_num];
int route[vertex_num];
int lastRoutePoint = 0;
void path(int destination){
	int i, j =0;
	for(i = 0;i < vertex_num;i++){
		nonReverseRoute[i] = -1;
		route[i] = -1;
	}
	for(i = destination ; prev[i] != -1 ; i = prev[i]){
		nonReverseRoute[j] =  i;
		j++;
	}
	nonReverseRoute[j] = i;
	for(i = 0;nonReverseRoute[i] != -1;i++){
		x = i+1;
	}
	i = 0;
	j = vertex_num-1;
	int mmm;
	while(i < j){
		mmm = nonReverseRoute[j];
		nonReverseRoute [j]= nonReverseRoute[i];
		nonReverseRoute[i] = mmm;
		j--;
		i++;
	}
	j = 0;
	for(i = 0;i < vertex_num;i++){
		if(nonReverseRoute[i] != -1){
			route[j] = nonReverseRoute[i];
			//printf("\nroute[%d] => %d",j,route[j]);
			j++;
		}
	}
		//	lastRoutePoint = j;
}
int nearestZoneToBot = -1;
void findNearestZoneToBot(){
	int alt = 100000;
	if(findDistance(pointPosition[redZone][0],pointPosition[redZone][1]) < alt){
		alt = findDistance(pointPosition[redZone][0],pointPosition[redZone][1]);
		nearestZoneToBot = redZone;
	}
	if(findDistance(pointPosition[blackZone][0],pointPosition[blackZone][1]) < alt){
		alt = findDistance(pointPosition[blackZone][0],pointPosition[blackZone][1]);
		nearestZoneToBot = blackZone;
	}
		if(findDistance(pointPosition[greenZone][0],pointPosition[greenZone][1]) < alt){
		alt = findDistance(pointPosition[greenZone][0],pointPosition[greenZone][1]);
		nearestZoneToBot = greenZone;
	}
}
void findNearestPointToBot(){
	int alt = 100000;
	int i;
	for(i = 0;i < vertex_num;i++){
		if(pointPosition[i][0] <= 360){
			if(alt >= findDistance(pointPosition[i][0], pointPosition[i][1])){
				alt = findDistance(pointPosition[i][0], pointPosition[i][1]);
				nearestPointToBot = i;
			}
		}
	}
}
void findNearestBoxToBot(){
	int alt = 100000;
	int i;
	for(i = 0;i < boxCount;i++){
		if(alt >= findDistance(pointPosition[orangeBox[i]][0], pointPosition[orangeBox[i]][1])){
			alt = findDistance(pointPosition[orangeBox[i]][0], pointPosition[orangeBox[i]][1]);
			nearestBoxToBot = orangeBox[i];
		}
	}
}

void findNearestPointToSuperObj(){
	int alt = 100000;
	int i;
	for(i = 0;i < vertex_num;i++){
		if(pointPosition[i][0] <= 360){
			if(alt >= findDistanceFromNode(superObjX,superObjY,pointPosition[i][0], pointPosition[i][1])){
				alt = findDistanceFromNode(superObjX,superObjY,pointPosition[i][0], pointPosition[i][1]);
				nearestPointToSuperObj = i;
			}
		}
	}
}
void findNearestPointToPath(){
	int alt = 100000;
	int i;
	findNearestPathToBot();
	for(i = 0;i < vertex_num;i++){
		if(pointPosition[i][0] <= 360){
			if(ourRobot == 'b'){
				if(alt >= findDistanceFromNode(locXB[nearestPathToBot],locYB[nearestPathToBot],pointPosition[i][0],pointPosition[i][1])){
					alt = findDistanceFromNode(locXB[nearestPathToBot],locYB[nearestPathToBot],pointPosition[i][0],pointPosition[i][1]);
					nearestPointToPath = i;
				}
			}
			else{
				if(alt >= findDistanceFromNode(locXR[nearestPathToBot],locYR[nearestPathToBot],pointPosition[i][0],pointPosition[i][1])){
					alt = findDistanceFromNode(locXR[nearestPathToBot],locYR[nearestPathToBot],pointPosition[i][0],pointPosition[i][1]);
					nearestPointToPath = i;
				}
			}
		}
	}
}
void findNearestPathToBot(){
	int alt = 100000;
	int i;
	if(ourRobot == 'b'){
		for(i = 0;i < pointCountB;i++){
			if(pointPosition[i][0] <= 360){
				if(alt >= findDistance(locXB[i],locYB[i])){
					alt = findDistance(locXB[i],locYB[i]);
					nearestPathToBot = i;
				}
			}
		}
	}
	else{
		for(i = 0;i < pointCountR;i++){
			if(pointPosition[i][0] <= 360){
				if(alt >= findDistance(locXR[i],locYR[i])){
					alt = findDistance(locXR[i],locYR[i]);
					nearestPathToBot = i;
				}
			}
		}
	}
	currentPoint = nearestPathToBot;
}
int counterDijkstra = 0;
void goToBox(){
	if(nearestBoxToBot == -1 || nearestPointToBot == -1){
		findNearestPointToBot();
		findNearestBoxToBot();
		//printf("\n nearest point to bot ==> %d && nearest box to bot %d \n",nearestPointToBot,nearestBoxToBot);
		performDijkstra(nearestPointToBot);
		path(nearestBoxToBot);
		pointcounterDijkstra = 0;
		//printf("man crash nakardam be mola");
	}
	goto_position_mellow(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
	if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 25){
		goto_position_sharp(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
	}
	if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 15){
		pointcounterDijkstra++;
		counterDijkstra = 0;
	}
	if(counterDijkstra >= 75 && route[pointcounterDijkstra] != -1){
		nearestBoxToBot = nearestPointToBot = -1;
		counterDijkstra = 0;
	}
	counterDijkstra++;
}
void goToSuperObj(){
	if(nearestPointToSuperObj == -1){
		findNearestPointToSuperObj();
		findNearestPointToBot();
		performDijkstra(nearestPointToBot);
		path(nearestPointToSuperObj);
		pointcounterDijkstra = 0;
	}
	if(route[pointcounterDijkstra] != -1){
		goto_position_mellow(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
		if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 40){
			goto_position_sharp(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
		}
		if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) <= 15){
			pointcounterDijkstra++;
			counterDijkstra = 0;
		}
	}
	if(findDistance(superObjX,superObjY) < 6){
		mode(STOPSUPEROBJ);
		nearestPointToBot = nearestBoxToBot = nearestPointToSuperObj = -1;
	}
	else if(route[pointcounterDijkstra] == -1){
		goto_position_sharp(superObjX,superObjY);
	}
	if(counterDijkstra >= 75 && route[pointcounterDijkstra] != -1){
		nearestPointToSuperObj = -1;
	    counterDijkstra = 0;
	}
	counterDijkstra++;
}
void goToPath(){
	if(nearestPointToPath == -1 || nearestPointToBot == -1){
		findNearestPointToBot();
		findNearestPointToPath();
		performDijkstra(nearestPointToBot);
		path(nearestPointToPath);
		pointcounterDijkstra = 0;
		if(lastMode == DEPOSITE)
			pointcounterDijkstra = 1;
	}
	goto_position_mellow(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
	if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 25){
		goto_position_sharp(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
	}
	if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 15){
		pointcounterDijkstra++;
	}
	if(counterDijkstra >= 75){
		nearestPointToPath = nearestPointToBot = -1;
	    counterDijkstra = 0;
	}
	counterDijkstra++;
}
void avoidOutSide(int Xmin,int Ymin,int Xmax,int Ymax,int distance){
	if(flaghandle == 0){
		int direction = compassFinder(10);
		int cornerDirection = compassFinder(45);
		int x_min = Xmin + distance;
		int x_max = Xmax - distance;
		int y_min = Ymin + distance;
		int y_max = Ymax - distance;
			//////////////////////////////////////////////////////////////
		if((counterOutSide > 5 && flagOutSide == 1) || counterOutSide >= 70){
			flagOutSide = 0;
			counterOutSide = 0;
		}
		if((5 > robotX && 5 < robotY && 265 > robotY) || (5 < robotX && 355 > robotX && 5 > robotY) || (355 < robotX && 5 < robotY && 265 > robotY) || (5 < robotX && 365 > robotX && 265 < robotY) || (265 < robotY && 5 > robotX) || (5 > robotY && 5 > robotX) || (5 > robotY && 355 < robotX) || (265 < robotY && 355 < robotX)){
			flagOutSide = 1;
			counterOutSide = 0;
		}
		counterOutSide++;
			//////////////////////////////////////////////////////////////
		if(x_min > robotX && y_min < robotY && y_max > robotY){/////////////////////////////////////Left
			if(direction == NL){
				move(3, 1);
			}
			if(direction == NW){
				move(4, -1);
			}
			if(direction == WU){
				move(5, -1);
			}
			if(direction == WD){
				move(-1, 5);
			}
			if(direction == SW){
				move(-1, 4);
			}
			if(direction == SL){
				move(1, 3);
			}
		}
		if(x_min < robotX && x_max > robotX && y_min > robotY){/////////////////////////////////////Down
			if(direction == WD){
				move(3, 1);
			}
			if(direction == SW){
				move(4, -1);
			}
			if(direction == SL){
				move(5, -1);
			}
			if(direction == SR){
				move(-1, 5);
			}
			if(direction == SE){
				move(-1, 4);
			}
			if(direction == ED){
				move(1, 3);
			}
		}
		if(x_max < robotX && y_min < robotY && y_max > robotY){/////////////////////////////////Right
			if(direction == SR){
				move(3, 1);
			}
			if(direction == SE){
				move(4, -1);
			}
			if(direction == ED){
				move(5, -1);
			}
			if(direction == EU){
				move(-1, 5);
			}
			if(direction == NE){
				move(-1, 4);
			}
			if(direction == NR){
				move(1, 3);
			}
		}
		if(x_min < robotX && x_max > robotX && y_max < robotY){/////////////////////////////////////Up
			if(direction == EU){
				move(3, 1);
			}
			if(direction == NE){
				move(4, -1);
			}
			if(direction == NR){
				move(5, -1);
			}
			if(direction == NL){
				move(-1, 5);
			}
			if(direction == NW){
				move(-1, 4);
			}
			if(direction == WU){
				move(1, 3);
			}
		}
			////////////////////////////////////////////////////////////////////////////////////////////////////////corners
		if(y_max < robotY && x_min > robotX){////////////////////////////////////////////////Corner-LU
			if(cornerDirection == NL){
				move(-1, -4);
			}
			if(cornerDirection == WU){
				move(-4, -1);
			}
		}
		if(y_min > robotY && x_min > robotX){/////////////////////////////////////////////////Corner-LD
			if(cornerDirection == WD){
				move(-1, -4);
			}
			if(cornerDirection == SL){
				move(-4, -1);
			}
		}
		if(y_min > robotY && x_max < robotX){/////////////////////////////////////////////////Corner-RD
			if(cornerDirection == SR){
				move(-1, -4);
			}
			if(cornerDirection == ED){
				move(-4, -1);
			}
		}
		if(y_max < robotY && x_max < robotX){/////////////////////////////////////////////////Corner-RU
			if(cornerDirection == EU){
				move(-1, -4);
			}
			if(cornerDirection == NR){
				move(-4, -1);
			}
		}
	}
}
int flagWallAndTrap = 0;
int counterWallAndTrap = 0;
int counterFlagHandle = 0;
void handleWallAndTrap(){
	if((flagWallR && flagOutSide) || (flagWallR && flagYellowL) || (flagWallL && flagOutSide) || (flagWallL && flagYellowR) || (flagYellowL && flagOutSide) || (flagYellowR && flagOutSide)){
		flaghandle = 1;
	}
	if((flagWallR || flagYellowR) && flagOutSide){
		moveTime(robotState,10,-3,0);
	}
	else if(flagWallR && flagYellowL){
		moveTime(robotState,10,-3,0);
	}
	else if((flagWallL || flagYellowL) && flagOutSide){
		moveTime(robotState, 10, 0, -3);
	}
	else if(flagWallL && flagYellowR){
		moveTime(robotState,10,-3,0);
	}
}
int flagSmartGo = 0;
void lastMomentGo(char p1,char p2,char p3){
	if(nearestPointToBot == -1){
		if(flagSmartGo == 0){
			if(p1 == 'b'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(blackZone);
			}
			else if(p1 == 'r'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(redZone);
			}
			else if(p1 == 'g'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(greenZone);
			}
			pointcounterDijkstra = 0;
			flagSmartGo = 1;
		}
		else if(flagSmartGo == 1){
			if(p2 == 'b'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(blackZone);
			}
			else if(p2 == 'r'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(redZone);
			}
			else if(p2 == 'g'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(greenZone);
			}
			pointcounterDijkstra = 0;
			flagSmartGo = 2;
		}
		else if(flagSmartGo == 2){
			if(p3 == 'b'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(blackZone);
			}
			else if(p3 == 'r'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(redZone);
			}
			else if(p3 == 'g'){
				findNearestPointToBot();
				performDijkstra(nearestPointToBot);
				path(greenZone);
			}
			pointcounterDijkstra = 0;
			flagSmartGo = 3;
		}
	}
	goto_position_mellow(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
	if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 25){
		goto_position_sharp(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
	}
	if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 15){
		pointcounterDijkstra++;
	}
	if(route[pointcounterDijkstra] == -1){
		nearestPointToBot = -1;
	}
}
int flagStayInCirlceZone;
void stayInCircle(int x,int y,int range){
	int direction = compassFinder(15);
	if(findDistance(x,y) > range){
		LED_1 = 1;
		if(direction == NL || direction == WD || direction == SR || direction == EU){
			move(-3,4);
		}
		if(direction == NR || direction == WU || direction == SL || direction == ED){
			move(4,-3);
		}
		else{
			move(5,-1);
		}
	}
	else
		move(3,3);
}
void stayInZone(int Xmin,int Ymin,int Xmax,int Ymax){
	int direction = compassFinder(10);
	int cornerDirection = compassFinder(45);
	int x_min = Xmin + 15;
	int x_max = Xmax - 15;
	int y_min = Ymin + 15;
	int y_max = Ymax - 15;
		//////
	if((counterOutSide > 5 && flagYellowR == 1) || counterOutSide >= 70){
		flagOutSide = 0;
		counterOutSide = 0;
	}
	if((x_min > robotX && y_min < robotY && y_max > robotY) || (x_min < robotX && x_max > robotX && y_min > robotY) || (x_max < robotX && y_min < robotY && y_max > robotY) || (x_min < robotX && x_max > robotX && y_max < robotY) || (y_max < robotY && x_min > robotX) || (y_min > robotY && x_min > robotX) || (y_min > robotY && x_max < robotX) || (y_max < robotY && x_max < robotX)){
		flagOutSide = 1;
		counterOutSide = 0;
	}
	counterOutSide++;
		//////
	if(x_min > robotX && y_min < robotY && y_max > robotY){/////////////////////////////////////Left
		if(direction == NL){
			move(3, 1);
		}
		if(direction == NW){
			move(4, -1);
		}
		if(direction == WU){
			move(5, -1);
		}
		if(direction == WD){
			move(-1, 5);
		}
		if(direction == SW){
			move(-1, 4);
		}
		if(direction == SL){
			move(1, 3);
		}
	}
	if(x_min < robotX && x_max > robotX && y_min > robotY){/////////////////////////////////////Down
		if(direction == WD){
			move(3, 1);
		}
		if(direction == SW){
			move(4, -1);
		}
		if(direction == SL){
			move(5, -1);
		}
		if(direction == SR){
			move(-1, 5);
		}
		if(direction == SE){
			move(-1, 4);
		}
		if(direction == ED){
			move(1, 3);
		}
	}
	if(x_max < robotX && y_min < robotY && y_max > robotY){/////////////////////////////////Right
		if(direction == SR){
			move(3, 1);
		}
		if(direction == SE){
			move(4, -1);
		}
		if(direction == ED){
			move(5, -1);
		}
		if(direction == EU){
			move(-1, 5);
		}
		if(direction == NE){
			move(-1, 4);
		}
		if(direction == NR){
			move(1, 3);
		}
	}
	if(x_min < robotX && x_max > robotX && y_max < robotY){/////////////////////////////////////Up
		if(direction == EU){
			move(3, 1);
		}
		if(direction == NE){
			move(4, -1);
		}
		if(direction == NR){
			move(5, -1);
		}
		if(direction == NL){
			move(-1, 5);
		}
		if(direction == NW){
			move(-1, 4);
		}
		if(direction == WU){
			move(1, 3);
		}
	}
		////////////////////////////////////////////////////////////////////////////////////////////////////////corners
	if(y_max < robotY && x_min > robotX){////////////////////////////////////////////////Corner-LU
		if(cornerDirection == NL){
			move(-1, -4);
		}
		if(cornerDirection == WU){
			move(-4, -1);
		}
	}
	if(y_min > robotY && x_min > robotX){/////////////////////////////////////////////////Corner-LD
		if(cornerDirection == WD){
			move(-1, -4);
		}
		if(cornerDirection == SL){
			move(-4, -1);
		}
	}
	if(y_min > robotY && x_max < robotX){/////////////////////////////////////////////////Corner-RD
		if(cornerDirection == SR){
			move(-1, -4);
		}
		if(cornerDirection == ED){
			move(-4, -1);
		}
	}
	if(y_max < robotY && x_max < robotX){/////////////////////////////////////////////////Corner-RU
		if(cornerDirection == EU){
			move(-1, -4);
		}
		if(cornerDirection == NR){
			move(-4, -1);
		}
	}
}
void avoidOrange(int status){
	if(status == 1){
		if (colorString("orange_b")){
			if (colorString("orange_l") || colorString("ornage_r") || colorString("orange_b")) {
				if (colorString("orange_b"))
					{
					////printf("Yellow_b \n");
					if (flagTrapDirection == 'l')
						move(2, -4);
					else if (flagTrapDirection == 'r')
						move(-4, 2);
					else
						move(-4, 1);
					}
				else if (colorString("orange_r"))
					{
					////printf("Yellow_r \n");
					flagTrapDirection = 'r';
					move(-2, 3);
					}
				else if (colorString("orange_l"))
					{
					////printf("Yellow_l \n");
					flagTrapDirection = 'l';
					move(3, -2);

					}
				}
		}
		if(status == 2){
			if(colorString("yellow_b")){
				move(-4,-5);
			}
		}
			//    if(colorString("yellow_b") || colorString("yellow_r") || colorString("yellow_l")){
			//        waitForFollowAngle(15);//change
			//        if(colorString("yellow_b")){
			//            move(-2, -4);
			//        }
			//        else if(colorString("yellow_r")){
			//            move(-1, 4);
			//        }
			//        else if(colorString("yellow_l")){
			//            move(4, -1);
			//        }
			//    }
	}
}
int checkObjs(){
	if(redObj >= 1 && blackObj >= 1 && (!greenObj || greenObj == 1))
		return greenZone;
	if((!redObj || redObj == 1) && blackObj >= 1 && greenObj >= 1)
		return redZone;
	if(redObj >= 1 && (!blackObj || blackObj == 1) && !greenObj >= 1)
		return blackZone;
	if(superObjX > 0 || (redObj > 0 && greenObj > 0 && blackObj > 0))
		return superObjOrRGB;
	return null;
}
void avoidSwampland()
{
	if (timerTrap > 2 && flagYellow == 1)
		{
		timerTrap = 0;
		counterAvoiding = 0;
		flagYellow = 0;
		}
	if (colorString("swampland_l") || colorString("swampland_r") || colorString("swampland_b")) {
		counterAvoiding++;
		timerTrap = 0;
		flagYellow = 1;
		if (colorString("swampland_r"))
			{
			flagTrapDirection = 'r';
			move(-3, 5);
			}
		if (colorString("swampland_l"))
			{
			flagTrapDirection = 'l';
			move(5, -3);

			}
		if (colorString("swampland_b"))
			{
			if (flagTrapDirection == 'l')
				move(3, -4);
			else if (flagTrapDirection == 'r')
				move(-4, 3);
			else
				move(-4, 2);
			}
	}
	else
		{
		flagTrapDirection = 'n';
		timerTrap++;
		}
}
void avoids(int avoidtrap,int obj0notavoidtrap,int handleWAT,int avoidswampland){
	if(superObjX > 0){
		if(findDistance(superObjX, superObjY) > 15 && flaghandle == 0){
			avoidWall();
		}
	 }
	else if(superObjX <= 0 && flaghandle == 0){
		avoidWall();
	}
	if(LoadedObjects != 0 && obj0notavoidtrap == ON){
		if(avoidtrap == ON && flaghandle == 0){
			if(route[pointcounterDijkstra] != -1 && robotState == GOTOSUPEROBJ)
				avoidTrap();
			else if(superObjX <= 0)
				avoidTrap();
		}
	}
	else if(obj0notavoidtrap == OFF){
		avoidTrap();
	}
	if(handleWAT == ON){
		handleWallAndTrap();
	}
	if(avoidswampland == ON){
		avoidSwampland();
	}
	if(flaghandle == 1){
		counterFlagHandle++;
	}
	if(counterFlagHandle >= 100){
		flaghandle = 0;
		counterFlagHandle = 0;
	}
}
void GoToZone(int zone){
	if(nearestPointToBot == -1){
		flagArrive = 0;
		findNearestPointToBot();
		performDijkstra(nearestPointToBot);
		path(zone);
		pointcounterDijkstra = 0;
	}
	if(route[pointcounterDijkstra] != -1){
		goto_position_mellow(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
		if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 40){
			goto_position_sharp(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
		}
		if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) <= 15){
			pointcounterDijkstra++;
		}
	}
	if(findDistance(pointPosition[zone][0],pointPosition[zone][1]) < 6){
		mode(LASTMOMENT);
		nearestPointToBot = nearestBoxToBot = nearestPointToSuperObj = -1;
		flagArrive = 1;

	}
	else if(route[pointcounterDijkstra] == -1){
		goto_position_sharp(pointPosition[zone][0],pointPosition[zone][1]);
	}
}
void data(){
	if(SuperObj_X > 0 && robotState != COLLECT){
		superObjX = SuperObj_X;
		superObjY = SuperObj_Y;
		CounterDeposite = 0;
		mode(GOTOSUPEROBJ);
		lastMode = DEPOSITE;
	}
		//////////////////////
	if(robotX > 0)
		world = 2;
	else
		world = 1;
		//////////////////////
	if(findDistance(pointPosition[orangeBox[nearestBoxToBot]][0],pointPosition[orangeBox[nearestBoxToBot]][1]) <= 20 && US_Front <= 10 && robotState == GOTOBOX && world == 2){
		flagObsticle = 1;
	}
	else
		flagObsticle = 0;
	if(robotState == SEARCH && Time > TimeLastMoment)//change
		mode(LASTMOMENT);  
}
void avoidTrapXY(){
	int i;
	for(i = 0;i < trapCount;i++){
		if(yellows[i][0] == 1){
			int direction = compassFinder(15);
			//////////////////////////////////////////////////////////////////up/////////////////////////////////////////////////////
			if (robotX > yellows[i][1] && robotX < yellows[i][3] && robotY < yellows[i][4] + 20 && robotY > yellows[i][4])
			{
				if (direction == NE)
				{
					move(-1, 3);
				}
				else if (direction == NW)
				{
					move(3, -1);
				}
				else if (direction == SR)
				{
					move(-1, 5);
				}
				else if (direction == SL)
				{
					move(5, -1);
				}
			}
			////////////////////////////////////////////////////////right/////////////////////////////////////////////////////////////
			else if (robotY < yellows[i][4] && robotY > yellows[i][2] && robotX < yellows[i][3] + 20 && robotX > yellows[i][3])
			{
				if (direction == NW)
				{
					move(3, -1);
				}
				else if (direction == SW)
				{
					move(-1, 3);
				}
				else if (direction == WU)
				{
					move(5, -1);
				}
				else if (direction == WD)
				{
					move(-1, 5);
				}
			}
			////////////////////////////////////////////////////////down//////////////////////////////////////////////////////////////
			else if (robotX < yellows[i][3] && robotX > yellows[i][1] && robotY > yellows[i][2] - 20 && robotY < yellows[i][2])
			{
				if (direction == NW)
				{
					move(-1, 3);
				}
				else if (direction == NE)
				{
					move(3, -1);
				}
				else if (direction == NL)
				{
					move(-1, 5);
				}
				else if (direction == NR)
				{
					move(5, -1);
				}
			}
			///////////////////////////////////////////////////////left///////////////////////////////////////////////////////////////
			else if (robotY > yellows[i][2] && robotY < yellows[i][4] && robotX > yellows[i][1] - 20 && robotX < yellows[i][1])
			{
				if (direction == NE)
				{
					move(-1, 3);
				}
				else if (direction == SE)
				{
					move(3, -1);
				}
				else if (direction == EU)
				{
					move(-1, 5);
				}
				else if (direction == ED)
				{
					move(5, -1);
				}
			}
		}
		else{
			if(findDistance(yellows[i][1],yellows[i][2]) < (yellows[i][3] + 10)){
				move(-5,-1);
			}
		}
	}
}
void goToNearestZone(int zone){
	if(nearestPointToBot == -1){
		flagArrive = 0;
		findNearestPointToBot();
		performDijkstra(nearestPointToBot);
		path(nearestZoneToBot);
		pointcounterDijkstra = 0;
	}
	if(route[pointcounterDijkstra] != -1){
		goto_position_mellow(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
		if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) < 40){
			goto_position_sharp(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]);
		}
		if(findDistance(pointPosition[route[pointcounterDijkstra]][0], pointPosition[route[pointcounterDijkstra]][1]) <= 15){
			pointcounterDijkstra++;
		}
	}
	if(findDistance(pointPosition[zone][0],pointPosition[zone][1]) < 6){
		mode(LASTMOMENT);
		nearestPointToBot = nearestBoxToBot = -1;
		flagArrive = 1;
	}
	else if(route[pointcounterDijkstra] == -1){
		goto_position_sharp(pointPosition[zone][0],pointPosition[zone][1]);
	}
}
int flagWhichRobot = 0;
void whichRobot2(char xOy,int minXorYoonyeki ,char whichBot){
	if(flagWhichRobot == 0){
		if(xOy == 'x'){
			if(whichBot == 'b'){
				if(robotX > minXorYoonyeki){
					ourRobot = 'b';
				}
				else{
					ourRobot = 'r';
				}
			}
			else{
				if(robotX > minXorYoonyeki){
					ourRobot = 'r';
				}
				else{
					ourRobot = 'b';
				}
			}
		}
		else{
			if(whichBot == 'b'){
				if(robotY > minXorYoonyeki){
					ourRobot = 'b';
				}
				else{
					ourRobot = 'r';
				}
			}
			else{
				if(robotY > minXorYoonyeki){
					ourRobot = 'r';
				}
				else{
					ourRobot = 'b';
				}
			}
		}
	    flagWhichRobot = 1;
	}
}
void whichRobot(){
	if(US_Left > 45){
		ourRobot = 'r';
	}
	else{
		ourRobot = 'b';
	}
	flagCheckRobot = 1;
}
void Game0(){
		//system("cls");
	whichRobot();///////////////////////////change Function
	teleport(1);
	changeModIfStuck(20);
	//printf("%s\n",getColor());
	data();
	switch (robotState){
		case START:
            timer = Time;
			mode(SEARCH);
			break;
		case SEARCH:
            move(3,3);
			LED_1 = 0;
			if(CounterDeposite <= 100)
				CounterDeposite++;
			if((LoadedObjects >= 5 && (colorString("orange_l") || colorString("orange_r") || colorString("orange_b"))))
				fitInBox();
            if (lastMode == GOTOBOX){
				changeModIfStuck(1);//cahnge
            }
			if(lastMode == DEPOSITE && CounterDeposite <= 70)
				avoidOrange(ON);
			avoids(ON, ON, ON, OFF);
			findObj(5,5,5);
			break;

		case SPECIALSEARCH:
			move(3,3);
			stayInColor(blueSpecial);
			LED_1 = 0;
			if(CounterDeposite <= 100)
				CounterDeposite++;
			if((LoadedObjects >= 5 && (colorString("orange_l") || colorString("orange_r") || colorString("orange_b"))))
				fitInBox();
			if(lastMode == GOTOBOX)
                    changeModIfStuck(1);//cahnge
			if(lastMode == DEPOSITE && CounterDeposite <= 70)
				avoidOrange(ON);
			avoids(ON, ON, ON, OFF);
			findObj(3,3,3);
			break;

		case COLLECT:
			move(0, 0);
			LED_1 = 1;
			moveTime(lastMode, 45, 0,0);
			break;
		case GOTOBOX:
			//followAngle(135);
			move(3,3);
			avoids(ON, OFF, OFF, OFF);
			fitInBox();
            //if(Time >= timerGoToBox + 5)
			//	mode(SEARCH);
			findObj(1, 1, 1);
			break;
		case DEPOSITE:
		//printf("***************\n");
			move(0, 0);
			LED_1 = 2;
			changeModIfStuck(3);
			CounterDeposite = 0;
			clearObj();
			break;

		/*case TURNFORDANGER:
			goToAngle(anglehandle,lastMode);
			flagYellowR = flagYellowL = flagWall = flagOutSide = 0;
			break;*/
	}
}
void Game1() {
		//whichRobot();///////////////////////////change Function
		//system("cls");
	update_robot_position();
	data();
	whichRobot2('x',180,'r');
	changeModIfStuck(40);
	switch (robotState){
		case START:
			mode(SEARCH);
			break;

		case SEARCH:
			LED_1 = 0;
			followPath(17);
			avoids(ON, ON, ON, OFF);
			avoidOrange(3);//flagDeposit = 0 -----> dar moveTime
			findObj(2,2,2);
			break;

		case LASTMOMENT:
			LED_1 = 0;
			if(checkObjs() != null && checkObjs() != superObjOrRGB && Time < 470){//change
				if(flagArrive){
					stayInCircle(pointPosition[checkObjs()][0],pointPosition[checkObjs()][1],15);
				}
				else
					GoToZone(checkObjs());
			}
			else if((Time > 470 && LoadedObjects > 0) || checkObjs() == superObjOrRGB){
				mode(GOTOBOX);
			}
			else {
				if(!flagArrive){
					findNearestZoneToBot();
					goToNearestZone(nearestZoneToBot);
				}
				else{
					stayInCircle(pointPosition[nearestZoneToBot][0],pointPosition[nearestZoneToBot][1],15);
				}
			}
			avoids(ON, OFF, ON, OFF);
			findObj(6,6,6);
			if(LoadedObjects >= 2){
				mode(GOTOBOX);
			}
			break;

		case COLLECT:
			LED_1 = 1;
			stopObj(45, lastMode);
			break;

		case GOTOBOX:
			LED_1 = 0;
			goToBox();
			avoids(ON, OFF, ON, OFF);
			if(Time <= 420)
				findObj(1,1,1);
			if(lastMode == lastMomentGo && Time < 460)
				findObj(2,2,2);
			fitInBox();
			break;

		case DEPOSITE:
			move(0, 0);
			LED_1 = 2;
			nearestBoxToBot = nearestPointToBot = nearestPointToSuperObj = -1;
			stopBox(50,BACKTOPATH);
			if(modeAfterDeposite != 0){
				mode(modeAfterDeposite);
				modeAfterDeposite = 0;
			}
			CounterDeposite = 0;
			flagObsticle = 0;
			clearObj();
			break;

		case GOINGOUT:
			moveTime(SEARCH,10,-4,-4);
			avoids(ON, ON, ON, OFF);
			findObj(1,2,2);
			break;

		case GOTOSUPEROBJ:
			if(CounterDeposite <= 100)
				CounterDeposite++;
			//if(lastMode == DEPOSITE && CounterDeposite <= 70)//change
				avoidOrange(3);//flagDeposit = 0 -----> dar moveTime
			LED_1 = 0;
			goToSuperObj();
			avoids(ON, ON, ON, OFF);
			if(Time <= 420)
				findObj(1,2,2);
			break;

		case STOPSUPEROBJ:
			LED_1 = 1;
			superObjY = superObjX = -1;
			nearestPointToSuperObj = nearestBoxToBot = nearestPointToBot = -1;
			stopObj(100,BACKTOPATH);//change
			break;

		case BACKTOPATH:
			LED_1 = 1;
			goToPath();
			avoids(ON, ON, ON, OFF);
			if(LoadedObjects >= 6){
				mode(GOTOBOX);
			}
			findObj(2, 2, 2);
			if(CounterDeposite <= 100)
				CounterDeposite++;
			//if(lastMode == DEPOSITE && CounterDeposite <= 70){//change
				//avoidOrange(3);
			//}//flagDeposit = 0 -----> dar moveTime
			if(ourRobot == 'b'){
				if(findDistance(locXB[nearestPathToBot], locYB[nearestPathToBot]) <= 15 || findDistance(pointPosition[route[lastRoutePoint]][0], pointPosition[route[lastRoutePoint]][1]) <= 15){
					nearestPointToPath = -1;
					nearestPathToBot = -1;
					nearestPointToBot = -1;
					mode(SEARCH);
				}
			}
			else{
				if(findDistance(locXR[nearestPathToBot], locYR[nearestPathToBot]) <= 15 || findDistance(pointPosition[route[lastRoutePoint]][0], pointPosition[route[lastRoutePoint]][1]) <= 15){
					nearestPointToPath = -1;
					nearestPathToBot = -1;
					nearestPointToBot = -1;
					mode(SEARCH);
				}
			}
			break;
		case 100:
			mode(lastMode);
			break;
		/*case TURNFORDANGER:
			goToAngle(anglehandle, lastMode);
			flagYellowR = flagYellowL = flagWall = flagOutSide = 0;
			break;*/
	}
	avoidOutSide(0, 0, 360, 270, 12);
}
DLL_EXPORT void OnTimer() {
	switch (CurGame)
	{
		case 9:
		break;
		case 10:
		WheelLeft = 0;
		WheelRight = 0;
		LED_1 = 0;
		MyState = 0;
		break;
		case 0:
		Game0();
		break;
		case 1:
		Game1();
		break;
		default:
		break;
	}
}
