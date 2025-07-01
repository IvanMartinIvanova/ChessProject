#include <piezagr.h>

//PiezaGr::PiezaGr()
//{
//
//}

PiezaGr::~PiezaGr()
{
    delete sprite;
}

std::string PiezaGr::gettipo()
{
    return tipo;
}

std::map<int, std::map < std::string, std::map<bool, std::string >> > PiezaGr::direcciones = {
{
        1, {
            {"caballo", {{0, "Horse_Black"}, {1, "Horse_White"}}},
            {"alfil",   {{0, "Bizhop_Black"}, {1, "Bizhop_White"}}},
            {"peon",    {{0, "Pawn_Black"}, {1, "Pawn_White"}}},
            {"rey",     {{0, "King_Black"}, {1, "King_White"}}},
            {"reina",   {{0, "Queen_Black"}, {1, "Queen_White"}}}
        }
    },
    {
        2, {
            {"caballo", {{0, "horsey_Black"}, {1, "horsey_White"}}},
            {"alfil",   {{0, "bizop_Black"}, {1, "bizop_White"}}},
            {"peon",    {{0, "pwaun_Black"}, {1, "pwaun_White"}}},
            {"rey",     {{0, "king_Black"}, {1, "king_White"}}},
            {"reina",   {{0, "qween_Black"}, {1, "qween_White"}}}
        }
    }
};

std::string PiezaGr::getdirecciones(int skin, std::string tipo, bool color)
{
    switch (skin)
    {
    case 1:
        if (color)
        {
            if (tipo == "peon") { return "rc/Pawn_White.png"; }
            if (tipo == "caballo") { return "rc/Horse_White.png"; }
            if (tipo == "alfil") { return "rc/Bizhop_White.png"; }
            if (tipo == "torre") { return "rc/Tower_White.png"; }
            if (tipo == "rey") { return "rc/King_White.png"; }
            if (tipo == "reina") { return "rc/Queen_White.png"; }
        }
        else
        {
            if (tipo == "peon") { return "rc/Pawn_Black.png"; }
            if (tipo == "caballo") { return "rc/Horse_Black.png"; }
            if (tipo == "alfil") { return "rc/Bizhop_Black.png"; }
            if (tipo == "torre") { return "rc/Tower_Black.png"; }
            if (tipo == "rey") { return "rc/King_Black.png"; }
            if (tipo == "reina") { return "rc/Queen_Black.png"; }
        }
    case 2:
        if (color)
        {
            if (tipo == "peon") { return "rc/pwaun.png"; }
            if (tipo == "caballo") { return "rc/horsey.png"; }
            if (tipo == "alfil") { return "rc/bizop.png"; }
            if (tipo == "torre") { return "rc/tower.png"; }
            if (tipo == "rey") { return "rc/king.png"; }
            if (tipo == "reina") { return "rc/qween.png"; }
        }
        else
        {
            if (tipo == "peon") { return "rc/pwaun.png"; }
            if (tipo == "caballo") { return "rc/horsey.png"; }
            if (tipo == "alfil") { return "rc/bizop.png"; }
            if (tipo == "torre") { return "rc/tower.png"; }
            if (tipo == "rey") { return "rc/king.png"; }
            if (tipo == "reina") { return "rc/qween.png"; }
        }

    }



}