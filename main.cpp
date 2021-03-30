#include <iostream>
using namespace std;

class SOCKET_BOOL{
    public:
        int val;
    void set(int in=0) {
        val = in;
    }
    int get() {
        return val;
    }
};

class NAND{
    public: 
        SOCKET_BOOL in_socket1;
        SOCKET_BOOL in_socket2;
        SOCKET_BOOL out;
    
    NAND(SOCKET_BOOL in_socket1, SOCKET_BOOL in_socket2) {
        int in_val1 = in_socket1.get();
        int in_val2 = in_socket2.get();
        int out_val;
        if (in_val1 == 1 && in_val2 == 1) { out_val = 0;}
        else { out_val = 1;}

        this->out.set(out_val);  
    }

    SOCKET_BOOL get() {
        return this->out;
    }
};

int main() {
    SOCKET_BOOL a;
    SOCKET_BOOL b;
    a.set(1);
    b.set(0);
    SOCKET_BOOL c(NAND(a, b).get());
    cout << c.val << endl;
    return 0;
}