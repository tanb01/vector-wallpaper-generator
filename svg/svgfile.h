#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED

#include <string>
#include <fstream>
#include <set>
#include <vector>
#include "coords.h"
#include "couleur.h"

constexpr char defcol[] = "black";

class Svgfile
{
    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour éviter les ouverture multiples
        static std::set<std::string> s_openfiles;

    public:

        Svgfile(std::string _filename = "wallpaper.svg", int _width=1366, int _height=768);//1000x800
        ~Svgfile();

        void addDisk(double x, double y, double r, std::string color=defcol, double opacite=1);//, std::string f=defcol);
        void addEllipse(double x, double y, double rx, double ry, std::string color, double opacite=1);
        void addPolygon(std::vector<Coords> mypoints, std::string color, double opacite=1);
        void addRectangle(double x, double y, double width, double height, std::string color, double opacite=1);

        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
        void addCross(double x, double y, double span, std::string color=defcol);

        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);

        void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey");
};

std::string makeRGB(int r, int g, int b);

std::string fillBallColor(std::string col);

#endif // SVGFILE_H_INCLUDED



