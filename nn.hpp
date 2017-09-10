#include <iostream>
#include <vexcl/vexcl.hpp>


namespace nn{

  //VEXCL simple dense multiplication.
/*
  template <class M, class V>
//  auto vexmult(size_t n, size_t m, M &&A, V &&x) {
  auto vexmult(size_t n, size_t m, M A, V x) {
    using namespace vex;
    auto NxM = extents[n][m];
    return reduce<SUM>(NxM, A * reshape(x, NxM, extents[1]), 1);
  }
 */

  //LAYER

  template<typename ValType>
  class layer{
    public:
      int type;
      int width;
      int height;
      vex::vector<ValType> weights;

      vex::vector<ValType> forward(vex::vector<ValType> input){
//        auto NxM = vex::extents[height][width];
//        return vex::reduce<vex::SUM>(NxM, input * vex::reshape(weights, NxM, vex::extents[1]), 1);
        return vexmult<vex::vector<ValType>,vex::vector<ValType>> (height,width,input,weights);
      }

      vex::vector<ValType> backward(vex::vector<ValType> result) {
        std::cout << "TODO" << std::endl;
      }

  };


  //NETWORK

  template<typename ValType>
  class net{
    public:
      vex::vector<layer<ValType>> layers;

      vex::vector<ValType> forward(vex::vector<ValType> input){
        auto tmp = input;
        for(int i=0; i<layers.size(); i++){
          tmp = layers[i].forward(tmp);
        }
      }

      vex::vector<ValType> backward(vex::vector<ValType> result){
        std::cout << "TODO" << std::endl;
      }
  };

}
