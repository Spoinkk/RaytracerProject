#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "../external/json.hpp"
#include <Eigen/Core>
#include <Eigen/Dense>
#include <IOStream>
#include <fstream>
#include <sstream>
using namespace std;

class RayTracer {
  public:
    

    RayTracer(nlohmann::json& j);

    int save_ppm(std::string file_name, const std::vector<double>& buffer, int dimx, int dimy);
    
    void run();
    
};



#endif
