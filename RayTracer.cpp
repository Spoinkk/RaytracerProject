#include "RayTracer.h"
#include <Eigen/Core>
#include <Eigen/Dense>



RayTracer::RayTracer(nlohmann::json& j){
    
    int dimX = 800;
    int dimY = 600;
    int w = 100;
    
    std::vector<double> buffer = set_buffer(dimX, dimY, w);
    std::string filename = parse_filename(j);



    sv_ppm(filename, buffer, dimX, dimY);
    
}

void RayTracer::run(){}
