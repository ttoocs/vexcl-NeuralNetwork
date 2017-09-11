#include <iostream>
#include <vexcl/vexcl.hpp>

#include "nn.hpp"

namespace nn{

  //VEXCL simple dense multiplication.
  template <class M, class V>
//  auto vexmult(size_t n, size_t m, M &&A, V &&x) {
  auto vexmult(size_t n, size_t m, M A, V x) {
    using namespace vex;
    auto NxM = extents[n][m];
    return reduce<SUM>(NxM, A * reshape(x, NxM, extents[1]), 1);
  }
  
  //LAYER
      template<typename ValType>
      vex::vector<ValType> layer<ValType>::forward(vex::vector<ValType> input){
        return vexmult<vex::vector<ValType>,vex::vector<ValType>> (width,height,input,weights);
      }

      template<typename ValType>
      vex::vector<ValType> layer<ValType>::backward(vex::vector<ValType> result) {
        std::cout << "TODO" << std::endl;
      }


      template<typename ValType>
      layer<ValType>::layer(){}

      template<typename ValType>
      layer<ValType>::layer(int width, int height, bool randomize){
        this->width = width;
        this->height = height;
        this->weights.resize(width*height);
        if(randomize){
          vex::Random<ValType, vex::random::threefry> rnd;
          this->weights = 200 * rnd(vex::element_index(0,32*32), std::rand()) -1;
        }
      }

  //NETWORK

      template<typename ValType>
      vex::vector<ValType> net<ValType>::forward(vex::vector<ValType> input){
        auto tmp = input;
        for(int i=0; i<layers.size(); i++){
          tmp = layers[i].forward(tmp);
        }
        return tmp;
      }

      template<typename ValType>
      vex::vector<ValType> net<ValType>::backward(vex::vector<ValType> result){
        std::cout << "TODO" << std::endl;
      }
}

