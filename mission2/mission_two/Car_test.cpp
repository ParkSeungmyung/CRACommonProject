#include "CommonHeader.h"

TEST(Car, createCar) {
	std::shared_ptr<Car> carSedan = std::make_shared<SedanCar>();
	EXPECT_NE(nullptr, carSedan);

	std::shared_ptr<Car> carSuv = std::make_shared<SuvCar>();
	EXPECT_NE(nullptr, carSuv);

	std::shared_ptr<Car> carTruck = std::make_shared<TruckCar>();
	EXPECT_NE(nullptr, carTruck);
}

TEST(Car, makeParts) {
	std::shared_ptr<Car> carSedan = std::make_shared<SedanCar>();
	EXPECT_NE(nullptr, carSedan);

	carSedan->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carSedan->setEngineSystem(nullptr);
	EXPECT_EQ(false, carSedan->checkEngine());

	carSedan->setEngineSystem(EngineFactory::createEngine(EngineType::TOYOTA));
	carSedan->setEngineSystem(EngineFactory::createEngine(EngineType::WIA));
	EXPECT_EQ(true, carSedan->checkEngine());

	carSedan->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::BOSCH_B));
	carSedan->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::CONTINENTAL));
	carSedan->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::MANDO));

	carSedan->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	carSedan->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::MOBIS));
	EXPECT_EQ(true, carSedan->validParts());

	carSedan->printAllParts();
}

TEST(Car, checkFunctionInCar) {
	std::shared_ptr<Car> carSedan = std::make_shared<SedanCar>();
	EXPECT_NE(nullptr, carSedan);

	carSedan->setEngineSystem(nullptr);
	EXPECT_EQ(false, carSedan->checkEngine());

	carSedan->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carSedan->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::CONTINENTAL));
	carSedan->setSteeringSystem(nullptr);
	EXPECT_EQ(false, carSedan->validParts());
	EXPECT_EQ(false, carSedan->validParts(true));

	carSedan->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carSedan->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::CONTINENTAL));
	carSedan->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	EXPECT_EQ(false, carSedan->validParts());
	EXPECT_EQ(false, carSedan->validParts(true));

	carSedan->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carSedan->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::BOSCH_B));
	carSedan->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::MOBIS));
	EXPECT_EQ(false, carSedan->validParts());
	EXPECT_EQ(false, carSedan->validParts(true));

	carSedan->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carSedan->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::BOSCH_B));
	carSedan->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	EXPECT_EQ(true, carSedan->validParts());
	EXPECT_EQ(true, carSedan->validParts(true));

	std::shared_ptr<Car> carSuv = std::make_shared<SuvCar>();
	EXPECT_NE(nullptr, carSuv);

	carSuv->setEngineSystem(nullptr);
	EXPECT_EQ(false, carSuv->checkEngine());

	carSuv->setEngineSystem(EngineFactory::createEngine(EngineType::TOYOTA));
	carSuv->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::CONTINENTAL));
	carSuv->setSteeringSystem(nullptr);
	EXPECT_EQ(false, carSuv->validParts());
	EXPECT_EQ(false, carSuv->validParts(true));

	carSuv->setEngineSystem(EngineFactory::createEngine(EngineType::TOYOTA));
	carSuv->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::CONTINENTAL));
	carSuv->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	EXPECT_EQ(false, carSuv->validParts());
	EXPECT_EQ(false, carSuv->validParts(true));

	carSuv->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carSuv->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::BOSCH_B));
	carSuv->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::MOBIS));
	EXPECT_EQ(false, carSuv->validParts());
	EXPECT_EQ(false, carSuv->validParts(true));

	carSuv->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carSuv->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::BOSCH_B));
	carSuv->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	EXPECT_EQ(true, carSuv->validParts());
	EXPECT_EQ(true, carSuv->validParts(true));

	std::shared_ptr<Car> carTruck = std::make_shared<TruckCar>();
	EXPECT_NE(nullptr, carTruck);

	carTruck->setEngineSystem(nullptr);
	EXPECT_EQ(false, carTruck->checkEngine());

	carTruck->setEngineSystem(EngineFactory::createEngine(EngineType::WIA));
	carTruck->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::CONTINENTAL));
	carTruck->setSteeringSystem(nullptr);
	EXPECT_EQ(false, carTruck->validParts());
	EXPECT_EQ(false, carTruck->validParts(true));

	carTruck->setEngineSystem(EngineFactory::createEngine(EngineType::WIA));
	carTruck->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::CONTINENTAL));
	carTruck->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	EXPECT_EQ(false, carTruck->validParts());
	EXPECT_EQ(false, carTruck->validParts(true));

	carTruck->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carTruck->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::MANDO));
	carTruck->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	EXPECT_EQ(false, carTruck->validParts());
	EXPECT_EQ(false, carTruck->validParts(true));

	carTruck->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carTruck->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::BOSCH_B));
	carTruck->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::MOBIS));
	EXPECT_EQ(false, carTruck->validParts());
	EXPECT_EQ(false, carTruck->validParts(true));

	carTruck->setEngineSystem(EngineFactory::createEngine(EngineType::GM));
	carTruck->setBreakSystem(BreakFactory::createBreak(BrakeSystemType::BOSCH_B));
	carTruck->setSteeringSystem(SteeringFactory::createSteering(SteeringSystemType::BOSCH_S));
	EXPECT_EQ(true, carTruck->validParts());
	EXPECT_EQ(true, carTruck->validParts(true));

	carSedan->printAllParts();
	carSuv->printAllParts();
	carTruck->printAllParts();
}