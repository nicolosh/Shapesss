#include <iostream>
#include "include/shapesss.h"

using namespace std;

#define LEN 3

void getOneArea(const Shapesss &s) {
    std::cout << "Single area of Rectangle";
    std::cout << " = " << s.computeArea() << std::endl;
}

void getAllAreas(const Shapesss **s, double *res, int N) {
    for (int i = 0; i < N; ++i) {
        res[i] = s[i]->computeArea();
    }
}


int main() {
    std::cout << "Shapesss " << std::endl;
    Rectangle rectangle(2.0, 5.1);
    Circle circle(3.2);
    Triangle triangle(4.2, 7.2);

    getOneArea(rectangle);


    const Shapesss *shapeOne[LEN];
    double areasOne[LEN];

    shapeOne[0] = &rectangle;
    shapeOne[1] = &circle;
    shapeOne[2] = &triangle;

    getAllAreas(shapeOne, areasOne, LEN); // copio i valori dell'area di ogni shape in areasOne
    for (int i = 0; i < LEN; ++i) {
        shapeOne[i]->tellMeWhoIam();
        std::cout << ", my area is = " << areasOne[i] << std::endl;
    }

    std::cout << "Allocazione dinamica ora: " << std::endl;

    //ora con new sono già indirizzi quindi NO & dopo
    const Rectangle *rectangle_ = new Rectangle(2.0, 5.1);
    const Circle *circle_ = new Circle(3.2);
    const Triangle *triangle_ = new Triangle(4.2, 7.2);

    const Shapesss **shapeTwo = new const Shapesss *[LEN];

    shapeTwo[0] = rectangle_;
    shapeTwo[1] = circle_;
    shapeTwo[2] = triangle_;

    double* areasTwo = new double[LEN];
    getAllAreas(shapeTwo, areasTwo, LEN);

    for (int i = 0; i < LEN; ++i) {
        shapeTwo[i]->tellMeWhoIam();
        std::cout << ", my area is = " << areasTwo[i];
        std::cout << endl;
        delete shapeTwo[i];
    }

    delete[] areasTwo;
    delete[] shapeTwo;
    return 0;
}
