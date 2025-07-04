#pragma once

enum CarType
{
	SEDAN = 1,
	SUV,
	TRUCK
};

enum EngineType
{
	GM = 1,
	TOYOTA,
	WIA
};

enum BrakeSystemType
{
	MANDO = 1,
	CONTINENTAL,
	BOSCH_B
};

enum SteeringSystemType
{
	BOSCH_S = 1,
	MOBIS
};

class EngineSystem {
public:
	EngineSystem(std::string name) {
		mCompany = name;
	}
	std::string getCompany() { return mCompany; };
protected:
	std::string mCompany{};
};

class EngineFactory {
public:
	static std::shared_ptr<EngineSystem> createEngine(int type) {
		if (type == EngineType::GM) {
			return std::make_shared<EngineSystem>("GM");
		}
		else if (type == EngineType::TOYOTA) {
			return std::make_shared<EngineSystem>("TOYOTA");
		}
		else if (type == EngineType::WIA) {
			return std::make_shared<EngineSystem>("WIA");
		}
		else {
			return nullptr;
		}
	};
};

class BreakSystem {
public:
	BreakSystem(std::string name) {
		mCompany = name;
	}
	std::string getCompany() { return mCompany; };
protected:
	std::string mCompany{};
};

class BreakFactory {
public:
	static std::shared_ptr<BreakSystem> createBreak (int type) {
		if (type == BrakeSystemType::MANDO) {
			return std::make_shared<BreakSystem>("MANDO");
		}
		else if (type == BrakeSystemType::CONTINENTAL) {
			return std::make_shared<BreakSystem>("CONTINENTAL");
		}
		else if (type == BrakeSystemType::BOSCH_B) {
			return std::make_shared<BreakSystem>("BOSCH");
		}
		else {
			return nullptr;
		}
	};
};

class SteeringSystem {
public:
	SteeringSystem(std::string name) {
		mCompany = name;
	}
	std::string getCompany() { return mCompany; };
protected:
	std::string mCompany{};
};

class SteeringFactory {
public:
	static std::shared_ptr<SteeringSystem> createSteering(int type) {
		if (type == SteeringSystemType::BOSCH_S) {
			return std::make_shared<SteeringSystem>("BOSCH");
		}
		else if (type == SteeringSystemType::MOBIS) {
			return std::make_shared<SteeringSystem>("MOBIS");
		}
		else {
			return nullptr;
		}
	};
};