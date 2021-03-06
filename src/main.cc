#include <iostream>
#include <glm/glm.hpp>

#include "Scene.hh"

#include "Primitives/Sphere.hh"
#include "Materials/Diffuse.hh"
#include "Lamps/PointLamp.hh"

static void WritePgm(const unsigned char *pixels, unsigned w, unsigned h)
{
    std::cout << "P6\n" << w << " " << h << "\n255\n";
    std::cout.write((const char*) pixels, w * h * 3);
}

int main(int argc, char *argv[])
{
    auto res = glm::vec2(4096, 2160) / (float)atof(argv[1]);
    float fov = glm::radians<float>(60.0f);
    yacre::Scene s(new yacre::Camera(res, fov));
    s.GetCamera()->SetPosition(glm::vec3(0, 0, 3));

    s.SetBackgroundColor(glm::vec3(0, 0, 0));

    s.AddMaterial("Branco", new yacre::Diffuse(glm::vec3(1)));

    auto p = new yacre::Sphere(glm::vec3(0), 1);
    p->SetMaterial(s.GetMaterial("Branco"));
    s.AddPrimitive("Bolota", p);
    p = new yacre::Sphere(glm::vec3(-.7, 0, 1), .25);
    p->SetMaterial(s.GetMaterial("Branco"));
    s.AddPrimitive("Bolota-2", p);
    p = new yacre::Sphere(glm::vec3(0, -1001, 0), 1000);
    p->SetMaterial(s.GetMaterial("Branco"));
    s.AddPrimitive("Bolota-3", p);

    auto l = new yacre::PointLamp(glm::vec3(0,0,5));
    l->SetPosition(glm::vec3(3, 2, 3));
    s.AddLamp("Lampadinha", l);
    l = new yacre::PointLamp(glm::vec3(25, 25, 15));
    l->SetPosition(glm::vec3(-3, 2, 3));
    s.AddLamp("Lampadinha-2", l);
    l = new yacre::PointLamp(glm::vec3(10, 10, 15));
    l->SetPosition(glm::vec3(0, 2, 2));
    s.AddLamp("Lampadinha-3", l);

    auto buff = s.Render();
    WritePgm(buff, res.x, res.y);
    delete[] buff;

    return 0;
}
