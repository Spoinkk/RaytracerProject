#include "RayTracer.h"
#include <Eigen/Core>
#include <Eigen/Dense>



RayTracer::RayTracer(nlohmann::json& j){
    
    int dimX = 800;
    int dimY = 600;
    
    std::string filename = parse_filename(j);



    sv_ppm(filename, dimX, dimY);
    
}

void RayTracer::run(){}
