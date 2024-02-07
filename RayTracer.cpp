#include "RayTracer.h"
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;

int save_ppm(std::string file_name, const std::vector<double>& buffer, int dimx, int dimy) {

    ofstream ofs(file_name, ios_base::out | ios_base::binary);
    ofs << "P6" << endl << dimx << ' ' << dimy << endl << "255" << endl;

    for (unsigned int j = 0; j < dimy; ++j)
        for (unsigned int i = 0; i < dimx; ++i)
            ofs << (char)(255.0 * buffer[3 * j * dimx + 3 * i + 0]) << (char)(255.0 * buffer[3 * j * dimx + 3 * i + 1]) << (char)(255.0 * buffer[3 * j * dimx + 3 * i + 2]);

    ofs.close();

    return 0;
}

std::vector<double> set_buffer(int dimX, int dimY, int w) {

    std::vector<double> buffer(3 * dimX * dimY);
    for (int j = 0; j < dimY; ++j) {
        for (int i = 0; i < dimY; ++i) {
            if (((i + j) / w) % 2 == 0) {
                buffer[3 * j * dimX + 3 * i + 0] = 1;
                buffer[3 * j * dimX + 3 * i + 1] = 1;
                buffer[3 * j * dimX + 3 * i + 2] = 0;
            }
            else {
                buffer[3 * j * dimX + 3 * i + 0] = 0;
                buffer[3 * j * dimX + 3 * i + 1] = 1;
                buffer[3 * j * dimX + 3 * i + 2] = 1;
            }
        }
    }

    return buffer;
}


RayTracer::RayTracer(nlohmann::json& j){
  
    int dimX = 800;
    int dimY = 600;
    int w = 100;
    
    std::vector<double> buffer = set_buffer(dimX, dimY, w);




    save_ppm(j, buffer, dimX, dimY);
    
}

void RayTracer::run(){}
