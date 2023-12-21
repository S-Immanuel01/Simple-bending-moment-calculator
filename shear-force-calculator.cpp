#include <iostream>

// calculating moment
// *the moment of a beam is equal to the force times the perpendicular distance of that beam
// *for bending moment lenght, force, position of force,  support, and postion of the support is needed

using namespace std;

class ShearForceCalculator 
{
private:
    double length;
    double force;
    double forcePos;
    double supportForceLeft;
    double supportForceRight;
    double supportPosLeft;
    double supportPosRight;

public:

    ShearForceCalculator(
        double length, 
        double force, 
        double forcePos, 
        double supportForceLeft, 
        double supportForceRight, 
        double supportPosLeft, 
        double supportPosRight)
    {
        this->length = length;
        this->force = force;
        this->forcePos = forcePos;
        this->supportForceLeft = supportForceLeft;
        this->supportForceRight = supportForceRight;
        this->supportPosLeft = supportPosLeft;
        this->supportPosRight = supportPosRight;
    }
    
    double computeMoment(double point_of_moment)
    {
        // moment = f * d
        // find the moment at any point of the beam
        if (point_of_moment > length)
        {
            return 0;
        }

        double distance_of_force = forcePos -  point_of_moment;
        double distance_to_support_left = supportPosLeft - point_of_moment;
        double distance_to_support_right = supportPosRight - point_of_moment;

        // *Get the absolute value of the distance
        (distance_of_force < 0) ? distance_of_force = distance_of_force * -1 : distance_of_force = distance_of_force;
        (distance_to_support_left < 0) ? distance_to_support_left = distance_to_support_left * -1 : distance_to_support_left = distance_to_support_left;
        (distance_to_support_right < 0) ? distance_to_support_right = distance_to_support_right * -1 : distance_to_support_right = distance_to_support_right;

        if (supportPosLeft > point_of_moment) 
        {
           // check if the moment is anti-clockwise and negate if positive
            supportForceLeft = -supportForceLeft;
        } else if(supportPosRight > point_of_moment) {
            // check if the moment is anti-clockwise and negate if positive
            supportForceRight = -supportForceRight;
        }
        if (forcePos < point_of_moment)
        {
            force = -force;
        }
        

        double moment_of_point = (force *  distance_of_force) +(supportForceLeft * distance_to_support_left) + (supportForceRight * distance_to_support_right)  ;
        
        return moment_of_point;
    }
};

int main(int argc, char const *argv[])
{
    // ShearForceCalculator *forceCalculator = new ShearForceCalculator(15,20,3,10,5,0,15);
    // ShearForceCalculator *forceCalculator = new ShearForceCalculator(10,10,5,5,5,0,10);
    ShearForceCalculator *forceCalculator = new ShearForceCalculator(15,20,3,10,5,0,15);
    double moment = forceCalculator->computeMoment(7.5); //lets try calculating the moment at point 15 we get -90
    cout << "The moment is: " << moment; // try something like the center of the beam. at the center of the beam the moment is 52.5kN!!!
    return 0;
}
