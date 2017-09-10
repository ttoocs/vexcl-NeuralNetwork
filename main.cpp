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
//  we = rnd(vex::element_index(0,10), std::rand());
//
//  std::vector<double> test(10);
//  test.push_back(32);

//  vex::copy(we,test);

//  std::cout << testLayer.weights << std::endl;

//  std::cout << input << std::endl;

// for (std::vector<double>::const_iterator i = test.begin(); i != test.end(); ++i)
//    std::cout << *i << ',';
//  std::cout << std::endl;

//  std::cout << test << std::endl;

//  vex::vector<double> input(32*32);
//  vex::vector<double> input = 4 * rnd(vex::element_index(0,32*32), std::rand()) - 1;
  

  auto ret = testLayer.forward(input);

  std::cout << input  << std::endl;
}


int main() {
  vex::Context ctx( vex::Filter::Any && vex::Filter::DoublePrecision );

  if (!ctx){
     std::cout << "No devices available." << std::endl;
  }

  // Print out list of selected devices:
  std::cout << ctx << std::endl;

  testLayer();
}




