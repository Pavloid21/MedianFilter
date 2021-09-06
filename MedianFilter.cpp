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

EMSCRIPTEN_KEEPALIVE void myFunction(uint8_t *arr, int size) {
    cout<<"My function called"<<endl;
    cout<<"Size: "<<size<<endl;
    for (int cnt = 0; cnt < 36; cnt++) 
       cout<<"arr["<<cnt<<"] = "<<(int) arr[cnt]<<endl;
}

#ifdef __cplusplus
}
#endif