#include <iostream>
#include <stdexcept>
//#include <vexcl/vexcl.hpp>

#include "nn.hpp"

void testLayer(){
  nn::layer<double> testLayer;
  testLayer.width=32;
  testLayer.height=32;
  testLayer.weights.resize(32*32);
  vex::Random<double, vex::random::threefry> rnd;
  testLayer.weights = 2 * rnd(vex::element_index(0,32*32), std::rand()) -1;

  vex::vector<double> input(32);
  input = 2 * rnd(vex::element_index(), std::rand()) -1 ;

  auto ret = testLayer.forward(input);

  std::cout << ret << std::endl;
}
void testMult(){
  nn::layer<double> testLayer;
  testLayer.width=1;
  testLayer.height=3;
  testLayer.weights.resize(3*1);
  vex::Random<double, vex::random::threefry> rnd;
  testLayer.weights[0] = 0;
  testLayer.weights[1] = 2;
  testLayer.weights[2] = -2;

  vex::vector<double> input(3);
  input[0] = 1;
  input[1] = 1;
  input[2] = 1;

  auto ret = testLayer.forward(input);

  std::cout << ret << std::endl;
}

void testConstructor(){
  #define SIZEIN  1024*1024
  #define SIZEOUT  1024*1024*3
  nn::layer<double> testConst(SIZEIN,SIZEOUT,true);
  vex::vector<double> input = nn::randVec<double> (SIZEIN);

  auto ret = testConst.forward(input);
//  std::cout << ret << std::endl;
}


int main() {
  vex::Context ctx( vex::Filter::Any && vex::Filter::DoublePrecision );

  if (!ctx){
     std::cout << "No devices available." << std::endl;
  }

  // Print out list of selected devices:
  std::cout << ctx << std::endl;

//  testLayer();
//  testMult();
  testConstructor();
}

