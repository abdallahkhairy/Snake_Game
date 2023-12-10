#include "raylib.h"

int main(){
    Image img_apple = LoadImage("images/apple.png");
    Image img_icon = LoadImage("images/logo.png");
    Image imguh = LoadImage("images/uhead.png");
    Image imgdh = LoadImage("images/dhead.png");
    Image imgrh = LoadImage("images/rhead.png");
    Image imglh = LoadImage("images/lhead.png");
    Image imgvbody = LoadImage("images/vbody.png");
    Image imghbody = LoadImage("images/hbody.png");
    Image imgtl = LoadImage("images/tl.png");
    Image imgtr = LoadImage("images/tr.png");
    Image imgtld = LoadImage("images/tld.png");
    Image imgtrd = LoadImage("images/trd.png");
    Image imgdt = LoadImage("images/dtail.png");
    Image imgut = LoadImage("images/utail.png");
    Image imgrt = LoadImage("images/rtail.png");
    Image imglt = LoadImage("images/ltail.png");

	ExportImageAsCode(img_apple, "apple.hpp");
	UnloadImage(img_apple);

	ExportImageAsCode(img_icon, "icon.hpp");
	UnloadImage(img_icon);

    ExportImageAsCode(imguh, "imguh.hpp");
    UnloadImage(imguh);

    ExportImageAsCode(imgdh, "imgdh.hpp");
    UnloadImage(imgdh);

    ExportImageAsCode(imgrh, "imgrh.hpp");
    UnloadImage(imgrh);

    ExportImageAsCode(imglh, "imglh.hpp");
    UnloadImage(imglh);

    ExportImageAsCode(imgvbody, "imgvbody.hpp");
    UnloadImage(imgvbody);


    ExportImageAsCode(imghbody, "imghbody.hpp");
    UnloadImage(imghbody);

    ExportImageAsCode(imgtr, "imgtr.hpp");
    UnloadImage(imgtr);

    ExportImageAsCode(imgtl, "imgtl.hpp");
    UnloadImage(imgtl);

    ExportImageAsCode(imgtld, "imgtld.hpp");
    UnloadImage(imgtld);

    ExportImageAsCode(imgtrd, "imgtrd.hpp");
    UnloadImage(imgtrd);

    ExportImageAsCode(imgdt, "imgdt.hpp");
    UnloadImage(imgdt);

    ExportImageAsCode(imgut, "imgut.hpp");
    UnloadImage(imgut);

    ExportImageAsCode(imgrt, "imgrt.hpp");
    UnloadImage(imgrt);

    ExportImageAsCode(imglt, "imglt.hpp");
    UnloadImage(imglt);
}