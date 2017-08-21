#include <iostream>
#include <stdexcept>
#include <vexcl/vexcl.hpp>

//VEXCL specific implmentation of multiplication. (from the dev of it)
template <class M, class V>
auto vexmult(size_t n, size_t m, M &&A, V &&x) {
    using namespace vex;
    auto NxM = extents[n][m];
    return reduce<SUM>(NxM, A * reshape(x, NxM, extents[1]), 1);
}


namespace nn{

  template<typename ValType>
  class layer{
    public:
      int type;
      vex::vector<ValType> weights;
      
      vex::vector<ValType> forward(vex::vector<ValType> input);
      vex::vector<ValType> backward(vex::vector<ValType> result);

  };
  
  template<typename ValType>
  class net{
    public:
      vex::vector<layer<ValType>> layers;
      
      vex::vector<ValType> forward(vex::vector<ValType> input);
      vex::vector<ValType> backward(vex::vector<ValType> result);
    
  };
  
}
int main() {
    vex::Context ctx( vex::Filter::Any && vex::Filter::DoublePrecision );

    if (!ctx){
       std::cout << "No devices available." << std::endl;
    }

    // Print out list of selected devices:
    std::cout << ctx << std::endl;
}


