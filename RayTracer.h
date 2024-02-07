#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "../external/json.hpp"
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace nlohmann;

class RayTracer {
  public:
    

    RayTracer(nlohmann::json& j);

        int sv_ppm(std::string file_name, const std::vector<double>& buffer, int dimx, int dimy) {

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

    std::string parse_filename(json& j) {
        cout << "Outputs: " << endl;
        int lc = 0;

        // use iterators to read-in array types
        for (auto itr = j["output"].begin(); itr != j["output"].end(); itr++) {

            std::string filename;
            if (itr->contains("filename")) {
                //  filename = static_cast<std::string>((*itr)["filename"]);
                filename = (*itr)["filename"].get<std::string>();
            }
            else {
                cout << "Fatal error: output shoudl always contain a filename!!!" << endl;
                return "";
            }

            cout << "Filename: " << filename << endl;
            return filename;
        }
       
    }
    
    void run();
    
};



#endif
