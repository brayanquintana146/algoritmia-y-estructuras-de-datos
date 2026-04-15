#include <iostream>
#include <iostream>
#include <iomanip>

using namespace std;

struct SecurityCheck {
    int cost;
    int benefit;
    int false_negatives;
};

const int NUM_SECURITY_CHECKS = 8;
const int NUM_ELEM_PER_ARRAY = 3;

void solve(SecurityCheck security_checks[NUM_SECURITY_CHECKS], int P, int B, int F) {
    bool found = false;
    int total_posib = 1<<NUM_SECURITY_CHECKS;
    for(int posib=0;posib<total_posib;posib++) {// 10100111
        int resources[NUM_SECURITY_CHECKS]{};
        int total_cost=0;
        int benefit=0;
        int false_negatives=0;
        int pos_resources = 0;
        for(int pos=0;pos<NUM_SECURITY_CHECKS;pos++) {
            if ((posib>>pos)&1) {
                resources[pos_resources] = pos+1;
                total_cost += security_checks[pos].cost;
                benefit += security_checks[pos].benefit;
                false_negatives += security_checks[pos].false_negatives;
                pos_resources++;
            }
        }
        if (total_cost <= P && benefit >= B && false_negatives <= F) {
            found = true;
            cout<<"Recursos: {";
            for(int i=0;i<pos_resources;i++) {
                cout<<resources[i];
                if(i!=pos_resources-1) cout<<",";
            }
            cout<<"}"<<", Costo total: "<<total_cost<<", Beneficio: "<<benefit<<", Falsos Negativos: "<<false_negatives<<endl;
        }
    }
}

int main() {
    SecurityCheck security_checks[8] {
        {35000,80,1},
        {24000,60,3},
        {30000,70,2},
        {27000,48,1},
        {10000,20,1},
        {7000,35,2},
        {6000,10,1},
        {40000,40,3}
    };
    int P=50000, B=100, F=3;
    solve(security_checks, P, B, F);
    return 0;
}
