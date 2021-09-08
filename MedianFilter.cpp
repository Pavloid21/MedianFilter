#include <iostream>
#include <emscripten/emscripten.h>
#include <stdint.h>

using namespace std;

int main() {
    cout<<"Hello world"<<endl;
}

#ifdef __cplusplus
extern "C" {
#endif

EMSCRIPTEN_KEEPALIVE uint8_t* myFunction(uint8_t *arr, int size) {
    cout<<"My function called"<<endl;
    cout<<"Size: "<<size<<endl;
    for (int cnt = 0; cnt < 3200; cnt++) {
        if (cnt%4 == 0) {
            cout<<"arr["<<cnt<<"] = "<<(int) arr[cnt]<<endl;
            arr[cnt] = 255;
            if (cnt > 0) {
                arr[cnt - 1] = 255;
                arr[cnt - 2] = 0;
                arr[cnt - 3] = 0;
            }
        }
    }

    return arr;
}

#ifdef __cplusplus
}
#endif