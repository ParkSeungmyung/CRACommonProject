#pragma once
class Car {
public:
	virtual bool validParts(bool isLogOn = false) = 0;
	void setEngineSystem(std::shared_ptr<EngineSystem> engine) {

		mEngineSystem = engine;
	}
	void setBreakSystem(std::shared_ptr<BreakSystem> breakSystem) {
		mBreakSystem = breakSystem;
	}

	void setSteeringSystem(std::shared_ptr<SteeringSystem> steering) {
		mSteeringSystem = steering;
	}

	bool checkEngine() {
		if (mEngineSystem == nullptr) {
			printf("엔진이 고장나있습니다.\n");
			printf("자동차가 움직이지 않습니다.\n");
			return false;
		}
		return true;
	}

	void printAllParts() {
		if (checkEngine()) {
			printf("Car type : %s\n", mCarType.c_str());
			printf("Engine : %s\n", mEngineSystem->getCompany().c_str());
			printf("BreakSystem : %s\n", mBreakSystem->getCompany().c_str());
			printf("SteeringSystem : %s\n", mSteeringSystem->getCompany().c_str());
		}
	}
protected:
	std::shared_ptr<EngineSystem> mEngineSystem;
	std::shared_ptr<BreakSystem> mBreakSystem;
	std::shared_ptr<SteeringSystem> mSteeringSystem;
	std::string mCarType{};
};

class SedanCar : public Car {
public:
	SedanCar() { mCarType = "Sedan"; };
	bool validParts(bool isLogOn = false) override;
};

class SuvCar : public Car {
public:
	SuvCar() { mCarType = "Suv"; };
	bool validParts(bool isLogOn = false) override;
};

class TruckCar : public Car {
public:
	TruckCar() { mCarType = "Truck"; };
	bool validParts(bool isLogOn = false) override;
};