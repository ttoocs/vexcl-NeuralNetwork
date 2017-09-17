#pragma once
#include <vexcl/vexcl.hpp>

namespace nn{

  //VEXCL simple dense multiplication.
  template <class M, class V>
  auto vexmult(size_t n, size_t m, M A, V x);


  //Quick helper functions for creating random vectors.
  template <typename T>
  vex::vector<T> randVec(size_t n, size_t m){
    return randVec<T>(n*m);
  }

  template <typename T>
  vex::vector<T> randVec(size_t n){
    vex::Random<T, vex::random::threefry> rnd;
    vex::vector<T> ret(n);
    ret = 200 * rnd(vex::element_index(), std::rand()) -1;
    return ret;
  }

  //LAYER

  template<typename ValType>
  class layer{
    public:

      int type;

      union{
        int width;
        int cols;
      };
      union{
        int height;
        int rows;
      };

      vex::vector<ValType> weights;

      vex::vector<ValType> forward(vex::vector<ValType> input);

      vex::vector<ValType> backward(vex::vector<ValType> result);

      layer();
      layer(int width, int height, bool randomize=false);
    
  };


  //NETWORK

  template<typename ValType>
  class net{
    public:
      vex::vector<layer<ValType>> layers;

      vex::vector<ValType> forward(vex::vector<ValType> input);
      vex::vector<ValType> backward(vex::vector<ValType> result);
  };

}

