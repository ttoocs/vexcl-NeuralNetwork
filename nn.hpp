#include <iostream>
#include <vexcl/vexcl.hpp>


namespace nn{

  //VEXCL simple dense multiplication.
  template <class M, class V>
//  auto vexmult(size_t n, size_t m, M &&A, V &&x) {
  auto vexmult(size_t n, size_t m, M A, V x) {
    using namespace vex;
    auto NxM = extents[n][m];
    return reduce<SUM>(NxM, A * reshape(x, NxM, extents[1]), 1);
  }


  //Quick helper functions for creating random vectors.
  template <typename T>
  inline vex::vector<T> randVec(size_t n, size_t m){
    return randVec<T>(n*m);
  }

  template <typename T>
  inline vex::vector<T> randVec(size_t n){
    vex::Random<double, vex::random::threefry> rnd;
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

      vex::vector<ValType> forward(vex::vector<ValType> input){
        return vexmult<vex::vector<ValType>,vex::vector<ValType>> (width,height,input,weights);
      }

      vex::vector<ValType> backward(vex::vector<ValType> result) {
        std::cout << "TODO" << std::endl;
      }


      layer(){}
      layer(int width, int height, bool randomize=false){
        this->width = width;
        this->height = height;
        this->weights.resize(width*height);
        if(randomize){
          vex::Random<double, vex::random::threefry> rnd;
          this->weights = 200 * rnd(vex::element_index(0,32*32), std::rand()) -1;
        }
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
