//NOTE: This is being abondoned, as I was mainly using it for matriacies, and vexcl.. seems to handle it in magical crazyness I've yet to understand... so this is here just in reference.

#define CHECK_MAT_BOUNDS

namespace mathWrapper{ //Because I'm already sick of switching implmentations.

  template <typename vType>
  using vector = vex::vector<vType>;

  
  template<class mType>
  class mat {
    public:
      vector<int> dimentions; //Size = number of dimentions, values = elements in dimention.
      vector<vector<mType>> values;
      
      //TODO: Make this handle mat's of different types by casting to the return type.
      static mat<mType> mult(mat<mType> m1, mat<mType> m2){
        #ifdef CHECK_MAT_BOUNDS
        if(m1.dimentions.size() > 2 || m2.dimentions.size() >  2){
          std::cout << "Ooo, fancey stuff. NOT YET IMPLMENTED." << std::endl; //TODO: Handle it by looping over the extra dimentions... (or more/better code)
          std::exit();
          return NULL;
        }
        if(m1.dimentions[1] != m2.dimentions[2]){
          std::cout << "Bad 2D matrix dimentions for multiplication." << std::endl;
          std::exit();
          return NULL;
        }
        #endif
 
        //I uh.. his is way better... welp.

        //vex::slicer<2> slice(vex::extents[m1.dimentions[0]],[m2.dimentions[1]])
         
        //END VEXCL specific        
        
        std::cout << "TODO" << std::endl;
        std::exit();
      }
  };
}

