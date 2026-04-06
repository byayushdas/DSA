// Main.java

interface FuelEfficient {
    double calculateFuelEfficiency(double distance, double fuelConsumed);
}

// ---------------- VEHICLE ----------------
class Vehicle {
    String color;
    int maxSpeed;
    int numWheels;

    Vehicle(String color, int maxSpeed, int numWheels) {
        this.color = color;
        this.maxSpeed = maxSpeed;
        this.numWheels = numWheels;
    }

    void displayDetails() {
        System.out.println("Color: " + color);
        System.out.println("Max Speed: " + maxSpeed);
        System.out.println("Wheels: " + numWheels);
    }

    void accelerate(int speedIncrease) {
        maxSpeed += speedIncrease;
        System.out.println("Vehicle accelerated to " + maxSpeed);
    }

    void brake(int speedDecrease) {
        maxSpeed -= speedDecrease;
        System.out.println("Vehicle slowed to " + maxSpeed);
    }
}

// ---------------- CAR ----------------
class Car extends Vehicle implements FuelEfficient {
    int doors;

    Car(String color, int maxSpeed, int numWheels, int doors) {
        super(color, maxSpeed, numWheels);
        this.doors = doors;
    }

    @Override
    void accelerate(int speedIncrease) {
        maxSpeed += speedIncrease;
        System.out.println("Car accelerates smoothly to " + maxSpeed);
    }

    @Override
    void brake(int speedDecrease) {
        maxSpeed -= speedDecrease;
        System.out.println("Car applies brakes, speed now " + maxSpeed);
    }

    @Override
    public double calculateFuelEfficiency(double distance, double fuelConsumed) {
        return distance / fuelConsumed;
    }
}

// ---------------- TRUCK ----------------
class Truck extends Vehicle implements FuelEfficient {
    int loadCapacity;

    Truck(String color, int maxSpeed, int numWheels, int loadCapacity) {
        super(color, maxSpeed, numWheels);
        this.loadCapacity = loadCapacity;
    }

    @Override
    void accelerate(int speedIncrease) {
        maxSpeed += speedIncrease;
        System.out.println("Truck accelerates with heavy load to " + maxSpeed);
    }

    @Override
    void brake(int speedDecrease) {
        maxSpeed -= speedDecrease;
        System.out.println("Truck slows down carefully to " + maxSpeed);
    }

    @Override
    public double calculateFuelEfficiency(double distance, double fuelConsumed) {
        return distance / fuelConsumed;
    }
}

// ---------------- ABSTRACT ELECTRIC VEHICLE ----------------
abstract class ElectricVehicle extends Vehicle {

    ElectricVehicle(String color, int maxSpeed, int numWheels) {
        super(color, maxSpeed, numWheels);
    }

    abstract void chargeBattery(int percentage);
}

// ---------------- ELECTRIC CAR ----------------
class ElectricCar extends ElectricVehicle {
    int batteryLevel = 0;

    ElectricCar(String color, int maxSpeed, int numWheels) {
        super(color, maxSpeed, numWheels);
    }

    @Override
    void chargeBattery(int percentage) {
        batteryLevel += percentage;
        if (batteryLevel > 100) batteryLevel = 100;
        System.out.println("Electric Car battery: " + batteryLevel + "%");
    }
}

// ---------------- HYBRID CAR ----------------
class HybridCar extends Car {
    int batteryLevel = 0;

    HybridCar(String color, int maxSpeed, int numWheels, int doors) {
        super(color, maxSpeed, numWheels, doors);
    }

    void chargeBattery(int percentage) {
        batteryLevel += percentage;
        if (batteryLevel > 100) batteryLevel = 100;
        System.out.println("Hybrid battery: " + batteryLevel + "%");
    }
}

// ---------------- MOTORCYCLE ----------------
class Motorcycle extends Vehicle {

    Motorcycle(String color, int maxSpeed, int numWheels) {
        super(color, maxSpeed, numWheels);
    }

    @Override
    void accelerate(int speedIncrease) {
        maxSpeed += speedIncrease;
        System.out.println("Motorcycle zooms to " + maxSpeed);
    }
}

// ---------------- MAIN CLASS ----------------
public class extends_implements {
    public static void main(String[] args) {

        // Car
        Car car = new Car("Red", 200, 4, 4);
        car.displayDetails();
        car.accelerate(50);
        car.brake(20);
        System.out.println("Car Efficiency: " + car.calculateFuelEfficiency(500, 25));

        System.out.println();

        // Truck
        Truck truck = new Truck("Blue", 120, 6, 1000);
        truck.displayDetails();
        truck.accelerate(30);
        truck.brake(10);
        System.out.println("Truck Efficiency: " + truck.calculateFuelEfficiency(300, 30));

        System.out.println();

        // Electric Car
        ElectricCar eCar = new ElectricCar("Green", 180, 4);
        eCar.displayDetails();
        eCar.chargeBattery(70);

        System.out.println();

        // Hybrid Car
        HybridCar hCar = new HybridCar("White", 190, 4, 4);
        hCar.displayDetails();
        hCar.chargeBattery(60);

        System.out.println();

        // Motorcycle
        Motorcycle bike = new Motorcycle("Black", 150, 2);
        bike.displayDetails();
        bike.accelerate(40);
    }
}