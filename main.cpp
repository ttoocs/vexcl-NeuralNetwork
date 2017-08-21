#include <iostream>
#include <stdexcept>
//#include <vexcl/vexcl.hpp>

#include "nn.hpp"

void testLayer(){
  nn::layer<double> testLayer;
  testLayer.width=32;
  testLayer.height=32;
  vex::Random<double, vex::random::threefry> rnd;
  testLayer.weights = 4 * rnd(vex::element_index(), std::rand()) - 1;

  vex::vector<double> input(32);

  auto ret = testLayer.forward(input);

  std::cout << ret  << std::endl;
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




