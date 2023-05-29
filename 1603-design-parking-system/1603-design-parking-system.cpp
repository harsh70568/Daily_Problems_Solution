class ParkingSystem
{
public:
    int space[3];
    ParkingSystem(int big, int medium, int small)
    {
        space[0] = big, space[1] = medium, space[2] = small;
    }
    bool addCar(int carType)
    {
        space[carType - 1]--;
        return (bool)(space[carType-1] >= 0);
    };
};