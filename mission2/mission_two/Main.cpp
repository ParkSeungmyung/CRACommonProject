#include "CommonHeader.h"

#ifdef _DEBUG
int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
#else
#define CLEAR_SCREEN "\033[H\033[2J"
#define TYPE_MAX 10

int answerEachTypes[TYPE_MAX];
std::shared_ptr<Car> car;

enum QuestionType
{
	CarType_Q,
	Engine_Q,
	brakeSystem_Q,
	SteeringSystem_Q,
	Run_Test,
};

void printSelectMenu(int step) {
	if (step == CarType_Q)
	{
		printf(CLEAR_SCREEN);

		printf("        ______________\n");
		printf("       /|            | \n");
		printf("  ____/_|_____________|____\n");
		printf(" |                      O  |\n");
		printf(" '-(@)----------------(@)--'\n");
		printf("===============================\n");
		printf("어떤 차량 타입을 선택할까요?\n");
		printf("1. Sedan\n");
		printf("2. SUV\n");
		printf("3. Truck\n");
	}
	else if (step == Engine_Q)
	{
		printf(CLEAR_SCREEN);
		printf("어떤 엔진을 탑재할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. GM\n");
		printf("2. TOYOTA\n");
		printf("3. WIA\n");
		printf("4. 고장난 엔진\n");
	}
	else if (step == brakeSystem_Q)
	{
		printf(CLEAR_SCREEN);
		printf("어떤 제동장치를 선택할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. MANDO\n");
		printf("2. CONTINENTAL\n");
		printf("3. BOSCH\n");
	}
	else if (step == SteeringSystem_Q)
	{
		printf(CLEAR_SCREEN);
		printf("어떤 조향장치를 선택할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. BOSCH\n");
		printf("2. MOBIS\n");
	}
	else if (step == Run_Test)
	{
		printf(CLEAR_SCREEN);
		printf("멋진 차량이 완성되었습니다.\n");
		printf("어떤 동작을 할까요?\n");
		printf("0. 처음 화면으로 돌아가기\n");
		printf("1. RUN\n");
		printf("2. Test\n");
	}
	printf("===============================\n");
}

bool isExitCommand(char* userInputCommand) {
	if (!strcmp(userInputCommand, "exit")) {
		return true;
	}
	return false;
}

bool isNumber(char* input) {
	if (*input != '\0') {
		return false;
	}
	return true;
}
bool isValidAnswer(int step, int answer) {
	if (step == CarType_Q && !(answer >= 1 && answer <= 3))
	{
		printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
		Sleep(800);
		return false;
	}

	if (step == Engine_Q && !(answer >= 0 && answer <= 4))
	{
		printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
		Sleep(800);
		return false;
	}

	if (step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
	{
		printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
		Sleep(800);
		return false;
	}

	if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
	{
		printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
		Sleep(800);
		return false;
	}

	if (step == Run_Test && !(answer >= 0 && answer <= 2))
	{
		printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
		Sleep(800);
		return false;
	}

	return true;
}

bool isBackwardStep(int& step, int answer) {
	// 처음으로 돌아가기
	if (answer == 0 && step == Run_Test)
	{
		step = CarType_Q;
		return true;
	}

	// 이전으로 돌아가기
	if (answer == 0 && step >= 1)
	{
		step -= 1;
		return true;
	}
	return false;
}

void saveAnswerAndChangeNextStep(int& step, int answer) {
	if (step == CarType_Q)
	{
		if (answer == CarType::SEDAN)
			car = std::make_shared<SedanCar>();
		else if (answer == CarType::SUV)
			car = std::make_shared<SuvCar>();
		else if (answer == CarType::TRUCK)
			car = std::make_shared<TruckCar>();
		else
			car = nullptr;
		step = Engine_Q;
	}
	else if (step == Engine_Q)
	{
		car->setEngineSystem(EngineFactory::createEngine(answer));
		Sleep(800);
		step = brakeSystem_Q;
	}
	else if (step == brakeSystem_Q)
	{
		car->setBreakSystem(BreakFactory::createBreak(answer));
		Sleep(800);
		step = SteeringSystem_Q;
	}
	else if (step == SteeringSystem_Q)
	{
		car->setSteeringSystem(SteeringFactory::createSteering(answer));
		Sleep(800);
		step = Run_Test;
	}
	else if (step == Run_Test && answer == 1)
	{
		if (!car->validParts()) {
			printf("차가 동작하지 않습니다.\n");
			Sleep(2000);
			return;
		}
			
		if (!car->checkEngine()) {
			Sleep(2000);
			return;
		}
			
		car->printAllParts();
		printf("자동차가 동작됩니다.\n");

		Sleep(2000);
	}
	else if (step == Run_Test && answer == 2)
	{
		printf("Test...\n");
		Sleep(1500);
		car->validParts(true);
		Sleep(2000);
	}
}

int main() {
	char userInput[100];
	int step = CarType_Q;
	
	while (1)
	{
		printSelectMenu(step);

		printf("INPUT > ");
		fgets(userInput, sizeof(userInput), stdin);

		// 엔터 개행문자 제거
		userInput[strlen(userInput) - 1] = '\0';

		if (isExitCommand(userInput))
		{
			printf("바이바이\n");
			break;
		}

		// 숫자로 된 대답인지 확인
		char* checkNumber;
		int answer = strtol(userInput, &checkNumber, 10); // 문자열을 10진수로 변환

		// 입력받은 문자가 숫자가 아니라면
		if (!isNumber(checkNumber))
		{
			printf("ERROR :: 숫자만 입력 가능\n");
			Sleep(800);
			continue;
		}

		if (!isValidAnswer(step, answer)) {
			continue;
		}

		if (isBackwardStep(step, answer)) {
			continue;
		}

		saveAnswerAndChangeNextStep(step, answer);
	}
}
#endif