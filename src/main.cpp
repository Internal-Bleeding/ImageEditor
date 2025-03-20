#include <iostream>
#include <sstream>

#include "Commands.hpp"
#include "Image.hpp"
#include "filter/Filter.hpp"
#include "Layer.hpp"
#include "Project.hpp"


int main(int argc, char** argv)
{
    Project proj("Project");

    for (size_t i = 0; i < argc; i++) 
    {
        
    }

    proj.NewLayer(new Layer("horse"));

    proj.Render();

    /*TEST(Test1, pixel) {
        Pixel p1(255, 102, 94);
        Pixel p2 = p1;
        EXPECT_EQ(255, p2.GetR());
        EXPECT_EQ(102, p2.GetG());
        EXPECT_EQ(94, p2.GetB());
        Pixel p3;
        p3 = p2;
        EXPECT_EQ(255, p3.GetR());
        EXPECT_EQ(102, p3.GetG());
        EXPECT_EQ(94, p3.GetB());
        Pixel p4 = p3 * Pixel(0, 0, 0);
        EXPECT_EQ(0, p4.GetR());
        EXPECT_EQ(0, p4.GetG());
        EXPECT_EQ(0, p4.GetB());
    } ENDM

    TEST(Test2, layer) {
        Layer layer1("layer");
        EXPECT_STREQ("layer", layer1.GetName());
        layer1.AddImage("horse.jpg");
    } ENDM

    TEST(Test3, sima) {
        Image img("horse.jpg");
        Image cpy = img;
        EXPECT_EQ(3, cpy.GetChannels());
        EXPECT_EQ(356, cpy.GetX());
        EXPECT_EQ(501, cpy.GetY());
        Image cpy2;
        cpy2 = img;
        EXPECT_EQ(3, cpy2.GetChannels());
        EXPECT_EQ(356, cpy2.GetX());
        EXPECT_EQ(501, cpy2.GetY());
    } ENDM

    TEST(Test4, pixel4) {
        Image img(1000, 100, 4);
        Image cpy = img;
        EXPECT_EQ(4, cpy.GetChannels());
        EXPECT_EQ(1000, cpy.GetX());
        EXPECT_EQ(100, cpy.GetY());
    } ENDM

    TEST(Test5, s) {
        Filter* filter1 = new Brightness(0.1f);
        Filter* filter2 = filter1;
        EXPECT_STREQ("brightness", filter2->GetName());
        Filter* filter3;
        filter3 = filter1;
        EXPECT_STREQ("brightness", filter3->GetName());
    } ENDM

    TEST(Test6, s) {
        BlendMode* mode1 = new Multiply(1.0f, true);
        BlendMode* mode2 = mode1;
        EXPECT_STREQ("Multiply", mode2->GetName());
        BlendMode* mode3 = new Normal(1.0f, true);
        mode2 = mode3;
        EXPECT_STREQ("Normal", mode3->GetName());
    } ENDM

    TEST(Test7, filter) {
        Layer layer1("layer1");
        EXPECT_STREQ("layer1", layer1.GetName());
        layer1.AddImage("horse.jpg");
        layer1.AddFilter(new GrayScale(true), 1);
        layer1.AddFilter(new Brightness(0.1f), 2);
        Filter* filter3 = new Brightness(0.1f);
        layer1.AddFilter(filter3, 3);
        EXPECT_EQ(3, layer1.GetSize());

    } ENDM    

    TEST(Test8, render) {
        Layer layer1("layer1");
        proj.NewLayer(&layer1);
        proj.Render("ReadyFile.jpg");
    } ENDM

    TEST(Test9, apply) {
        Saturate sat = Saturate(2.0f, true);
        Image img1("horse.jpg");
        Image img2("horse.jpg");
        Layer layer1("layer2");
        sat.Apply(img2, img1);
        GrayScale gray = GrayScale(true);
        gray.Apply(img2, img1);
        Brightness bright = Brightness(0.1f, true);
        bright.Apply(img2, img1);
    } ENDM

    /*TEST(Test10, allcommand) {
        std::string CommandName = "Layer";
        int Arg0 = 0;
        std::string Arg1 = "layer";
        std::string Arg2 = "horse.jpg";
        try
        {
            Command command = NewLayer(&proj, Arg1.c_str(), Arg2.c_str());
        }
        catch (const char* str)
        {
            std::cout << str << std::endl;
        }
        
    } ENDM*/
    return 0;
}