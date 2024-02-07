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

        int sv_ppm(std::string file_name, int dimx, int dimy) {

        ofstream ofs(file_name, ios_base::out | ios_base::binary);
        ofs << "P6" << endl << dimx << ' ' << dimy << endl << "255" << endl;

        for (unsigned int j = 0; j < dimy; ++j)
            for (unsigned int i = 0; i < dimx; ++i){
                int R = 204;
                int G = 204;
                int B = 255;
                ofs << (char)R << (char)G << (char)B;
            }
        ofs.close();

        return 0;
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
