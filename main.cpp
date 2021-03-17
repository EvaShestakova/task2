
//#include "CVector.h"
//#include "Temp.h"
//#include "CVectorHori.h"
//#include "CVectorVert.h"
#include "Fabric.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
//void AutoTest();

class Fabric;
class FabricHori;
class FabricVert;

int main() {
    try {
        CVectorHori a;
        CVectorVert c,b;
        a[1] = 3;
        b[1] = 2;
        c = a + b;
        c.print();
        AutoTest();
        ifstream fin("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        string str;
        string s;
        int m;
        double d;
        int n = 0;
        while (!fin.eof())
        {
            getline(fin,str);
            n++;
        }
        fin.seekg(0, ios_base::beg);
        fin.close();
        fin.open("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        vector <CVector*> arr(n);
        map<string, Fabric*> factory;
        factory["Hori"] = new FabricHori;
        factory["Vert"] = new FabricVert;
        for (int i = 0; i < n; ++i) {
            fin >> s;
            arr[i] = create(s, factory);
            fin >> s;
            arr[i]->SetFileName(s);
            fin >> m;
            arr[i]->Setn(m);
            for (int j = 0; j < m; ++j) {
                fin >> d;
                (*arr[i])[j] = d;
            }
        }
        for (int i = 0; i < n; ++i) {
            arr[i]->output(arr[i]->GetFileName());
        }
        fin.close();
        for (int i = 0; i < n; ++i) {
            delete arr[i];
        }
        return 0;
    }
    catch (int err) { printf("error=%d\n", err); }
}
