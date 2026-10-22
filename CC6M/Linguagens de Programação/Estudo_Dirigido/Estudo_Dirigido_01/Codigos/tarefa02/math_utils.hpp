#pragma once
#include <iostream>

class MathUtils {
private:
    float pi;
    float raio;

public:
    MathUtils();
    MathUtils(float raio);

    float getPi() const;
    float getRaio() const;

    void setPi(float pi);
    void setRaio(float raio);
    
    void exibir() const;

};      