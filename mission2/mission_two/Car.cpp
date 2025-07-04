#include "CommonHeader.h"

bool SedanCar::validParts(bool isLogOn) {
	if (mEngineSystem == nullptr || mBreakSystem == nullptr || mSteeringSystem == nullptr) {
		return false;
	}

	if (!mBreakSystem->getCompany().compare("CONTINENTAL")) {
		if (isLogOn) {
			printf("자동차 부품 조합 테스트 결과 : FAIL\n");
			printf("Sedan에는 Continental제동장치 사용 불가\n");
		}
		return false;
	}

	if (!mBreakSystem->getCompany().compare("BOSCH") && mSteeringSystem->getCompany().compare("BOSCH")) {
		if (isLogOn) {
			printf("자동차 부품 조합 테스트 결과 : FAIL\n");
			printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
		}
		return false;
	}

	if (isLogOn) {
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
	return true;
}

bool SuvCar::validParts(bool isLogOn) {
	if (mEngineSystem == nullptr || mBreakSystem == nullptr || mSteeringSystem == nullptr) {
		return false;
	}

	if (!mEngineSystem->getCompany().compare("TOYOTA")) {
		if (isLogOn) {
			printf("자동차 부품 조합 테스트 결과 : FAIL\n");
			printf("SUV에는 TOYOTA엔진 사용 불가\n");
		}
		return false;
	}

	if (!mBreakSystem->getCompany().compare("BOSCH") && mSteeringSystem->getCompany().compare("BOSCH")) {
		if (isLogOn) {
			printf("자동차 부품 조합 테스트 결과 : FAIL\n");
			printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
		}
		return false;
	}

	if (isLogOn) {
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
		
	return true;
}

bool TruckCar::validParts(bool isLogOn) {
	if (mEngineSystem == nullptr || mBreakSystem == nullptr || mSteeringSystem == nullptr) {
		return false;
	}

	if (!mEngineSystem->getCompany().compare("WIA")) {
		if (isLogOn) {
			printf("자동차 부품 조합 테스트 결과 : FAIL\n");
			printf("Truck에는 WIA엔진 사용 불가\n");
		}
		return false;
	}

	if (!mBreakSystem->getCompany().compare("MANDO")) {
		if (isLogOn) {
			printf("자동차 부품 조합 테스트 결과 : FAIL\n");
			printf("Truck에는 Mando제동장치 사용 불가\n");
		}
		return false;
	}

	if (!mBreakSystem->getCompany().compare("BOSCH") && mSteeringSystem->getCompany().compare("BOSCH")) {
		if (isLogOn) {
			printf("자동차 부품 조합 테스트 결과 : FAIL\n");
			printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
		}
		return false;
	}

	if (isLogOn) {
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
		
	return true;
}