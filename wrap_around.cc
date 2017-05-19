#include <iostream>


int main() {
    unsigned short int curr_seq = 3, prev_seq = 65535;
    short int  sn_diff = curr_seq  - prev_seq;
    if (sn_diff >= 0) {
        if (curr_seq  < prev_seq) {
            // Wrap-around detected.
            std::cout << " wrap around detected"<<sn_diff<<std::endl;
        }
    }
    std::cout << " sn_diff : "<<sn_diff<<std::endl;

}
