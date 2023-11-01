#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <iostream>
#include <QMovie>
#include <QDebug>
#include <QTime>
#include <Magick++.h> 
#include <list>
// parametre olarak  8 konuya değinceğiz
// MACOS da brew install imagemagick
// ubuntuda  sudo apt install imagemagick
// 1 - çerçeve(frame) sayısı animasyonun kaç kare olduğunu belirler
// 2 - çerçeve hızı saniyede oynatılan kare sayısını verir
// 3 - çözünürlük giffin genişlik ve yüksekliği piksel cinsinden belirlenir
// 4 - renk sayısı
// 5 - döngü sayısı anımasyon kaç kere döncek
// 6 - şeffaflık (transparan)
// 7 - sıkıştırma oranı  gif dosyasının ne kadar sıkışıcağını belirler
// 8 - metin bilgisi gif içine eklenmiş
int main(int argc, char **argv)
{

    QCoreApplication a(argc, argv);

    Magick::InitializeMagick(*argv);

    QFile file("/Users/mertacar/Desktop/resim1.bmp");

    if(!file.open(QFile::ReadOnly))
        qDebug() << "dosyamızı alamadık";
    std::string filepath = "/Users/mertacar/Desktop/resim1.bmp";
    Magick::Image img;

    try
    {
         img.read(filepath);
    }catch (std::exception& e)
    {
         qDebug() << e.what();
    }

  int cercevesayı = 360 / 10; // 1 - çerçeve sayısını burda aldık
  double cercevehızı = 36; // saniyede 1 çerçeve

  int sütun = img.columns();// çözünürlük için baktık
  int satır = img.rows();//çözünürlük için baktık
  size_t renksayısı;
  if (img.classType() == Magick::PseudoClass) {
        Magick::Image frame = img;
        renksayısı = img.colorMapSize();
     if (renksayısı < frame.colorMapSize() || frame.colorMapSize() == 0)
        {
            frame.type(Magick::PaletteType);  // Resmi paletli resim formatına dönüştürdük
             frame.quantizeColors(renksayısı);
        }

  }
  else {
        qDebug()<< "renk yok";

         // Renk haritası yok, başka bir işlem yap

  //int loopCount = 0; //sınırsız döngü
  //double sıkıştırmaoranı = 1.0;//sıkıştırma olmıcak

  std::list<Magick::Image> frameList;

  for (int i = 0; i < cercevesayı; ++i) {
    Magick::Image frame = img;
        frame.rotate(10 * i);  // Her çerçeve için 10 derece döndür

         frame.resize(Magick::Geometry(sütun, satır));

        frame.animationDelay(1000 / cercevehızı);  // Çerçeve hızını ayarla
        frameList.push_back(frame);
  }

  Magick::writeImages(frameList.begin(), frameList.end(), "/Users/mertacar/Desktop/output1.gif");

  qDebug() << "GIF dosyası başarıyla oluşturuldu!";
  }

    return a.exec();
}
